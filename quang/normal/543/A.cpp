#include <bits/stdc++.h>

using namespace std;

const int N = 510;

int dp[2][N][N], cur, a[N];
int n, m, b, mod;


int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m >> b >> mod;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  cur = 1;
  dp[0][0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      for (int k = 0; k <= b; k++) {
        dp[cur][j][k] = dp[cur ^ 1][j][k];
        if (j && k >= a[i]) {
          dp[cur][j][k] += dp[cur][j - 1][k - a[i]];
        }
        if (dp[cur][j][k] >= mod) {
          dp[cur][j][k] -= mod;
        }
      }
    }
    cur ^= 1;
  }
  cur ^= 1;
  int res = 0;
  for (int i = 0; i <= b; i++) {
    res += dp[cur][m][i];
    if (res >= mod) {
      res -= mod;
    }
  }
  cout << res << endl;
  return 0;
}