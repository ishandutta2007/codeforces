#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> edge(m);
  vector<vector<int>> adj(n), dag(n);
  for (int i = 0; i < m; i++) {
    cin >> edge[i].first >> edge[i].second;
    edge[i].first--, edge[i].second--;
    adj[edge[i].first].emplace_back(edge[i].second);
  }
  vector<int> dist(n, -1);
  vector<int> dp(n, n + 1);
  queue<int> q;
  q.emplace(0);
  dist[0] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto v : adj[u]) {
      if (dist[v] == -1) {
        dist[v] = dist[u] + 1;
        q.emplace(v);
      }
    }
  }
  dp = dist;
  for (auto [u, v] : edge) {
    if (dist[u] < dist[v]) {
      dag[u].emplace_back(v);
    } else {
      dp[u] = min(dp[u], dist[v]);
    }
  }
  vector<int> vis(n);
  const auto Dfs = [&](const auto &self, int u) -> void {
    if (vis[u]) return;
    vis[u] = true;
    for (auto v : dag[u]) {
      self(self, v);
      dp[u] = min(dp[u], dp[v]);
    }
  };
  for (int i = 0; i < n; i++) {
    Dfs(Dfs, i);
    cout << dp[i] << ' ';
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}