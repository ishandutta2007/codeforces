#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=3e5;
int n, m, eu[mxN], ev[mxN], ans;
int who1[mxN], who2[mxN], cp, ecc, tin[mxN], low[mxN], t;
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

int dfs2(int u=who2[0]) {
	vector<int> c={0, 0};
	for (int v : adj2[u])
		c.push_back(dfs2(v));
	sort(c.rbegin(), c.rend());
	ans=max(ans, c[0]+c[1]);
	return c[0]+1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
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
	}
	dfs2();
	cout << ans;
	return 0;
}