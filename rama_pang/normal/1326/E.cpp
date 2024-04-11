#include <bits/stdc++.h>
using namespace std;

class SegTree {
 private:
  int sz;
  vector<int> tree;
  vector<int> lazy;

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
    if (r < tl || tr < l || tl > tr || l > r) return;
    if (l <= tl && tr <= r) return Apply(n, x);
    int mid = (tl + tr) / 2;
    int lc = n + 1;
    int rc = n + 2 * (mid - tl + 1);
    Push(n, lc, rc);
    Update(lc, tl, mid, l, r, x);
    Update(rc, mid + 1, tr, l, r, x);
    Pull(n, lc, rc);
  }

  int Query(int n, int tl, int tr, int l, int r) {
    if (r < tl || tr < l || tl > tr || l > r) return -1e9;
    if (l <= tl && tr <= r) return tree[n];
    int mid = (tl + tr) / 2;
    int lc = n + 1;
    int rc = n + 2 * (mid - tl + 1);
    Push(n, lc, rc);
    return max(Query(lc, tl, mid, l, r), Query(rc, mid + 1, tr, l, r));
  }

 public:
  SegTree() {}
  SegTree(int n) : sz(n) {
    tree.assign(2 * sz, 0);
    lazy.assign(2 * sz, 0);
  }

  void Update(int l, int r, int x) {
    return Update(1, 0, sz - 1, l, r, x);
  }

  int Query(int l, int r) {
    return Query(1, 0, sz - 1, l, r);
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n;
  cin >> n;
  
  vector<int> p(n);
  vector<int> q(n);
  vector<int> pos(n);

  for (int i = 0; i < n; i++) {
    cin >> p[i];
    p[i]--;
    pos[p[i]] = i;
  }
  for (int i = 0; i < n; i++) {
    cin >> q[i];
    q[i]--;
  }

  int ans = n - 1;
  int cnt = 0;
  
  SegTree seg(n); // bombs in the suffix
  seg.Update(0, pos[ans], 1);

  for (int i = 0; i < n; i++) {
    cout << ans + 1 << " \n"[i == n - 1];
    seg.Update(0, q[i], -1);

    while (seg.Query(0, n - 1) <= 0) {
      seg.Update(0, pos[--ans], 1);
    }
  }

  return 0;
}