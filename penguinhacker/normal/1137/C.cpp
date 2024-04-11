#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
 
const int mxN=1e5;
int n, m, d, n2, who[50*mxN], dp[50*mxN];
string open[mxN];
vector<int> adj1[mxN], adj2[mxN], st, cmp[50*mxN], scc;
bool vis[50*mxN], seen[50*mxN], used[mxN];
 
void dfs1(int u=0) {
	vis[u]=seen[u]=1;
	for (int v : adj1[u%n]) if (!vis[(u/n*n+v+n)%(n*d)]) dfs1((u/n*n+v+n)%(n*d));
	st.push_back(u);
}
 
void dfs2(int u, int r) {
	vis[u]=0, who[u]=r;
	for (int v : adj2[u%n]) if (vis[(u/n*n+v+(d-1)*n)%(n*d)]) dfs2((u/n*n+v+(d-1)*n)%(n*d), r);
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> d;
	for (int i=0; i<m; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj1[u].push_back(v);
		adj2[v].push_back(u);
	}
	for (int i=0; i<n; ++i)
		cin >> open[i];
	st.reserve(n*d);
	dfs1();
	for (int i=st.size()-1; ~i; --i) if (vis[st[i]]) dfs2(st[i], st[i]), scc.push_back(st[i]);
	for (int i=0; i<n*d; ++i) if (seen[i]) cmp[who[i]].push_back(i);
	reverse(scc.begin(), scc.end());
	for (int i : scc) {
		for (int j : cmp[i]) for (int k : adj1[j%n]) {
			int x=who[(j/n*n+k+n)%(n*d)];
			if (x!=i) dp[i]=max(dp[i], dp[x]);
		}
		for (int j : cmp[i]) if (!used[j%n]&&open[j%n][j/n]=='1') ++dp[i], used[j%n]=1;
		for (int j : cmp[i]) used[j%n]=0;
	}
	cout << dp[who[0]];
	return 0;
}