#include <bits/stdc++.h>
using namespace std;

class BST
{
public:
    int data;
    BST *left;
    BST *right;

    BST()
    {
        data = 0;
        left = right = NULL;
    }

    BST(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }

    BST *Insert(BST *root, int val)
    {
        if (root == NULL)
        {
            return new BST(val);
        }
        if (val > root->data)
        {
            root->right = Insert(root->right, val);
        }
        else
        {
            root->left = Insert(root->left, val);
        }
        return root;
    }
};

vector<vector<int>> levelOrder(BST *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
    {
        return ans;
    }
    queue<BST *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> level;
        for (int i = 0; i < size; i++)
        {
            BST *node = q.front();
            q.pop();
            if (node->left != NULL)
            {
                q.push(node->left);
            }
            if (node->right != NULL)
            {
                q.push(node->right);
            }
            level.push_back(node->data);
        }
        ans.push_back(level);
    }
    return ans;
}

BST *search(BST *root, int key)
{
    if (root == NULL || root->data == key)
    {
        return root;
    }
    if (root->data < key)
    {
        return search(root->right, key);
    }
    return search(root->left, key);
}

int main()
{
    BST b;
    BST *root = NULL;
    root = b.Insert(root, 50);
    b.Insert(root, 30);
    b.Insert(root, 20);
    b.Insert(root, 40);
    b.Insert(root, 70);
    b.Insert(root, 60);
    b.Insert(root, 80);

    vector<vector<int>> ans = levelOrder(root);
    for (auto it : ans)
    {
        for (auto it2 : it)
        {
            cout << it2 << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}