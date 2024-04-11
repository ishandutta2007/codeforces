#include <bits/stdc++.h>
using namespace std;

const int N = 405;

int n, m;

char s[N];
char t[N];

short dp[N][N][N];
int f(int x, int i1, int i2) {
  if (x == n) return i2 == m ? i1 : 0;
  if (~dp[x][i1][i2]) return dp[x][i1][i2];

  int ret = f(x+1, i1, i2);
  if (i2 < m && s[x] == t[i2]) ret = max(ret, f(x+1, i1, i2+1));
  if (i1 < m && s[x] == t[i1]) ret = max(ret, f(x+1, i1+1, i2));

  return dp[x][i1][i2] = ret;
}

int solve() {
  scanf("%s", s);
  scanf("%s", t);

  n = strlen(s); m = strlen(t);

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= m; ++j) for (int k = 0; k <= m; ++k) {
      dp[i][j][k] = -1;
    }
  }

  for (int i = 1; i <= m; ++i) {
    if (f(0, 0, i) >= i) return 0 * printf("YES\n");
  }

  printf("NO\n");
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}