#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;
vector<int> v(123457);
vector<int> at;
vector<int> a(123457);
vector<vector<int>> adj(123457);
vector<int> dist(123457);

int dfs(int now, int prev, int ds) {
	if (prev != -1) {
		dist[now] = dist[prev] + 1;
	}
	
	for (int u: adj[now]) {
		if (u == prev) continue;
		ds |= dfs(u, now, 0);
	}
	ds |= a[now];
 	if (ds == 0) {v[now] = 1;} 
	return ds;
}

void dfs2(int now, int prev) {
	if (prev != -1) {dist[now] = dist[prev] + 1;}
	
	for (int u: adj[now]) {
		if (u != prev) dfs2(u, now);
	}
}

int main() {
	ios::sync_with_stdio(0);

	cin >> n >> m;
	at.resize(m);
	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for (int i = 0; i < m; i++) {
		cin >> at[i];
		a[at[i]] = 1;
	}
	if (m == 1) {cout << at[0] << "\n" << 0; return 0;}
	
	dfs(at[0], -1, 0);
	
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (dist[i] > dist[ans] && !v[i]) {ans = i;}
	}
	
	for (int i = 1; i <= n; i++) {
		dist[i] = 0;
	}
	dfs2(ans, -1);
	
	int tmp = ans;
	for (int i = 1; i <= n; i++) {
		if (v[i]) continue;
		if (dist[i] > dist[ans]) {
			ans = i;
		} else if (dist[i] == dist[ans]) {
			ans = min(ans, i);
		}
	}
	
	ll ss = -2;
	for (int i = 1; i <= n; i++) {
		if (!v[i]) {ss += 2;}
	}
	ss -= dist[ans];
	
	cout << min(tmp, ans) << '\n' << ss;

	return 0;
}