#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
const int mxN=2e5+1;

int n, a[mxN], b[mxN], c[mxN], cnt0[mxN], cnt1[mxN]; //cnt is number of unpaired 0s and 1s
vector<int> adj[mxN];

ll ans=0;
void dfs(int u=1, int p=-1) {
	if (b[u]!=c[u]) {
		b[u]?++cnt0[u]:++cnt1[u];
	}
	for (int v : adj[u]) {
		if (v!=p) {
			a[v]=min(a[v], a[u]);
			dfs(v, u);
			cnt0[u]+=cnt0[v];
			cnt1[u]+=cnt1[v];
		}
	}
	int k=min(cnt0[u], cnt1[u]);
	cnt0[u]-=k;
	cnt1[u]-=k;
	ans+=2ll*k*a[u];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=1; i<=n; ++i)
		cin >> a[i] >> b[i] >> c[i];
	for (int i=1, u, v; i<n; ++i) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	if (count(b+1, b+n+1, 1)!=count(c+1, c+n+1, 1)) {
		cout << -1;
		return 0;
	}
	dfs();
	cout << ans << '\n';
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/