#include<bits/stdc++.h>
#define L(i, j, k) for (int i = (j); i <= (k); i++)
#define R(i, j, k) for (int i = (j); i >= (k); i--) 
#define sz(a) ((int) (a).size())
#define ll long long 
#define vi vector < int > 
using namespace std;
const int N = 2e5 + 7;
int n, c[N], col[N];
vi e[N], ns;
void dfs1 (int x, int fa) {
	col[x] = c[x];
	for (const int &v : e[x]) if(v != fa) {
		dfs1 (v, x);
		if(col[v] == 0 || col[v] != col[x]) col[x] = 0;
	}
}
void dfs2 (int x, int fa, int cv) {
	int all = 0;
	if(c[x] != cv) all = 1;
	bool ok = true;
	for (const int &v : e[x]) if(v != fa) {
		if(!col[v]) ok = false;
		if(col[v] != cv) all += 1; 
	}
	if(ok) ns.push_back(x);
	for (const int &v : e[x]) 
		if(v != fa && all == (col[v] != cv)) 
			dfs2 (v, x, cv);
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	L(i, 1, n - 1) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	L(i, 1, n) cin >> c[i];
	dfs1 (1, 0);
	dfs2 (1, 0, c[1]);
	if(!sz(ns)) cout << "NO\n";
	else {
		cout << "YES\n";
		cout << ns[0] << '\n';
	}
	return 0;
}