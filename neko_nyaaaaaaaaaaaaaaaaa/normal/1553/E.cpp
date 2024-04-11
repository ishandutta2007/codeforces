#include <bits/stdc++.h>
using namespace std;

bool test(int n, int m, vector<int> p, int k) {
	rotate(p.begin(), p.begin()+k, p.end());

	vector<int> vis(n);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			ans++;
			int x = i;
			while (!vis[x]) {
				vis[x] = 1;
				x = p[x];
			}
		}
	}
	ans = n-ans;

	if (m < ans) return 0;
	else return 1;
}

void solve() {
	int n, m; cin >> n >> m;
	vector<int> p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i]; p[i]--;
	}

	vector<int> cds;
	if (n <= 1000) {
		for (int i = 0; i <= n-1; i++) {
			cds.push_back(i);
		}
	} else {
		map<int, int> kc;
		vector<int> pos(n);
		for (int i = 0; i < n; i++) {
			pos[p[i]] = i;
		}
		for (int i = 0; i < n; i++) {
			if (pos[i] == i) kc[0]++;
			else if (pos[i] > i) kc[abs(pos[i] - i)]++;
			else kc[n - abs(pos[i] - i)]++;
		}

		for (auto [u, v]: kc) {
			if (v >= n/3) cds.push_back(u);
		}
	}

	vector<int> ans;
	for (int i: cds) {
		if (test(n, m, p, i)) {
			ans.push_back(i);
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << ' ';
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