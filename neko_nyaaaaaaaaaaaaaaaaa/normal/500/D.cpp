#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;
vector<int> adj[100001];
vector<pair<int, int>> edge(100001);
vector<int> w(100001);
vector<int> sub(100001, 1);
vector<int> level(100001);
vector<int> c(100001);

void dfs(int now, int prev) {
	level[now] = level[prev] + 1;
	for (int u: adj[now]) {
		if (u != prev) {
			dfs(u, now);
			sub[now] += sub[u];
		}
	}
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(8);
	
	cin >> n;
	for (int i = 1; i < n; i++) {
		int x, y; cin >> x >> y >> w[i];
		adj[x].push_back(y);
		adj[y].push_back(x);
		edge[i] = {x, y};
	}
	dfs(1, 0);
	
	for (int i = 1; i < n; i++) {
		if (level[edge[i].first] < level[edge[i].second]) swap(edge[i].first, edge[i].second);
		
		int x = sub[edge[i].first], y = n - sub[edge[i].first];
		
		int s1 = x*y*(y-1)/2;
		int s2 = x*(x-1)*y/2;
		
		c[i] = (s1 + s2)*2;
	} 
	
	long double ans = 0;
	for (int i = 1; i < n; i++) {
		ans += w[i]*c[i];
	}
	
	int k = n*(n-1)*(n-2)/6;
	int q; cin >> q;
	while (q--) {
		int x, y; cin >> x >> y;
		ans -= w[x]*c[x];
		w[x] = y;
		ans += w[x]*c[x];
		
		cout << ans/k << '\n';
	}
	 
	return 0;
}