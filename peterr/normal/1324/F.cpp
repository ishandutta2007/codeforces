#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
bool isWhite[MAXN + 1];
vector<int> adjList[MAXN + 1];
int dp[MAXN + 1];
int ans[MAXN + 1];

void dfs(int v, int p)
{
    dp[v] = isWhite[v] ? 1 : -1;
    for (int adj : adjList[v])
    {
        if (adj != p)
        {
            dfs(adj, v);
            dp[v] += max(0, dp[adj]);
        }
    }
}

void solve(int v, int p)
{
    ans[v] = dp[v];
    if (v != p && ans[p] > 0)
    {
        int temp = ans[p];
        temp -= max(0, dp[v]);
        if (temp > 0)
            ans[v] += temp;
    }
    for (int adj : adjList[v])
    {
        if (adj != p)
            solve(adj, v);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> isWhite[i];
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    dfs(1, 1);
    solve(1, 1);
    for (int i = 1; i <= n; i++)
    {
        if (i > 1)
            cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return 0;
}