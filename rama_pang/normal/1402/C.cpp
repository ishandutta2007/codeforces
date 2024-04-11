#include <bits/stdc++.h>
using namespace std;
using lint = long long;

class SegTree {
 public:
  int sz;
  vector<int> tree;
  SegTree() {}
  SegTree(int sz) : sz(sz), tree(2 * sz) {}
  void Update(int p, int x) {
    tree[p += sz] = x;
    for (p /= 2; p > 0; p /= 2) {
      tree[p] = min(tree[p * 2], tree[p * 2 + 1]);
    }
  }
  int Query(int l, int r) {
    int res = sz;
    for (l += sz, r += sz; l < r; l /= 2, r /= 2) {
      if (l & 1) res = min(res, tree[l++]);
      if (r & 1) res = min(res, tree[--r]);
    }
    return res;
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  vector<int> coord;
  vector<deque<int>> occ(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    coord.emplace_back(a[i]);
  }
  sort(begin(coord), end(coord));
  coord.resize(unique(begin(coord), end(coord)) - begin(coord));
  for (int i = 0; i < n; i++) {
    a[i] = lower_bound(begin(coord), end(coord), a[i]) - begin(coord);
    occ[a[i]].emplace_back(i);
  }
  SegTree seg(n);
  for (int i = 0; i < n; i++) {
    if (occ[i].size() < k) {
      seg.Update(i, 1e9);
    } else {
      seg.Update(i, occ[i][k - 1]);
    }
  }
  lint ans = 0;
  for (int l = 0; l < n; l++) {
    ans += n - seg.Query(0, n);
    int del = a[l];
    occ[del].pop_front();
    if (occ[del].size() < k) {
      seg.Update(del, 1e9);
    } else {
      seg.Update(del, occ[del][k - 1]);
    }
  }

  cout << ans << "\n";
  return 0;
}