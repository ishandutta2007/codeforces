#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, m, q, eu[mxN], ev[mxN];
int who1[mxN], who2[mxN], cp, ecc, tin[mxN], low[mxN], t;
int d[mxN], anc[mxN][18], dp[mxN][2];
vector<int> adj[mxN], adj2[mxN];
stack<int> st;
vector<ar<int, 2>> br;

void make(int u) {
	who2[u]=ecc;
	for (; st.top()^u; st.pop())
		who2[st.top()]=ecc;
	st.pop(), ++ecc;
}

void dfs(int u, int p=-1) {
	who1[u]=cp;
	tin[u]=low[u]=++t;
	st.push(u);
	for (int i : adj[u]) {
		if (i==p)
			continue;
		int v=u^eu[i]^ev[i];
		if (!tin[v]) {
			dfs(v, i);
			low[u]=min(low[u], low[v]);
			if (low[v]>tin[u]) {
				br.push_back({u, v});
				make(v);
			}
		} else
			low[u]=min(low[u], tin[v]);
	}
}

void dfs2(int u, int p=-1) {
	anc[u][0]=p;
	for (int i=1; i<18; ++i)
		anc[u][i]=anc[u][i-1]^-1?anc[anc[u][i-1]][i-1]:-1;
	for (int v : adj2[u]) {
		d[v]=d[u]+1;
		dfs2(v, u);
	}
}

int lca(int u, int v) {
	if (d[u]>d[v])
		swap(u, v);
	for (int i=17; ~i; --i)
		if (d[u]<=d[v]-(1<<i))
			v=anc[v][i];
	if (u==v)
		return u;
	for (int i=17; ~i; --i)
		if (anc[u][i]^anc[v][i])
			u=anc[u][i], v=anc[v][i];
	return anc[u][0];
}

void dfs3(int u) {
	for (int v : adj2[u]) {
		dfs3(v);
		dp[u][0]+=dp[v][0];
		dp[u][1]+=dp[v][1];
	}
	if (dp[u][0]&&dp[u][1]) {
		cout << "No";
		exit(0);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> q;
	for (int i=0; i<m; ++i) {
		cin >> eu[i] >> ev[i], --eu[i], --ev[i];
		adj[eu[i]].push_back(i);
		adj[ev[i]].push_back(i);
	}
	for (int i=0; i<n; ++i) {
		if (tin[i])
			continue;
		dfs(i), ++cp;
		make(i);
		for (ar<int, 2> b : br)
			adj2[who2[b[0]]].push_back(who2[b[1]]);
		br.clear();
		dfs2(who2[i]);
	}
	for (int i=0; i<q; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		if (who1[u]^who1[v]) {
			cout << "No";
			return 0;
		}
		u=who2[u], v=who2[v];
		int uv=lca(u, v);
		++dp[u][0], --dp[uv][0];
		++dp[v][1], --dp[uv][1];
	}
	for (int i=0; i<ecc; ++i)
		if (anc[i][0]==-1)
			dfs3(i);
	cout << "Yes";
	return 0;
}