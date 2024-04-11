#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 51;
const int MAXK = 25 * 49 + 1;

int dp[MAXN][MAXK];  // dp[n][k] ...
int dp2[MAXN][MAXK]; // nb paires de perms sur n elem avec diff >= k
int fact[MAXN];
int binom[MAXN][MAXN];

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbElem, mod;
  cin >> nbElem >> mod;
  fact[0] = 1;
  for (int i = 1; i < MAXN; ++i)
    fact[i] = i * fact[i - 1] % mod;

  dp[0][0] = 1;
  for (int n = 1; n < MAXN; ++n)
    for (int k = 0; k <= n * (n - 1) / 2; ++k) {
      for (int i = 1; i <= n; ++i) {
        if (k - (i - 1) >= 0) {
          dp[n][k] += dp[n - 1][k - (i - 1)];
          if (dp[n][k] >= mod)
            dp[n][k] -= mod;
        }
      }
    }
  for (int lig = 0; lig < MAXN; ++lig) {
    binom[lig][0] = 1;
    for (int col = 1; col <= lig; ++col) {
      binom[lig][col] = binom[lig - 1][col] + binom[lig - 1][col - 1];
      if (binom[lig][col] >= mod)
        binom[lig][col] -= mod;
    }
  }

  for (int n = 0; n < MAXN; ++n)
    for (int diff = MAXK - 1; diff >= 0; --diff) {
      for (int invA = 0; invA + diff < MAXK; ++invA) {
        dp2[n][diff] += dp[n][invA] * dp[n][invA + diff] % mod;
        if (dp2[n][diff] >= mod)
          dp2[n][diff] -= mod;
      }
      if (diff < MAXK - 1) {
        dp2[n][diff] += dp2[n][diff + 1];
        if (dp2[n][diff] >= mod)
          dp2[n][diff] -= mod;
      }
    }

  int ret = 0;

  for (int take = 1; take <= nbElem; ++take) {
    int curRet = 0;
    for (int p0 = 1; p0 < take; ++p0)
      for (int q0 = p0 + 1; q0 <= take; ++q0) {
        curRet += dp2[take - 1][q0 - p0 + 1] * binom[nbElem][take] % mod *
                  fact[nbElem - take] % mod;
        if (curRet >= mod)
          curRet -= mod;
      }
    // cout << take << ' ' << curRet << endl;
    ret += curRet;
    if (ret >= mod)
      ret -= mod;
  }
  cout << ret << endl;
}