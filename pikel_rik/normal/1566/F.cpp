#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		vector<int> a(n), l(m), r(m);
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < m; i++) cin >> l[i] >> r[i];

		sort(a.begin(), a.end());

		vector<int> ind(m);
		iota(ind.begin(), ind.end(), 0);
		ind.erase(remove_if(ind.begin(), ind.end(), [&](int i) {
			int j = lower_bound(a.begin(), a.end(), l[i]) - a.begin();
			return j != n && a[j] <= r[i];
		}), ind.end());

		sort(ind.begin(), ind.end(), [&](int i, int j) {
			return r[i] < r[j];
		});

		{
			m = (int) ind.size();
			vector<int> new_l(m), new_r(m);
			for (int i = 0; i < m; i++) {
				new_l[i] = l[ind[i]];
				new_r[i] = r[ind[i]];
			}
			l.swap(new_l);
			r.swap(new_r);
		}

		if (m == 0) {
			cout << 0 << '\n';
			continue;
		}

		vector<int> left(m), right(m);
		for (int i = 0; i < m; i++) {
			left[i] = lower_bound(a.begin(), a.end(), l[i]) - a.begin() - 1;
			right[i] = upper_bound(a.begin(), a.end(), r[i]) - a.begin();
		}

		vector<int> lefti(n), righti(n);
		for (int i = 0; i < n; i++) {
			lefti[i] = lower_bound(r.begin(), r.end(), a[i]) - r.begin() - 1;
			righti[i] = upper_bound(r.begin(), r.end(), a[i]) - r.begin();
		}

		vector<int> prefix(m);
		partial_sum(l.begin(), l.end(), prefix.begin(), [&](int x, int y) {
			return x > y ? x : y;
		});

		const long long inf = (long long)1e10;
		vector<array<long long, 2>> dp(m, {-1, -1});

		auto recurse = [&](int i, int f, const auto &self) -> long long {
			if (i == m) {
				return 0;
			} else if (dp[i][f] != -1) {
				return dp[i][f];
			} else if (right[i] == n) {
				return dp[i][f] = (1ll + f) * (prefix.back() - a[n - 1]);
			} else {
				long long &ans = (dp[i][f] = inf), cost;
				if (left[i] == -1 || righti[left[i]] == i) {
					cost = 0;
				} else {
					cost = (1ll + f) * (prefix[i - 1] - a[left[i]]);
				}
				if (righti[right[i]] != m && left[righti[right[i]]] != right[i]) {
					ans = min(ans, cost + a[right[i]] - r[i] + self(righti[right[i]], 0, self));
					ans = min(ans, cost + 2ll * (a[right[i]] - r[i]) + self(righti[right[i]], 0, self));
				} else {
					ans = min(ans, cost + a[right[i]] - r[i] + self(righti[right[i]], 1, self));
					ans = min(ans, cost + 2ll * (a[right[i]] - r[i]) + self(righti[right[i]], 0, self));
				}
				if (left[i] != -1) {
					if (i != lefti[right[i]]) {
						ans = min(ans, self(i + 1, f, self));
					} else {
						ans = min(ans, (1ll + f) * (prefix[i] - a[left[i]]) + self(i + 1, 0, self));
					}
				}
				return ans;
			}
		};

		cout << min(recurse(0, 0, recurse), recurse(0, 1, recurse)) << '\n';
	}
	return 0;
}