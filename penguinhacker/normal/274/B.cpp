#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=100000;
int n;
vector<int> adj[mxN];
ll ans=0, a[mxN];

/*ll dfs(int u=0, int p=-1) {
	ll mn=0, mx=0, add=0;
	for (int v : adj[u]) {
		if (v==p) continue;
		add+=dfs(v, u);
		mn=min(mn, a[v]);
		mx=max(mx, a[v]);
	}
	add+=-mx-mn;
	a[u]+=add;
	ans+=mx-mn;
	return add;
}*/

pair<ll, ll> dfs(int u=0, int p=-1) {
	ll add=0, sub=0;
	for (int v : adj[u]) {
		if (v==p) continue;
		pair<ll, ll> p=dfs(v, u);
		add=max(add, p.first);
		sub=max(sub, p.second);
	}
	a[u]+=add-sub;
	if (a[u]>0) sub+=a[u];
	else add-=a[u];
	return {add, sub};
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0, u, v; i<n-1; ++i) {
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i=0; i<n; ++i)
		cin >> a[i];
	pair<ll, ll> p=dfs();
	cout << p.first+p.second;
	//ans+=abs(a[0]);
	//cout << ans;
	return 0;
}