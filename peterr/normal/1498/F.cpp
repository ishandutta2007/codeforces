#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
const int MAXK = 20;
bool ans[MAXN + 1];
vector<int> adjList[MAXN + 1];
int dp[MAXN + 1][2 * MAXK];
int a[MAXN + 1];

void reroot(int v, int u, int k)
{
    for (int i = 0; i < 2 * k; i++)
    {
        dp[v][i] = dp[v][i] ^ dp[u][(i + 1) % (2 * k)];
    }
    for (int i = 0; i < 2 * k; i++)
    {
        dp[u][i] = dp[u][i] ^ dp[v][(i + 1) % (2 * k)];
    }
}

void dfs1(int v, int p, int k)
{
    for (int i = 0; i < k; i++)
        dp[v][k + i] = a[v];
    for (int adj : adjList[v])
    {
        if (adj == p)
            continue;
        dfs1(adj, v, k);
        for (int i = 0; i < 2 * k; i++)
        {
            dp[v][i] = dp[v][i] ^ dp[adj][(i + 1) % (2 * k)];
        }
    }
}

void solve(int v, int p, int k)
{
    ans[v] = dp[v][0] != 0;
    for (int adj : adjList[v])
    {
        if (adj == p)
            continue;
        reroot(v, adj, k);
        solve(adj, v, k);
        reroot(adj, v, k);
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
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    dfs1(1, 1, k);
    solve(1, 1, k);
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " \n"[i == n];
    }
    return 0;
}