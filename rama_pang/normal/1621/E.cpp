#include <bits/stdc++.h>
using namespace std;

using lint = long long;
// #define int lint

 
class SegTree {
 public:
  int sz;
  vector<int> tree;
  vector<int> lazy;
  SegTree(int sz) : sz(sz), tree(2 * sz), lazy(2 * sz) {}
  void Apply(int n, int x) {
    tree[n] += x;
    lazy[n] += x;
  }
  void Push(int n, int lc, int rc) {
    Apply(lc, lazy[n]);
    Apply(rc, lazy[n]);
    lazy[n] = 0;
  }
  void Pull(int n, int lc, int rc) {
    tree[n] = max(tree[lc], tree[rc]);
  }
  void Update(int n, int tl, int tr, int l, int r, int x) {
    if (tl > tr || l > r || tl > r || l > tr) return;
    if (l <= tl && tr <= r) return Apply(n, x);
    int md = (tl + tr) / 2;
    int z = n + 2 * (md - tl + 1);
    Push(n, n + 1, z);
    Update(n + 1, tl, md, l, r, x);
    Update(z, md + 1, tr, l, r, x);
    Pull(n, n + 1, z);
  }
  int Query() {
    return tree[1];
  }
};

void Main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(begin(a), end(a));
  int id = 0;
  vector<vector<pair<int, int>>> b(m);
  for (int i = 0; i < m; i++) {
    int k;
    cin >> k;
    while (k--) {
      int x;
      cin >> x;
      b[i].emplace_back(x, id++);
    }
  }

  SegTree seg(n + 1);
  for (int i = 0; i <= n; i++) {
    seg.Update(1, 0, n, i, i, i - n);
  }
  string ans(id, 'Z');
  for (int i = 0; i < m; i++) {
    int lo = 0, hi = n;
    lint sum = 0;
    for (auto [x, y] : b[i]) sum += x;
    int cnt = b[i].size();
    while (lo < hi) {
      int md = (lo + hi) / 2;
      if (sum <= 1ll * cnt * a[md]) {
        hi = md;
      } else {
        lo = md + 1;
      }
    }
    seg.Update(1, 0, n, 0, lo, 1);
  }
  for (int i = 0; i < m; i++) {
    int lo = 0, hi = n;
    lint sum = 0;
    for (auto [x, y] : b[i]) sum += x;
    int cnt = b[i].size();
    while (lo < hi) {
      int md = (lo + hi) / 2;
      if (sum <= 1ll * cnt * a[md]) {
        hi = md;
      } else {
        lo = md + 1;
      }
    }
    seg.Update(1, 0, n, 0, lo, -1);
    for (auto [x, y] : b[i]) {
      int l = 0, h = n;
      while (l < h) {
        int md = (l + h) / 2;
        if ((sum - x) <= 1ll * (cnt - 1) * a[md]) {
          h = md;
        } else {
          l = md + 1;
        }
      }
      seg.Update(1, 0, n, 0, l, 1);
      if (seg.Query() > 0) {
        ans[y] = '0';
      } else {
        ans[y] = '1';
      }
      seg.Update(1, 0, n, 0, l, -1);      
    }
    seg.Update(1, 0, n, 0, lo, 1);
  }
  cout << ans << '\n';
}

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}