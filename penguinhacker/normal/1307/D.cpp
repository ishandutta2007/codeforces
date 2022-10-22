#include <bits/stdc++.h>
using namespace std;

const int mxN=200000;
int n, m, k, x[mxN], y[mxN];
vector<int> adj[mxN], ind;

void bfs(int s, int *d) {
	fill(d, d+n, -1);
	d[s]=0;
	queue<int> q;
	q.push(s);
	while(!q.empty()) {
		int u=q.front(); q.pop();
		for (int v : adj[u]) {
			if (d[v]==-1) {
				d[v]=d[u]+1;
				q.push(v);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i=0, a; i<k; ++i)
		cin >> a, --a, ind.push_back(a);
	for (int i=0, u, v; i<m; ++i) {
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	bfs(0, x);
	bfs(n-1, y);
	sort(ind.begin(), ind.end(), [](int a, int b) {return x[a]-y[a]==x[b]-y[b]?a<b:x[a]-y[a]<x[b]-y[b];});
	int suf=y[ind.back()], ans=0;
	for (int i=k-2; ~i; --i) {
		ans=max(ans, suf+x[ind[i]]+1);
		suf=max(suf, y[ind[i]]);
	}
	ans=min(ans, x[n-1]);
	cout << ans;
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/