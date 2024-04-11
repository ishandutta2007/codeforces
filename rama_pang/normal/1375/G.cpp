#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n;
  cin >> n;
  vector<vector<int>> adj(n);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }

  queue<int> q;
  vector<int> dist(n, -1);
  q.emplace(0);
  dist[0] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto v : adj[u]) if (dist[v] == -1) {
      dist[v] = dist[u] + 1;
      q.emplace(v);
    }
  }

  int black = 0, white = 0;
  for (int i = 0; i < n; i++) {
    if (dist[i] & 1) {
      black++;
    } else {
      white++;
    }
  }

  cout << min(black, white) - 1 << "\n";
  return 0;
}