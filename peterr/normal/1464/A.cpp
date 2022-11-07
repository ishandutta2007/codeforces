#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
vector<pair<int, int>> adjList[MAXN + 1];
bool visited[MAXN + 1];
bool used[MAXN];

bool dfs(int v)
{
    if (visited[v])
        return true;
    visited[v] = true;
    for (pair<int, int> edge : adjList[v])
    {
        int adj = edge.first;
        int ind = edge.second;
        if (used[ind] || adj == v)
            continue;
        used[ind] = true;
        if (dfs(adj))
            return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        fill(used, used + n, false);
        fill(visited + 1, visited + n + 1, false);
        for (int i = 1; i <= n; i++)
        {
            adjList[i].clear();
        }
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            if (a != b)
                ans++;
            adjList[a].push_back({b, i});
            adjList[b].push_back({a, i});
        }
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                ans += dfs(i);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}