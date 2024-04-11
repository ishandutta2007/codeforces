#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;

int F[MAX];

class Item {
  public:
  int all_one;
  int left;
  int right;
  int score;
  Item(int x = 0) {
    if (x == -1) {
      all_one = -1;
      left = -1;
      right = -1;
      score = -1;
    } else if (x == 0) {
      all_one = false;
      left = 0;
      right = 0;
      score = 0;
    } else if (x == 1) {
      all_one = true;
      left = 1;
      right = 1;
      score = F[1];
    } else {
      assert(false);
    }
  }

  friend Item operator+(const Item &a, const Item &b) {
    if (a.all_one == -1) return b;
    if (b.all_one == -1) return a;
    Item c(0);
    c.all_one = a.all_one && b.all_one;
    c.left = a.left + (a.all_one ? b.left : 0);
    c.right = (b.all_one ? a.right : 0) + b.right;
    c.score = a.score + b.score;
    c.score -= F[a.right];
    c.score -= F[b.left];
    c.score += F[a.right + b.left];
    return c;
  }
};

class SegTree {
 public:
  int sz;
  vector<Item> tree;

  SegTree(int sz) : sz(sz), tree(2 * sz) {}

  void Modify(int p, int x) {
    tree[p += sz] = Item(x);
    for (p /= 2; p > 0; p /= 2) {
      tree[p] = tree[p * 2] + tree[p * 2 + 1];
    }
  }

  Item Query(int l, int r) {
    Item left(-1), right(-1);
    for (l += sz, r += sz + 1; l < r; l /= 2, r /= 2) {
      if (l & 1) left = left + tree[l++];
      if (r & 1) right = tree[--r] + right;
    }
    return (left + right);
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, Q;
  cin >> N >> Q;

  for (int i = 1; i <= N - 1; i++) {
    cin >> F[i];
  }

  vector<array<int, 3>> edges;
  vector<vector<int>> adj(N);
  for (int i = 1; i < N; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
    edges.push_back({w, u, v});
  }

  vector<array<int, 4>> query;
  for (int i = 0; i < Q; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    query.push_back({w, u, v, i});
  }

  // Heavy Light Decomposition
  vector<int> st(N);
  vector<int> et(N);
  vector<int> siz(N);
  vector<int> par(N);
  vector<int> root(N);
  vector<int> depth(N);

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

  SegTree seg(N);
  const auto Query = [&](int x, int y) -> int {
    Item left(-1), right(-1);
    while (root[x] != root[y]) {
      if (depth[root[x]] < depth[root[y]]) {
        right = seg.Query(st[root[y]], st[y]) + right;
        y = par[root[y]];
      } else {
        left = seg.Query(st[root[x]], st[x]) + left;
        x = par[root[x]];
      }
    }
    if (depth[x] < depth[y]) {
      right = seg.Query(st[x] + 1, st[y]) + right;
    } else if (depth[x] > depth[y]) {
      left = seg.Query(st[y] + 1, st[x]) + left;
    }
    swap(left.left, left.right);
    return (left + right).score;
  };

  sort(begin(edges), end(edges));
  sort(begin(query), end(query));
  reverse(begin(query), end(query));

  vector<int> ans(Q);
  for (auto [w, u, v, i] : query) {
    while (!edges.empty() && w <= edges.back()[0]) {
      int x = edges.back()[1];
      int y = edges.back()[2];
      // Turn edge (x, y) from 0 to 1
      if (depth[x] > depth[y]) swap(x, y);
      assert(par[y] == x);
      seg.Modify(st[y], 1);
      edges.pop_back();
    }
    // Query path (u, v)
    ans[i] = Query(u, v);
  }

  for (int i = 0; i < Q; i++) {
    cout << ans[i] << '\n';
  }
  return 0;
}