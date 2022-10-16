#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll M = 998244353;

ll dp[503][503];

void init() {
	for (int i = 1; i <= 500; i++) {
		dp[0][i] = 1;
	}
	for (int k = 0; k <= 500; k++) {
		for (int j = 1; j <= 500; j++) {
			for (int i = k+1; i <= k + j && i <= 500; i++) {
				dp[i][j] = (dp[i][j] + dp[k][j]) % M;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	init();
	
	int n, k; 
	cin >> n >> k;
	
	ll ans = 0;
	for (int i = 1; i < k && i <= n; i++) {
		ll h = min((k - 1)/i, n);
		
		ll x = (dp[n][i] - dp[n][i-1] + M) % M;
		ans += (2*x*dp[n][h]) % M;
		ans %= M;
	}
	cout << ans;
	
	return 0;
}