#include <bits/stdc++.h>

using namespace std;

const int N = 510, MOD = 1000000007;

int n, m;
char a[N][N], b[N][N];
int dp[2][N][N];
int res = 0;

int main() {
  ios_base::sync_with_stdio(0);
  #ifdef Doflamingo
  freopen("input", "r", stdin);
  #endif // Doflamingo
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> (a[i] + 1);
  }
  int cur = 0, next;
  dp[0][1][m] = a[1][1] == a[n][m];
  for (int it = 1; it < (n + m) / 2; it++) {
    next = cur ^ 1;
    for (int i = 1; i <= max(n, m); i++) {
      for (int j = 1; j <= max(n, m); j++) {
        dp[next][i][j] = 0;
      }
    }
    for (int j1 = 1; j1 <= max(n, m); j1++) {
      int i1 = it + 2 - j1;
      if (i1 < 1 || i1 > n) {
        continue;
      }
      for (int j2 = 1; j2 <= max(n, m); j2++) {
        int i2 = n + m - j2 - it;
        if (i2 < 1 || i2 > n) {
          continue;
        }
        if (a[i1][j1] != a[i2][j2]) {
          continue;
        }
        dp[next][j1][j2] = (dp[next][j1][j2] + dp[cur][j1][j2]) % MOD;
        dp[next][j1][j2] = (dp[next][j1][j2] + dp[cur][j1][j2 + 1]) % MOD;
        dp[next][j1][j2] = (dp[next][j1][j2] + dp[cur][j1 - 1][j2]) % MOD;
        dp[next][j1][j2] = (dp[next][j1][j2] + dp[cur][j1 - 1][j2 + 1]) % MOD;
      }
    }
    cur = next;
  }
  if ((n + m) & 1) {
    for (int i = 1; i <= max(n, m); i++) {
      res = (1ll * res + dp[cur][i][i] + dp[cur][i][i + 1]) % MOD;
    }
  } else {
    for (int i = 1; i <= max(n, m); i++) {
      res = (res + dp[cur][i][i]) % MOD;
    }
  }
  cout << res << endl;
  return 0;
}