#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, k;
int a[N];

int solve() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }

  int ans = 0;
  for (int i = 1; i < n - 1; ++i) {
    if (a[i] > a[i - 1] + a[i + 1]) ++ans;
  }

  if (k == 1) ans = (n - 1) / 2;
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