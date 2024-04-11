#include <bits/stdc++.h>
using namespace std;


int n, m;

int solve() {
  scanf("%d %d", &n, &m);
  if (n < m) swap(n, m);

  int ans = min(min(m, n/2), n - m);
  n -= ans*2; m -= ans;

  printf("%d\n", ans + min(n, m) / 3 * 2 + (min(n, m) % 3 == 2));

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