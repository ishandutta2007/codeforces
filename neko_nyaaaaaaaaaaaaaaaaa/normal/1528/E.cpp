#include <bits/stdc++.h>
using namespace std;

#define int long long
const int M = 998244353;

int modpow(int n, int k) {
	int ans = 1;
	while (k) {
		if (k % 2) ans = (ans*n) % M;
		n = (n*n) % M; k /= 2;
	}
	return ans;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n; cin >> n;
	if (n == 1) {
		cout << "5\n";
		exit(0);
	}
	vector<int> dp(n+1);
	vector<int> pref(n+1);

	dp[0] = pref[0] = 1;
	dp[1] = 2; pref[1] = 3;
	for (int i = 2; i <= n; i++) {
		dp[i] = (dp[i] + dp[i-1]) % M;
		dp[i] = (dp[i] + dp[i-1]*pref[i-2]) % M;
		dp[i] = (dp[i] + (dp[i-1]*(dp[i-1] + 1) % M)*modpow(2, M-2)) % M;

		pref[i] = (pref[i-1] + dp[i]) % M;
	}

	int ans = 0;
	ans = (ans + dp[n]) % M;
	{
		int tmp = dp[n-1]; 
		tmp = (tmp*pref[n-2]) % M;
		tmp = (tmp*(pref[n-2] + 1)) % M;
		tmp = (tmp*modpow(2, M-2)) % M;

		ans = (ans + tmp) % M;
	}
	{
		int tmp = dp[n-1]; 
		tmp = (tmp*pref[n-2]) % M;
		tmp = (tmp*(dp[n-1] + 1)) % M;
		tmp = (tmp*modpow(2, M-2)) % M;

		ans = (ans + tmp) % M;
	}
	{
		int tmp = dp[n-1]; 
		tmp = (tmp*(dp[n-1] + 2)) % M;
		tmp = (tmp*(dp[n-1] + 1)) % M;
		tmp = (tmp*modpow(6, M-2)) % M;

		ans = (ans + tmp) % M;
	}
	ans = (ans*2) % M;
	ans = (ans + M - 1) % M;

	//cout << ans << '\n';

	for (int i = 0; i < n; i++) {
		int dp1 = (dp[i] + M - 1) % M;
		int dp2 = (n-i-1 == 0 ? 0 : (dp[n-i-1] - dp[n-i-2] + M) % M);
		ans = (ans + dp1*dp2) % M;
	}
	cout << ans << '\n';

	return 0;
}