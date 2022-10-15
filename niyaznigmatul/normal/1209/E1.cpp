/**
 * Niyaz Nigmatullin
 */

#include <bits/stdc++.h>

using namespace std;

void relax(vector<int> &ndp, vector<int> const &a, int shift) {
	int n = (int) a.size();
	for (int mask = 0; mask < 1 << n; mask++) {
		for (int i = 0; i < n; i++) {
			if (((mask >> i) & 1) == 1) continue;
			int nmask = mask | (1 << i);
			ndp[nmask] = max(ndp[nmask], ndp[mask] + a[(shift + i) % n]);
		}
	}
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<pair<int,vector<int>>> a(m, {0, vector<int>(n)});
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[j].second[i];
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			a[i].first = max(a[i].first, a[i].second[j]);
		}
	}
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	a.resize(min(m, n));
	m = (int) a.size();
	int const INF = 1 << 30;
	vector<int> dp(1 << n, -INF);
	dp[0] = 0;
	for (int i = 0; i < m; i++) {
		vector<int> ndp = dp;
		for (int shift = 0; shift < n; shift++) {
			vector<int> zdp = dp;
			relax(zdp, a[i].second, shift);
			for (int mask = 0; mask < 1 << n; mask++) {
				ndp[mask] = max(ndp[mask], zdp[mask]);
			}
		}
		dp.swap(ndp);
	}
	cout << dp[(1 << n) - 1] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}	
}