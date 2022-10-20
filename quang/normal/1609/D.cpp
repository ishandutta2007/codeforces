#include <bits/stdc++.h>

using namespace std;

class DSU {
 public:
  explicit DSU(int n) : num_comp_(n), root_(n, -1), sz_(n, 1) {}

  int num_comp() const { return num_comp_; }
  int sz(int u) { return sz_[GetRoot(u)]; }

  int GetRoot(int u) { return ~root_[u] ? root_[u] = GetRoot(root_[u]) : u; }

  bool Unite(int u, int v) {
    u = GetRoot(u);
    v = GetRoot(v);
    if (u == v) return false;
    sz_[v] += sz_[u];
    root_[u] = v;
    num_comp_--;
    return true;
  }

 private:
  int num_comp_;  // number of connected components
  vector<int> sz_;
  vector<int> root_;
};


int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, d;
  cin >> n >> d;
  int cnt = 1;
  DSU dsu(n);
  while (d--) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    if (!dsu.Unite(x, y)) {
      cnt++;
    }
    vector<int> ls;
    for (int i = 0; i < n; i++) {
      if (dsu.GetRoot(i) == i) {
        ls.push_back(dsu.sz(i));
      }
    }
    sort(ls.begin(), ls.end());
    reverse(ls.begin(), ls.end());
    assert(cnt <= ls.size());
    int res = -1;
    for (int i = 0; i < cnt; i++) {
      res += ls[i];
    }
    cout << res << '\n';
  }

  return 0;
}