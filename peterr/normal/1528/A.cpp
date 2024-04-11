#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
long long dp[MAXN + 1][2];
pair<long long, long long> a[MAXN + 1];
vector<int> adjList[MAXN + 1];

void dfs(int v, int p)
{
    dp[v][0] = dp[v][1] = 0;
    for (int adj : adjList[v])
    {
        if (adj == p)
            continue;
        dfs(adj, v);
        dp[v][0] += max(dp[adj][1] + abs(a[v].first - a[adj].second), dp[adj][0] + abs(a[v].first - a[adj].first));
        dp[v][1] += max(dp[adj][1] + abs(a[v].second - a[adj].second), dp[adj][0] + abs(a[v].second - a[adj].first));
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            adjList[i].clear();
            cin >> a[i].first >> a[i].second;
        }
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        dfs(1, 1);
        cout << max(dp[1][0], dp[1][1]) << "\n";
    }
    return 0;
}