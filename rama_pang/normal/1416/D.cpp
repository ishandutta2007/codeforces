#include <bits/stdc++.h>
using namespace std;

class SegTree {
 public:
  int sz;
  vector<int> tree;

  SegTree(int sz) : sz(sz), tree(2 * sz) {}

  void Modify(int p, int x) {
    tree[p += sz] = x;
    for (p /= 2; p > 0; p /= 2) tree[p] = max(tree[p * 2], tree[p * 2 + 1]);
  }

  int Query(int l, int r) {
    int res = 0;
    for (l += sz, r += sz; l < r; l /= 2, r /= 2) {
      if (l & 1) res = max(res, tree[l++]);
      if (r & 1) res = max(res, tree[--r]);
    }
    return res;
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, M, Q;
  cin >> N >> M >> Q;

  vector<int> A(N), iA(N + 1);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    iA[A[i]] = i;
  }

  vector<pair<int, int>> edges(M);
  for (int i = 0; i < M; i++) {
    cin >> edges[i].first >> edges[i].second;
    edges[i].first--, edges[i].second--;
  }

  vector<pair<int, int>> query(Q);
  for (int i = 0; i < Q; i++) {
    cin >> query[i].first >> query[i].second;
    query[i].second--;
  }

  vector<int> par(N);
  vector<vector<int>> adj(N);
  iota(begin(par), end(par), 0);
  function<int(int)> Find = [&](int x) {
    return par[x] == x ? x : par[x] = Find(par[x]);
  };

  vector<int> done_edge(M);
  for (int i = 0; i < Q; i++) {
    if (query[i].first == 2) {
      done_edge[query[i].second] = 1;
    }
  }
  for (int i = 0; i < M; i++) {
    if (!done_edge[i]) {
      auto [u, v] = edges[i];
      done_edge[i] = 1;
      if (Find(u) != Find(v)) {
        adj.emplace_back();
        par.emplace_back(par.size());
        adj.back().emplace_back(Find(u));
        adj.back().emplace_back(Find(v));
        par[Find(u)] = par.back();
        par[Find(v)] = par.back();
      }      
    }
  }
  for (int i = Q - 1; i >= 0; i--) {
    if (query[i].first == 2) {
      auto [u, v] = edges[query[i].second];
      done_edge[query[i].second] = 1;
      if (Find(u) != Find(v)) {
        adj.emplace_back();
        par.emplace_back(par.size());
        adj.back().emplace_back(Find(u));
        adj.back().emplace_back(Find(v));
        par[Find(u)] = par.back();
        par[Find(v)] = par.back();
      }
    } else {
      query[i].second = Find(query[i].second);
    }
  }

  for (int i = 1; i < N; i++) {
    auto [u, v] = pair(0, i);
    if (Find(u) != Find(v)) {
      adj.emplace_back();
      par.emplace_back(par.size());
      adj.back().emplace_back(Find(u));
      adj.back().emplace_back(Find(v));
      par[Find(u)] = par.back();
      par[Find(v)] = par.back();
    }
  }

  for (int i = 0; i < N; i++) assert(Find(0) == Find(i));

  int timer = 0;
  vector<int> st(adj.size());
  vector<int> et(adj.size());
  const auto Dfs = [&](const auto &self, int u, int p) -> void {
    st[u] = timer++;
    for (auto v : adj[u]) if (v != p) {
      self(self, v, u);
    }
    et[u] = timer;
  };

  Dfs(Dfs, int(adj.size()) - 1, -1);
  SegTree seg(adj.size());
  for (int i = 0; i < N; i++) {
    seg.Modify(st[i], A[i]);
  }

  for (int i = 0; i < Q; i++) {
    if (query[i].first == 1) {
      int v = query[i].second;
      int ans = seg.Query(st[v], et[v]);
      cout << ans << '\n';
      if (ans != 0) {
        seg.Modify(st[iA[ans]], 0);
      }
    }
  }
  return 0;
}