#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
 
bool fib[200001];
void preprocess() {
	int a = 1, b = 1;
	while(b <= 200000) {
		fib[b] = 1;
		swap(a, b);
		b = a + b;
	}
}
 
int n, sz[200000], p[200000];
set<int> adj[200000];
 
void dfs(int u, int ts, vector<ar<int, 3>>& splits) {
	sz[u] = 1;
	for (const int& v : adj[u]) if (v != p[u]) {
		p[v] = u;
		dfs(v, ts, splits);
		sz[u] += sz[v];
	}
	if (fib[sz[u]] && fib[ts - sz[u]])
		splits.push_back({u, p[u], sz[u]});
}
 
bool check(int r, int ts) {
	if (ts == 1) return 1;
	vector<ar<int, 3>> splits;
	p[r] = -1;
	dfs(r, ts, splits);
	//cerr << r << " " << ts  << " " << sz[r] << "\n";
	assert(ts == sz[r]);
	for (ar<int, 3> e : splits) {
		adj[e[0]].erase(e[1]);
		adj[e[1]].erase(e[0]);
		bool a = check(e[0], e[2]);
		bool b = check(e[1], ts - e[2]);
		adj[e[0]].insert(e[1]);
		adj[e[1]].insert(e[0]);
		//if (a && b)
		//	return 1;
		return a && b;
	}
	return 0;
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	preprocess();
	cin >> n;
	if (!fib[n]) {
		cout << "NO";
		return 0;
	}
	for (int i = 1; i < n; ++i) {
		int a, b; cin >> a >> b, --a, --b;
		adj[a].insert(b);
		adj[b].insert(a);
	}
	cout << (check(0, n) ? "YES" : "NO");
	return 0;
}