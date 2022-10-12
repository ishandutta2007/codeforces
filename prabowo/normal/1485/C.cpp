#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;
const int MOD = 1000000007;
const int INF = 1e9;

int n, m;

int solve() {
  scanf("%d %d", &n, &m);

  long long ans = 0;
  for (int b = 1; b <= min(m, 40000); ++b) {
    ans += min(b - 1, n / (b + 1));
  }

  for (int i = 1; i < 40000; ++i) {
    int r = n / i, l = n / (i + 1);
    r = min(r, m + 1);
    l = max(l, 40001);
    if (l < r) ans += 1LL * (r - l) * i;
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