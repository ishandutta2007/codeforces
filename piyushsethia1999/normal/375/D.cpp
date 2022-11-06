#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int as[100004];
std::vector<std::vector<pair<int, int> > > qu;
std::vector<std::vector<int> > adj;
std::vector<int> siz;
std::vector<int> bc;
int cl[100004] = {};
int nu[100004] = {};
int c[100004];

int pdfs(int u, int p)
{
	for (auto v : adj[u]) if (v != p) siz[u] += pdfs(v, u);
	int mx = -1;
	for (auto v : adj[u]) if (v != p && siz[v] > mx) mx = siz[v], bc[u] = v;
	return siz[u];
}

void add(int u, int x) { x ? ++nu[++cl[c[u]]]: --nu[cl[c[u]]--]; }

void dfsu(int u, int p, int x) {
	add(u, x);
	for (auto v : adj[u]) if (v != p) dfsu(v, u, x);
}

void query(int u) {	for (auto p : qu[u]) as[p.second] = nu[p.first]; }

void ans(int u, int p, int clear) 
{
	for (auto v : adj[u]) if (v != p && v != bc[u]) ans(v, u, 1);
	if (bc[u] != -1) ans(bc[u], u, 0);
	for (auto v : adj[u]) if (v != p && v != bc[u]) dfsu(v, u, 1);
	add(u, 1); query(u);
	if (clear) dfsu(u, p, 0);
}

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	int m; cin >> m;
	qu.resize(n);
	bc.resize(n, -1);
	siz.resize(n, 1);
	for (int i = 0; i < n; ++i) cin >> c[i];
	adj.resize(n); for (int o = 0; o < n - 1; o++) { int x, y; cin >> x >> y; x--; y--; adj[x].pb(y); adj[y].pb(x); }
	pdfs(0, 0);
	for (int i = 0; i < m; ++i) {
		int in; cin >> in; in--;
		int k; cin >> k;
		qu[in].pb(k, i);
	}
	ans(0, 0, 0);
	for (int i = 0; i < m; ++i) cout << as[i] << "\n";
}