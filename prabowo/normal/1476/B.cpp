#include <bits/stdc++.h>
using namespace std;
 
const int N = 105;

int n, k;
int a[N];

int solve() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }

  long long ans = 0;

  long long cur = 0;
  for (int i = 1; i < n; ++i) {
    cur += a[i - 1];
    if (100LL * a[i] > cur * k) {
      long long inc = (100LL * a[i] - cur * k + k - 1) / k;
      cur += inc;
      ans += inc;
    }
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