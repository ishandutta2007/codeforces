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

		vector<int> p(n + 1);
		iota(p.begin(), p.end(), 0);

		for (int i = 0; i < n; i++) {
			if (a[i] == 1) {
				p[i] = i + 1;
			}
		}

		auto find = [&](int x, const auto &self) -> int {
			return x == p[x] ? x : p[x] = self(p[x], self);
		};

		long long ans = 0;
		auto go = [&](int i) -> void {
			ans += 1;
			for (int j = i; j < n;) {
				if (a[j] > 2) {
					j += a[j]--;
				} else if (a[j] == 2) {
					a[j] -= 1, p[j] = j + 1;
					j += 2;
				} else {
					j = find(j, find);
				}
			}
		};

		for (int i = 0; i < n; i++) {
			if (a[i] > n - i) {
				ans += a[i] - n + i;
				a[i] = n - i;
			}
			while (a[i] > 1) {
				go(i);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}