#include <bits/stdc++.h>

using namespace std;

void solve(int test) {
  int n, m;
  cin >> n >> m;
  vector<int> deg(n, 0);
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    if (u > v) swap(u, v);
    deg[u]++;
  }
  int res = 0;
  for (const auto &u : deg) res += (u == 0);
  int q;
  cin >> q;
  while (q--) {
    int op;
    cin >> op;
    if (op == 3) {
      cout << res << '\n';
    } else {
      int u, v;
      cin >> u >> v;
      u--, v--;
      if (u > v) swap(u, v);
      if (op == 1) {
        res -= (deg[u] == 0);
        deg[u]++;
      } else {
        deg[u]--;
        res += (deg[u] == 0);
      }
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  // cin >> tc;
  tc = 1;
  for (int test = 1; test <= tc; ++test) solve(test);
  return 0;
}