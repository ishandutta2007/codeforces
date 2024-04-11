#include <bits/stdc++.h>

using namespace std;

struct Node
{
    Node* left;
    Node* right;
    int key;
    int prior;
    int sz;

    Node(int k, int p)
    {
        key = k;
        prior = p;
        sz = 1;
        left = right = nullptr;
    }
};

int getSz(Node* root)
{
    if (root == nullptr)
        return 0;
    return root->sz;
}

void updSz(Node* root)
{
    if (root == nullptr)
        return;
    root->sz = 1 + getSz(root->left) + getSz(root->right);
}

void rotLeft(Node* &root, Node* child)
{
    root->right = child->left;
    child->left = root;
    updSz(root);
    updSz(child);
    root = child;
}

void rotRight(Node* &root, Node* child)
{
    root->left = child->right;
    child->right = root;
    updSz(root);
    updSz(child);
    root = child;
}

int query(Node* root, int key)
{
    if (root == nullptr)
        return 0;
    if (root->key == key)
        return 1 + getSz(root->left);
    else if (root->key > key)
        return query(root->left, key);
    return 1 + getSz(root->left) + query(root->right, key);
}

void ins(Node* &root, Node* node)
{
    if (root == nullptr)
        root = node;
    else if (node->key > root->key)
    {
        ins(root->right, node);
        updSz(root);
        if (root->right->prior > root->prior)
            rotLeft(root, root->right);
    }
    else
    {
        ins(root->left, node);
        updSz(root);
        if (root->left->prior > root->prior)
            rotRight(root, root->left);
    }
    updSz(root);
}

const int MAXN = 1E5;
const int MAXF = 1E4;
tuple<int, int, int> stations[MAXN];
Node* roots[MAXF + 1];
int perm[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < MAXN; i++)
        perm[i] = i;
    mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
    shuffle(perm, perm + MAXN, rng);
    int n, k;
    cin >> n >> k;
    int p = 0;
    for (int i = 0; i < n; i++)
    {
        int x, r, f;
        cin >> x >> r >> f;
        stations[i] = make_tuple(r, x, f);
    }
    sort(stations, stations + n);
    reverse(stations, stations + n);
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        int r, x, f;
        r = get<0>(stations[i]);
        x = get<1>(stations[i]);
        f = get<2>(stations[i]);
        for (int j = max(1, f - k); j <= min(MAXF, f + k); j++)
        {
            ans += query(roots[j], x + r) - query(roots[j], x - r - 1);
        }
        Node* node = new Node(x, perm[p++]);
        ins(roots[f], node);
    }
    cout << ans << "\n";
    return 0;
}