#include <bits/stdc++.h>
using namespace std;

int n, m;

int solve() {
  scanf("%d %d", &n, &m);
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    sum += a;
  }

  if (sum == m) printf("YES\n"); else printf("NO\n");
  // printf("-1\n");
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