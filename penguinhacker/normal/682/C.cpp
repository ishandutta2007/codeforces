#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, a[100000], sub[100000];
vector<pair<int, int>> adj[100000];

void dfs1(int u=0, int p=-1) {
	sub[u]=1;
	for (auto v:adj[u])
		if (v.first!=p) {
			dfs1(v.first, u);
			sub[u]+=sub[v.first];
		}
}

int ans=0;
void dfs2(int u=0, int p=-1, int l=0) { // <l is length of path>
	if (l>a[u]) {
		ans+=sub[u];
		return;
	}
	for (auto v:adj[u])
		if (v.first!=p)
			dfs2(v.first, u, max(l+v.second, v.second));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	for (int i=1, p, c; i<n; ++i) {
		cin >> p >> c, p--;
		adj[i].emplace_back(p, c);
		adj[p].emplace_back(i, c);
	}
	dfs1();
	dfs2();
	cout << ans;
	return 0;
}