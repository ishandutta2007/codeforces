#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, k;
  cin >> n >> m >> k;
  vector<pair<int, int>> edges;
  vector<vector<pair<int, int>>> adj(n);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    edges.emplace_back(u, v);
    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, w);
  }
  const auto Dijkstra = [&](int s, vector<int> &d) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, s);
    d.assign(n, -1);
    d[s] = 0;
    while (!pq.empty()) {
      int u = pq.top().second;
      int dt = pq.top().first;
      pq.pop();
      if (d[u] != dt) {
        continue;
      }
      for (auto v : adj[u]) {
        if (d[v.first] == -1 || d[v.first] > d[u] + v.second) {
          d[v.first] = d[u] + v.second;
          pq.emplace(d[v.first], v.first);
        }
      }
    }
  };
  vector<vector<int>> dist(n);
  for (int i = 0; i < n; i++) {
    Dijkstra(i, dist[i]);
  }
  vector<int> a(k), b(k);
  for (int i = 0; i < k; i++) {
    cin >> a[i] >> b[i];
    a[i]--, b[i]--;
  }
  int ans = INT_MAX;
  for (int p = 0; p < m; p++) {
    int cur = 0;
    int u = edges[p].first;
    int v = edges[p].second;
    for (int i = 0; i < k; i++) {
      cur += min({dist[a[i]][b[i]], dist[a[i]][u] + dist[b[i]][v], dist[b[i]][u] + dist[a[i]][v]});
    }
    ans = min(ans, cur);
  }
  cout << ans << "\n";
  return 0; 
}