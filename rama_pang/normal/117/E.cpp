#include <bits/stdc++.h>
using namespace std;

using lint = long long;

// #Components = Vertex - Edges + Cycle

class SegTree {
 public:
  lint sz;
  vector<lint> tree;
  vector<lint> lazy;

  SegTree(lint sz) : sz(sz), tree(2 * sz, 0), lazy(2 * sz, 0) {}

  void Modify(lint n, lint tl, lint tr, lint l, lint r) {
    if (tl > r || l > tr || l > r || tl > tr) return;
    if (l <= tl && tr <= r) {
      tree[n] = (tr - tl + 1) - tree[n];
      lazy[n] ^= 1;
      return;
    }
    int md = (tl + tr) / 2;
    int z = n + 2 * (md - tl + 1);
    if (lazy[n]) {
      tree[n + 1] = (md - tl + 1) - tree[n + 1];
      lazy[n + 1] ^= 1;

      tree[z] = (tr - md) - tree[z];
      lazy[z] ^= 1;

      lazy[n] = 0;
    }
    Modify(n + 1, tl, md, l, r);
    Modify(z, md + 1, tr, l, r);
    tree[n] = tree[n + 1] + tree[z];
  }

  void Modify(lint l, lint r) {
    return Modify(1, 0, sz - 1, l, r);
  }

  lint Query(lint n, lint tl, lint tr, lint l, lint r) {
    if (tl > r || l > tr || l > r || tl > tr) return 0;
    if (l <= tl && tr <= r) return tree[n];
    int md = (tl + tr) / 2;
    int z = n + 2 * (md - tl + 1);
    if (lazy[n]) {
      tree[n + 1] = (md - tl + 1) - tree[n + 1];
      lazy[n + 1] ^= 1;

      tree[z] = (tr - md) - tree[z];
      lazy[z] ^= 1;

      lazy[n] = 0;
    }
    return Query(n + 1, tl, md, l, r) + Query(z, md + 1, tr, l, r);
  }

  lint Query(lint l, lint r) {
    return Query(1, 0, sz - 1, l, r);
  }
};

class Disjoint {
 public:
  int sz;
  vector<int> p;

  Disjoint(int sz) : sz(sz), p(sz) {
    iota(begin(p), end(p), 0);
  }

  int Find(int x) {
    return p[x] == x ? x : p[x] = Find(p[x]);
  }

  int Unite(int x, int y) {
    x = Find(x), y = Find(y);
    if (x == y) return 0;
    p[x] = y;
    return 1;
  }
};

void Main() {
  lint N, Q;
  cin >> N >> Q;

  Disjoint D(N);
  vector<vector<lint>> adj(N);
  pair<lint, lint> cycle_endpoint = {-1, -1};
  for (lint i = 0; i < N; i++) {
    lint x, y;
    cin >> x >> y;
    x--, y--;
    if (D.Unite(x, y)) {
      adj[x].emplace_back(y);
      adj[y].emplace_back(x);
    } else {
      assert(cycle_endpoint.first == -1);
      cycle_endpoint = pair(x, y);
    }
  }

  vector<int> cycle_list;
  vector<int> in_cycle(N);
  const auto DfsGetCycle = [&](const auto &self, int u, int t, int p) {
    if (u == t) {
      cycle_list.emplace_back(u);
      in_cycle[u] = 1;
      return 1;
    }
    for (auto v : adj[u]) if (v != p) {
      if (self(self, v, t, u)) {
        cycle_list.emplace_back(u);
        in_cycle[u] = 1;
        return 1;
      }
    }
    return 0;
  };

  assert(cycle_endpoint.first != -1);
  assert(DfsGetCycle(DfsGetCycle, cycle_endpoint.first, cycle_endpoint.second, -1));

  int cycle_len = 0;
  for (int i = 0; i < N; i++) {
    cycle_len += in_cycle[i];
  }

  vector<int> color(N);
  const auto DfsColor = [&](const auto &self, lint u, lint p, lint c) -> void {
    color[u] = c;
    for (auto v : adj[u]) if (v != p) {
      self(self, v, u, c);
    }
  };
  for (int i = 0; i < N; i++) if (in_cycle[i]) {
    color[i] = i;
    for (auto j : adj[i]) {
      if (!in_cycle[j]) {
        DfsColor(DfsColor, j, i, i);
      }
    }
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

  SegTree segT(N);
  SegTree segC(cycle_list.size());

  assert(cycle_list.size() == cycle_len);

  vector<int> pos_in_cycle(N);
  for (int i = 0; i < int(cycle_list.size()); i++) {
    pos_in_cycle[cycle_list[i]] = i;
  }

  const auto Modify = [&](int x, int y) {
    for (; root[x] != root[y]; y = par[root[y]]) {
      if (depth[root[x]] > depth[root[y]]) swap(x, y);
      segT.Modify(st[root[y]], st[y]);
    }
    assert(root[x] == root[y]);
    if (depth[x] > depth[y]) swap(x, y);
    segT.Modify(st[x] + 1, st[y]);
  };

  while (Q--) {
    int x, y;
    cin >> x >> y;
    x--, y--;

    if (color[x] != color[y]) {
      Modify(x, color[x]);
      Modify(y, color[y]);
      x = color[x];
      y = color[y];

      assert(in_cycle[x] == 1);
      assert(in_cycle[y] == 1);

      int posx = pos_in_cycle[x];
      int posy = pos_in_cycle[y];

      int len = (cycle_len + posy - posx) % cycle_len; // x -> y

      if (len * 2 == cycle_len) {
        int prvx = posx == 0 ? cycle_list.back() : cycle_list[posx - 1];
        int nxtx = posx + 1 == cycle_len ? cycle_list.front() : cycle_list[posx + 1];
        if (prvx < nxtx) {
          swap(posx, posy);
        }
      } else {
        if (len > cycle_len - len) {
          swap(posx, posy);
        }
      }
      if (posx > posy) {
        segC.Modify(posx, cycle_len - 1);
        segC.Modify(0, posy - 1);
      } else {
        segC.Modify(posx, posy - 1);
      }
    } else {
      Modify(x, y);
    }

    int edgeT = segT.Query(0, N - 1);
    int edgeC = segC.Query(0, cycle_len - 1);

    cout << (N - (edgeT + edgeC) + (edgeC == cycle_len)) << '\n';
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  Main();
  return 0;
}