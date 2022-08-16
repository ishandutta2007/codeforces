#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;

	vector<int> t(n);
	vector<vector<int>> a(n);
	vector<ll> sum(n);

	for (int i = 0; i < n; i++) {
		cin >> t[i];
		a[i].resize(t[i]);
		for (int j = 0; j < t[i]; j++) {
			cin >> a[i][j];
		}
		if (t[i] > k) {
			a[i].resize(k);
		}
		sum[i] = accumulate(a[i].begin(), a[i].end(), 0ll);
	}

	ll ans = 0;
	auto recurse = [&](int l, int r, vector<ll> dp, const auto &self) -> void {
		if (l == r) {
			ll cur = 0;
			for (int i = 0; i < t[l] && k - i - 1 >= 0; i++) {
				cur += a[l][i];
				ans = max(ans, cur + dp[k - i - 1]);
			}
			return;
		}

		int mid = (l + r) >> 1;
		vector<ll> dpl = dp, dpr = dp;

		for (int j = l; j <= mid; j++) {
			for (int i = k; i >= 0; i--) {
				if (i + t[j] <= k) {
					dpl[i + t[j]] = max(dpl[i + t[j]], dpl[i] + sum[j]);
				}
			}
		}

		for (int j = mid + 1; j <= r; j++) {
			for (int i = k; i >= 0; i--) {
				if (i + t[j] <= k) {
					dpr[i + t[j]] = max(dpr[i + t[j]], dpr[i] + sum[j]);
				}
			}
		}

		self(l, mid, dpr, self);
		self(mid + 1, r, dpl, self);
	};

	recurse(0, n - 1, vector<ll>(k + 1), recurse);
	cout << ans << '\n';
	return 0;
}