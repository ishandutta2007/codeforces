#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
	int n; cin >> n;
	vector<int> b(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}

	vector<vector<int>> adj(n+1);
	int mn = 0, mx = n+1;
	for (int i = 1; i <= n; i++) {
		int l = min(i, b[i]);
		int r = max(i, b[i]);
		// threshold is within [i, b[i])

		mn = max(mn, l);
		mx = min(mx, r);

		if (b[i] == 0 || b[i] == n+1) continue;
		adj[b[i]].push_back(i);
	}
	int k = mn;
	cout << k << '\n';

	vector<vector<int>> groups(1);
	vector<int> last;
	for (int i = 1; i <= n; i++) {
		if (b[i] == 0 || b[i] == n+1) {
			groups[0].push_back(i);
		}
	}

	for (int i = 0; ; i++) {
		vector<int> nxt_group;
		int ls = 0;
		for (int u: groups[i]) {
			for (int v: adj[u]) {
				nxt_group.push_back(v);
				ls = u;
			}
		}
		if (nxt_group.empty()) break;
		groups.push_back(nxt_group);
		last.push_back(ls);
	}

	for (int i = 0; i < groups.size(); i++) {
		if (i == last.size()) {
			for (int j: groups[i]) cout << j << ' ';
		} else {
			for (int j: groups[i]) if (j != last[i]) cout << j << ' ';
			for (int j: groups[i]) if (j == last[i]) cout << j << ' ';
		}
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