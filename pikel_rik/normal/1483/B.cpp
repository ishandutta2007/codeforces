#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> a(n);
		for (auto &x : a) cin >> x;

		vector<int> next(n), prev(n), deleted(n);
		iota(next.begin(), next.end(), 1);
		iota(prev.begin(), prev.end(), -1);
		next[n - 1] = 0, prev[0] = n - 1;

		vector<int> p(n);
		iota(p.begin(), p.end(), 0);

		auto find = [&](int x, const auto &self) -> int {
			return x == p[x] ? x : p[x] = self(p[x], self);
		};

		vector<int> ans;

		for (int i = 1, c = 0; c < 2 * n && ans.size() < n - 1; i = next[find(i, find)], c++) {
			if (__gcd(a[i], a[prev[i]]) == 1) {
				ans.push_back(i), deleted[i] = 1;
				next[prev[i]] = next[i];
				prev[next[i]] = prev[i];
				i = next[i];
				c = 0;
			} else {
				p[prev[i]] = find(i, find);
			}
		}

		if (ans.size() == n - 1) {
			for (int i = 0; i < n; i++) {
				if (!deleted[i] && a[i] == 1) {
					ans.push_back(i);
				}
			}
		}

		cout << ans.size() << ' ';
		for (int x : ans) cout << x + 1 << ' ';
		cout << '\n';
	}
	return 0;
}