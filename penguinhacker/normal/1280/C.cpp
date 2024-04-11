#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, sub[200000];
vector<ar<int, 2>> adj[200000];

ll ans1, ans2;
void dfs(int u=0, int p=-1) {
	sub[u]=1;
	for (ar<int, 2> v: adj[u]) if (v[0]!=p) {
		dfs(v[0], u);
		if (sub[v[0]]&1)
			ans1+=v[1];
		ans2+=1ll*v[1]*min(sub[v[0]], n-sub[v[0]]);
		sub[u]+=sub[v[0]];
	}
}

void solve() {
	cin >> n, n*=2;
	for (int i=0; i<n; ++i)
		adj[i].clear();
	for (int i=1; i<n; ++i) {
		int a, b, c; cin >> a >> b >> c, --a, --b;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}
	ans1=ans2=0;
	dfs();
	cout << ans1 << " " << ans2 << "\n";
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