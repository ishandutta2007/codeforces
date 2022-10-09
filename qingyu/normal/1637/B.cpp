#include <bits/stdc++.h>

const int N = 105;
int a[N], mex[N][N];
long long dp[N];
bool vis[N];

int solve(int l, int r) {
	memset(dp, 0xcf, sizeof dp);
	dp[l - 1] = 0;
	for (int i = l; i <= r; ++i) {
		for (int j = l; j <= i; ++j)
			dp[i] = std::max(dp[i], dp[j - 1] + mex[j][i] + 1);
	}
	return dp[r];
}

int main() {
	std::ios::sync_with_stdio(false);
	int t;
	std::cin >> t;
	while (t--) {
		int n;
		std::cin >> n;
		for (int i = 1; i <= n; ++i)
			std::cin >> a[i];
		for (int l = 1; l <= n; ++l) {
			memset(vis, 0, sizeof vis);
			int p = 0;
			for (int r = l; r <= n; ++r) {
				if (a[r] <= n) {
					vis[a[r]] = true;
				}
				while (vis[p]) ++p;
				mex[l][r] = p;
			}
		}
		long long ans = 0;
		for (int l = 1; l <= n; ++l)
			for (int r = l; r <= n; ++r) {
				ans += solve(l, r);
			}
		std::cout << ans << '\n';
	}
}