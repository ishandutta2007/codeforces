#include <bits/stdc++.h>
using namespace std;

using lint = long long;

class SegmentTree {
 private:
  int sz;
  vector<int> mx;
  vector<lint> sum;

  void Pull(int n, int lc, int rc) {
    sum[n] = sum[lc] + sum[rc];
    mx[n] = max(mx[lc], mx[rc]);
  }

  void Update(int n, int tl, int tr, int l, int r, int k) {
    if (tr < l || r < tl || tl > tr || l > r || mx[n] < k) return;
    if (tl == tr) {
      sum[n] = (mx[n] %= k);
      return;
    }
    int md = (tl + tr) / 2;
    int z = n + 2 * (md - tl + 1);
    Update(n + 1, tl, md, l, r, k);
    Update(z, md + 1, tr, l, r, k);
    Pull(n, n + 1, z);
  }

  void Set(int n, int tl, int tr, int p, int x) {
    if (tl == tr) {
      mx[n] = x;
      sum[n] = x;
      return;
    }
    int md = (tl + tr) / 2;
    int z = n + 2 * (md - tl + 1);
    if (p <= md) {
      Set(n + 1, tl, md, p, x);
    } else {
      Set(z, md + 1, tr, p, x);
    }
    Pull(n, n + 1, z);
  }

  lint Query(int n, int tl, int tr, int l, int r) {
    if (tr < l || r < tl || tl > tr || l > r) return 0;
    if (l <= tl && tr <= r) return sum[n];
    int md = (tl + tr) / 2;
    int z = n + 2 * (md - tl + 1);
    return Query(n + 1, tl, md, l, r) + Query(z, md + 1, tr, l, r);    
  }

 public:
  SegmentTree() {}
  SegmentTree(int sz) : sz(sz) {
    mx.assign(2 * sz, 0);
    sum.assign(2 * sz, 0);
  }

  lint Query(int l, int r) {
    return Query(1, 0, sz - 1, l, r);
  }

  void Update(int l, int r, int k) {
    return Update(1, 0, sz - 1, l, r, k);
  }

  void Set(int p, int x) {
    return Set(1, 0, sz - 1, p, x);
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int N, Q;
  cin >> N >> Q;
  SegmentTree seg(N);
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    seg.Set(i, a);
  }

  for (int i = 0; i < Q; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      int l, r;
      cin >> l >> r;
      cout << seg.Query(--l, --r) << "\n";
    } else if (t == 2) {
      int l, r, k;
      cin >> l >> r >> k;
      seg.Update(--l, --r, k);
    } else if (t == 3) {
      int p, x;
      cin >> p >> x;
      seg.Set(--p, x);
    }
  }
  return 0;
}