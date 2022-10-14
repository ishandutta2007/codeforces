#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint INF = 1e18;

class SegTree {
 public:
  int sz;
  vector<pair<int, int>> tree;

  SegTree(int n) {
    sz = 1;
    while (sz < n) sz *= 2;
    tree.assign(2 * sz, {1e9, 1e9});
  }

  void Modify(int p, int x) {
    p += sz;
    tree[p] = {x, p - sz};
    for (p /= 2; p > 0; p /= 2) {
      tree[p] = min(tree[p * 2], tree[p * 2 + 1]);
    }
  }

  pair<int, int> Query(int l, int r) {
    pair<int, int> res = {1e9, 1e9};
    for (l += sz, r += sz + 1; l < r; l /= 2, r /= 2) {
      if (l & 1) res = min(res, tree[l++]);
      if (r & 1) res = min(res, tree[--r]);
    }
    return res;
  }
};

const int MAXN = 2e5 + 5;

// Disjoint Set with rollbacks
int par[MAXN];
int sz[MAXN];
 
int Find(int x) {
  return par[x] == x ? x : Find(par[x]);
}
 
int Unite(int x, int y) {
  x = Find(x), y = Find(y);
  if (x == y) return 0;
  if (sz[x] > sz[y]) swap(x, y);
  par[x] = y;
  sz[y] += sz[x];
  return 1;
}

void Main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  iota(par, par + MAXN, 0);
  fill(sz, sz + MAXN, 1);

  // Assume inverse G is connected (otherwise, solve each component separately, then use existing edge to connect them)
  // if inverse G has a BCC, answer =   0
  // else, inverse G is a spanning forest
  // in this case, N is small
  // we add all XOR to 1 nonexisting edge:
  //   find the MST, since N small, easy
  // we add all XOR to 2 nonexisting edge:
  //   if the MST does not include both edge, we can put put them together and MST isn't changed
  //   if the MST contains 1 of them, put them in the unused, MST becomes less
  //   if the MST containts 2 of them, put them together, doesn't change MST
  
  int N, M;
  cin >> N >> M;
  int XorAll = 0;
  vector<array<int, 3>> edge;
  vector<vector<int>> adj(N);
  for (int i = 0; i < M; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    edge.push_back({w, u, v});
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
    XorAll ^= w;
  }

  SegTree unvisited(N);
  for (int i = 0; i < N; i++) {
    unvisited.Modify(i, 0);
  }
  vector<vector<pair<int, int>>> edgeI(N);
  vector<int> color(N, -1);
  const auto DfsI = [&](const auto &self, int u, int c) -> void {
    assert(color[u] == -1);
    color[u] = c;
    unvisited.Modify(u, 1);
    vector<int> ls = {-1, N};
    for (auto v : adj[u]) ls.emplace_back(v);
    sort(begin(ls), end(ls));
    for (int i = 0; i + 1 < int(ls.size()); i++) {
      int lo = ls[i] + 1;
      int hi = ls[i + 1] - 1;
      if (lo > hi) continue;
      while (true) {
        auto q = unvisited.Query(lo, hi);
        if (q.first != 0) {
          break;
        }
        edgeI[c].emplace_back(u, q.second);
        self(self, q.second, c);
      }
    }
  };
  for (int i = 0; i < N; i++) {
    if (unvisited.Query(i, i).first == 0) {
      DfsI(DfsI, i, i);
    }
  }

  for (int i = 0; i < N; i++) {
    adj[i].clear();
  }

  lint base_ans = 0;
  sort(begin(edge), end(edge));
  
  vector<lint> cnt_node(N);
  vector<lint> cnt_edge(N);
  
  for (int i = 0; i < N; i++) {
    cnt_node[color[i]] += 1;
  }

  for (auto [w, u, v] : edge) {
    if (color[u] != color[v]) {
      if (Unite(color[u], color[v])) {
        base_ans += w;
      }
    } else {
      cnt_edge[color[u]] += 1;
      adj[u].emplace_back(v);
      adj[v].emplace_back(u);
    }
  }

  bool bcc = false;
  vector<pair<int, int>> edge2;
  for (int i = 0; i < N; i++) if (color[i] == i) {
    lint nodes = cnt_node[color[i]];
    lint edges = nodes * (nodes - 1) / 2 - cnt_edge[color[i]];
    assert(edges >= nodes - 1);
    if (edges == nodes - 1) {
      assert(edgeI[color[i]].size() == edges);
      for (auto j : edgeI[color[i]]) edge2.emplace_back(j);
    } else {
      bcc = true;
    }
  }

  if (bcc) {
    cout << base_ans << '\n';
    return;
  }

  // N is small <= sqrt(M)
  lint ans = 1e18;
  sort(begin(edge), end(edge));
  assert(edge2.size() <= N);
  for (auto inite : edge2) { // O(M sqrt M)
    iota(par, par + MAXN, 0);
    fill(sz, sz + MAXN, 1);
    lint mst = 0;
    for (auto e : edge2) if (e != inite) {
      Unite(e.first, e.second);
    }
    int in = 0;
    for (auto [w, u, v] : edge) {
      if (in == 0 && XorAll <= w) {
        if (Unite(inite.first, inite.second)) {
          in = 1;
          mst += XorAll;
        }
      }
      if (Unite(u, v)) {
        mst += w;
      }
    }
    if (in == 0) {
      if (Unite(inite.first, inite.second)) {
        in = 1;
        mst += XorAll;
      }
    }
    ans = min(ans, mst);
  }

  cout << ans << '\n';

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