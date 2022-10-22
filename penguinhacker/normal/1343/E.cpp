#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m, a, b, c, p[200000];
ll pref[200001];
vector<int> adj[200000];

void bfs(int s, vector<int> &d) {
	d[s]=0;
	queue<int> q;
	q.push(s);
	while(!q.empty()) {
		int u=q.front();
		q.pop();
		for (int v:adj[u])
			if (d[v]==1e9) {
				d[v]=d[u]+1;
				q.push(v);
			}
	}
}

void solve() {
	cin >> n >> m >> a >> b >> c, a--, b--, c--;
	for (int i=0; i<m; ++i)
		cin >> p[i];
	sort(p, p+m);
	for (int i=0; i<n; ++i)
		adj[i].clear();
	for (int i=1; i<=m; ++i)
		pref[i]=pref[i-1]+p[i-1];
	for (int i=0, u, v; i<m; ++i) {
		cin >> u >> v, u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int> da(n, 1e9), db(n, 1e9), dc(n, 1e9);
	bfs(a, da); bfs(b, db); bfs(c, dc);

	ll ans=1e18;
	for (int i=0; i<n; ++i) {
		if (da[i]+db[i]+dc[i]<=m)
			ans=min(ans, pref[da[i]+db[i]+dc[i]]+pref[db[i]]);
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	pref[0]=0;
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}