#include <bits/stdc++.h>
using namespace std;

using lint = long long;
#define int lint

class SegTree {
 public:
  int sz;
  vector<int> tree;
  vector<int> lazy;
  SegTree(int sz) : sz(sz), tree(2 * sz), lazy(2 * sz) {}
  void Apply(int n, int x) {
    tree[n] += x;
    lazy[n] += x;
  }
  void Push(int n, int lc, int rc) {
    Apply(lc, lazy[n]);
    Apply(rc, lazy[n]);
    lazy[n] = 0;
  }
  void Pull(int n, int lc, int rc) {
    tree[n] = max(tree[lc], tree[rc]);
  }
  void Update(int n, int tl, int tr, int l, int r, int x) {
    if (tl > tr || l > r || tl > r || l > tr) return;
    if (l <= tl && tr <= r) return Apply(n, x);
    int md = (tl + tr) / 2;
    int z = n + 2 * (md - tl + 1);
    Push(n, n + 1, z);
    Update(n + 1, tl, md, l, r, x);
    Update(z, md + 1, tr, l, r, x);
    Pull(n, n + 1, z);
  }
  int Query(int n, int tl, int tr) {
    if (tl == tr) return tl;
    int md = (tl + tr) / 2;
    int z = n + 2 * (md - tl + 1);
    Push(n, n + 1, z);
    if (tree[n] == tree[n + 1]) {
      return Query(n + 1, tl, md);
    } else if (tree[n] == tree[z]) {
      return Query(z, md + 1, tr);
    } else {
      return -1;
    }
  }
};

void Main() {
  // w(r - b)
  // (n - r - b)(r - b)
  // n(r - b) - r(r - b) - b(r - b)
  // n(r - b) - r^2 + rb - rb + b^2
  // n(r - b) - r^2 + b^2
  // nr - r^2 + b^2 - nb
  // n >= r
  // so nr - r^2 is max when r is big, but not too big
  //

  int n, k;
  cin >> n >> k;
  vector<vector<int>> adj(n);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }

  pair<lint, int> mx = {-1, -1};
  for (int i = 0; i <= n; i++) {
    mx = max(mx, {1ll * i * n - 1ll * i * i, i});
  }

  // must choose k nodes such that we minimize the number of blue nodes we can get
  // wait, but hm
  // we need to count minBlue for 1...n
  // is it convex?
  //
  //

  vector<int> which(n, -1);
  int leaf = 0;
  vector<int> par(n, -1);
  vector<pair<int, int>> leafRange(n);
  const auto Dfs = [&](const auto &self, int u, int p) -> void {
    int isLeaf = 1;
    leafRange[u] = {1e9, -1e9};
    for (auto v : adj[u])
      if (v != p) {
        isLeaf = 0;
        par[v] = u;
        self(self, v, u);
        leafRange[u].first = min(leafRange[u].first, leafRange[v].first);
        leafRange[u].second = max(leafRange[u].second, leafRange[v].second);
      }
    if (isLeaf) {
      leafRange[u] = {leaf, leaf};
      which[leaf++] = u;
    }
  };
  Dfs(Dfs, 0, -1);

  SegTree seg(leaf);
  vector<int> state(n, 1);
  for (int i = 0; i < n; i++) {
    seg.Update(1, 0, leaf - 1, leafRange[i].first, leafRange[i].second, 1);
  }

  int b = n;
  lint ans = -1e18;
  const auto Calc = [&](int x) {
    x = min(x, mx.second);
    return 1ll * n * x - 1ll * x * x;
  };
  for (int r = 0; r <= k; r++) {
    ans = max(ans, 1ll * n * r - 1ll * r * r - Calc(b));
    int u = seg.Query(1, 0, leaf - 1);
    u = which[u];
    // cout << r << ' ' << b << '\n';
    while (u != -1 && state[u] == 1) {
      b--;
      state[u] = 0;
      seg.Update(1, 0, leaf - 1, leafRange[u].first, leafRange[u].second, -1);
      u = par[u];
    }
  }

  cout << ans << '\n';

  // 14 - 4 -6
}

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  // cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}