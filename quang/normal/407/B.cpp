#include <bits/stdc++.h>

using namespace std;

const int N = 1010, MOD = 1000000007;

int n;
int p[N];
int dp[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
  }
  dp[1] = 2;
  for (int i = 2; i <= n; i++) {
    dp[i] = dp[i - 1] + 1;
    dp[i] = (1ll * dp[i] + dp[i] - dp[p[i] - 1] + MOD) % MOD;
  }
  cout << dp[n] << endl;
  return 0;
}