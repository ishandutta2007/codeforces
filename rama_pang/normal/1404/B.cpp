#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    int n, a, b, da, db;
    cin >> n >> a >> b >> da >> db;
    a--, b--;
    // if dist(a, b) <= da: ALICE
    // if diam <= 2da: ALICE
    // if db > 2da: BOB
    // if db <= 2da: ALICE
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      adj[u].emplace_back(v);
      adj[v].emplace_back(u);
    }
    const auto GetDist = [&](const auto &self, int u, int t, int p) -> int {
      if (u == t) return 0;
      int res = 1e9;
      for (auto v : adj[u]) if (v != p) {
        res = min(res, 1 + self(self, v, t, u));
      }
      return res;
    };
    const auto GetFar = [&](const auto &self, int u, int p) -> pair<int, int> {
      pair<int, int> res = {-1, u};
      for (auto v : adj[u]) if (v != p) {
        res = max(res, self(self, v, u));
      }
      res.first += 1;
      return res;
    };
    int distab = GetDist(GetDist, a, b, -1);
    if (distab <= da) {
      cout << "Alice\n";
      continue;
    }
    int diam = GetFar(GetFar, GetFar(GetFar, 0, -1).second, -1).first;
    if (diam <= 2 * da) {
      cout << "Alice\n";
      continue;
    }
    if (db <= 2 * da) {
      cout << "Alice\n";
      continue;
    }
    cout << "Bob\n";
  }
  return 0;
}