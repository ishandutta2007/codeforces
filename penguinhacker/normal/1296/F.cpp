#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=5000;
struct edge {
	int a, b;
	int w=0;
	int get(int x) {return x^a^b;}
} e[mxN];

int n, m, qry[mxN];
vector<int> adj[mxN];
vector<int> path[mxN];

bool dfs(int u, int ee, int ind, int p=-1) {
	if (u==ee) return 1;
	for (int x: adj[u]) {
		int v=e[x].get(u);
		if (v==p) continue;
		path[ind].push_back(x);
		if (dfs(v, ee, ind, u)) return 1;
		path[ind].pop_back();
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=1; i<n; ++i) {
		cin >> e[i].a >> e[i].b, --e[i].a, --e[i].b;
		adj[e[i].a].push_back(i);
		adj[e[i].b].push_back(i);
	}
	cin >> m;
	for (int i=0; i<m; ++i) {
		int a, b, c; cin >> a >> b >> c, --a, --b;
		qry[i]=c;
		dfs(a, b, i);
		/*for (int j: path[i])
			cout << j << "  ";
		cout << "\n";*/
		for (int j: path[i])
			e[j].w=max(e[j].w, c);
	}
	for (int i=0; i<m; ++i) {
		bool b=0;
		for (int j: path[i])
			b|=e[j].w==qry[i];
		if (!b) {
			cout << -1;
			return 0;
		}
	}
	for (int i=1; i<n; ++i)
		cout << (e[i].w==0?1000000:e[i].w) << " ";
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/