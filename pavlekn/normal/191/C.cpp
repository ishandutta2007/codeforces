#include<bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 25;

const int MAXL = 18;

vector<vector<int>> g(MAXN);

int p[MAXN][MAXL];
int add[MAXN][MAXL];

int used[MAXN];
int tin[MAXN];
int tout[MAXN];

int t = 0;

void dfs(int u)
{
    tin[u] = t++;
    used[u] = true;
    for (auto v : g[u])
    {
        if (!used[v])
        {
            dfs(v);
            p[v][0] = u;
        }
    }
    tout[u] = t++;
}

int lca(int u, int v)
{
    if (tin[u] <= tin[v] && tout[v] <= tout[u])
    {
        return u;
    }
    if (tin[v] <= tin[u] && tout[u] <= tout[v])
    {
        return v;
    }
    int ans = u;
    for (int i = MAXL - 1; i >= 0; --i)
    {
        int cur = p[ans][i];
        if (!(tin[cur] <= tin[v] && tout[v] <= tout[cur]))
        {
            ans = cur;
        }
    }
    return p[ans][0];
}

map<pair<int, int>, int> num;
vector<int> res(MAXN);

void sl(int u, int v)
{
    if (u == v)
    {
        return;
    }
    int ans = u;
    for (int i = MAXL - 1; i >= 0; --i)
    {
        int cur = p[ans][i];
        if (!(tin[cur] <= tin[v] && tout[v] <= tout[cur]))
        {
            add[ans][i]++;
            ans = cur;
        }
    }
    add[ans][0]++;
}

void solve(int u, int v)
{
    int w = lca(u, v);
    sl(u, w);
    sl(v, w);
}

int used2[MAXN];

void dfs2(int u)
{
    used2[u] = true;
    for (auto v : g[u])
    {
        if (!used2[v])
        {
            res[num[{u, v}]] += add[v][0];
            dfs2(v);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
        num[{u, v}] = i;
        num[{v, u}] = i;
    }
    dfs(0);
    for (int i = 1; i < MAXL; ++i)
    {
        for (int u = 0; u < n; ++u)
        {
            p[u][i] = p[p[u][i - 1]][i - 1];
        }
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        --u; --v;
        solve(u, v);
    }
    for (int i = MAXL - 1; i > 0; --i)
    {
        for (int u = 0; u < n; ++u)
        {
            add[u][i - 1] += add[u][i];
            add[p[u][i - 1]][i - 1] += add[u][i];
        }
    }
    dfs2(0);
    for (int i = 0; i < n - 1; ++i)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}