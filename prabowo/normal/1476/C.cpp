#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;

int n;
int a[N];
int b[N];
int c[N];

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &c[i]);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &b[i]);
  }

  for (int i = 1; i < n; ++i) {
    if (a[i] > b[i]) swap(a[i], b[i]);
  }
  a[n] = b[n] = 1;

  long long ans = 0;
  for (int i = 0; i < n; ) {
    int j = i;
    while (a[j + 1] != b[j + 1]) ++j;
    // cerr << i << " " << j << endl;

    long long cur = 0;
    for (int k = j; k >= i; --k) {
      ans = max(ans, cur + b[k + 1] - a[k + 1]);
      if (b[k + 1] - a[k + 1] > cur) {
        cur = c[k] + 1;
      } else {
        cur += (a[k + 1] - 1) + (c[k] - b[k + 1]) + 2;
      }
      cerr << cur << endl;
    }
    if (i > 0) ans = max(ans, cur);

    i = j + 1;
  }

  printf("%lld\n", ans);
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}