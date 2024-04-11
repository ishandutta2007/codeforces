#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	ll n, p, q, r;
	cin >> n >> p >> q >> r;
	vector<vector<ll>> dp(3, vector<ll>(n));
	vector<ll> a(n);
	for (ll i = 0; i < n; i++) {
	      cin >> a[i];
	}
	dp[0][0] = a[0]*p;
	for (ll i = 1; i < n; i++) {
	      dp[0][i] = max(dp[0][i-1], a[i]*p);
	}
	dp[1][0] = dp[0][0] + a[0]*q;
	for (ll i = 1; i < n; i++) {
	      dp[1][i] = max(dp[1][i-1], dp[0][i] + a[i]*q);
	}
	dp[2][0] = dp[1][0] + a[0]*r;
	for (ll i = 1; i < n; i++) {
	      dp[2][i] = max(dp[2][i-1], dp[1][i] + a[i]*r);
	}
	cout << dp[2][n-1];
	
	return 0;
}