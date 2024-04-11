#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5000;
vector<int> adjList[MAXN + 1];
bool visited[MAXN + 1];
bool recStack[MAXN + 1];
pair<int, int> edges[MAXN + 1];

bool hasCycle(int u)
{
    visited[u] = true;
    recStack[u] = true;
    for (int adj : adjList[u])
    {
        if (recStack[adj])
            return true;
        if (!visited[adj])
        {
            if (hasCycle(adj))
                return true;
        }
    }
    recStack[u] = false;
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        edges[i] = {u, v};
    }
    bool cyclic = false;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i] && hasCycle(i))
            cyclic = true;
    }
    if (!cyclic)
    {
        cout << 1 << endl;
        for (int i = 0; i < m; i++)
        {
            cout << 1 << " ";
        }
        cout << endl;
    }
    else
    {
        cout << 2 << endl;
        for (int i = 0; i < m; i++)
        {
            if (edges[i].first > edges[i].second)
                cout << 1 << " ";
            else
                cout << 2 << " ";
        }
        cout << endl;
    }
    return 0;
}