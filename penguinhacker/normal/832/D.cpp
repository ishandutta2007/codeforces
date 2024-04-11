#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=100000;
int n, q, d[mxN], anc[mxN][17];
vector<int> adj[mxN];

void dfs(int u=0) {
	for (int i=1; i<17; ++i)
		anc[u][i]=anc[anc[u][i-1]][i-1];
	for (int v : adj[u])
		d[v]=d[u]+1, anc[v][0]=u, dfs(v);
}

int lca(int a, int b) {
	if (d[a]>d[b])
		swap(a, b);
	for (int i=16; ~i; --i)
		if (d[a]<=d[b]-(1<<i))
			b=anc[b][i];
	if (a==b)
		return a;
	for (int i=16; ~i; --i)
		if (anc[a][i]^anc[b][i])
			a=anc[a][i], b=anc[b][i];
	return anc[a][0];
}

int dist(int a, int b) {
	return d[a]+d[b]-2*d[lca(a, b)];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for (int i=1; i<n; ++i) {
		int p;
		cin >> p, --p;
		adj[p].push_back(i);
	}
	dfs();
	while(q--) {
		int a, b, c;
		cin >> a >> b >> c, --a, --b, --c;
		if (a==b&&b==c) {
			cout << "1\n";
			continue;
		}
		if (a==b) {
			cout << dist(a, c)+1 << "\n";
			continue;
		}
		else if (a==c||b==c) {
			cout << dist(a, b)+1 << "\n";
			continue;
		}
		int ab=dist(a, b), ac=dist(a, c), bc=dist(b, c);
		cout << max({ac+bc-ab, ab+bc-ac, ab+ac-bc})/2+1 << "\n";
	}
	return 0;
}