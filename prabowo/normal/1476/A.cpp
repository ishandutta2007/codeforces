#include <bits/stdc++.h>
using namespace std;
 
int n, m, k;

int solve() {
  scanf("%d %d", &n, &m);

  if (m < n) m = n + (n % m == 0 ? 0 : n - (n % m));
  
  long long ans = (1LL * m + n - 1) / n;

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