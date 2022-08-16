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

		vector<int> a(n);
		for (auto &x : a) cin >> x;

		map<long long, int> mp; mp[0] = -1;
		long long sum = 0;
		for (int i = 0; i < n; i++) {
			sum += a[i];
			if (mp.find(sum) == mp.end()) {
				mp[sum] = i;
			}
		}

		vector<pair<long long, int>> v(mp.begin(), mp.end());

		for (int i = int(v.size()) - 2; i >= 0; i--) {
			v[i].second = min(v[i].second, v[i + 1].second);
		}

		auto search = [&](long long sum) -> int {
			if (sum > v.back().first)
				return -1;
			int lo = 0, hi = int(v.size()) - 1;
			while (lo < hi) {
				int mid = lo + (hi - lo) / 2;
				if (v[mid].first >= sum)
					hi = mid;
				else lo = mid + 1;
			}
			return lo;
		};

		int x;
		while (m--) {
			cin >> x;
			auto lb = search(x);
			if (lb != -1) {
				cout << v[lb].second << ' ';
			} else if (sum <= 0) {
				cout << -1 << ' ';
			} else {
				long long iter = x / sum;
				long long ans = iter * n + v[search(x % sum)].second;
				if ((x - v.back().first + sum - 1) / sum < x / sum) {
					int lo = 0, hi = int(v.size()) - 1;
					while (lo < hi) {
						int mid = lo + (hi - lo) / 2;
						long long mx = v[mid].first;
						if ((x - mx + sum - 1) / sum == (x - v.back().first + sum - 1) / sum) {
							hi = mid;
						} else lo = mid + 1;
					}
					iter = (x - v[lo].first + sum - 1) / sum;
					ans = min(ans, iter * n + v[lo].second);
				}
				cout << ans << ' ';
			}
		}
		cout << '\n';
	}
	return 0;
}