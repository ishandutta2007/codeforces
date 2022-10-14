#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint INF = 1e15;

class Item {
 public:
  int ok = 1;
  array<array<lint, 2>, 2> M;

  Item(int ok = 1) : ok(ok) {
    M[0][0] = 0;    M[0][1] = 0;
    M[1][0] = -INF; M[1][1] = 0;
  }

  friend Item operator+(Item a, Item b) {
    swap(a, b);
    if (a.ok == 0) return b;
    if (b.ok == 0) return a;
    Item c;
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        c.M[i][j] = max({-INF, a.M[i][0] + b.M[0][j], a.M[i][1] + b.M[1][j]});
      }
    }
    return c;
  }
};

class SegTree {
 public:
  int sz;
  vector<Item> tree;
  vector<int> lazy;
  vector<Item> base_case;

  SegTree(int sz) : sz(sz), tree(2 * sz), lazy(2 * sz) {}

  void GetBaseCase() {
    for (int i = 0; i < sz; i++) Modify(i, 0);
    base_case = tree;
  }

  void Reset(int n) {
    tree[n] = base_case[n];
    lazy[n] = 1;
  }

  void Push(int n, int lc, int rc) {
    if (lazy[n]) {
      Reset(lc);
      Reset(rc);
      lazy[n] = 0;
    }
  }

  void Pull(int n, int lc, int rc) {
    tree[n] = tree[lc] + tree[rc];
  }

  void Reset(int n, int tl, int tr, int l, int r) {
    if (tl > r || l > tr || l > r || tl > tr) return;
    if (l <= tl && tr <= r) return Reset(n);
    int md = (tl + tr) / 2;
    int z = n + 2 * (md - tl + 1);
    Push(n, n + 1, z);
    Reset(n + 1, tl, md, l, r);
    Reset(z, md + 1, tr, l, r);
    Pull(n, n + 1, z);
  }

  void Reset(int l, int r) {
    return Reset(1, 0, sz - 1, l, r);
  }

  void Modify(int n, int tl, int tr, int p, int x) {
    if (tl == tr) {
      tree[n].M[0][0] += x;
      return;
    }
    int md = (tl + tr) / 2;
    int z = n + 2 * (md - tl + 1);
    Push(n, n + 1, z);
    if (p <= md) {
      Modify(n + 1, tl, md, p, x);
    } else {
      Modify(z, md + 1, tr, p, x);
    }
    Pull(n, n + 1, z);
  }

  void Modify(int p, int x) {
    return Modify(1, 0, sz - 1, p, x);
  }

  Item Query(int n, int tl, int tr, int l, int r) {
    if (tl > r || l > tr || l > r || tl > tr) return Item(0);
    if (l <= tl && tr <= r) return tree[n];
    int md = (tl + tr) / 2;
    int z = n + 2 * (md - tl + 1);
    Push(n, n + 1, z);
    return Query(n + 1, tl, md, l, r) + Query(z, md + 1, tr, l, r);
  }

  Item Query(int l, int r) {
    return Query(1, 0, sz - 1, l, r);
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, Q;
  cin >> N >> Q;

  vector<vector<int>> adj(N + N - 1);
  for (int i = 1; i < N; i++) {
    int u;
    cin >> u;
    u--;
    int v = i;
    int e = N + i - 1;
    adj[u].emplace_back(e);
    adj[e].emplace_back(u);
    adj[v].emplace_back(e);
    adj[e].emplace_back(v);
  }

  // Heavy Light Decomposition
  vector<int> st(N + N - 1);
  vector<int> et(N + N - 1);
  vector<int> siz(N + N - 1);
  vector<int> par(N + N - 1);
  vector<int> root(N + N - 1);
  vector<int> depth(N + N - 1);

  const auto DfsInit = [&](const auto &self, int u, int p) -> void {
    if (p != -1) {
      adj[u].erase(find(begin(adj[u]), end(adj[u]), p));
    }
    siz[u] = 1;
    par[u] = p;
    for (auto &v : adj[u]) {
      depth[v] = depth[u] + 1;
      self(self, v, u);
      siz[u] += siz[v];
      if (siz[v] > siz[adj[u][0]]) {
        swap(v, adj[u][0]);
      }
    }
  };

  int timer = 0;
  const auto DfsHld = [&](const auto &self, int u) -> void {
    st[u] = timer++;
    for (auto v : adj[u]) {
      if (v == adj[u][0]) {
        root[v] = root[u];
      } else {
        root[v] = v;
      }
      self(self, v);
    }
    et[u] = timer;
  };

  DfsInit(DfsInit, 0, -1);
  DfsHld(DfsHld, 0);

  SegTree seg(N + N - 1);
  for (int i = N; i < N + N - 1; i++) {
    seg.Modify(st[i], -1);
  }

  seg.GetBaseCase();

  const auto Query = [&](int x) {
    Item res(0);
    while (x != -1) {
      res = seg.Query(st[root[x]], st[x]) + res;
      x = par[root[x]];
    }
    return max(res.M[0][0], res.M[0][1]);
  };

  while (Q--) {
    int t, v;
    cin >> t >> v;
    v--;
    if (t == 1) {
      seg.Modify(st[v], 1);
    } else if (t == 2) {
      seg.Reset(st[v], et[v] - 1);
      int q = Query(v);
      if (q > 0) {
        seg.Modify(st[v], -q);
      }
    } else if (t == 3) {
      int q = Query(v);
      if (q > 0) {
        cout << "black\n";
      } else {
        cout << "white\n";
      }
    }
  }
  return 0;
}