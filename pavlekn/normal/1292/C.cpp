#include<bits/stdc++.h>

using namespace std;

const int MAXN = 3107;

vector<vector<int>> g(MAXN);

long long dp[MAXN][MAXN];

int used[MAXN];

int p[MAXN][MAXN];
int sz[MAXN][MAXN];
int dist[MAXN][MAXN];

int st = 0;

void dfs(int u, int pr, int d)
{
    p[st][u] = pr;
    sz[st][u] = 1;
    dist[st][u] = d;
    used[u] = true;
    for (auto v : g[u])
    {
        if (!used[v])
        {
            dfs(v, u, d + 1);
            sz[st][u] += sz[st][v];
        }
    }
}

vector<pair<int, int>> cc[MAXN];

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
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            used[j] = false;
        }
        st = i;
        dfs(i, i, 0);
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cc[dist[i][j]].push_back({i, j});
        }
    }
    long long ans = 0;
    for (int len = 1; len <= n; ++len)
    {
        for (auto el : cc[len])
        {
            int u = el.first;
            int v = el.second;
            dp[u][v] = max(dp[u][p[u][v]], dp[v][p[v][u]]) + (long long)sz[u][v] * (long long)sz[v][u];
            ans = max(ans, dp[u][v]);
        }
    }
    cout << ans << endl;
    return 0;
}