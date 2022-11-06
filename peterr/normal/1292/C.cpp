#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3000;
int sze[MAXN + 1][MAXN + 1];
long long dp[MAXN + 1][MAXN + 1];
int path[MAXN + 1][MAXN + 1];
vector<int> adjList[MAXN + 1];

void dfs(int v, int cur, int p)
{
    path[v][cur] = p;
    sze[v][cur] = 1;
    for (int adj : adjList[cur])
    {
        if (adj != p)
        {
            dfs(v, adj, cur);
            sze[v][cur] += sze[v][adj];
        }
    }
}

void solve(int a, int b)
{
    if (dp[a][b] != -1)
        return;
    solve(a, path[a][b]);
    solve(path[b][a], b);
    dp[a][b] = max(dp[a][path[a][b]] + sze[a][b] * sze[b][a], dp[path[b][a]][b] + sze[a][b] * sze[b][a]);
    dp[b][a] = dp[a][b];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
    {
        dfs(i, i, 0);
    }
    for (int i = 1; i <= n; i++)
    {
        fill(dp[i] + 1, dp[i] + n + 1, -1);
        dp[i][i] = 0;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            solve(i, j);
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}