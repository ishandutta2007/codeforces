#include <bits/stdc++.h>
using namespace std;

int n, m;
long long k;

int solve() {
  scanf("%d %d %lld", &n, &m, &k);

  --k;
  int r = k % n, c = k / n;

  printf("%lld\n", 1LL * r * m + c + 1);
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