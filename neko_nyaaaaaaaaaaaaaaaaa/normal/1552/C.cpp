#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, k; cin >> n >> k;
	vector<pair<int, int>> e;
	for (int i = 0; i < k; i++) {
		int x, y; cin >> x >> y;
		e.emplace_back(x, y);
	}

	set<int> st;
	for (int i = 1; i <= 2*n; i++) {
		st.insert(i);
	}
	for (auto [u, v]: e) {
		st.erase(u);
		st.erase(v);
	}

	vector<int> s(st.begin(), st.end());
	int nk = s.size();
	for (int i = 0; i*2 < nk; i++) {
		e.emplace_back(s[i], s[i+nk/2]);
	}

	int ans = 0;
	for (auto [u1, v1]: e) {
		for (auto [u2, v2]: e) {
			if (u1 == u2) continue;

			if (u1 > v1) swap(u1, v1);
			int inside = 0;
			if (u2 > u1 && u2 < v1) inside++;
			if (v2 > u1 && v2 < v1) inside++;

			if (inside == 1) ans++;
		}
	}
	cout << ans/2 << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}