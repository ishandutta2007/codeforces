#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;
const int INF = 1E8;
vector<pair<int, int>> adjList[MAXN + 1];
int dist[MAXN + 1][MAXN + 1];
int dist2[MAXN + 1];
pair<int, int> a[MAXN];

void dij(int start)
{
    fill(dist2 + 1, dist2 + MAXN + 1, INF);
    dist2[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, start));
    while (!pq.empty())
    {
        pair<int, int> pr = pq.top();
        pq.pop();
        int v = pr.second;
        int d = pr.first;
        if (dist2[v] < d)
            continue;
        for (pair<int, int> edge : adjList[v])
        {
            int adj = edge.first;
            int w = edge.second;
            if (w + d < dist2[adj])
            {
                dist2[adj] = w + d;
                pq.push(make_pair(dist2[adj], adj));
            }
        }
    }
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        adjList[a].push_back(make_pair(b, w));
        adjList[b].push_back(make_pair(a, w));
    }
    for (int i = 0; i < k; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    for (int i = 1; i <= n; i++)
    {
        dij(i);
        for (int j = 1; j <= n; j++)
        {
            dist[i][j] = dist2[j];
        }
    }
    int ans = 0;
    for (int i = 0; i < k; i++)
    {
        ans += dist[a[i].first][a[i].second];
    }
    for (int i = 1; i <= n; i++)
    {
        for (pair<int, int> edge : adjList[i])
        {
            int temp = 0;
            int adj = edge.first;
            for (int j = 0; j < k; j++)
            {
                temp += min(dist[a[j].first][a[j].second], min(dist[a[j].first][i] + dist[adj][a[j].second], dist[a[j].first][adj] + dist[i][a[j].second]));
            }
            ans = min(ans, temp);
        }
    }
    cout << ans << "\n";
    return 0;
}