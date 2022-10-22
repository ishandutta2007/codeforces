#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=3e5;
int n, m, s, e, cur;
int who[mxN], ecc, tin[mxN], low[mxN], t;
vector<ar<int, 2>> adj[mxN], adj2[mxN];
stack<int> st;
vector<ar<int, 3>> br;
bool g[mxN];

void make(int u) {
	who[u]=ecc;
	for (; st.top()^u; st.pop())
		who[st.top()]=ecc;
	st.pop(), ++ecc;
}

void dfs(int u=0, int p=-1) {
	tin[u]=low[u]=++t;
	st.push(u);
	for (ar<int, 2> v : adj[u]) {
		if (v[0]==p)
			continue;
		if (!tin[v[0]]) {
			dfs(v[0], u);
			low[u]=min(low[u], low[v[0]]);
			if (low[v[0]]>tin[u]) {
				br.push_back({u, v[0], v[1]});
				make(v[0]);
			}
		} else
			low[u]=min(low[u], tin[v[0]]);
	}
}

void dfs2(int u=s, int p=-1) {
	cur+=g[u];
	if (u==e)
		cout << (cur?"YES":"NO");
	for (ar<int, 2> v : adj2[u])
		if (v[0]^p)
			cur+=v[1], dfs2(v[0], u), cur-=v[1];
	cur-=g[u];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		int u, v, w;
		cin >> u >> v >> w, --u, --v;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	dfs();
	make(0);
	for (ar<int, 3> b : br) {
		int u=who[b[0]], v=who[b[1]];
		//cout << u << " " << v << endl;
		adj2[u].push_back({v, b[2]});
		adj2[v].push_back({u, b[2]});
	}
	for (int i=0; i<n; ++i)
		for (ar<int, 2> j : adj[i])
			g[who[i]]|=who[i]==who[j[0]]&&j[1];
	cin >> s >> e, --s, --e;
	s=who[s], e=who[e];
	dfs2();
	return 0;
}