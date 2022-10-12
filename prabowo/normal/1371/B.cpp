#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, r;

int solve() {
  scanf("%d %d", &n, &r);

  long long ans = 0;
  if (r < n) {
    ans = 1LL * r * (r+1) / 2;
  } else {
    ans = 1LL * n * (n-1) / 2 + 1;
  }

  printf("%lld\n", ans);
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}