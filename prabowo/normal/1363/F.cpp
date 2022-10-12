#include <bits/stdc++.h>
using namespace std;

const int N = 2005;

int n;
char s[N], t[N];

int dp[N][N];
int cnts[N][26], cntt[N][26];

int solve() {
  scanf("%d", &n);
  scanf("%s", s + 1);
  scanf("%s", t + 1);

  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < 26; ++j) {
      cnts[i][j] = cnts[i-1][j];
      cntt[i][j] = cntt[i-1][j];
    }

    ++cnts[i][s[i] - 'a'];
    ++cntt[i][t[i] - 'a'];
  }

  for (int i = 0; i < 26; ++i) {
    if (cnts[n][i] != cntt[n][i]) return 0 * printf("-1\n");
  }

  for (int i = 1; i <= n; ++i) dp[i][0] = i;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      dp[i][j] = dp[i-1][j] + 1;
      if (s[i] == t[j]) dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
      if (cnts[n][t[j] - 'a'] - cnts[i][t[j]- 'a'] > cntt[n][t[j] - 'a'] - cntt[j][t[j] - 'a']) {
        dp[i][j] = min(dp[i][j], dp[i][j-1]);
      }
    }
  }

  printf("%d\n", dp[n][n]);
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