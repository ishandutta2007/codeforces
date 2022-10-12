#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;

int l, r;

int solve() {
  scanf("%d %d", &l, &r);

  long long ans = 0;
  for (long long ten = 1, cnt = 1; ten <= r; ten *= 10, ++cnt) {
    ans += r / ten - l / ten;
    // ans += (((r + 1) / ten - (r + 1) / (ten * 10)) - ((l + 1) / ten - (l + 1) / (ten * 10))) * cnt;
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