#include <bits/stdc++.h>
using namespace std;

void Main() {
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
  vector<int> ans(n);
  const auto Dfs = [&](const auto &self, int u, int p, int c) -> void {
    ans[u] = c * int(adj[u].size());
    for (auto v : adj[u]) {
      if (v != p) {
        self(self, v, u, -c);
      }
    }
  };
  Dfs(Dfs, 0, -1, 1);
  for (int i = 0; i < n; i++) {
    cout << ans[i] << ' ';
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