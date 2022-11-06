#include <bits/stdc++.h>

using namespace std;

const long long INF = 1E17;
const int MAXN = 2E5;
vector<pair<int, int>> adjList[MAXN + 1];
long long dist[4 * MAXN + 1];

int encode(int v, int mask)
{
    return (v - 1) * 4 + mask;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }
    fill(dist, dist + 4 * n + 1, INF);
    dist[encode(1, 0)] = 0;
    priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> pq;
    pq.push({0, 1, 0});
    while (!pq.empty())
    {
        tuple<long long, int, int> tup = pq.top();
        pq.pop();
        long long d = get<0>(tup);
        int v = get<1>(tup);
        int mask = get<2>(tup);
        if (dist[encode(v, mask)] < d)
            continue;
        for (pair<int, int> edge : adjList[v])
        {
            int adj = edge.first;
            int w = edge.second;
            int ind = encode(adj, mask);
            if (d + w < dist[ind])
            {
                dist[ind] = d + w;
                pq.push({dist[ind], adj, mask});
            }
            ind = encode(adj, mask | 1);
            if (!(mask & 1) && d + w + w < dist[ind])
            {
                dist[ind] = d + w + w;
                pq.push({dist[ind], adj, mask | 1});
            }
            ind = encode(adj, mask | 2);
            if (!(mask & 2) && d < dist[ind])
            {
                dist[ind] = d;
                pq.push({dist[ind], adj, mask | 2});
            }
            ind = encode(adj, 3);
            if (mask == 0 && d + w < dist[ind])
            {
                dist[ind] = d + w;
                pq.push({dist[ind], adj, 3});
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        long long ans = INF;
        ans = min(ans, dist[encode(i, 3)]);
        ans = min(ans, dist[encode(i, 1)]);
        ans = min(ans, dist[encode(i, 0)]);
        cout << ans << " ";
    }
    cout << "\n";
    return 0;
}