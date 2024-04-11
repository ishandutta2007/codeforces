#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
	int n, m; cin >> n >> m;
	vector<pair<int, int>> p1;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		int cpy = 1;

		while (x % m == 0) {
			x /= m; cpy *= m;
		}

		if (p1.empty()) {
			p1.emplace_back(x, cpy);
		} else if (p1.back().first != x) {
			p1.emplace_back(x, cpy);
		} else {
			p1.back().second += cpy;
		}
	}

	int k; cin >> k;
	vector<pair<int, int>> p2;
	for (int i = 0; i < k; i++) {
		int x; cin >> x;
		int cpy = 1;

		while (x % m == 0) {
			x /= m; cpy *= m;
		}

		if (p2.empty()) {
			p2.emplace_back(x, cpy);
		} else if (p2.back().first != x) {
			p2.emplace_back(x, cpy);
		} else {
			p2.back().second += cpy;
		}
	}

	if (p1 == p2) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}