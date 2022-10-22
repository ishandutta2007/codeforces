#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=4e5;
int n, m, a[mxN], who[mxN], scc;
string g[mxN];
vector<int> oc[mxN], adj1[mxN], adj2[mxN], stk, adj3[mxN], adj4[mxN];
bool vis1[mxN], vis2[mxN], mark[mxN], bad[mxN];

void add_edge(int u, int v) {
	//cout << u << " " << v << endl;
	adj1[u].push_back(v);
	adj2[v].push_back(u);
}

void dfs1(int u) {
	vis1[u]=1;
	for (int v : adj1[u])
		if (!vis1[v])
			dfs1(v);
	stk.push_back(u);
}

void dfs2(int u) {
	vis1[u]=0;
	who[u]=scc;
	for (int v : adj2[u])
		if (vis1[v])
			dfs2(v);
}

void dfs4(int u) {
	vis2[u]=1;
	for (int v : adj3[u])
		if (!vis2[v])
			dfs4(v);
}

void dfs3(int u) {
	vis1[u]=1;
	dfs4(u);
	for (int v : adj4[u])
		if (!vis1[v])
			dfs3(v);
}

void dfs5(int u) {
	vis1[u]=1;
	for (int v : adj4[u]) {
		if (!vis1[v])
			dfs5(v);
		bad[u]|=bad[v]||mark[v];
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> g[i];
	for (int i=0; i<m; ++i) {
		cin >> a[i];
		for (int j=n-1; ~j; --j)
			if (g[j][i]=='#')
				oc[i].push_back(n-1-j);
		assert(a[i]<=oc[i].size());
	}
	for (int i=0; i<m; ++i)
		for (int j=0; j<oc[i].size(); ++j) {
			if (j) add_edge(i*n+oc[i][j], i*n+oc[i][j-1]);
			if (j+1<oc[i].size()&&oc[i][j+1]==oc[i][j]+1) add_edge(i*n+oc[i][j], i*n+oc[i][j+1]);
			if (i&&oc[i-1].size()&&oc[i-1][0]<=oc[i][j]) add_edge(i*n+oc[i][j], (i-1)*n+(*prev(upper_bound(oc[i-1].begin(), oc[i-1].end(), oc[i][j]))));
			if (i+1<m&&oc[i+1].size()&&oc[i+1][0]<=oc[i][j]) add_edge(i*n+oc[i][j], (i+1)*n+(*prev(upper_bound(oc[i+1].begin(), oc[i+1].end(), oc[i][j]))));
		}
	for (int i=0; i<m; ++i)
		for (int j : oc[i])
			if (!vis1[i*n+j])
				dfs1(i*n+j);
	reverse(stk.begin(), stk.end());
	for (int i : stk)
		if (vis1[i])
			dfs2(i), ++scc;
	for (int i=0; i<n*m; ++i)
		for (int j : adj1[i])
			if (who[i]!=who[j]) {
				adj3[who[i]].push_back(who[j]);
				adj4[who[j]].push_back(who[i]);
			}
	for (int i=0; i<m; ++i)
		if (a[i])
			mark[who[i*n+oc[i][a[i]-1]]]=1;
	for (int i=0; i<scc; ++i)
		if (!vis1[i])
			dfs5(i);
	memset(vis1, 0, sizeof(vis1));
	int ans=0;
	for (int i=0; i<m; ++i) {
		if (!a[i])
			continue;
		int u=who[i*n+oc[i][a[i]-1]];
		if (!bad[u]&&!vis2[u])
			dfs3(u), ++ans;
	}
	cout << ans;
	return 0;
}