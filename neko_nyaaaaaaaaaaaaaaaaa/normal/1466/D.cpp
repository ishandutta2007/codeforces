#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAX = 100001;

int n, w[MAX];
vector<int> adj[MAX];

void input() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		adj[i].clear();
		cin >> w[i];
	}
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}

void solve() {
	vector<int> s;
	int ans = 0;

	for (int i = 1; i <= n; i++) {
		ans += w[i];
		int deg = adj[i].size() - 1;
		while (deg--) {
			s.push_back(w[i]);
		}
	}
	sort(s.begin(), s.end(), greater<int>());

	cout << ans;
	for (int i: s) {
		ans += i;
		cout << ' ' << ans;
	}
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		input();
		solve();
	}

	return 0;
}