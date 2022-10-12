#include <bits/stdc++.h>
using namespace std;

int x, y, a, b;

int solve() {
  scanf("%d %d %d %d", &x, &y, &a, &b);

  long long ans;
  if (b < a*2 && (a < 0) == (b < 0)) {
    int mini = min(abs(x), abs(y));
    int maxi = max(abs(x), abs(y));
    ans = 1LL * mini * b + 1LL * (maxi - mini) * a;
  } else {
    ans = 1LL * (abs(x) + abs(y)) * a;
  }

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