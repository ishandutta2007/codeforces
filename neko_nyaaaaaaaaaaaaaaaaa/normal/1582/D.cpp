#include <bits/stdc++.h>
using namespace std;

#define int long long

pair<int, int> resolve(int x, int y) {
	return make_pair(-y, x);
}

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<int> ans(n);
	for (int i = 0; i+1 < n; i += 2) {
		auto [u, v] = resolve(a[i], a[i+1]);
		ans[i] += u; ans[i+1] += v;
	}

	if (n % 2) {
		auto [u, v] = resolve(a[n-2], a[n-1]);
		if (ans[n-2] + u == 0) {
			u *= -1; v *= -1;
		}
		ans[n-2] += u;
		ans[n-1] += v;	
	}

	for (int i = 0; i < n; i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}