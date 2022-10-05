#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 4e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

int ask(int u, int v) {
	cout << "? " <<  1 + u << " " << 1 + v << endl;
	fflush(stdout);
	int w;
	cin >> w;
	return w - 1;
}
int submit(int v) {
	cout << "! " << 1 + v << endl;
	fflush(stdout);
	return 0;
}

int n;
vector<vector<int>> g;
vector<int> no;

int main() {
	//ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	g.resize(n);
	no.resize(n, 0);
	for (int i = 0, u, v; i < n - 1; i++) {
		cin >> u >> v;
		--u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int m = n / 2;
	while (m--) {
		int u = -1, v = -1;
		for (int i = 0; i < n; i++) {
			if (g[i].size() == 1) {
				if (u == -1) u = i;
				else v = i;
			}
		}
		int w = ask(u, v);
		if (w == u) return submit(u);
		if (w == v) return submit(v);
		
		int u2 = g[u][0], v2 = g[v][0];
		g[u2].erase(find(g[u2].begin(), g[u2].end(), u));
		g[v2].erase(find(g[v2].begin(), g[v2].end(), v));
		g[u].clear(), g[v].clear();
		no[u] = no[v] = 1;
	}
	for (int i = 0; i < n; i++)
		if (!no[i])
			submit(i);
}