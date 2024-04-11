#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void Solve(int test) {
  int n;
  cin >> n;
  vector<vector<int>> adj(n);
  for (int i = 0; i + 1 < n; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> res(n);

  function<void(int, int, int)> Dfs = [&](int u, int p, int delta) {
    res[u] = delta * adj[u].size();
    for (auto v : adj[u]) {
      if (v == p) continue;
      Dfs(v, u, -delta);
    }
  };

  Dfs(0, -1, 1);
  for (auto &u : res) {
    cout << u << ' ';
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  for (int test = 1; test <= tc; ++test) Solve(test);
  return 0;
}