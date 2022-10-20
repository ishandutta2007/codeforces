#include <bits/stdc++.h>

using namespace std;

const int N = 210, K = 1010, MOD = 1000000007;

inline int add(int u, int v) {
  u += v;
  if (u >= MOD) {
    u -= MOD;
  }
  return u;
}

int n, k;
int a[N];
int dp[2][N][K];

int main() {
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  sort(a + 1, a + n + 1);
  dp[0][0][0] = 1;
  int cur = 0;
  for (int i = 0; i < n; i++) {
    int next = cur ^ 1;
    memset(dp[next], 0, sizeof dp[next]);
    for (int j = 0; j <= i; j++) {
      for (int kk = 0; kk <= k; kk++) {
        int sum = kk + j * (a[i + 1] - a[i]);
        if (sum > k) {
          continue;
        }
        dp[next][j + 1][sum] = add(dp[next][j + 1][sum], dp[cur][j][kk]);
        if (j) {
          dp[next][j - 1][sum] = add(dp[next][j - 1][sum], 1ll * dp[cur][j][kk] * j % MOD);
        }
        dp[next][j][sum] = add(dp[next][j][sum], 1ll * dp[cur][j][kk] * (j + 1) % MOD);
      }
    }
    cur ^= 1;
  }
  int res = 0;
  for (int i = 0; i <= k; i++) {
    res = add(res, dp[cur][0][i]);
  }
  cout << res << endl;
  return 0;
}