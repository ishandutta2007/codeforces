#include <bits/stdc++.h>
using namespace std;

int n, m;

int solve() {
  scanf("%d %d", &n, &m);
  
  int d = (n - m) / (m + 1);
  int r = (n - m) % (m + 1);

  printf("%lld\n", 1LL * n * (n+1) / 2 - (1LL * d * (d+1) / 2 * (m+1 - r) + 1LL * (d+1) * (d+2) / 2 * r));

  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}