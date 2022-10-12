#include <bits/stdc++.h>
using namespace std;

const int N = 10005;

char s[N], t[N];
int prv[N];

int dp[N][N];

int solve() {
  scanf("%s", s + 1);
  scanf("%s", t + 1);

  int n = strlen(s + 1), m = strlen(t + 1);
  for (int i = 1; i <= n; ++i) {
    int h = 0;
    prv[i] = -1;
    for (int j = i; j > 0; --j) {
      h += (s[j] == '.' ? -1 : 1);
      if (h > 0) break;
      if (h == 0) {
        prv[i] = j-1;
        break;
      }
    }
  }

  dp[0][0] = 0;
  for (int j = 1; j <= m; ++j) dp[0][j] = N;

  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      dp[i][j] = 1 + dp[i-1][j];
      if (j > 0 && s[i] == t[j]) dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
      if (prv[i] != -1) dp[i][j] = min(dp[i][j], dp[prv[i]][j]);
    }
  }

  printf("%d\n", dp[n][m]);
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}