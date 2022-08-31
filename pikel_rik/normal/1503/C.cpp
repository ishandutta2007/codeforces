#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a(n), c(n);
	for (int i = 0; i < n; i++) cin >> a[i] >> c[i];

	vector<int> ind(n);
	iota(ind.begin(), ind.end(), 0);
	sort(ind.begin(), ind.end(), [&](int i, int j) {
		return a[i] < a[j];
	});

	vector<int> pos(n);
	for (int i = 0; i < n; i++) {
		pos[ind[i]] = i;
	}

	vector<int> lim(n);
	for (int i = 0; i < n; i++) {
		int &lo = lim[i], hi = n - 1;
		while (lo < hi) {
			int mid = lo + (hi - lo + 1) / 2;
			if (a[ind[mid]] - a[i] <= c[i]) {
				lo = mid;
			} else hi = mid - 1;
		}
	}

	vector<int> pref(n); pref[0] = ind[0];
	for (int i = 1; i < n; i++) {
		if (lim[ind[i]] > lim[pref[i - 1]]) {
			pref[i] = ind[i];
		} else pref[i] = pref[i - 1];
	}

	long long ans = accumulate(c.begin(), c.end(), 0ll);

	vector<long long> dp(n);
	vector<long long> suf_dp(n), pref_mx(n);

	for (int i = 0; i < n; i++) {
		pref_mx[i] = a[ind[i]] + c[ind[i]];
	}

	partial_sum(pref_mx.begin(), pref_mx.end(), pref_mx.begin(), [&](auto x, auto y) {
		return x > y ? x : y;
	});

	dp[n - 1] = accumulate(c.begin(), c.end(), 0ll);
	suf_dp[n - 1] = dp[n - 1] + a[ind[n - 1]];
	for (int j = n - 2; j >= 0; j--) {
		if (lim[pref[j]] == j) {
			dp[j] = suf_dp[j + 1] - pref_mx[j];
		} else {
			dp[j] = dp[lim[pref[j]]];
		}
		suf_dp[j] = min(a[ind[j]] + dp[j], suf_dp[j + 1]);
	}
	cout << dp.front() << '\n';
	return 0;
}