#include <bits/stdc++.h>
using namespace std;
 
const int N = 1005;
const int MOD = 998244353;

int n, m;
char s[N], t[N];

int sames[N], samet[N];

int dp[N][N][27];
int f(int x, int y, int lst) {
  if (~dp[x][y][lst]) return dp[x][y][lst];

  int ret = 1;
  if (x < n && s[x] - 'a' != lst) {
    ret = (ret + f(x + 1, y, s[x] - 'a')) % MOD;
  }
  if (y < m && t[y] - 'a' != lst) {
    ret = (ret + f(x, y + 1, t[y] - 'a')) % MOD;
  }

  return dp[x][y][lst] = ret;
}

int solve() {
  scanf("%s", s);
  scanf("%s", t);

  n = strlen(s);
  m = strlen(t);

  memset(dp, -1, sizeof dp);

  sames[n] = n;
  for (int i = n - 1; i >= 0; --i) {
    sames[i] = sames[i + 1];
    if (s[i] == s[i + 1]) sames[i] = i + 1;
  }

  samet[m] = m;
  for (int i = m - 1; i >= 0; --i) {
    samet[i] = samet[i + 1];
    if (t[i] == t[i + 1]) samet[i] = i + 1;
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
    ans = (ans + f(i, j, 26) - 1 - (sames[i] - i) - (samet[j] - j)) % MOD;
  }

  if (ans < 0) ans += MOD;
  printf("%d\n", ans);
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}