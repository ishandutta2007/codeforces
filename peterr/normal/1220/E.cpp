#include <bits/stdc++.h>

using namespace std;

const int MAXN = (int) 2E5;
int scores[MAXN + 1];
vector<int> adjList[MAXN + 1];
vector<int> tree[MAXN + 1];
vector<int> bck[MAXN + 1];
bool visited[MAXN + 1];
bool recurse[MAXN + 1];

void dfs(int v, int parent)
{
    visited[v] = true;
    recurse[v] = true;
    for (int adj : adjList[v])
    {
        if (adj == parent)
            continue;
        if (recurse[adj])
        {
            bck[adj].push_back(v);
        }
        else if (!visited[adj])
        {
            tree[v].push_back(adj);
            tree[adj].push_back(v);
            dfs(adj, v);
        }
    }
    recurse[v] = false;
}

long long dfs2(int v, int parent)
{
    long long ans = 0;
    for (int adj : tree[v])
    {
        if (adj != parent)
        {
            ans = max(ans, dfs2(adj, v));
        }
    }
    if (!visited[v])
        ans += scores[v];
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, s;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> scores[i];
    }
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    cin >> s;
    dfs(s, 0);
    fill(visited + 1, visited + n + 1, false);
    long long ans = scores[s];
    visited[s] = true;
    for (int i = 1; i <= n; i++)
    {
        for (int adj : bck[i])
        {
            int u = adj;
            while (!visited[u])
            {
                visited[u] = true;
                ans += scores[u];
                u = tree[u][0];
            }
        }
    }
    ans += dfs2(s, 0);
    cout << ans << endl;
    return 0;
}