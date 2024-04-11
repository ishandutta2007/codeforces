#include <bits/stdc++.h>

using namespace std;

const int INF = 1E9;
const int MAXN = 200;
int color[MAXN + 1];
vector<pair<int, int>> adjList[MAXN + 1];
int dist[MAXN + 1][MAXN + 1];

bool isBi(int v)
{
    for (pair<int, int> edge : adjList[v])
    {
        int adj = edge.first;
        if (color[adj])
        {
            if (color[v] == color[adj])
                return false;
            continue;
        }
        color[adj] = (color[v] == 1 ? -1 : 1);
        if (!isBi(adj))
            return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        fill(dist[i] + 1, dist[i] + n + 1, INF);
        dist[i][i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adjList[a].push_back(make_pair(b, c));
        adjList[b].push_back(make_pair(a, -c));
        if (c)
        {
            dist[a][b] = 1;
            dist[b][a] = -1;
        }
        else
        {
            dist[a][b] = 1;
            dist[b][a] = 1;
        }
    }
    color[1] = 1;
    if (!isBi(1))
    {
        cout << "NO\n";
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }
    }
    int ans = 0;
    int start = -1;
    bool valid = true;
    for (int i = 1; i <= n; i++)
    {
        if (dist[i][i] < 0)
        {
            valid = false;
            break;
        }
        for (int j = 1; j <= n; j++)
        {
            if (dist[i][j] > ans)
            {
                ans = dist[i][j];
                start = i;
            }
        }
    }
    if (valid)
    {
        cout << "YES\n";
        cout << ans << "\n";
        for (int i = 1; i <= n; i++)
        {
            cout << dist[start][i] << " \n"[i == n];
        }
    }
    else
        cout << "NO\n";
    return 0;
}