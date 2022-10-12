#include <bits/stdc++.h>
using namespace std;

int n, x;

int solve() {
  scanf("%d %d", &n, &x);

  int cnt[2] = {0, 0};
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    ++cnt[a & 1];
  }

  bool can = false;
  for (int i = 0; i <= cnt[0]; ++i) {
    if (i > x) break;
    if ((x-i) > cnt[1]) continue;

    if ((x-i) & 1) can = true;
  }

  if (can) printf("Yes\n");
  else printf("No\n");
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