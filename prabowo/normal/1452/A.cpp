#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int n, k;
int a[N];

int solve() {
  int x, y;
  scanf("%d %d", &x, &y);

  int ans = min(x, y) * 2;
  int m = max(x, y) - min(x, y);
  ans += (m > 0 ? m*2 - 1 : 0);
  printf("%d\n", ans);
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    solve();
  }
  return 0;
}