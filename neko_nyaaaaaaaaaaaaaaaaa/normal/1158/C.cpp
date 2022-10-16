#include <bits/stdc++.h>
using namespace std;

int cur, hasans, ptr;
vector<int> adj[500004];
vector<int> ans(500004);

void dfs(int now) {
	cur--;
	for (auto u: adj[now]) {
		if (u == cur) {
			dfs(u);
		} else {
			hasans = 0;
		}
	}
	ans[ptr++] = now;
}

void solve() {
	int n; cin >> n;
	for (int i = 1; i <= n+1; i++) {
		adj[i].clear();
		ans[i] = 0;
	}

	cur = n+1, hasans = 1, ptr = 1;
	vector<int> a(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == -1) a[i] = i+1;
	}

	for (int i = 1; i <= n; i++) {
		adj[a[i]].push_back(i);
	}
	for (int i = 1; i <= n+1; i++) {
		sort(adj[i].begin(), adj[i].end(), greater<int>());
	}

	dfs(n+1);

	if (!hasans) {
		cout << "-1\n";
	} else {
		vector<int> res(n+1);
		for (int i = 1; i <= n; i++) {
			res[ans[i]] = i;
		}

		for (int i = 1; i <= n; i++) {
			cout << res[i] << ' ';
		}
		cout << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}