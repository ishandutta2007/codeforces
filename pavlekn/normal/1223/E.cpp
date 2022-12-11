#include<bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 5e5 + 25;

int dp[MAXN][2];

int used[MAXN];

vector<vector<pair<int, int>>> g(MAXN);

int k;

void dfs(int u)
{
    used[u] = true;
    dp[u][0] = 0;
    dp[u][1] = 0;
    vector<int> cur;
    for (auto el : g[u])
    {
        int v = el.first;
        int w = el.second;
        if (!used[v])
        {
            dfs(v);
            dp[u][0] += dp[v][0];
            dp[u][1] += dp[v][0];
            cur.push_back(dp[v][1] + w - dp[v][0]);
        }
    }
    sort(cur.begin(), cur.end());
    reverse(cur.begin(), cur.end());
    int j = 0;
    for (int i = 0; i < cur.size(); ++i)
    {
        if (cur[i] > 0 && j < k)
        {
            dp[u][0] += cur[i];
        }
        if (cur[i] > 0 && j < k - 1)
        {
            dp[u][1] += cur[i];
        }
        ++j;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int q;
    cin >> q;
    for (int _ = 0; _ < q; ++_)
    {
        int n;
        cin >> n >> k;
        for (int i = 0; i < n; ++i)
        {
            used[i] = false;
        }
        for (int i = 0; i < n; ++i)
        {
            g[i].clear();
        }
        for (int i = 0; i < n - 1; ++i)
        {
            int u, v, w;
            cin >> u >> v >> w;
            --u; --v;
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }
        dfs(0);
        cout << max(dp[0][0], dp[0][1]) << endl;
    }
    return 0;
}