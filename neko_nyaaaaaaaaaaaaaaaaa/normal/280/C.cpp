#include <bits/stdc++.h>
using namespace std;

int n; 
vector<int> adj[100005];
double ans = 0;

void dfs(int now, int prev, int d) {
	ans += 1.0/d;
	for (auto u: adj[now]) {
		if (u != prev) dfs(u, now, d+1);
	}
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i < n; i++) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(1, 0, 1);

	cout << fixed << setprecision(12) << ans;
	
	return 0;
}