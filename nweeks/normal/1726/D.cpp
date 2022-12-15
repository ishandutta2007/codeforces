#include <bits/stdc++.h>
#define int long long
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int randint(int lb, int ub) {
  return uniform_int_distribution<int>(lb, ub)(rng);
}

struct UnionFind {
  vector<int> id;

  UnionFind() {}
  UnionFind(int N) { id.assign(N, -1); }

  int find(int u) {
    if (id[u] < 0)
      return u;
    return id[u] = find(id[u]);
  }

  bool merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v)
      return false;
    if (id[u] > id[v])
      swap(u, v);
    id[u] += id[v];
    id[v] = u;
    return true;
  }
};

void solve() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> edges(m);
  for (auto &[u, v] : edges) {
    cin >> u >> v;
    --u, --v;
  }
  while (true) {
    vector<int> indices(m);
    iota(indices.begin(), indices.end(), 0LL);
    UnionFind dsuRed(n), dsuBlue(n);
    vector<int> col(m);
    shuffle(indices.begin(), indices.end(), rng);
    bool ok = true;
    for (int ind : indices) {
      auto [u, v] = edges[ind];
      if (dsuRed.find(u) == dsuRed.find(v)) {
        if (dsuBlue.find(u) == dsuBlue.find(v)) {
          ok = false;
          break;
        }
        col[ind] = 1;
        dsuBlue.merge(u, v);
      } else
        dsuRed.merge(u, v);
    }
    if (ok) {
      for (int i : col)
        cout << i;
      cout << '\n';
      return;
    }
  }
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbTests;
  cin >> nbTests;
  for (int iTest(0); iTest < nbTests; ++iTest)
    solve();
}