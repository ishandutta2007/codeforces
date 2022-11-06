#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5000;
vector<int> adjList[MAXN + 1];
vector<int> comp[MAXN + 1];
bool visited[MAXN + 1];
pair<int, int> sze[MAXN + 1];

void dfs(int v, vector<int> &vec)
{
    vec.push_back(v);
    visited[v] = true;
    for (int adj : adjList[v])
    {
        if (!visited[adj])
        {
            dfs(adj, vec);
        }
    }
}

int main()
{
    int n, m, s;
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
    }
    for (int i = 1; i <= n; i++)
    {
        fill(visited + 1, visited + n + 1, false);
        dfs(i, comp[i]);
        sze[i] = {(int) comp[i].size(), i};
    }
    sort(sze + 1, sze + n + 1);
    int ans = 0;
    fill(visited + 1, visited + n + 1, false);
    for (int v : comp[s])
        visited[v] = true;
    for (int i = n; i >= 1; i--)
    {
        int v = sze[i].second;
        if (!visited[v])
        {
            ans++;
            for (int u : comp[v])
            {
                visited[u] = true;
            }
        }
    }
    cout << ans << endl;
    return 0;
}