#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, m, deg[mxN], d[mxN], mx[mxN];
vector<int> adj[mxN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[v].push_back(u);
		++deg[u];
	}
	memset(d, 0x3f, sizeof(d));
	priority_queue<ar<int, 2>, vector<ar<int, 2>>, greater<ar<int, 2>>> pq;
	pq.push({d[n-1]=0, n-1});
	while(pq.size()) {
		int u=pq.top()[1], x=pq.top()[0];
		pq.pop();
		if (d[u]!=x)
			continue;
		for (int v : adj[u]) {
			--deg[v];
			mx[v]=max(mx[v], x);
			int nd=mx[v]+deg[v]+1;
			if (nd<d[v])
				pq.push({d[v]=nd, v});
		}
	}
	cout << d[0];
	return 0;
}