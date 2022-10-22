#include <bits/stdc++.h>
using namespace std;

int n, h, l, r, a[2000], dp[2001][2001]; //[ith sleep][how many -1s]

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> h >> l >> r;
	for (int i=0; i<n; ++i) {
		cin >> a[i];
	}

	int curr = a[0];
	dp[0][0] = (l<=a[0] && a[0]<=r);
	dp[0][1] = (l<=a[0]-1 && a[0]-1<=r);
	for (int i=1; i<n; ++i) {
		curr += a[i];
		dp[i][0] = dp[i-1][0] + (l<=curr%h && curr%h<=r);
		for (int j=1; j<=i+1; ++j) {
			dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + (l<=(curr-j)%h && (curr-j)%h<=r);
		}
	}
	int ans = 0;
	for (int i=0; i<=n; ++i)
		ans = max(ans, dp[n-1][i]);
	cout << ans;
	return 0;
}