#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint INF = 1e18;

class SegTree {
 public:
  lint sz;
  vector<lint> lazy;
  vector<array<lint, 3>> tree;
  vector<vector<array<lint, 3>>> elements;

  SegTree() {}
  SegTree(lint n, vector<lint> c) {
    sz = 1;
    while (sz < n) sz *= 2;
    tree.assign(2 * sz, {INF, INF, INF});
    lazy.assign(2 * sz, 0);

    elements.resize(sz);
    for (int i = 0; i < int(c.size()); i++) {
      elements[c[i]].push_back({i + 1, c[i], i});
    }
    for (int i = 0; i < sz; i++) {
      sort(begin(elements[i]), end(elements[i]));
      reverse(begin(elements[i]), end(elements[i]));
    }
    for (int i = 0; i < sz; i++) {
      tree[i + sz] = elements[i].empty() ? array<lint, 3>{INF, INF, INF} : elements[i].back();
    }
    for (int i = sz - 1; i > 0; i--) {
      tree[i] = min(tree[i * 2], tree[i * 2 + 1]);
    }
  }

  void Apply(lint n, lint add) {
    lazy[n] += add;
    tree[n][0] = min(INF, tree[n][0] + add);
  }

  void Update(lint n, lint tl, lint tr, lint l, lint r, lint add) {
    if (tl > r || l > tr || tl > tr || l > r) return;
    if (l <= tl && tr <= r) return Apply(n, add);
    int md = (tl + tr) / 2;

    Apply(n * 2, lazy[n]);
    Apply(n * 2 + 1, lazy[n]);
    lazy[n] = 0;

    Update(n * 2, tl, md, l, r, add);
    Update(n * 2 + 1, md + 1, tr, l, r, add);

    tree[n] = min(tree[n * 2], tree[n * 2 + 1]);
  }

  void Update(lint l, lint r, lint add) {
    return Update(1, 0, sz - 1, l, r, add);
  }

  void Pop(lint n, lint tl, lint tr, lint p) {
    if (tl == tr) {
      assert(n == p + sz);
      if (!elements[p].empty()) elements[p].pop_back();
      tree[n] = elements[p].empty() ? array<lint, 3>{INF, INF, INF} : elements[p].back();
      tree[n][0] = min(INF, tree[n][0] + lazy[n]);
      return;
    }
    int md = (tl + tr) / 2;

    Apply(n * 2, lazy[n]);
    Apply(n * 2 + 1, lazy[n]);
    lazy[n] = 0;

    if (p <= md) {
      Pop(n * 2, tl, md, p);
    } else {
      Pop(n * 2 + 1, md + 1, tr, p);
    }
    tree[n] = min(tree[n * 2], tree[n * 2 + 1]);
  }

  void Pop(lint p) {
    return Pop(1, 0, sz - 1, p);
  }

  array<lint, 3> Query(lint n, lint tl, lint tr, lint l, lint r) {
    if (tl > r || l > tr || l > r || tl > tr) return {INF, INF, INF};
    if (l <= tl && tr <= r) return tree[n];
    int md = (tl + tr) / 2;

    Apply(n * 2, lazy[n]);
    Apply(n * 2 + 1, lazy[n]);
    lazy[n] = 0;

    return min(Query(n * 2, tl, md, l, r), Query(n * 2 + 1, md + 1, tr, l, r));
  }

  array<lint, 3> Query(lint l, lint r) {
    return Query(1, 0, sz - 1, l, r);
  }
};

void Main() {
  lint N, M, Q;
  cin >> N >> M >> Q;

  vector<vector<lint>> adj(N);
  for (lint i = 1; i < N; i++) {
    lint x, y;
    cin >> x >> y;
    x--, y--;
    adj[x].emplace_back(y);
    adj[y].emplace_back(x);
  }

  vector<lint> c(M);
  for (int i = 0; i < M; i++) {
    cin >> c[i];
    c[i]--;
  }

  vector<lint> sz(N);
  vector<lint> par(N);
  vector<lint> root(N);
  vector<lint> st(N);
  vector<lint> et(N);
  vector<lint> depth(N);
  const auto DfsSz = [&](const auto &self, lint u, lint p) -> void {
    if (p != -1) {
      adj[u].erase(find(begin(adj[u]), end(adj[u]), p));
    }
    sz[u] = 1;
    par[u] = p;
    for (auto &v : adj[u]) {
      depth[v] = depth[u] + 1;
      self(self, v, u);
      sz[u] += sz[v];
      if (sz[v] > sz[adj[u][0]]) {
        swap(v, adj[u][0]);
      }
    }
  };
  DfsSz(DfsSz, 0, -1);
  lint timer = 0;
  const auto DfsHld = [&](const auto &self, lint u, lint p) -> void {
    st[u] = timer++;
    for (auto v : adj[u]) {
      if (v == adj[u][0]) {
        root[v] = root[u];
      } else {
        root[v] = v;
      }
      self(self, v, u);
    }
    et[u] = timer;
  };
  DfsHld(DfsHld, 0, -1);

  for (int i = 0; i < M; i++) {
    c[i] = st[c[i]];
  }

  SegTree seg(N, c);

  const auto Query = [&](int x, int y) {
    array<lint, 3> res = {INF, INF, INF};
    for (; root[x] != root[y]; y = par[root[y]]) {
      if (depth[root[x]] > depth[root[y]]) swap(x, y);
      res = min(res, seg.Query(st[root[y]], st[y]));
    }
    assert(root[x] == root[y]);
    if (depth[x] > depth[y]) swap(x, y);
    res = min(res, seg.Query(st[x], st[y]));
    return res;
  };

  while (Q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int u, v, k;
      cin >> u >> v >> k;
      u--, v--;
      static vector<int> ans; ans.clear();
      while (k--) {
        auto res = Query(u, v);
        if (res[0] == INF) {
          break;
        }
        ans.emplace_back(res[2]);
        seg.Pop(res[1]);
      }
      cout << ans.size();
      for (auto i : ans) cout << ' ' << i + 1;
      cout << '\n';
    } else if (t == 2) {
      int v, k;
      cin >> v >> k;
      v--;
      seg.Update(st[v], et[v] - 1, k);
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  Main();
  return 0;
}