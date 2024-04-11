#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
	int n; cin >> n;
	vector<int> a(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int mn = *min_element(a.begin()+1, a.end());
	int mn_id = min_element(a.begin()+1, a.end()) - a.begin();

	int cnt = 0;
	stringstream ss;
	for (int i = 1; i <= n; i++) {
		if (i == mn_id) continue;

		int ds = abs(i - mn_id) % 2;
		int val = mn + ds;

		ss << i << ' ' << mn_id << ' ' << val << ' ' << mn << '\n';
		cnt++;
	}
	cout << cnt << '\n' << ss.str();
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}