#include <bits/stdc++.h>
using namespace std;

#define int long long

int go(vector<int> a, vector<int> b) {
	// a first
	int bdou = min((int)b.size(), (int)a.size());
	int adou = min((int)b.size(), (int)a.size() - 1);

	int ans = 0;
	for (int i: a) ans += i;
	for (int i: b) ans += i;

	while (bdou--) {
		ans += b.back(); b.pop_back();
	}
	while (adou--) {
		ans += a.back(); a.pop_back();
	}
	return ans;
}

void solve() {
	int n; cin >> n;

	vector<int> a(n), b(n);
	for (int &i: a) cin >> i;
	for (int &i: b) cin >> i;

	vector<int> o, z;
	for (int i = 0; i < n; i++) {
		if (a[i]) o.push_back(b[i]);
		else z.push_back(b[i]);
	}

	if (o.empty()) {
		int ans = 0;
		for (int i: z) ans += i;
			cout << ans << '\n';
		return;
	}
	if (z.empty()) {
		int ans = 0;
		for (int i: o) ans += i;
			cout << ans << '\n';
		return;
	}

	sort(o.begin(), o.end());
	sort(z.begin(), z.end());

	cout << max(go(o, z), go(z, o)) << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}