#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;

int n, x, t;

int solve() {
  scanf("%d %d %d", &n, &x, &t);

  // sum(min(n - i - 1, t/x))
  long long ans = t/x;
  ans = t/x;
  if (ans >= n) ans = 1LL * n * (n - 1) / 2;
  else ans = 1LL * ans * (ans - 1) / 2 + ans * (n - ans);

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