#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;
int n;
vector<int> adj[mxN];
vector<ar<int, 4>> ans;

ar<int, 3> dfs(int u=0) {
	if (adj[u].empty())
		return {-1, u, u};
	vector<ar<int, 3>> c;
	for (int v : adj[u]) {
		adj[v].erase(find(adj[v].begin(), adj[v].end(), u));
		c.push_back(dfs(v));
	}
	sort(c.begin(), c.end());
	while(c.size()>2||(c.size()==2&&c.back()[0]!=-1)) {
		ar<int, 3> a=c.back();
		c.pop_back();
		ar<int, 3> b=c.back();
		c.pop_back();
		if (a[0]==-1)
			a[0]=a[2];
		ans.push_back({u, a[2], a[0], b[1]});
		b[1]=a[1];
		c.push_back(b);
	}
	assert(c.size()&&c.size()<=2);
	if (c.size()==2) {
		assert(c[0][0]==-1&&c[1][0]==-1);
		return {c[0][1], c[1][1], u};
	}
	if (c[0][0]==-1)
		return {-1, c[0][1], u};
	ans.push_back({u, c[0][2], u, c[0][0]});
	return {-1, c[0][1], u};
}

void solve() {
	cin >> n;
	for (int i=1; i<n; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs();
	cout << ans.size() << "\n";
	for (ar<int, 4> a : ans)
		cout << a[0]+1 << " " << a[1]+1 << " " << a[2]+1 << " " << a[3]+1 << "\n";
	for (int i=0; i<n; ++i)
		adj[i].clear();
	ans.clear();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}