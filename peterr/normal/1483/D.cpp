#include <bits/stdc++.h>

using namespace std;

const int MAXN = 600;
const long long INF = 1E18;
long long dist[MAXN + 1][MAXN + 1];
tuple<int, int, int> a[MAXN * MAXN];
vector<pair<int, int>> adjList[MAXN + 1];
long long best[MAXN + 1][MAXN + 1];
vector<int> where[MAXN + 1];

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
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = dist[v][u] = w;
        adjList[u].push_back({v, w});
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
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int u, v, l;
        cin >> u >> v >> l;
        if (u > v)
            swap(u, v);
        a[i] = {u, v, l};
        where[u].push_back(i);
        where[v].push_back(i);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            best[i][j] = 0;
            for (int id : where[i])
            {
                int k = get<0>(a[id]);
                if (k == i)
                    k = get<1>(a[id]);
                best[i][j] = max(best[i][j], get<2>(a[id]) - dist[j][k]);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (pair<int, int> edge : adjList[i])
        {
            int adj = edge.first;
            int w = edge.second;
            bool useful = false;
            for (int j = 1; j <= n; j++)
            {
                if (dist[j][i] == INF)
                    continue;
                if (w + dist[j][i] <= best[j][adj])
                {
                    useful = true;
                    break;
                }
            }
            ans += useful;
        }
    }
    cout << ans << "\n";
    return 0;
}