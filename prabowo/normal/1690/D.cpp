#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, k;
char s[N];

int pre[N];

int solve() {
  scanf("%d %d", &n, &k);
  scanf("%s", s + 1);

  pre[0] = 0;
  for (int i = 1; i <= n; ++i) {
    pre[i] = pre[i - 1];
    if (s[i] == 'B') ++pre[i];
  }

  int ans = n;
  for (int i = 1; i <= n - k + 1; ++i) {
    ans = min(ans, k - (pre[i + k - 1] - pre[i - 1]));
  }

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