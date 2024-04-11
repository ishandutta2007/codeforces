#include <bits/stdc++.h>
using namespace std;

int n, c;
int a[200000], b[200000];
int dp[200000][2];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> c;
	for (int i=1; i<n; ++i)
		cin >> a[i];
	for (int i=1; i<n; ++i)
		cin >> b[i];

	dp[0][0] = 0;
	dp[0][1] = c;

	for (int i=1; i<n; ++i) {
		dp[i][0] = a[i]+min(dp[i-1][0], dp[i-1][1]);
		dp[i][1] = min(dp[i-1][0]+b[i]+c, dp[i-1][1]+b[i]);
	}
	for (int i=0; i<n; ++i)
		cout << min(dp[i][0], dp[i][1]) << ' ';
	return 0;
}