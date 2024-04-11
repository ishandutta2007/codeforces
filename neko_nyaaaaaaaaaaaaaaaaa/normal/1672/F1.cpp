#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
	int n; cin >> n;
	vector<pair<int, int>> a(n);
	map<int, int> mp;
	int mx = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i].first; a[i].second = i;
		mp[a[i].first]++; mx = max(mx, mp[a[i].first]);
	}
	sort(a.begin(), a.end());

	vector<int> p;
	for (int i = 0; i < n; i++) {
		p.push_back(a[i].second);
	}
	rotate(a.begin(), a.begin()+mx, a.end());

	vector<int> ans(n);
	for (int i = 0; i < n; i++) {
		ans[p[i]] = a[i].first;
	}

	for (int i: ans) cout << i << ' ';
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