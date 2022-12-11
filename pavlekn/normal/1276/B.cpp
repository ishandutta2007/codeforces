#include<bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 2e5 + 7;

int used[MAXN];

vector<vector<int>> g(MAXN);

int ans1, ans2;

void dfs(int u)
{
    used[u] = true;
    --ans1;
    for (auto v : g[u])
    {
        if (!used[v])
        {
            dfs(v);
        }
    }
}

void dfs2(int u)
{
    used[u] = true;
    --ans2;
    for (auto v : g[u])
    {
        if (!used[v])
        {
            dfs2(v);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_)
    {
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        --a; --b;
        for (int i = 0; i < n; ++i)
        {
            g[i] = {};
        }
        for (int i = 0; i < m; ++i)
        {
            int u, v;
            cin >> u >> v;
            --u; --v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        ans1 = n - 1;
        ans2 = n - 1;
        for (int i = 0; i < n; ++i)
        {
            used[i] = false;
        }
        used[a] = true;
        dfs(b);
        for (int i = 0; i < n; ++i)
        {
            used[i] = false;
        }
        used[b] = true;
        dfs2(a);
        cout << ans1 * ans2 << endl;
    }
    return 0;
}