#include <bits/stdc++.h>
using namespace std;
 
int n, ans;
vector<int> adj[100005];
vector<int> dp1(100005), dp2(100005);
 
pair<int, int> dfs(int now, int prev) {
	int t1 = 1, t2 = 0;
	for (auto u: adj[now]) {
		if (u != prev) {
			auto [f1, f2] = dfs(u, now);
			t1 = max(t1, f2 + 1);
			t2 = max(t2, f1);
			t2 = max(t2, f2); 
		}
	}
	t2 += max(0, (int)adj[now].size() - (now != 1) - 1);
 
	dp1[now] = t1;
	dp2[now] = t2;
 
	return make_pair(t1, t2);
}
 
void dfs2(int now, int prev, int t1p, int t2p) {
	int dg = adj[now].size() - 1;
 
	ans = max(ans, max(dp1[now], t2p + 1));
	ans = max(ans, max(dp2[now], max(t1p, t2p) + dg - (now != 1)));
 
	multiset<int> g1, g2;
	g1.insert(t2p); 
	g2.insert(max(t1p, t2p));
	for (int u: adj[now]) {
		if (u != prev) {
			g1.insert(dp2[u]);
			g2.insert(max(dp1[u], dp2[u]));
		}
	}
 
	for (int u: adj[now]) {
		if (u != prev) {
			g1.erase(g1.find(dp2[u]));
			int t1n = 0;
			if (g1.size()) t1n = max(t1n, *g1.rbegin());
			t1n++;
 
			g2.erase(g2.find(max(dp1[u], dp2[u])));
			int t2n = 0;
			if (g2.size()) t2n = max(t2n, *g2.rbegin());
			t2n += max(dg-1, 0);
 
			g1.insert(dp2[u]);
			g2.insert(max(dp1[u], dp2[u]));
 
			dfs2(u, now, t1n, t2n);
		}
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
	dfs(1, 0);
	dfs2(1, 0, 0, 0);
 
	cout << ans << '\n';
 
	return 0;
}