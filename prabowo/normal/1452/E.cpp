#include <bits/stdc++.h>
using namespace std;

const int N = 2005;

int n, m, k;
int l[N], r[N];

struct SegTree {
  int maxi[N << 2];
  int lazy[N << 2];

  void propagate(int node) {
    for (int i = 0; i < 2; ++i) {
      maxi[node*2 + i + 1] += lazy[node];
      lazy[node*2 + i + 1] += lazy[node];
    }
    lazy[node] = 0;
  }

  void update(int node, int l, int r, int ll, int rr, int val) {
    // cerr << node << l << " " << r << " " << ll << " " << rr << " " << val << endl;
    if (l > rr || r < ll) return;
    if (l >= ll && r <= rr) {
      maxi[node] += val;
      lazy[node] += val;
      return;
    }

    int mid = (l + r) >> 1;
    propagate(node);

    update(node*2 + 1, l, mid+0, ll, rr, val);
    update(node*2 + 2, mid+1, r, ll, rr, val);
    maxi[node] = max(maxi[node*2 + 1], maxi[node*2 + 2]);
  }

  int query(int node, int l, int r, int ll, int rr) {
    // cerr << node << " " << l << " " << r << " " << ll << " " << rr << endl;
    if (l > rr || r < ll) return 0;
    if (l >= ll && r <= rr) return maxi[node];

    int mid = (l + r) >> 1;
    propagate(node);

    return max(query(node*2 + 1, l, mid, ll, rr), query(node*2 + 2, mid+1, r, ll, rr));
  }

  void update(int l, int r, int val) {
    // cerr << "UPD " << l << " " << r << " " << val << endl;
    update(0, 0, n-1, l, r, val);
  }

  void update(int x, int val) {
    update(x, x, val);
  }

  int query(int l, int r) {
    // cerr << l << " " << r << endl;
    return query(0, 0, n-1, l, r);
  }
} tree;

int inter(int l, int r, int ll, int rr) {
  return max(0, min(r, rr) - max(l, ll) + 1);
}

int lst[N];

int solve() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < m; ++i) {
    scanf("%d %d", &l[i], &r[i]);
    --l[i], --r[i];
  }

  for (int i = 0; i < n - k + 1; ++i) {
    for (int j = 0; j < m; ++j) {
      tree.update(i, inter(i, i + k - 1, l[j], r[j]));
    }
  }

  // cerr << "OK" << endl;

  int ans = 0;
  for (int i = 0; i < n - k + 1; ++i) {
    int sum = 0;
    for (int j = 0; j < m; ++j) {
      int cur = inter(i, i + k - 1, l[j], r[j]);
      sum += cur;

      if (lst[j] < cur) {
        for (int kk = lst[j] + 1; kk <= cur; ++kk) {
          tree.update(max(0, l[j] - k + kk), min(n - k, r[j] - kk + 1), -1);
        }
        lst[j] = cur;
      }
    }

    ans = max(ans, sum + tree.query(i + 1, n - k));
    // cerr << "asdf" << endl;
  }

  printf("%d\n", ans);
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    solve();
  }
  return 0;
}