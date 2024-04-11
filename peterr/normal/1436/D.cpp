#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
vector<int> adjList[MAXN + 1];
int a[MAXN + 1];
long long sum[MAXN + 1];
int leaves[MAXN + 1];

void dfs(int v, int p)
{
    if ((int) adjList[v].size() == 1 && v != p)
        leaves[v] = 1;
    sum[v] = a[v];
    for (int adj : adjList[v])
    {
        if (adj == p)
            continue;
        dfs(adj, v);
        sum[v] += sum[adj];
        leaves[v] += leaves[adj];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        int p;
        cin >> p;
        adjList[i].push_back(p);
        adjList[p].push_back(i);
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    long long ans = 0;
    dfs(1, 1);
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, (sum[i] + leaves[i] - 1) / leaves[i]);
    }
    cout << ans << "\n";
    return 0;
}