#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n, m; cin >> n >> m;
	vector<int> b(n), g(m);
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> g[i];
	}
	sort(b.begin(), b.end(), greater<int>());
	sort(g.begin(), g.end(), greater<int>());

	if (b[0] > g.back()) {
		cout << -1;
		exit(0);
	}

	int bsum = 0;
	for (int i: b) {
		bsum += i;
	}

	int ans = 0;
	for (int i: g) {
		ans += bsum;
	}

	if (b[0] == g.back()) {
		for (int i: g) {
			ans -= b[0];
			ans += i;
		}
		cout << ans;
		exit(0);
	}

	for (int i = 0; i < m-1; i++) {
		ans -= b[0];
		ans += g[i];
	}
	ans -= b[1];
	ans += g[m-1];

	cout << ans;

	return 0;
}