#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a(n);
	for (auto &x : a) cin >> x;

	vector<int> temp = a;
	sort(temp.begin(), temp.end());
	temp.erase(unique(temp.begin(), temp.end()), temp.end());
	int sz = temp.size();

	for (auto &x : a) {
		x = lower_bound(temp.begin(), temp.end(), x) - temp.begin();
	}

	vector<int> cnt(sz);
	vector<vector<long long>> inv(sz, vector<long long>(sz));

	for (int i = 0; i < n; i++) {
		cnt[a[i]]++;
		for (int j = 0; j < sz; j++) {
			if (a[i] != j) {
				inv[a[i]][j] += cnt[j];
			}
		}
	}

	constexpr long long inf = (long long)1e15;

	vector<long long> dp(1 << sz, inf);
	dp[0] = 0;

	for (int mask = 0; mask < (1 << sz); mask++) {
		for (int i = 0; i < sz; i++) {
			if (mask >> i & 1) {
				continue;
			}
			long long sum = 0;
			for (int j = 0; j < sz; j++) {
				if (mask >> j & 1) {
					sum += inv[j][i];
				}
			}
			dp[mask | (1 << i)] = min(dp[mask | (1 << i)], sum + dp[mask]);
		}
	}
	cout << dp.back() << '\n';
	return 0;
}