#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n;
int a[N];

int pre[N];

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }

  int ans = 1;

  pre[0] = 1;
  for (int i = 1; i < n; ++i) {
    if (a[i] > a[i-1]) pre[i] = pre[i-1] + 1;
    else pre[i] = 1;
    ans = max(ans, pre[i]);
  }

  if (pre[n-1] == n-1) return 0 * printf("%d\n", n-1);

  int suf = 1;
  for (int i = n-2; i > 0; --i) {
    if (a[i-1] < a[i+1]) ans = max(ans, pre[i-1] + suf);
    if (a[i] < a[i+1]) suf = suf + 1;
    else suf = 1;
  }

  printf("%d\n", ans);
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