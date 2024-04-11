#include <bits/stdc++.h>
using namespace std;

int x, y, a, b;
int test(int take, int x, int y, int a, int b) {
  // cerr << take << endl;
  if (1LL * take * a > x || 1LL * take * b > y) return min(x / a, y / b);

  int ret = take;
  x -= take * a, y -= take * b;

  take = min(x / (a + b), y / (a + b));
  ret += take * 2;
  x -= take * (a + b); y -= take * (a + b);

  if (x >= a && y >= b || x >= b && y >= a) ++ret;
  return ret;
}

int solve() {
  scanf("%d %d %d %d", &x, &y, &a, &b);
  if (a == b) return 0 * printf("%d\n", min(x / a, y / b));
  if (x < y) swap(x, y);
  if (a < b) swap(a, b);

  int ans = test((x - y) / (a - b), x, y, a, b);
  ans = max(ans, test((x - y) / (a - b) + 1, x, y, a, b));

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