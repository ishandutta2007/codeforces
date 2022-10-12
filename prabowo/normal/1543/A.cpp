#include <bits/stdc++.h>
using namespace std;
 
long long n, m;

int solve() {
  scanf("%lld %lld", &n, &m);
  if (n > m) swap(n, m);

  long long diff = m - n;
  if (diff == 0) return 0 * printf("0 0\n");

  long long ans = min(n % diff, diff - n % diff);
  printf("%lld %lld\n", diff, ans);
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