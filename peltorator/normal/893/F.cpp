#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef double ld;

const int N = (100001), INF = 1e9 + 7;

struct Node
{
   // int num;
    int min;
    Node *left;
    Node *right;
    Node(int num, Node* l, Node* r):
        min(num),
        left(l),
        right(r) {}
};

Node* build(int l, int r)
{
    if (l == r)
        return new Node(INF, 0, 0);
    int mid = (r + l) / 2;
    Node *v = build(l, mid);
    return new Node(INF, v, v);
}

Node* update(Node *v, int p, int val, int l, int r)
{
    if (p < l || p > r)
        return v;//return new Node(v->min, v->left, v->right);//eq(v); 
    if (l == r)
        return new Node(min(v->min, val), 0, 0);
    int mid = (r + l) / 2;
    return new Node(min(v->min, val), update(v->left, p, val, l, mid), update(v->right, p, val, mid + 1, r));
}

int find_min(Node *v, int l, int r, int ql, int qr)
{
    if (r < ql || l > qr)
        return INF;
    if (ql <= l && r <= qr)
        return v->min;
    int mid = (r + l) / 2;
    return min(find_min(v->left, l, mid, ql, qr), find_min(v->right, mid + 1, r, ql, qr));
}

int a[N];
vector<int> g[N];
int used[N];
int lvl[N], down[N];
Node* tree[N];

void dfs(int v)
{
    if (!lvl[v])
        lvl[v] = 1;
    used[v] = 1;
    down[v] = 1;
    for (int i = 0; i + 1 < g[v].size(); i++)
        if (used[g[v][i]])
            swap(g[v][i], g[v][i + 1]);
    if (g[v].size() && used[g[v].back()])
        g[v].pop_back();
    for (int i = 0; i < g[v].size(); i++)
    {
        lvl[g[v][i]] = lvl[v] + 1;
        dfs(g[v][i]);
        down[v] = max(down[v], down[g[v][i]] + 1);
    }
    for (int i = 1; i < g[v].size(); i++)
        if (down[g[v][0]] < down[g[v][i]])
                swap(g[v][0], g[v][i]);
}

int n;

void dfs1(int v)
{
    //cout << v << endl;
    used[v] = 1;
    if (!g[v].size())
    {
        tree[v] = build(1, n);
       // cout << v << endl;
        tree[v] = update(tree[v], lvl[v], a[v], 1, n);
       // cout << v << endl;
        return;
    }
    for (int i = 0; i < g[v].size(); i++)
    {
        dfs1(g[v][i]);
        if (!i)
        {
            tree[v] = tree[g[v][i]];//new Node(tree[g[v][i]]->min, tree[g[v][i]]->left, tree[g[v][i]]->right);
            //tree[v] = eq(tree[g[v][i]]);
            tree[v] = update(tree[v], lvl[v], a[v], 1, n);
           // ok = true;
            continue;
        }
        for (int j = lvl[g[v][i]]; j <= lvl[g[v][i]] + down[g[v][i]] - 1; j++)
            tree[v] = update(tree[v], j, find_min(tree[g[v][i]], 1, n, j, j), 1, n);
    }
    return;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int r;
    //scanf("%d %d", &n, &r);
    cin >> n >> r;
    for (int i = 1; i <= n; i++)
        //scanf("%d", &a[i]);
        cin >> a[i];
    for (int i = 1; i < n; i++)
    {
        int x, y;
        //scanf("%d %d", &x, &y);
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(r);
    for (int i = 1; i <= n; i++)
        used[i] = 0;
    dfs1(r);
    int m;
    //scanf("%d", &m);
    cin >> m;
    int last = 0;
    //return 0;
    for (int i = 0; i < m; i++)
    {
        int p, q;
        cin >> p >> q;
        int v = (p + last) % n + 1, k = (q + last) % n;
        last = find_min(tree[v], 1, n, lvl[v], min(lvl[v] + k, n));
        cout << last << " ";
    }
    cout << endl;
    return 0;
}