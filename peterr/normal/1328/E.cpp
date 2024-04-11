#include <bits/stdc++.h>

using namespace std;

const int LOGN = 17;
const int MAXN = 2E5;
vector<int> adjList[MAXN + 1];
int parent[MAXN + 1];
int depth[MAXN + 1];
int anc[LOGN + 1][MAXN + 1];

void dfs(int v, int p, int d)
{
    depth[v] = d;
    parent[v] = p;
    anc[0][v] = p;
    for (int adj : adjList[v])
    {
        if (adj != p)
        {
            dfs(adj, v, d + 1);
        }
    }
}

int lca(int u, int v)
{
    if (depth[u] < depth[v])
        swap(u, v);
    int diff = depth[u] - depth[v];
    for (int i = LOGN; i >= 0; i--)
    {
        if (diff & (1 << i))
        {
            u = anc[i][u];
        }
    }
    for (int i = LOGN; i >= 0; i--)
    {
        if (anc[i][u] != anc[i][v])
        {
            u = anc[i][u];
            v = anc[i][v];
        }
    }
    if (u != v)
        u = anc[0][u];
    return u;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    dfs(1, 1, 0);
    for (int i = 1; i <= LOGN; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            anc[i][j] = anc[i - 1][anc[i - 1][j]];
        }
    }
    while (m--)
    {
        int k;
        cin >> k;
        vector<int> vec;
        int v = 1;
        int d = -1;
        for (int i = 0; i < k; i++)
        {
            int x;
            cin >> x;
            vec.push_back(x);
            if (depth[x] > d)
            {
                d = depth[x];
                v = x;
            }
        }
        int terminal = parent[v];
        bool ans = true;
        for (int x : vec)
        {
            if (lca(parent[x], terminal) != parent[x])
                ans = false;
        }
        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}