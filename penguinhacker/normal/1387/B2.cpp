#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;
int n, sz[mxN], ans[mxN];
vector<int> adj[mxN], oc[mxN];
set<ar<int, 2>> s;
ll sum=0;

void dfs1(int u=0, int p=-1) {
	sz[u]=1;
	for (int v : adj[u])
		if (v^p)
			dfs1(v, u), sz[u]+=sz[v];
}

int dfs2(int u=0, int p=-1) {
	for (int v : adj[u])
		if (v^p&&sz[v]>n/2)
			return dfs2(v, u);
	return u;
}

void dfs3(int u, int p, int h) {
	sum+=2*sz[u];
	oc[h].push_back(u);
	for (int v : adj[u])
		if (v^p)
			dfs3(v, u, h);
}

void ins(int u) {
	if (oc[u].size())
		s.insert({oc[u].size(), u});
}

int rem(int u) {
	s.erase({oc[u].size(), u});
	int x=oc[u].back();
	oc[u].pop_back();
	return x;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=1; i<n; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs1();
	int c=dfs2();
	dfs1(c);
	oc[c]={c}, ins(c);
	for (int u : adj[c])
		dfs3(u, c, u), ins(u);
	iota(ans, ans+n, 0);
	while(s.size()>=2) {
		int r1=(*s.rbegin())[1];
		int u=rem(r1);
		int r2=(*s.rbegin())[1];
		int v=rem(r2);
		swap(ans[u], ans[v]);
		ins(r1), ins(r2);
	}
	if (s.size()) {
		assert(s.size()==1&&n%2);
		int r=(*s.begin())[1];
		assert(oc[r].size()==1);
		int u=oc[r][0];
		if (u^c) {
			swap(ans[u], ans[c]);
		} else {
			swap(ans[c], c==0?ans[1]:ans[0]);
		}
	}
	cout << sum << "\n";
	for (int i=0; i<n; ++i)
		cout << ans[i]+1 << " ";
	return 0;
}