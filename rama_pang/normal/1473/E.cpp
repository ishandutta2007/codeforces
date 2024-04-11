#include <bits/stdc++.h>
using namespace std;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, M;
  cin >> N >> M;
  // must ignore cost once, must take double cost once
  vector<vector<pair<int, long long>>> adj(4 * N);
  for (int i = 0; i < M; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    adj[N * 0 + u].emplace_back(N * 0 + v, w);
    adj[N * 0 + v].emplace_back(N * 0 + u, w);

    adj[N * 0 + u].emplace_back(N * 1 + v, 0);
    adj[N * 0 + v].emplace_back(N * 1 + u, 0);

    adj[N * 0 + u].emplace_back(N * 2 + v, w + w);
    adj[N * 0 + v].emplace_back(N * 2 + u, w + w);

    adj[N * 0 + u].emplace_back(N * 3 + v, w);
    adj[N * 0 + v].emplace_back(N * 3 + u, w);

    adj[N * 1 + u].emplace_back(N * 1 + v, w);
    adj[N * 1 + v].emplace_back(N * 1 + u, w);

    adj[N * 1 + u].emplace_back(N * 3 + v, w + w);
    adj[N * 1 + v].emplace_back(N * 3 + u, w + w);

    adj[N * 2 + u].emplace_back(N * 2 + v, w);
    adj[N * 2 + v].emplace_back(N * 2 + u, w);

    adj[N * 2 + u].emplace_back(N * 3 + v, 0);
    adj[N * 2 + v].emplace_back(N * 3 + u, 0);

    adj[N * 3 + u].emplace_back(N * 3 + v, w);
    adj[N * 3 + v].emplace_back(N * 3 + u, w);
  }

  vector<long long> dist(4 * N, -1);
  priority_queue<pair<long long, int>> pq;
  dist[0] = 0;
  pq.emplace(0, 0);
  while (!pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();
    if (-d != dist[u]) {
      continue;
    }
    for (auto [v, w] : adj[u]) {
      if (dist[v] == -1 || dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w;
        pq.emplace(-dist[v], v);
      }
    }
  }

  for (int i = 1; i < N; i++) {
    cout << dist[N * 3 + i] << ' ';
  }
  cout << '\n';
  return 0;
}