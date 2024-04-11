#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
const int MOD = 1000000007;

int n, m;
char s[N];
char t[N];

short dp[N][N][3];
int f(int x, int y, int st) {
  if (y < 0) return (x + 1) * 2;
  if (x < 0) return N;
  short &res = dp[x][y][st];
  if (~res) return res;

  int ret = N;
  if (st == 0) {
    ret = min(ret, f(x, y, 1));
    ret = min(ret, f(x - 1, y, st) + 1);
    if (s[x] == t[y]) {
      ret = min(ret, f(x - 1, y - 1, st) + 1);
    }
  } else if (st == 1) {
    ret = min(ret, f(x, y, 2));
    if (s[x] == t[y]) {
      ret = min(ret, f(x - 1, y - 1, 1));
    }
  } else {
    if (s[x] == t[y]) {
      ret = min(ret, f(x - 1, y - 1, 2) + 1);
    }
    ret = min(ret, f(x - 1, y, 2) + 2);
  }

  return res = ret;
}

int solve() {
  scanf("%d %d", &n, &m);
  scanf("%s", s);
  scanf("%s", t);

  for (int i = 0; i <= n; ++i) for (int j = 0; j <= m; ++j) {
    dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = -1;
  }

  int ans = 1e9;

  for (int j = 0, i = 0; j < m; ++j) {
    while (i < n && s[i] != t[j]) ++i;
    if (i >= n) return 0 * printf("-1\n");
    if (i != j && ans > n) ans = n - j;
    ++i;
  }
  if (ans > n) ans = n - m;

  ans = min(ans, f(n - 1, m - 1, 0) + 1);
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