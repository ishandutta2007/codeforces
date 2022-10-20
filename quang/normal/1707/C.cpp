#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

class DSU {
 public:
  explicit DSU(int n) : num_comp_(n), root_(n, -1), sz_(n, 1) {}

  int num_comp() const { return num_comp_; }
  int sz(int u) { return sz_[GetRoot(u)]; }

  int GetRoot(int u) { return ~root_[u] ? root_[u] = GetRoot(root_[u]) : u; }

  bool Unite(int u, int v) {
    u = GetRoot(u);
    v = GetRoot(v);
    if (u == v) return false;
    sz_[v] += sz_[u];
    root_[u] = v;
    num_comp_--;
    return true;
  }

 private:
  int num_comp_;  // number of connected components
  vector<int> sz_;
  vector<int> root_;
};

template <typename T>
class BIT {
 public:
  explicit BIT(int n) : n_(n), t_(n, T(0)) {}

  void Add(int x, T v) {
    assert(x >= 0);
    for (; x < n_; x += (x + 1) & -(x + 1)) t_[x] += v;
  }

  // [l, r] INCLUSIVELY
  void Add(int l, int r, T v) {
    debug("add", l, r, v);
    assert(l <= r && l >= 0 && r < n_);
    Add(l, v);
    Add(r + 1, -v);
  }

  T Get(int x) const {
    assert(x >= 0 && x < n_);
    T res(0);
    for (; x >= 0; x -= (x + 1) & -(x + 1)) res += t_[x];
    return res;
  }

  // [l, r] INCLUSIVELY
  T Get(int l, int r) const {
    assert(l <= r && r < n_ && l >= 0);
    return Get(r) - (l ? Get(l - 1) : T(0));
  }

 private:
  int n_;
  vector<T> t_;
};

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> edges;
  vector<vector<int>> adj(n);
  DSU dsu(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    if (dsu.Unite(u, v)) {
      adj[u].push_back(v);
      adj[v].push_back(u);
    } else {
      edges.push_back({u, v});
    }
  }

  vector<bool> used(n);
  vector<int> lv(n, 0);
  const int LOG = 20;
  vector<vector<int>> par(LOG, vector<int>(n, -1));
  vector<int> in(n), out(n);
  int cnt = 0;
  function<void(int, int)> Dfs = [&](int u, int p) {
    in[u] = cnt;
    used[u] = 1;
    par[0][u] = p;
    for (int i = 1; i < LOG; i++) {
      if (par[i - 1][u] == -1) {
        continue;
      }
      par[i][u] = par[i - 1][par[i - 1][u]];
    }
    for (auto v : adj[u]) {
      if (used[v]) continue;
      lv[v] = lv[u] + 1;
      Dfs(v, u);
    }
    out[u] = cnt++;
  };

  Dfs(0, -1);

  auto GetPar = [&](int u, int h) {
    for (int i = LOG - 1; i >= 0; i--) {
      if (h >> i & 1) {
        u = par[i][u];
      }
    }
    return u;
  };

  BIT<int> t(cnt);
  debug(in);
  debug(out);
  for (auto &[u, v] : edges) {
    if (lv[u] > lv[v]) swap(u, v);
    debug(u, v);
    if (in[u] <= in[v] && out[v] <= out[u]) {
      t.Add(in[v], out[v], -1);
      auto w = GetPar(v, lv[v] - lv[u] - 1);
      t.Add(in[w], out[w], +1);
    } else {
      t.Add(in[0], out[0], +1);
      t.Add(in[u], out[u], -1);
      t.Add(in[v], out[v], -1);
    }
  }
  for (int i = 0; i < n; i++) {
    cout << (int)(t.Get(out[i]) == 0);
  }
  cout << '\n';
  return 0;
}