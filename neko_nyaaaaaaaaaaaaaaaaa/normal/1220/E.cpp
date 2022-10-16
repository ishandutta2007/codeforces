#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, m; 
vector<int> w(200001);	
vector<int> adj[200001];
vector<int> remov(200001);
vector<int> deg(200001);
vector<int> dp(200001);
 
signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> w[i];
	}
	while (m--) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
		deg[x]++; deg[y]++;
	}
	int s; cin >> s;
 
	vector<int> d1;
	for (int i = 1; i <= n; i++) {
		if (deg[i] == 1) d1.push_back(i);
	}
 
	while (d1.size()) {
		int x = d1.back(); d1.pop_back();
		if (x == s) continue;
 
		remov[x] = 1;
		for (int u: adj[x]) {
			if (!remov[u]) {
				deg[u]--;
				dp[u] = max(dp[u], w[x] + dp[x]);
				if (deg[u] == 1) {
					d1.push_back(u);
				}
			}
		}
	}
 
	int ans = 0, mx = 0;
	for (int i = 1; i <= n; i++) {
		if (!remov[i]) {
			ans += w[i];
			mx = max(mx, dp[i]);
		}
	}
	cout << ans + mx << '\n';
 
	return 0;
}