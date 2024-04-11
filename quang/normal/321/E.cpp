#include <bits/stdc++.h>

using namespace std;

const int inf = 2000000000;

int n, k;
int dp[810][4010];
int cost[4010][4010];
char s[8010];

int val(int l, int r) {
  return (cost[r][r] - cost[r][l] - cost[l][r] + cost[l][l]);
}

void get(int u, int l, int r, int x, int y) {
  if (l > r) {
    return;
  }
  int m = (l + r) >> 1;
  dp[u][m] = inf;
  int pos = x;
  for (int i = x; i <= min(m - 1, y); i++) {
    int foo = val(i, m) + dp[u - 1][i];
    if (foo < dp[u][m]) {
      dp[u][m] = foo;
      pos = i;
    }
  }
  get(u, l, m - 1, x, pos);
  get(u, m + 1, r, pos, y);
}

int main() {
  #ifdef Doflamingo
  freopen("input", "r", stdin);
  #endif // Doflamingo
  scanf("%d %d", &n, &k);
  gets(s);
  for (int i = 1; i <= n; i++) {
    gets(s);
    for (int j = 1; j <= n; j++) {
      cost[i][j] = cost[i - 1][j] + cost[i][j - 1] - cost[i - 1][j - 1] + s[(j - 1) * 2] - '0';
    }
  }
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    dp[0][i] = inf;
  }
  for (int i = 1; i <= k; i++) {
    get(i, 1, n, 0, n);
  }
  printf("%d\n", dp[k][n] / 2);
  return 0;
}