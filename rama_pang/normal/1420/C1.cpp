#include <bits/stdc++.h>
using namespace std;

class SegTree {
 public:
  int sz;
  vector<array<array<long long, 2>, 2>> tree;

  SegTree() {}
  SegTree(int sz) : sz(sz), tree(2 * sz) {}

  void Update(int n, int tl, int tr, int p, int x) {
    if (tl == tr) {
      tree[n][0][0] = x;
      tree[n][1][1] = -x;
      tree[n][0][1] = -1e18;
      tree[n][1][0] = -1e18;
      return;
    }
    int md = (tl + tr) / 2;
    int z = n + 2 * (md - tl + 1);
    if (p <= md) {
      Update(n + 1, tl, md, p, x);
    } else {
      Update(z, md + 1, tr, p, x);
    }
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        tree[n][i][j] = max(tree[n + 1][i][j], tree[z][i][j]);
        for (int k = 0; k < 2; k++) {
          tree[n][i][j] = max(tree[n][i][j], tree[n + 1][i][k] + tree[z][k ^ 1][j]);
        }
      }
    }
  }

  void Update(int p, int x) {
    return Update(1, 0, sz - 1, p, x);
  }

  long long Query() {
    return max({tree[1][0][0], tree[1][0][1], tree[1][1][0], tree[1][1][1]});
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    SegTree seg(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      seg.Update(i, a[i]);
    }
    cout << seg.Query() << "\n";
    while (q--) {
      int l, r;
      cin >> l >> r;
      l--, r--;
      swap(a[l], a[r]);
      seg.Update(l, a[l]);
      seg.Update(r, a[r]);
      cout << seg.Query() << "\n";
    }
  }
  return 0;
}