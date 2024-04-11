#include <bits/stdc++.h>
using namespace std;

#define int long long
const int M = 998244353;

long long modpow(long long n, long long k, long long MOD);

int dp[2005][5005];

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n, k; cin >> n >> k;
	if (k == 1) {
		cout << 0; exit(0);
	}
	// initially we have 2500 points
	// we want to end up with strictly higher
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];

		int ls = i-1;
		if (ls < 0) ls += n;

		b[ls] = a[i];
	}

	// how many arrays such that it strictly matches more in b than in a
	// pick the first number
	if (a[0] == b[0]) {
		// all choices yields 0 points
		dp[0][2500] = k % M;
	} else {
		// pick a[i] yields -1
		// pick b[i] yields +1
		// all others yield 0
		dp[0][2499] = dp[0][2501] = 1;
		dp[0][2500] = (k-2) % M; 
	}

	for (int i = 1; i < n; i++) {
		if (a[i] == b[i]) {
			for (int j = 1; j <= 5000; j++) {
				dp[i][j] = (dp[i-1][j]*k) % M;
			}
		} else {
			for (int j = 1; j <= 5000; j++) {
				dp[i][j] = (dp[i][j] + dp[i-1][j]*(k-2)) % M;
				dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % M;
				dp[i][j] = (dp[i][j] + dp[i-1][j+1]) % M;
			}
		}
	}

	int ans = 0;
	for (int i = 2501; i <= 5000; i++) {
		ans = (ans + dp[n-1][i]) % M;
	}
	cout << ans << '\n';

	return 0;
}

long long modpow(long long n, long long k, long long MOD) {
	long long ans = 1; n %= MOD;
	while (k > 0) {
		if (k & 1) ans = (ans*n) % MOD;
		k >>= 1; n = (n*n) % MOD;
	}
	return ans;
}