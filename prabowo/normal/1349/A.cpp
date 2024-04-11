#include <bits/stdc++.h>
using namespace std;
 
int n;
 
long long gcd(long long x, long long y) {
  while (y) {
    long long t = x;
    x = y;
    y = t % y;
  }
  return x;
}
 
int solve() {
  scanf("%d", &n);
  int g = 0;
  long long ans = 0;
  int a;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a);
    ans = gcd(ans, 1LL * a / gcd(a, g) * g);
    g = gcd(g, a);
  }
 
  printf("%lld\n", ans);
  return 0;
}
 
int main() {
  int t = 1;
  // scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    solve();
  }
  return 0;
}