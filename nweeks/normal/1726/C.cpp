#include <algorithm>
#include <bits/stdc++.h>
#define int long long
using namespace std;

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

map<int, vector<int>> withVal;
int nbCC;
UnionFind dsu(0);

void rec(int deb, int fin, int depth) {
  if (deb >= fin)
    return;
  auto &vec = withVal[depth];
  int posL = lower_bound(vec.begin(), vec.end(), deb) - vec.begin();
  int posR = lower_bound(vec.begin(), vec.end(), fin) - vec.begin();

  for (int i = posL + 1; i < posR; ++i)
    if (dsu.merge(vec[posL] + 1, vec[i]))
      nbCC--;
  for (int i = posL; i < posR - 1; ++i)
    if (dsu.merge(vec[i] + 1, vec[posR - 1]))
      nbCC--;
  for (int i = posL; i < posR - 1; ++i)
    rec(vec[i] + 1, vec[i + 1], depth + 1);
}

void solve() {
  int n;
  string s;
  cin >> n >> s;
  n *= 2;
  vector<int> pref(n + 1);
  int cur = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '(')
      cur++;
    else
      cur--;
    pref[i + 1] = cur;
  }
  withVal.clear();
  for (int i = 0; i <= n; ++i)
    withVal[pref[i]].push_back(i);
  dsu = UnionFind(n + 1);
  nbCC = n;
  rec(0, n + 1, 0);
  cout << nbCC << '\n';
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbTests;
  cin >> nbTests;
  for (int iTest(0); iTest < nbTests; ++iTest)
    solve();
}