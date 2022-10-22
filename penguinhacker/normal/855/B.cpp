#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll n, p, q, r, a[100000], dp[100000][3];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> p >> q >> r;
	for (int i=0; i<n; ++i)
		cin >> a[i];

	dp[0][0] = p*a[0];
	for (int i=1; i<n; ++i)
		dp[i][0] = max(dp[i-1][0], p*a[i]);
	dp[0][1] = dp[0][0] + q*a[0];
	for (int i=1; i<n; ++i)
		dp[i][1] = max(dp[i-1][1], dp[i][0]+q*a[i]);
	dp[0][2] = dp[0][1] + r*a[0];
	for (int i=1; i<n; ++i)
		dp[i][2] = max(dp[i-1][2], dp[i][1]+r*a[i]);
	cout << dp[n-1][2];
	return 0;
}