#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<int> a(n);
	for (auto &x : a) cin >> x;

	vector<int> coord = a;
	sort(coord.begin(), coord.end());

	map<int, int> mp;
	for (int i = 0; i < n; i++) {
		mp[a[i]] = i;
	}

	auto recurse = [&](int x, int l, bool f = true) -> int {
		int idx;
		while (true) {
			if (f) {
				idx = lower_bound(coord.begin(), coord.end(), x - l) - coord.begin();
			} else {
				idx = upper_bound(coord.begin(), coord.end(), x + l) - coord.begin();
				idx -= 1;
			}
			if (coord[idx] != x) {
				int times = l / abs(coord[idx] - x);
				l %= abs(coord[idx] - x);
				if (times % 2 != 0) {
					x = coord[idx], f = !f;
				}
			} else {
				break;
			}
		}
		return mp[x] + 1;
	};

	while (m--) {
		int i, l;
		cin >> i >> l, --i;

		int x = upper_bound(coord.begin(), coord.end(), a[i] + l) - coord.begin();
		x -= 1;
		if (a[i] != coord[x]) {
			cout << recurse(coord[x], l - (coord[x] - a[i])) << '\n';
		} else {
			cout << recurse(a[i], l) << '\n';
		}
	}
	return 0;
}