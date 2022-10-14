#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<array<int, 3>>> adj(n);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    adj[u].push_back({v, w, i});
    adj[v].push_back({u, w, i});
  }

  using lint = long long;
  priority_queue<pair<lint, int>, vector<pair<lint, int>>, greater<pair<lint, int>>> pq;
  vector<lint> dist(n, -1);
  vector<pair<int, int>> prv(n, {-1, -1});

  dist[0] = 0;
  pq.emplace(0, 0);

  while (!pq.empty()) {
    int u = pq.top().second;
    lint d = pq.top().first;
    pq.pop();
    if (dist[u] != d) {
      continue;
    }
    for (auto v : adj[u]) {
      if (dist[v[0]] == -1 || dist[v[0]] > dist[u] + v[1]) {
        dist[v[0]] = dist[u] + v[1];
        prv[v[0]] = {u, v[2]};
        pq.emplace(dist[v[0]], v[0]);
      }
    } 
  }

  adj.clear();
  adj.resize(n);

  for (int i = 0; i < n; i++) {
    if (prv[i].first != -1) {
      adj[prv[i].first].push_back({i, prv[i].second, 1});
    }
  }

  queue<int> q;
  vector<int> ans;
  q.emplace(0);
  dist.assign(n, 0);
  while (ans.size() < k && !q.empty()) {
    int u = q.front();
    q.pop();
    for (auto v : adj[u]) {
      if (dist[v[0]] == 0) {
        dist[v[0]] = 1;
        q.emplace(v[0]);
        ans.emplace_back(v[1]);
      }
    }
  }

  ans.resize(min((int) ans.size(), k));

  cout << ans.size() << "\n";
  for (auto i : ans) {
    cout << i + 1 << " ";
  }
  cout << "\n";
  return 0;
}