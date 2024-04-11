#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
	int n, m; cin >> n >> m;
	vector<pair<int, int>> p(m);
	for (int i = 0; i < m; i++) {
		cin >> p[i].first; p[i].second = -i;
	}
	sort(p.begin(), p.end());
	for (int i = 0; i < m; i++) {
		p[i].second *= -1;
	}

	int ans = 0;
	for (int i = 0; i < m; i++) {
		for (int j = i+1; j < m; j++) {
			if (p[i].second < p[j].second) ans++;
		}
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}