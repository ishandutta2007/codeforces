#include <bits/stdc++.h>
using namespace std;

class SegTree {
 public:
  int sz;
  vector<vector<int>> tree;

  SegTree() {}
  SegTree(int sz) : sz(sz), tree(2 * sz) {}

  void Add(int l, int r, int x) {
    for (l += sz, r += sz + 1; l < r; l /= 2, r /= 2) {
      if (l & 1) tree[l++].emplace_back(x);
      if (r & 1) tree[--r].emplace_back(x);
    }
  }

  void Build() {
    for (int i = 0; i < 2 * sz; i++) {
      sort(begin(tree[i]), end(tree[i]));
    }
  }

  int Query(int p, int x, int y) {
    int res = 0;
    for (p += sz; p > 0; p /= 2) {
      res += upper_bound(begin(tree[p]), end(tree[p]), y) - lower_bound(begin(tree[p]), end(tree[p]), x);
    }
    return res;
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n, m;
  cin >> n >> m;

  const int MAX = 1e6 + 5;
  SegTree seg(MAX);
  seg.Add(0, 1e6, 0);
  seg.Add(0, 1e6, 1e6);
  
  long long ans = 1;
  for (int i = 0; i < n; i++) {
    int y, l, r;
    cin >> y >> l >> r;
    seg.Add(l, r, y);
    if (l == 0 && r == int(1e6)) {
      ans += 1;
    }
  }
  seg.Build();
  for (int i = 0; i < m; i++) {
    int x, l, r;
    cin >> x >> l >> r;
    ans += seg.Query(x, l, r) - 1;
  }

  cout << ans << "\n";
  return 0;
}