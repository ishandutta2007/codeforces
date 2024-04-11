#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
vector<int> adjList[MAXN + 1];
long long dp[MAXN + 1];
int s[MAXN + 1];

void dfs(int v, int p)
{
    s[v] = 1;
    for (int adj : adjList[v])
    {
        if (adj == p)
            continue;
        dfs(adj, v);
        s[v] += s[adj];
        dp[v] += dp[adj];
    }
    dp[v] += s[v];
}

void rot(int x, int y)
{
    s[x] -= s[y];
    dp[x] -= s[y];
    dp[x] -= dp[y];
    s[y] += s[x];
    dp[y] += s[x];
    dp[y] += dp[x];
}

long long dfs2(int v, int p)
{
    long long ans = dp[v];
    for (int adj : adjList[v])
    {
        if (adj == p)
            continue;
        rot(v, adj);
        ans = max(ans, dfs2(adj, v));
        rot(adj, v);
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    dfs(1, 1);
    cout << dfs2(1, 1) << endl;
    return 0;
}