#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, m, s, a[mxN];
bool vis[mxN]; //cov[mxN];
vector<int> adj[mxN];
ll ans=0, pos=0;

pair<ll, bool> dfs(int u, int p=-1) {
	vis[u]=1;
	ll sum=0;
	bool reach=0;
	for (int v : adj[u]) {
		if (vis[v]&&v!=p) {
			reach=1;
		}
	}
	for (int v : adj[u]) {
		if (!vis[v]) {
			pair<ll, bool> cur=dfs(v, u);
			reach|=cur.second;
			sum=max(sum, cur.first);
		}
	}
	if (reach) {
		ans+=a[u];
	}
	else {
		sum+=a[u];
	}
	return {sum, reach};
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		cin >> a[i];
	}
	for (int i=0; i<m; ++i) {
		int a, b; cin >> a >> b, --a, --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	cin >> s, --s;
	ans+=dfs(s).first;
	/*pair<ll, bool> p=dfs();
	cout << ans << " " << p.first << " " << p.second << "\n";
	ans+=p.first;*/
	cout << ans;
	return 0;
}