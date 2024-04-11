#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int MOD = 998244353;
int n, k;
vector<vector<int>> dp, ndp;
ll sum[501];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	dp.assign(n + 1, vector<int>(n + 1));
	dp[1][1] = 2;
	for (int r = 2; r <= n; ++r) {
		ndp.assign(n + 1, vector<int>(n + 1));
		for (int i = 1; i < r; ++i) {
			ndp[i + 1][i + 1] = (ndp[i + 1][i + 1] + dp[i][i]) % MOD;
			ndp[i][1] = (ndp[i][1] + dp[i][i]) % MOD;
			for (int j = 1; j < i; ++j) {
				ndp[i][j + 1] = (ndp[i][j + 1] + dp[i][j]) % MOD;
				ndp[i][1] = (ndp[i][1] + dp[i][j]) % MOD;
			}
		}
		swap(dp, ndp);
	}
	for (int i = 1; i <= n; ++i)
		sum[i] = accumulate(dp[i].begin(), dp[i].end(), 0ll) % MOD;
	ll ans = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (i * j < k)
				ans = (ans + sum[i] * sum[j]) % MOD;
	ans = ans * (MOD + 1) / 2 % MOD;
	cout << ans;
	return 0;
}