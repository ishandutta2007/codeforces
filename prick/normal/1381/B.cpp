#include <bits/stdc++.h>

using namespace std;

//#define int long long
#define sz(x) ((int) (x).size())

void chmin(int &x, int y) {
	x = min(x, y);
}

const int inf = 1e7;

int dp[4005][2005][2];

void solve() {
	int n;
	cin >> n;
	n *= 2;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	
	for (int taken = 0; taken <= n / 2; ++taken) {
		dp[0][taken][0] = dp[0][taken][1] = inf;
	}
	dp[0][0][0] = dp[0][0][1] = 0;
	
	for (int it = 0; it < n; ++it) {
		for (int taken = 0; taken <= n / 2; ++taken) {
			dp[it + 1][taken][0] = dp[it + 1][taken][1] = inf;
		}
		for (int taken = 0; taken <= n / 2; ++taken) {
			chmin(dp[it + 1][taken + 1][0], max(dp[it][taken][0], a[it]));
			if (a[it] > dp[it][taken][0]) {
				chmin(dp[it + 1][taken][1], a[it]);
			}
			chmin(dp[it + 1][taken][1], max(dp[it][taken][1], a[it]));
			if (a[it] > dp[it][taken][1]) {
				chmin(dp[it + 1][taken + 1][0], a[it]);
			}
		}
	}
	if (dp[n][n / 2][0] < inf || dp[n][n / 2][1] < inf) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}

signed main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		solve();
	}
}