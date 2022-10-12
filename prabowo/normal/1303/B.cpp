#include <bits/stdc++.h>
using namespace std;

int n, g, b;

long long ceil(long long x, long long y) { return (x + y - 1) / y; }

void solve() {
  scanf("%d %d %d", &n, &g, &b);

  int least = (n + 1) / 2;
  long long ans = n;
  if (least % g == 0) ans = max(ans, 1LL*least/g * (g+b) - b);
  else ans = max(ans, 1LL*least/g * (g+b) + least%g);
  printf("%lld\n", ans);
}

int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}