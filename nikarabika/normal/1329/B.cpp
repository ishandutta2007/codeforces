//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const int maxn = 50,
      maxl = 50;

int solve() {
  LL d, Mod;
  cin >> d >> Mod;
  LL dp[maxn][maxl];
  dp[0][0] = 1;
  for (int j = 1; j < maxl; j++)
    dp[0][j] = dp[0][j - 1] * 2 % Mod;
  for (int i = 1; i < maxn; i++)
    for (int j = 0; j < maxl; j++) {
      dp[i][j] = 0;
      for (int k = 0; k < j; k++)
        dp[i][j] += dp[i - 1][k] * dp[0][j] % Mod;
      dp[i][j] %= Mod;
    }
  int dc = 31 - __builtin_clz(d);
  LL ans = d % Mod;
  for (int i = 0; i < maxn; i++)
    for (int j = 0; (1LL << (j + 1)) <= d; j++) {
      ans += (d - (1 << (j + 1)) + 1) * dp[i][j];
      ans %= Mod;
    }
  cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int q;
	cin >> q;
	while (q--)
		solve();
	return 0;
}