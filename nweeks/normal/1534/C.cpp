#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;

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
  int n;
  cin >> n;

  vector<int> p1(n), p2(n);
  for (int i = 0; i < n; ++i) {
    cin >> p1[i];
    --p1[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> p2[i];
    --p2[i];
  }

  vector<int> pos(n);
  for (int i = 0; i < n; ++i)
    pos[p2[i]] = i;

  UnionFind uf(n);
  for (int i = 0; i < n; ++i) {
    uf.merge(i, pos[p1[i]]);
  }
  int nbCC = 0;
  for (int i = 0; i < n; ++i)
    nbCC += uf.find(i) == i;

  int sol = 1;
  for (int i = 0; i < nbCC; ++i)
    sol = 2 * sol % MOD;
  cout << sol << '\n';
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbTests;
  cin >> nbTests;
  for (int iTest(0); iTest < nbTests; ++iTest)
    solve();
}