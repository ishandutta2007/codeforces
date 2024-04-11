#include <bits/stdc++.h>

using namespace std;

const int N = 3010;
const int MOD = 1000000007;

int n, m;
char a[N][N];
int dp[N][N];

void add(int &u, int v) {
  u += v;
  if (u >= MOD) {
    u -= MOD;
  }
}

void dfs(int u, int v) {
  memset(dp, 0, sizeof dp);
  dp[u][v] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == '#') {
        dp[i][j] = 0;
        continue;
      }
      if (i > 1) {
        add(dp[i][j], dp[i - 1][j]);
      }
      if (j > 1) {
        add(dp[i][j], dp[i][j - 1]);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> (a[i] + 1);
  }
  int A, B, C, D;
  dfs(2, 1);
  A = dp[n][m - 1];
  B = dp[n - 1][m];
  dfs(1, 2);
  C = dp[n][m - 1];
  D = dp[n - 1][m];
  A = 1ll * A * D % MOD;
  B = 1ll * B * C % MOD;
  cout << (1ll * A - B + MOD) % MOD << endl;
  return 0;
}