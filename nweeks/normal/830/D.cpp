#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 401;
const int MOD = 1e9 + 7;
int dp[MAXN][MAXN];
int binom[MAXN][MAXN];

void init() {
  for (int lig = 0; lig < MAXN; ++lig) {
    binom[lig][lig] = binom[lig][0] = 1;
    for (int col = 1; col < lig; ++col) {
      binom[lig][col] = binom[lig - 1][col - 1] + binom[lig - 1][col];
      if (binom[lig][col] >= MOD)
        binom[lig][col] -= MOD;
    }
  }
}

int solve(int n, int k) {
  if (!k)
    return 1;
  if (n == 1)
    return k == 1;

  if (dp[n][k] != -1)
    return dp[n][k];
  dp[n][k] = 0;
  for (int i(0); i <= k; ++i)
    dp[n][k] += solve(n - 1, i) * solve(n - 1, k - i) % MOD * binom[k][i] % MOD;
  for (int i(0); i < k; ++i)
    dp[n][k] += k * solve(n - 1, i) % MOD * solve(n - 1, k - 1 - i) % MOD *
                binom[k - 1][i] % MOD;
  for (int i = 0; i < k; ++i) {
    dp[n][k] += 4 * k * solve(n - 1, i + 1) % MOD * solve(n - 1, k - 1 - i) %
                MOD * binom[k - 1][i] % MOD;
  }
  for (int i = 0; i < k; ++i) {
    dp[n][k] += 2 * k * solve(n - 1, i + 1) % MOD * solve(n - 1, k - i) % MOD *
                binom[k - 1][i] % MOD;
  }
  for (int i = 0; i < k; ++i) {
    dp[n][k] += 2 * k * solve(n - 1, i + 2) % MOD * solve(n - 1, k - 1 - i) %
                MOD * binom[k - 1][i] % MOD;
  }
  dp[n][k] %= MOD;
  return dp[n][k];
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  init();
  for (int i = 0; i < MAXN; ++i) {
    for (int k = 0; k < MAXN; ++k) {
      dp[i][k] = -1;
    }
  }
  int n;
  cin >> n;
  cout << solve(n, 1) << endl;
}