#include <bits/stdc++.h>
using namespace std;
using lint = long long;

class SegmentTree {
 public:
  int sz;
  vector<int> cnt;
  vector<lint> tree;
  vector<int> data;

  void Toggle(int n, int tl, int tr, int p, int x) {
    if (tr - tl == 1) {
      if (x == 0) {
        cnt[n] = 0;
        tree[n] = 0;
      } else {
        cnt[n] = 1;
        tree[n] = data[tl];
      }
      return;
    }
    int md = (tl + tr) / 2;
    int lc = n + 1;
    int rc = n + 2 * (md - tl);
    if (p < md) {
      Toggle(lc, tl, md, p, x);
    } else {
      Toggle(rc, md, tr, p, x);
    }
    tree[n] = tree[lc] + tree[rc];
    cnt[n] = cnt[lc] + cnt[rc];
  }

  lint Query(int n, int tl, int tr, int k) { // sum of k-smallest
    if (cnt[n] <= k) return tree[n];
    if (k <= 0 || tr - tl == 1) return 0;
    int md = (tl + tr) / 2;
    int lc = n + 1;
    int rc = n + 2 * (md - tl);
    return Query(lc, tl, md, k) + Query(rc, md, tr, k - cnt[lc]);
  }

  SegmentTree() {}
  SegmentTree(int n, vector<int> a) : sz(n), data(a) {
    sort(begin(data), end(data));
    tree.assign(2 * sz, 0);
    cnt.assign(2 * sz, 0);
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n, len, k;
  cin >> n >> len;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cin >> k;
  lint ans = -1e18;
  for (int _ = 0; _ < 2; _++) {
    vector<int> order(n);
    iota(begin(order), end(order), 0);
    sort(begin(order), end(order), [&](int i, int j) { return a[i] < a[j]; });
    vector<int> where(n);
    for (int i = 0; i < n; i++) {
      where[order[i]] = i;
    }
    SegmentTree seg(n, a);
    lint sum = 0;

    for (int i = 0; i < len; i++) {
      sum += a[i];
      if (a[i] < 0) {
        seg.Toggle(1, 0, n, where[i], 1);
      }
    }

    ans = max(ans, sum - 2ll * seg.Query(1, 0, n, k));
    for (int i = len; i < n; i++) {
      sum -= a[i - len];
      sum += a[i];
      if (a[i - len] < 0) {
        seg.Toggle(1, 0, n, where[i - len], 0);
      }
      if (a[i] < 0) {
        seg.Toggle(1, 0, n, where[i], 1);
      }
      ans = max(ans, sum - 2ll * seg.Query(1, 0, n, k));
    }

    for (int i = 0; i < n; i++) {
      a[i] *= -1;
    }
  }

  cout << ans << "\n";
  return 0;
}