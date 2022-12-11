#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 7;

vector<vector<int>> g(MAXN);

int us[MAXN];

void dfs(int u)
{
    us[u] = true;
    for (auto v : g[u])
    {
        if (!us[v])
        {
            dfs(v);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> deg(n);
    map<pair<int, int>, int> was;
    vector<pair<int, int>> edges;
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        --u; --v;
        ++deg[u];
        ++deg[v];
        was[{u, v}] = true;
        was[{v, u}] = true;
    }
    int ans = n;
    int u = 0;
    for (int i = 0; i < n; ++i)
    {
        if (deg[i] < ans)
        {
            u = i;
            ans = deg[i];
        }
    }
    vector<int> used(n);
    used[u] = true;
    vector<int> a;
    for (int v = 0; v < n; ++v)
    {
        if (!was[{u, v}])
        {
            used[v] = true;
        }
        else if (u != v)
        {
            a.push_back(v);
        }
    }
    a.push_back(u);
    for (auto u : a)
    {
        for (int v = 0; v < n; ++v)
        {
            if (u != v && !was[{u, v}])
            {
                edges.push_back({u, v});
            }
        }
    }
    used[u] = false;
    for (auto el : edges)
    {
        if (!used[el.first] || !used[el.second])
        {
            auto p = el;
            if (used[p.first])
            {
                p.first = u;
            }
            if (used[p.second])
            {
                p.second = u;
            }
            g[el.first].push_back(el.second);
            g[el.second].push_back(el.first);
        }
    }
    dfs(u);
    int res = 0;
    for (int i = 0; i < n; ++i)
    {
        if (!used[i])
        {
            if (!us[i])
            {
                dfs(i);
                ++res;
            }
        }
    }
    cout << res << endl;
    return 0;
}