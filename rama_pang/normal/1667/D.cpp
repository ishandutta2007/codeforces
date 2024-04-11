#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n;
  cin >> n;
  vector<int> state(n);
  vector<vector<int>> adj(n);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
    state[u] ^= 1;
    state[v] ^= 1;
  }
  int r = -1;
  for (int i = 0; i < n; i++) {
    if (adj[i].size() == 1) {
      r = i;
    }
  }
  vector<pair<int, int>> ans;
  vector<vector<vector<int>>> pending(n, vector<vector<int>>(2));
  const auto Dfs = [&](const auto &self, int u, int p, int t) -> void {
    if (t == 1) {
      ans.emplace_back(u, p);
      state[u] ^= 1;
    } else {
      for (auto v : adj[u]) {
        if (v == p) {
          continue;
        }
        self(self, v, u, 0);
        pending[u][state[v]].emplace_back(v);        
      }
    }
    while (!pending[u][state[u]].empty()) {
      int v = pending[u][state[u]].back();
      pending[u][state[u]].pop_back();
      state[u] ^= 1;
      self(self, v, u, 1);
    }
  };
  Dfs(Dfs, r, -1, 0);
  if (ans.size() != n - 1) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  for (auto [x, y] : ans) {
    cout << x + 1 << ' ' << y + 1 << '\n';
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    Main();
  }
  return 0;
}