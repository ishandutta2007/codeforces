#include <bits/stdc++.h>
using namespace std;

long long dist[100005][55];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> adj(n);
  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, w);
  }

  using lint = long long;
  priority_queue<array<lint, 3>, vector<array<lint, 3>>, greater<array<lint, 3>>> pq;
  pq.push({0, 0, 0});
  memset(dist, -1, sizeof(dist));
  dist[0][0] = 0;
  while (!pq.empty()) {
    int u = pq.top()[1];
    int w = pq.top()[2];
    lint d = pq.top()[0];
    pq.pop();
    if (dist[u][w] != d) {
      continue;
    }
    for (auto [v, ww] : adj[u]) {
      if (w == 0) {
        if (dist[v][ww] == -1 || dist[v][ww] > dist[u][w]) {
          dist[v][ww] = dist[u][w];
          pq.push({dist[v][ww], v, ww});
        }
      } else {
        if (dist[v][0] == -1 || dist[v][0] > dist[u][w] + (w + ww) * (w + ww)) {
          dist[v][0] = dist[u][w] + (w + ww) * (w + ww);
          pq.push({dist[v][0], v, 0});
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << dist[i][0] << ' ';
  }
  cout << '\n';
  return 0;
}