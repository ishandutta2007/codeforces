#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
vector<int> adjList[MAXN + 1];
int val[MAXN + 1];

int dfs(int v, int p, int l)
{
    val[v] = l;
    int sz = 0;
    for (int adj : adjList[v])
    {
        if (adj == p)
            continue;
        sz += dfs(adj, v, l + 1);
    }
    val[v] -= sz;
    return sz + 1;
}

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    dfs(1, 1, 0);
    sort(val + 1, val + n + 1);
    long long ans = 0;
    for (int i = 0; i < k; i++)
    {
        ans += val[n - i];
    }
    cout << ans << endl;
    return 0;
}