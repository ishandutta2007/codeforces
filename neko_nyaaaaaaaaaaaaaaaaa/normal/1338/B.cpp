#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> adj[100005];

vector<int> lf;
vector<int> col(100005);

void dfs(int now, int prev) {
	col[now] = col[prev] ^ 1;
	if (adj[now].size() == 1) lf.push_back(now);
	for (int u: adj[now]) {
		if (u != prev) dfs(u, now);
	}
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	for (int i = 1; i < n; i++) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(1, 0);

	// min
	int mn_ans = 1;
	int cl = col[lf[0]];
	for (int i: lf) {
		if (col[i] != cl) {
			mn_ans = 3;
		}
	}

	// max
	int mx_ans = n-1;
	set<int> s;
	for (int i: lf) {
		int u = adj[i][0];
		if (s.find(u) == s.end()) {
			s.insert(u);
		} else {
			mx_ans--;
		}
	}

	cout << mn_ans << ' ' << mx_ans << '\n';


	return 0;
}