#include <bits/stdc++.h>
using namespace std;

class SegTree {
 public:
  int sz;
  vector<int> tree;

  SegTree(int sz) : sz(sz), tree(2 * sz, 1e9) {}

  void Modify(int p, int x) {
    p += sz;
    tree[p] = min(tree[p], x);
    for (p /= 2; p > 0; p /= 2) {
      tree[p] = min(tree[p * 2], tree[p * 2 + 1]);
    }
  }

  int Query(int l, int r) {
    int res = 1e9;
    for (l += sz, r += sz + 1; l < r; l /= 2, r /= 2) {
      if (l & 1) res = min(res, tree[l++]);
      if (r & 1) res = min(res, tree[--r]);
    }
    return res;
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  int last = 0;
  int lazy = 0;
  SegTree dp(n + 1);
  dp.Modify(0, 0);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;

    int dp_a = dp.Query(a, a) + lazy;
    int dp_not_a = min(dp.Query(0, a - 1), dp.Query(a + 1, n)) + lazy;

    int dp_last = dp.Query(last, last) + lazy;

    // Put it into current sequence
    lazy += last != a;

    // Put it into second sequence
    dp.Modify(last, min({dp_last + (last != a), dp_a, dp_not_a + 1}) - lazy);

    last = a;
  }

  cout << dp.Query(0, n) + lazy << '\n';
  return 0;
}