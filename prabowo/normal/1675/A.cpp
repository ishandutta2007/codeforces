#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n;
int a[N];

int solve() {
  int a, b, c, x, y;
  scanf("%d %d %d %d %d", &a, &b, &c, &x, &y);
  x -= a;
  y -= b;
  if (max(0, x) + max(0, y) > c) printf("NO\n");
  else printf("YES\n");
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc + 1);
    solve();
  }
}