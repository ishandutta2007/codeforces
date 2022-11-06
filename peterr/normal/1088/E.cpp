#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3E5;
int a[MAXN + 1];
vector<int> adjList[MAXN + 1];
long long dp[MAXN + 1];
bool used[MAXN + 1];

long long dfs(int v, int p)
{
    long long ans = a[v];
    dp[v] = a[v];
    for (int adj : adjList[v])
    {
        if (adj != p)
        {
            ans = max(ans, dfs(adj, v));
            if (dp[adj] > 0)
                dp[v] += dp[adj];
        }
    }
    return max(ans, dp[v]);
}

int dfs2(int v, int p, long long target)
{
    int ans = 0;
    dp[v] = a[v];
    for (int adj : adjList[v])
    {
        if (adj != p)
        {
            ans += dfs2(adj, v, target);
            if (!used[adj] && dp[adj] > 0)
                dp[v] += dp[adj];
        }
    }
    if (dp[v] == target)
    {
        ans++;
        used[v] = true;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    long long best = dfs(1, 1);
    int k = dfs2(1, 1, best);
    cout << best * k << " " << k << endl;
    return 0;
}