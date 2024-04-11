#include <bits/stdc++.h>
using namespace std;

int k;

int solve() {
  scanf("%d", &k);

  int ans = 1e9;
  for (int i = 1; i <= 100; ++i) {
    if ((100 - k) * i % k != 0) continue;
    int x = (100 - k) * i / k;
    ans = min(ans, i + x);
  }

  printf("%d\n", ans);
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