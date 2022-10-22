#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5, M=1e9+7;
int n, x[mxN], y[mxN], vis[mxN], p[2*mxN+1];
map<int, vector<ar<int, 2>>> mp1, mp2;
vector<int> adj[mxN];
set<int> sx, sy;
ll ans=1;

bool dfs(int u, int p=-1) {
	vis[u]=1;
	sx.insert(x[u]);
	sy.insert(y[u]);
	bool cyc=0;
	for (int v : adj[u]) {
		if (v==p)
			continue;
		if (!vis[v])
			cyc|=dfs(v, u);
		else if (vis[v]==1)
			cyc=1;
	}
	vis[u]=2;
	return cyc;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> x[i] >> y[i];
		mp1[x[i]].push_back({y[i], i});
		mp2[y[i]].push_back({x[i], i});
	}
	for (auto& mp : {mp1, mp2}) {
		for (auto& x : mp) {
			vector<ar<int, 2>> v=x.second;
			sort(v.begin(), v.end());
			for (int i=1; i<v.size(); ++i) {
				adj[v[i-1][1]].push_back(v[i][1]);
				adj[v[i][1]].push_back(v[i-1][1]);
			}
		}
	}
	p[0]=1;
	for (int i=1; i<=2*n; ++i)
		p[i]=p[i-1]*2%M;
	for (int i=0; i<n; ++i) {
		if (vis[i])
			continue;
		bool cyc=dfs(i);
		ans=ans*(p[sx.size()+sy.size()]-(cyc^1))%M;
		sx.clear(), sy.clear();
	}
	cout << ans;
	return 0;
}