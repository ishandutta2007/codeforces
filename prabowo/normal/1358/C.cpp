#include <bits/stdc++.h>
using namespace std;

int x, y, xx, yy;

int solve() {
  scanf("%d %d %d %d", &x, &y, &xx, &yy);
  int a = xx - x;
  int b = yy - y;
  printf("%lld\n", 1LL * b * a + 1);
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