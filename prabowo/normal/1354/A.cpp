#include <bits/stdc++.h>
using namespace std;

int solve() {
  int a, b, c, d;
  scanf("%d %d %d %d", &a, &b, &c, &d);
  if (b >= a) return 0 * printf("%d\n", b);
  if (d >= c) return 0 * printf("-1\n");
  a -= b;
  long long ans = b + 1LL * ((a + (c - d) - 1) / (c - d)) * c;
  printf("%lld\n", ans);
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) solve();  
  return 0;
}