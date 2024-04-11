#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, m;
int a[N];

long long rgt[N], lft[N];

int solve() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }

  for (int i = 1; i < n; ++i) {
    rgt[i] = rgt[i - 1] + max(0, a[i - 1] - a[i]);
  }
  lft[n - 1] = 0;
  for (int i = n - 2; i >= 0; --i) {
    lft[i] = lft[i + 1] + max(0, a[i + 1] - a[i]);
  }

  while (m--) {
    int l, r;
    scanf("%d %d", &l, &r);
    --l, --r;

    long long ans = 0;
    if (l < r) ans = rgt[r] - rgt[l];
    else ans = lft[r] - lft[l];
    printf("%lld\n", ans);
  }
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc + 1);
    solve();
  }
  return 0;
}