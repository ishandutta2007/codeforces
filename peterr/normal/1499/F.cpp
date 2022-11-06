#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5000;
const int MOD = 998244353;
vector<int> adjList[MAXN + 1];
int dp[MAXN + 1][MAXN];
int temp[MAXN + 5];
int dist[MAXN + 1];

void add(int &x, int y)
{
    x += y;
    if (x >= MOD)
        x -= MOD;
}

void solve(int v, int p, int k)
{
    dp[v][0] = 1;
    int cur = 0;
    for (int adj : adjList[v])
    {
        if (adj == p)
            continue;
        solve(adj, v, k);
        fill(temp, temp + max(cur, dist[adj] + 1) + 1, 0);
        for (int i = 0; i <= cur; i++)
        {
            for (int j = 0; j <= min(k, dist[adj]); j++)
            {
                add(temp[i], (int) ((long long) dp[v][i] * dp[adj][j] % MOD));
                if (i + j + 1 > k)
                    continue;
                add(temp[max(i, j + 1)], (int) ((long long) dp[v][i] * dp[adj][j] % MOD));
            }
        }
        cur = min(k, max(cur, dist[adj] + 1));
        for (int i = 0; i <= cur; i++)
        {
            dp[v][i] = temp[i];
        }
    }
    //cout << "dp " << v << " " << dp[v][0] << endl;
}

void dfs(int v, int p)
{
    for (int adj : adjList[v])
    {
        if (adj == p)
            continue;
        dfs(adj, v);
        dist[v] = max(dist[v], dist[adj] + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    dfs(1, 1);
    solve(1, 1, k);
    int ans = 0;
    for (int i = 0; i <= k; i++)
    {
        add(ans, dp[1][i]);
    }
    cout << ans << "\n";
    return 0;
}