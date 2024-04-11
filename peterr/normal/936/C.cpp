#include <bits/stdc++.h>

using namespace std;

struct Node
{
    Node* left;
    Node* right;
    int val, prior, sz, bitmask;
    bool rev;

    Node(int v, int p)
    {
        val = v;
        prior = p;
        left = right = nullptr;
        sz = 1;
        bitmask = 1 << val;
        rev = false;
    }
};

const int INF = 1E9;
const int MAXN = 2000;
int perm[MAXN];
int freq[26];
vector<int> ans;
mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

int getSz(Node* root)
{
    if (root)
        return root->sz;
    return 0;
}

int getBits(Node* root)
{
    if (root)
        return root->bitmask;
    return 0;
}

void upd(Node* root)
{
    if (!root)
        return;
    root->sz = getSz(root->left) + getSz(root->right) + 1;
    root->bitmask = (1 << root->val) | getBits(root->left) | getBits(root->right);
}

void rev(Node* root)
{
    if (root)
        root->rev = !root->rev;
}

void prop(Node* root)
{
    if (!root)
        return;
    if (root->rev)
    {
        root->rev = false;
        swap(root->left, root->right);
        rev(root->left);
        rev(root->right);
    }
}

void rotLeft(Node* &root, Node* child)
{
    root->right = child->left;
    child->left = root;
    upd(root);
    upd(child);
    root = child;
}

void rotRight(Node* &root, Node* child)
{
    root->left = child->right;
    child->right = root;
    upd(root);
    upd(child);
    root = child;
}

void ins(Node* &root, int pos, Node* node)
{
    if (!root)
    {
        root = node;
        return;
    }
    prop(root);
    if (getSz(root->left) + 1 <= pos)
    {
        ins(root->right, pos - (getSz(root->left) + 1), node);
        upd(root);
        if (root->right->prior > root->prior)
            rotLeft(root, root->right);
    }
    else
    {
        ins(root->left, pos, node);
        upd(root);
        if (root->left->prior > root->prior)
            rotRight(root, root->left);
    }
}

void meld(Node* left, Node* right, Node* &root)
{
    if (left)
        prop(left);
    if (right)
        prop(right);
    if (!left && !right)
        root = nullptr;
    else if (!left)
        root = right;
    else if (!right)
        root = left;
    else
    {
        if (left->prior > right->prior)
        {
            root = left;
            meld(left->right, right, root->right);
        }
        else
        {
            root = right;
            meld(left, right->left, root->left);
        }
    }
    upd(root);
}

void split(Node* root, int numLeft, Node* &_left, Node* &_right)
{
    prop(root);
    Node* temp = new Node(0, INF);
    ins(root, numLeft, temp);
    _left = temp->left;
    _right = temp->right;
    delete temp;
}

int _search(Node* root, int key)
{
    if (!root)
        return -1;
    prop(root);
    if (!((1 << key) & root->bitmask))
        return -1;
    if (root->right && (root->right->bitmask & (1 << key)))
        return getSz(root->left) + 1 + _search(root->right, key);
    else if (root->val == key)
        return getSz(root->left);
    assert(root->left && root->left->bitmask & (1 << key));
    return _search(root->left, key);
}

void _do(Node* &root, int x, int n)
{
    int numLeft = n - x;
    Node* left;
    Node* right;
    split(root, numLeft, left, right);
    rev(right);
    meld(right, left, root);
}

void process(Node* &root, char key, int n, int &len)
{
    int ind = _search(root, key);
    int x = n - ind;
    ans.push_back(x);
    _do(root, ans.back(), n);
    ans.push_back(n - x - len);
    _do(root, ans.back(), n);
    len++;
    ans.push_back(len);
    _do(root, ans.back(), n);
}

int main()
{
    int n;
    string s, t;
    cin >> n >> s >> t;
    for (int i = 0; i < n; i++)
    {
        perm[i] = i;
        freq[s[i] - 'a']++;
        freq[t[i] - 'a']--;
    }
    shuffle(perm, perm + n, rng);
    Node* root = nullptr;
    for (int i = 0; i < n; i++)
    {
        Node* temp = new Node(s[i] - 'a', perm[i]);
        ins(root, i, temp);
    }
    bool poss = true;
    for (int i = 0; i < 26; i++)
    {
        if (freq[i])
            poss = false;
    }
    if (poss)
    {
        int mid = n / 2;
        int offset = 1;
        int len = 0;
        process(root, t[mid] - 'a', n, len);
        while (1)
        {
            if (mid - offset < 0)
                break;
            process(root, t[mid - offset] - 'a', n, len);
            if (mid + offset >= n)
                break;
            process(root, t[mid + offset] - 'a', n, len);
            offset++;
        }
        if (!(n & 1))
            ans.push_back(n);
        cout << (int) ans.size() << "\n";
        for (int i = 0; i < (int) ans.size(); i++)
            cout << ans[i] << " \n"[i == (int) ans.size() - 1];
    }
    else
        cout << "-1\n";
    return 0;
}