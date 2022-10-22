#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, a[mxN], sz[mxN];
vector<int> adj[mxN];
string s;
ll ans[mxN], dp[mxN];
bool dead[mxN];
vector<int> v, mp[1<<20];

int dfs1(int u, int p=-1) {
	sz[u]=1;
	for (int v : adj[u])
		if (v^p&&!dead[v])
			sz[u]+=dfs1(v, u);
	return sz[u];
}

int dfs2(int u, int p, int ts) {
	for (int v : adj[u])
		if (v^p&&!dead[v]&&2*sz[v]>ts)
			return dfs2(v, u, ts);
	return u;
}

int inc, rt;

void dfs4(int u, int p, int m) {
	if (__builtin_popcount(m^a[rt])<=1)
		++dp[rt];
	mp[m].push_back(u);
	v.push_back(m);
	for (int v : adj[u])
		if (v^p&&!dead[v])
			dfs4(v, u, m^a[v]);
}

void dfs5(int u, int p) {
	for (int v : adj[u])
		if (v^p&&!dead[v]) {
			dfs5(v, u);
			dp[u]+=dp[v];
			ans[v]+=dp[v]*inc;
			dp[v]=0;
		}
}

void solve(int u, int p, int m) {
	dfs4(u, p, m);
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end())-v.begin());
	for (int x : v) {
		int y=x^a[rt];
		int cur=mp[y].size();
		for (int i=0; i<20; ++i)
			cur+=mp[y^(1<<i)].size();
		for (int i : mp[x])
			dp[i]+=cur;
	}
	dfs5(u, p);
	if (p==rt) {
		ans[u]+=dp[u]*inc;
		dp[rt]+=dp[u];
		dp[u]=0;
	}
	for (int i : v)
		mp[i].clear();
	v.clear();
}

void dbg() {
	for (int i=0; i<n; ++i) {
		if (i)
			cout << " ";
		cout << ans[i];
	}
	cout << "\n";
}

void dfs3(int u=0) {
	u=dfs2(u, -1, dfs1(u));
	inc=1, rt=u;
	solve(u, -1, 0), ans[u]+=dp[u]/2, dp[u]=0;
	//cout << "[" << u << "]\n";
	//dbg();
	inc=-1;
	for (int v : adj[u])
		if (!dead[v])
			solve(v, u, a[v]);
	ans[u]-=dp[u]/2, dp[u]=0;
	//dbg();
	dead[u]=1;
	for (int v : adj[u])
		if (!dead[v])
			dfs3(v);
	dead[u]=0;
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
	cin >> s;
	for (int i=0; i<n; ++i)
		a[i]=1<<(s[i]-'a');
	dfs3();
	for (int i=0; i<n; ++i)
		cout << ans[i] << " ";
	return 0;
}