#include <bits/stdc++.h>
using namespace std;

#define int long long

int solve(int n, int k, vector<int> a) {
	for (int i = 1; i <= n; i++) {
		a[i] += a[i-1];
	}	
	if (a[n] <= k) {
		return 1;
	}

	vector<int> nxt(n+1);
	int j = 1;
	for (int i = 1; i <= n; i++) {
		while (j <= n && a[j] - a[i-1] <= k) j++;
		nxt[i] = j;
	}

	vector<int> lst(n+1);
	vector<int> dp(n+1);
	for (int i = n; i >= 1; i--) {
		if (nxt[i] == n+1) {
			dp[i] = 1;
			lst[i] = a[n] - a[i-1];
		} else {
			dp[i] = dp[nxt[i]] + 1;
			lst[i] = lst[nxt[i]];
		}
	}

	int ans = dp[1];
	for (int i = 1; i < n; i++) {
		if (a[i] + lst[i+1] <= k) {
			ans = min(ans, dp[i+1]);
		}
	}
	return ans;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, q; cin >> n >> q;
	vector<int> a(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	while (q--) {
		int k; cin >> k;
		cout << solve(n, k, a) << '\n';
	}

	return 0;
}