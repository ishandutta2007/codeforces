#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
const int INF = 1e9 + 5;

int n;
int a[N];

struct SegTree {
  int mini[N << 2];
  int maxi[N << 2];

  void build(int idx, int l, int r) {
    if (l == r) {
      mini[idx] = maxi[idx] = a[l];
      return;
    }

    int mid = (l + r) >> 1;
    build(idx*2 + 1, l, mid+0);
    build(idx*2 + 2, mid+1, r);
    mini[idx] = min(mini[idx*2 + 1], mini[idx*2 + 2]);
    maxi[idx] = max(maxi[idx*2 + 1], maxi[idx*2 + 2]);
  }

  int queryMin(int idx, int l, int r, int ll, int rr) {
    if (l > rr || r < ll) return INF;
    if (l >= ll && r <= rr) return mini[idx];

    int mid = (l + r) >> 1;
    return min(queryMin(idx*2 + 1, l, mid+0, ll, rr),
               queryMin(idx*2 + 2, mid+1, r, ll, rr));
  }

  int queryMax(int idx, int l, int r, int ll, int rr) {
    if (l > rr || r < ll) return 0;
    if (l >= ll && r <= rr) return maxi[idx];

    int mid = (l + r) >> 1;
    return max(queryMax(idx*2 + 1, l, mid+0, ll, rr),
               queryMax(idx*2 + 2, mid+1, r, ll, rr));
  }

  int queryMin(int l, int r) {
    return queryMin(0, 0, n-1, l, r);
  }

  int queryMax(int l, int r) {
    return queryMax(0, 0, n-1, l, r);
  }
} tree;

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  tree.build(0, 0, n-1);

  int m = 0;
  for (int i = 0; i < n; ++i) {
    m = max(m, a[i]);

    int l = i+1, r = n-2;
    while (l <= r) {
      int mid = (l + r) >> 1;

      int mini = tree.queryMin(i+1, mid);
      int maxi = tree.queryMax(mid+1, n-1);

      if (mini > m || maxi > m) {
        l = mid + 1;
        continue;
      } 

      if (mini < m || maxi < m) {
        r = mid - 1;
        continue;
      }

      return 0 * printf("YES\n%d %d %d\n", i+1, mid-i, n - (mid+1));
    }
  }

  printf("NO\n");
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    solve();
  }
  return 0;
}