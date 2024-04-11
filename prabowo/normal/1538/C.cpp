#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;

int n, l, r;
int a[N];
char s[N];

int solve() {
  scanf("%d %d %d", &n, &l, &r);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }

  sort(a, a + n);

  long long ans = 0;

  for (int i = 0; i < n; ++i) {
    ans += upper_bound(a, a + i, r - a[i]) - lower_bound(a, a + i, l - a[i]);
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