#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2 * 1e5;
vector<int> adjList[MAXN + 1];
bool c[MAXN + 1];
bool visited[MAXN + 1];

int solve(int v)
{
    int num = 0;
    visited[v] = true;
    bool found = false;
    for (int adj : adjList[v])
    {
        if (c[adj])
            found = true;
    }
    if (!found)
        c[v] = true;
    for (int adj : adjList[v])
    {
        if (!visited[adj])
        {
            visited[adj] = true;
            num += solve(adj);
        }
    }

    return num + c[v];
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

        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        int numChosen = solve(1);
        if (numChosen <= n / 2)
        {
            cout << numChosen << endl;
            for (int i = 1; i <= n; i++)
                if (c[i])
                    cout << i << " ";
            cout << endl;
        }
        else
        {
            cout << (n - numChosen) << endl;
            for (int i = 1; i <= n; i++)
                if (!c[i])
                    cout << i << " ";
            cout << endl;
        }

        fill(visited, visited + n + 1, false);
        fill(c, c + n + 1, false);
        for (int i = 0; i <= n; i++)
            adjList[i].clear();
    }
    return 0;
}