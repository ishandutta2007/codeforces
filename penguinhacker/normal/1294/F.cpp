#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, a, b, c=-1, x[200000], y[200000];
vector<int> adj[200000];

int bfs(int s, int *d) {
	fill(d, d+n, -1);
	d[s]=0;
	queue<int> q;
	q.push(s);
	while(!q.empty()) {
		int u=q.front(); q.pop();
		for (int v : adj[u])
			if (d[v]==-1) {
				d[v]=d[u]+1;
				q.push(v);
			}
	}
	pair<int, int> res={-1, -1};
	for (int i=0; i<n; ++i)
		if (d[i]>res.first)
			res={d[i], i};
	return res.second;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=1, u, v; i<n; ++i) {
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	a=bfs(0, x);
	b=bfs(a, x);
	bfs(b, y);
	for (int i=0; i<n; ++i)
		if (i!=a&&i!=b&&(c==-1||x[i]+y[i]>x[c]+y[c]))
			c=i;
	cout << (x[b]+x[c]+y[c])/2 << '\n';
	cout << a+1 << ' ' << b+1 << ' ' << c+1;
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/