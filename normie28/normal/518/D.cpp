#include <bits/stdc++.h>
using namespace std;
 
const long long MAX_N = 2e3 + 6;
int n, t;
double p;
double dp[MAX_N][MAX_N];
 
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> p >> t;
	for (int i = 0; i <= t; i++)
		dp[0][i] = 0;
	for (int i = 1; i <= n; i++) {
		dp[i][0] = 0;
		for (int j = 1; j <= t; j++)
			dp[i][j] = (1 - p) * dp[i][j - 1] + p * (1 + dp[i - 1][j - 1]);
	}
	cout << fixed << setprecision(1000) << dp[n][t] << "\n";
}