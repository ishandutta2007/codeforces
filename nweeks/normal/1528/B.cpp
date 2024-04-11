#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 1e6 + 1;
const int MOD = 998244353;

int dp[MAXN];
int prefSum[MAXN];
int diviseurs[MAXN];

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  dp[0] = 1, dp[1] = 1;
  for (int i(1); i < MAXN; ++i)
    for (int j(2 * i); j < MAXN; j += i)
      diviseurs[j]++;
  prefSum[1] = 2;

  for (int i(2); i < MAXN; ++i) {
    dp[i] = prefSum[i - 1] + diviseurs[i];
    dp[i] %= MOD;
    prefSum[i] = prefSum[i - 1] + dp[i];
    prefSum[i] %= MOD;
  }

  cout << dp[n] << endl;
}