#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	ll n, m;
	cin >> n >> m;
	vector<vector<ll>> a(n, vector<ll>(m));
	for (ll i = 0; i < n; i++) {
	      for (ll j = 0; j < m; j++) {
	            cin >> a[i][j];
	      }
	}
	vector<vector<ll>> dp(n, vector<ll>(m));
	dp[0][0] = a[0][0];
	for (ll i = 1; i < n; i++) {
	      dp[i][0] = a[i][0] + dp[i-1][0];
	}
	for (ll i = 1; i < m; i++) {
	      dp[0][i] = dp[0][i-1] + a[0][i];
	}
	for (ll i = 1; i < n; i++) {
	      for (ll j = 1; j < m; j++) {
	            dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + a[i][j];
	      }
	}
	for (ll i = 0; i < n; i++) {
	      cout << dp[i][m-1] << " ";
	}
	
}