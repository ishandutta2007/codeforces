#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n;
int a[N];

int solve() {
  int l1, r1, l2, r2;
  scanf("%d %d %d %d", &l1, &r1, &l2, &r2);
  int ans = 1e9;
  if (max(l1, l2) <= min(r1, r2)) {
    ans = max(l1, l2);
  }
  ans = min(ans, l1 + l2);
  printf("%d\n", ans);
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc + 1);
    solve();
  }
  return 0;
}