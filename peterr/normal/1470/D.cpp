#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3E5;
vector<int> adjList[MAXN + 1];
bool visited[MAXN + 1];
vector<int> tree[MAXN + 1];
vector<int> backedges[MAXN + 1];
bool ans[MAXN + 1];

void dfs(int v, int p)
{
    visited[v] = true;
    for (int adj : adjList[v])
    {
        if (adj == p)
            continue;
        if (!visited[adj])
        {
            tree[v].push_back(adj);
            tree[adj].push_back(v);
            dfs(adj, v);
        }
        else
        {
            backedges[v].push_back(adj);
            backedges[adj].push_back(v);
        }
    }
}

void solve(int v, int p)
{
    if (!visited[v])
    {
        visited[v] = visited[p] = true;
        ans[v] = true;
        for (int adj : backedges[v])
            visited[adj] = true;
        for (int adj : tree[v])
            visited[adj] = true;
    }
    for (int adj : tree[v])
    {
        if (adj == p)
            continue;
        solve(adj, v);
    }
    /*
    if (!visited[v])
    {
        ans[v] = true;
        visited[v] = true;
        for (int adj : backedges[v])
            visited[adj] = true;
        visited[p] = true;
    }
    */
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
        for (int i = 1; i <= n; i++)
        {
            adjList[i].clear();
            tree[i].clear();
            backedges[i].clear();
        }
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        fill(visited + 1, visited + n + 1, false);
        dfs(1, 1);
        bool connected = true;
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                connected = false;
                break;
            }
        }
        if (!connected)
        {
            cout << "NO\n";
            continue;
        }
        fill(ans + 1, ans + n + 1, false);
        fill(visited + 1, visited + n + 1, false);
        solve(1, 1);
        cout << "YES\n";
        vector<int> lst;
        for (int i = 1; i <= n; i++)
            if (ans[i])
                lst.push_back(i);
        cout << lst.size() << "\n";
        for (int x : lst)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}