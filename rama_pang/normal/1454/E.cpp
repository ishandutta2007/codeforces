#include <bits/stdc++.h>
using namespace std;

void Main() {
  using lint = long long;

  int n;
  cin >> n;
  vector<int> p(n);
  iota(begin(p), end(p), 0);
  function<int(int)> Find = [&](int x) {
    return p[x] == x ? x : p[x] = Find(p[x]);
  };
  vector<vector<int>> adj(n);
  int x = -1, y = -1;
  for (int i = 0; i < n; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    if (Find(u) != Find(v)) {
      adj[u].emplace_back(v);
      adj[v].emplace_back(u);
      p[Find(u)] = Find(v);
    } else {
      x = u;
      y = v;
    }
  }

  lint ans = 1ll * n * (n - 1);
  vector<int> incyc(n, 0);
  function<bool(int, int)> Dfs = [&](int u, int par) {
    if (u == y) {
      incyc[u] = 1;
      return true;
    }
    for (auto v : adj[u]) if (v != par) {
      if (Dfs(v, u)) {
        incyc[u] = 1;
        return true;
      }
    }
    return false;
  };

  Dfs(x, -1);

  function<int(int, int)> GetSize = [&](int u, int par) {
    int res = 1;
    for (auto v : adj[u]) if (v != par) {
      res += GetSize(v, u);
    }
    return res;
  };
  
  for (int i = 0; i < n; i++) {
    if (incyc[i]) {
      int cnt = 1;
      for (auto j : adj[i]) {
        if (!incyc[j]) {
          cnt += GetSize(j, i);
        }
      }
      ans -= 1ll * cnt * (cnt - 1) / 2;
    }
  }
  
  cout << ans << '\n';
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