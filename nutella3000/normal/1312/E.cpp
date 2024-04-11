#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
 
using namespace std;
const int inf = 1e15 + 7;
const int max_n = 2e5;
int n;
int a[max_n];

void solve() {
	cin >> n;
	for(int i = 0;i < n;i++) cin >> a[i];


	int dp[n][n], Min[n][n];
	for(int i = 0;i < n;i++) {
		for(int j = 0;j < n;j++) {
			dp[i][j] = inf;
			Min[i][j] = inf;
		}
	}

	for(int len = 0;len < n;len++) {
		for(int l = 0;l < n;l++) {
			int r = l + len;
			if (r >= n) break;

			if (l == r) {
				Min[l][r] = a[l];
				dp[l][r] = 1;
				continue;
			}
			//dp[l][r] = r - l + 1;
			for(int k = l;k < r;k++) {
				dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r]);
				if (dp[l][k] + dp[k + 1][r] == 2 && Min[l][k] == Min[k + 1][r]) {
					dp[l][r] = 1;
					Min[l][r] = Min[l][k] + 1;
				}
			}

			//cout << l << " " << r << " " << dp[l][r] << '\n';
		}
	}

	cout << dp[0][n - 1];	
}



signed main() {
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    solve();
}