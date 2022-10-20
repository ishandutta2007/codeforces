#include <bits/stdc++.h>

using namespace std;

const int N = 510, MOD = 1000000007;

int n, k;
int Pow[N];
int dp[2][N][N];

int main() {
  cin >> n >> k;
  Pow[0] = 1;
  for (int i = 1; i <= n; i++) {
    Pow[i] = 1ll * Pow[i - 1] * 2 % MOD;
  }
  int cur = 0;
  dp[0][0][0] = 1;
  for (int i = 1; i <= n; i++) {
    int next = cur ^ 1;
    for (int j = 0; j < i; j++) {
      for (int last = 0; last < i; last++) {
        dp[next][j + 1][i] = (1ll * Pow[last] * (Pow[i - last] - 1) % MOD * dp[cur][j][last] + dp[next][j + 1][i]) % MOD;
        dp[next][j][last] = (1ll * Pow[last] * dp[cur][j][last] + dp[next][j][last]) % MOD;
        dp[cur][j][last] = 0;
      }
    }
    cur ^= 1;
  }
  int res = 0;
  for (int i = 0; i <= n; i++) {
    res = (1ll * res + dp[cur][k][i]) % MOD;
  }
  cout << res;
  return 0;
}