#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint INF = 1e18;

void Main() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> adj(k);
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < k; j++) {
      adj[i].emplace_back(j);
    }
  }

  vector<int> res;
  const auto Dfs = [&](const auto &self, int u) -> void {
    while (!adj[u].empty()) {
      int v = adj[u].back(); adj[u].pop_back();
      self(self, v);
    }
    res.emplace_back(u);
  };
  Dfs(Dfs, 0);
  for (int i = 0; i < k; i++) {
    assert(adj[i].empty());
  }
  string S;
  for (auto i : res) {
    S.push_back(i + 'a');
  }
  S.pop_back();

  while (n > 0) {
    if (n >= S.size()) {
      n -= S.size();
      cout << S;
    } else {
      while (S.size() > n) {
        S.pop_back();
      }
      cout << S;
      break;
    }
  }
  cout << '\n';
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