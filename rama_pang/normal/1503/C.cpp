#include <bits/stdc++.h>
using namespace std;

using lint = long long;

void Main() {
  int N;
  cin >> N;
  vector<lint> A(N), C(N);
  lint add = 0;
  for (int i = 0; i < N; i++) {
    cin >> A[i] >> C[i];
    add += C[i];
  }
  // i -> j: max(0, A[j] - A[i] - C[i])
  // Sort by A increasing:
  // If i > j, cost = 0
  // Minimum to get from 1 to N

  vector<int> ord(N);
  iota(begin(ord), end(ord), 0);
  sort(begin(ord), end(ord), [&](int i, int j) { return A[i] < A[j]; });

  vector<vector<pair<int, lint>>> adj(N);
  for (int o = 0; o < N; o++) {
    int u = ord[o];
    int lo = o, hi = N - 1;
    while (lo < hi) {
      int md = (lo + hi + 1) / 2;
      if (A[ord[md]] - A[u] - C[u] <= 0) {
        lo = md;
      } else {
        hi = md - 1;
      }
    }
    adj[u].emplace_back(ord[lo], 0);
    if (lo + 1 < N) {
      lint cost = A[ord[lo + 1]] - A[u] - C[u];
      assert(cost > 0);
      adj[u].emplace_back(ord[lo + 1], cost);
    }
    if (o) {
      adj[ord[o]].emplace_back(ord[o - 1], 0);
    }
  }
  
  priority_queue<pair<lint, int>> pq;
  pq.emplace(0, ord[0]);
  vector<lint> dist(N, -1);
  dist[ord[0]] = 0;
  while (!pq.empty()) {
    auto [d, u] = pq.top(); pq.pop(); d *= -1;
    if (dist[u] != d) continue;
    for (auto [v, w] : adj[u]) {
      if (dist[v] == -1 || dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w;
        pq.emplace(-dist[v], v);
      }
    }
  } 

  cout << dist[ord[N - 1]] + add << '\n';
  return;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  // cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}