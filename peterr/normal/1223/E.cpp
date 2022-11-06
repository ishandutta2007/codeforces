#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5E5;
vector<pair<int, int>> adjList[MAXN + 1];
long long dp[MAXN + 1][2];

void solve(int v, int p, int k)
{
    dp[v][0] = dp[v][1] = 0;
    vector<long long> delta;
    for (pair<int, int> edge : adjList[v])
    {
        int u = edge.first;
        int w = edge.second;
        if (u != p)
        {
            solve(u, v, k);
            dp[v][0] += dp[u][1];
            delta.push_back(w + dp[u][0] - dp[u][1]);
        }
    }
    sort(delta.rbegin(), delta.rend());
    for (int i = 0; i < k - 1 && i < (int) delta.size() && delta[i] > 0; i++)
    {
        dp[v][0] += delta[i];
    }
    dp[v][1] = dp[v][0];
    if (k - 1 < (int) delta.size() && delta[k - 1] > 0)
        dp[v][1] += delta[k - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> q;
    while (q--)
    {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
            adjList[i].clear();
        for (int i = 0; i < n - 1; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            adjList[u].push_back(make_pair(v, w));
            adjList[v].push_back(make_pair(u, w));
        }
        solve(1, 1, k);
        cout << dp[1][1] << "\n";
    }
    return 0;
}