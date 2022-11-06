#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5E5;
const int INF = 1E8;
vector<int> adjList1[MAXN + 1];
vector<int> adjList2[MAXN + 1];
vector<int> rev1[MAXN + 1];
vector<int> rev2[MAXN + 1];
int ans[MAXN + 1];
int dist[MAXN + 1];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, t;
        cin >> u >> v >> t;
        if (t)
        {
            adjList2[u].push_back(v);
            rev2[v].push_back(u);
        }
        else
        {
            adjList1[u].push_back(v);
            rev1[v].push_back(u);
        }
    }
    fill(ans + 1, ans + n + 1, -1);
    fill(dist + 1, dist + n + 1, INF);
    dist[n] = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(n, 0));
    while (!q.empty())
    {
        pair<int, int> pr = q.front();
        q.pop();
        int cur = pr.first;
        int d = pr.second;
        if (cur == 1)
            break;
        for (int adj : rev1[cur])
        {
            if (dist[adj] < INF)
                continue;
            if (ans[adj] == -1)
            {
                ans[adj] = 1;
            }
            else if (ans[adj] == 0)
            {
                dist[adj] = d + 1;
                q.push(make_pair(adj, dist[adj]));
            }
        }
        for (int adj : rev2[cur])
        {
            if (dist[adj] < INF)
                continue;
            if (ans[adj] == -1)
            {
                ans[adj] = 0;
            }
            else if (ans[adj] == 1)
            {
                dist[adj] = d + 1;
                q.push(make_pair(adj, dist[adj]));
            }
        }
    }
    if (dist[1] == INF)
        cout << "-1\n";
    else
        cout << dist[1] << "\n";
    for (int i = 1; i <= n; i++)
    {
        cout << max(ans[i], 0);
    }
    cout << "\n";
    return 0;
}