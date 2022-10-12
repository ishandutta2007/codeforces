#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, m, k;
pair<int, int> edge[N];
int weight[N];

pair<int, int> routes[N];

vector<pair<int, int>> edges[N];

int dist[N][N];

void dijkstra(int u, int dist[]) {
  vector<bool> vis(n, false);
  // for (int i = 0; i < n; ++i) dist[i] = 1e9;
  priority_queue<pair<int, int>> pq;
  pq.push({0, u});
  dist[u] = 0;

  while (pq.size()) {
    int u, d;
    tie(d, u) = pq.top();
    d = -d;
    pq.pop();

    if (vis[u]) continue;
    dist[u] = d;
    vis[u] = true;

    for (int i = 0; i < edges[u].size(); ++i) {
      int v, w;
      tie(v, w) = edges[u][i];
      if (vis[v]) continue;
      pq.push({-d - w, v});
    }
  }
}

int solve() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    --u, --v;

    edge[i] = {u, v};
    weight[i] = w;

    edges[u].emplace_back(v, w);
    edges[v].emplace_back(u, w);
  }

  for (int i = 0; i < k; ++i) {
    scanf("%d %d", &routes[i].first, &routes[i].second);
    --routes[i].first, --routes[i].second;
  }

  for (int i = 0; i < n; ++i) dijkstra(i, dist[i]);


  int ans = 1e9;
  for (int i = 0; i < m; ++i) {
    int sum = 0;
    for (int j = 0; j < k; ++j) {
      sum += min(dist[routes[j].first][routes[j].second],
      min(dist[routes[j].first][edge[i].first] + dist[edge[i].second][routes[j].second],
          dist[routes[j].first][edge[i].second] + dist[edge[i].first][routes[j].second])
      );
    }

    ans = min(ans, sum);
  }

  printf("%d\n", ans);
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}