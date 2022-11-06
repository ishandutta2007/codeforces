#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
int dist[MAXN + 1];
vector<int> adjList[MAXN + 1];

void dfs(int v, int p)
{
    for (int adj : adjList[v])
    {
        if (adj == p)
            continue;
        dist[adj] = dist[v] + 1;
        dfs(adj, v);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, a, b, da, db;
        cin >> n >> a >> b >> da >> db;
        for (int i = 1; i <= n; i++)
        {
            adjList[i].clear();
        }
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        if (da * 2 >= db)
        {
            cout << "Alice\n";
            continue;
        }
        dist[a] = 0;
        dfs(a, a);
        if (dist[b] <= da)
        {
            cout << "Alice\n";
            continue;
        }
        int far = a;
        for (int i = 1; i <= n; i++)
        {
            if (dist[i] > dist[far])
                far = i;
        }
        dist[far] = 0;
        dfs(far, far);
        int diam = 0;
        for (int i = 1; i <= n; i++)
        {
            diam = max(diam, dist[i]);
        }
        if (2 * da >= diam)
            cout << "Alice\n";
        else
            cout << "Bob\n";
    }
    return 0;
}