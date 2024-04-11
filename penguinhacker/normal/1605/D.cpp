#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, ans[mxN];
vector<int> adj[mxN], oc[2];

void dfs(int u=0, int p=-1, int par=0) {
	oc[par].push_back(u);
	for (int v : adj[u])
		if (v^p)
			dfs(v, u, par^1);
}

void solve() {
	cin >> n;
	for (int i=0; i<n; ++i)
		adj[i].clear();
	for (int i=1; i<n; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	//oc[0].clear();
	//oc[1].clear();
	dfs();
	for (int b=31-__builtin_clz(n); ~b; --b) {
		int p=oc[1].size()>oc[0].size();
		for (int i=1<<b; i<=min(n, (1<<b+1)-1); ++i) {
			assert(oc[p].size());
			//cout << oc[p].back() << " " << i << endl;
			ans[oc[p].back()]=i;
			oc[p].pop_back();
		}
	}
	assert(oc[0].empty()&&oc[1].empty());
	for (int i=0; i<n; ++i)
		cout << ans[i] << " ";
	cout << "\n";
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