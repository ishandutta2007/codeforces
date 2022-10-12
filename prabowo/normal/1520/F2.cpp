#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;

int n, t;

int ask(int l, int r) {
  printf("? %d %d\n", l + 1, r + 1);
  int ret;
  fflush(stdout);
  scanf("%d", &ret);
  return ret;
}

struct SegTree {
  int sum[N << 2], subs[N << 2];
  bool asked[N << 2];

  int get(int idx, int l, int r) {
    if (asked[idx]) {
      // cerr << l << " " << r << " " << sum[idx] << " " << subs[idx] << endl;
      return sum[idx] - subs[idx];
    }
    asked[idx] = true;
    sum[idx] = (r - l + 1) - ask(l, r);
    // cerr << l << " " << r << " " << sum[idx] << " " << subs[idx] << endl;
    return sum[idx] - subs[idx];
  }

  int query(int idx, int l, int r, int k) {
    ++subs[idx];
    // cerr << l << " " << r << " " << sum[idx] - subs[idx] << " " << k << endl;
    if (l == r) return l;
    int mid = (l + r) >> 1;
    if (get(idx * 2 + 1, l, mid) < k) {
      k -= get(idx * 2 + 1, l, mid);
      return query(idx * 2 + 2, mid + 1, r, k);
    } else {
      return query(idx * 2 + 1, l, mid, k);
    }
  }

  int query(int k) {
    return query(0, 0, n - 1, k);
  }
} tree;

int solve() {
  scanf("%d %d", &n, &t);
  while (t--) {
    int k;
    scanf("%d", &k);
    printf("! %d\n", tree.query(k) + 1);
    fflush(stdout);
  }

  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}