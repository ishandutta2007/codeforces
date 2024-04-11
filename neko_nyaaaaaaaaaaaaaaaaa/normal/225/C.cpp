#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m, x, y;
int cost[2][1008];
int pf[2][1008];
int dp[2][1008];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> m >> n >> x >> y;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			char c; cin >> c;
			if (c == '#') cost[0][j]++;
			else cost[1][j]++;
		}
	}
	
	for (int i = 1; i <= n+1; i++) {
		dp[0][i] = dp[1][i] = 1e9;
		pf[0][i] = pf[0][i-1] + cost[0][i];
		pf[1][i] = pf[1][i-1] + cost[1][i];
	}
	for (int i = 1; i < x; i++) {
		dp[0][i] = dp[0][i-1] + cost[0][i];
		dp[1][i] = dp[1][i-1] + cost[1][i];
	}
	
	for (int i = x; i <= n; i++) {
		for (int j = x; j <= y; j++) {
			if (i - j < 0) break;
			
			dp[0][i] = min(dp[0][i], dp[1][i-j] + pf[1][i] - pf[1][i-j]);
			dp[1][i] = min(dp[1][i], dp[0][i-j] + pf[0][i] - pf[0][i-j]);
		}
	}
	
	cout << min(dp[0][n], dp[1][n]);
	
	return 0;
}