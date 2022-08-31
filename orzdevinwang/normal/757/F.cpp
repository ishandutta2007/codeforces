#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) ((int) a.size()) 
#define vi vector<int>
using namespace std;
const int N = 2e5 + 7; 
int n, m, s, ord[N], idt, zp[N], dep[N], siz[N], mx;
vi e[N], ew[N], se[N], c[N];
ll dis[N];
int up[N][20];
bool use[N];
void dij() {
	memset(dis, 0x3f, sizeof(dis));
	priority_queue < pair < ll, int > > q;
	q.push(make_pair(0, s)), dis[s] = 0;
	while(!q.empty()) {
		int u = q.top().second;
		q.pop();
		if(use[u]) continue;
		use[u] = true, ord[++idt] = u;
		L(i, 0, sz(e[u]) - 1) {
			int v = e[u][i], val = ew[u][i];
			if(dis[v] > dis[u] + val) dis[v] = dis[u] + val, q.push(make_pair(-dis[v], v));
		}
	}
}
int LCA(int x, int y) {
	if(dep[x] < dep[y]) swap(x, y);
	R(i, 19, 0) if(dep[x] - dep[y] >= (1 << i)) x = up[x][i];
	if(x == y) return x;
	R(i, 19, 0) if(up[x][i] != up[y][i]) x = up[x][i], y = up[y][i];
	return up[x][0];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> s;
	L(i, 1, m) {
		int u, v, w;
		cin >> u >> v >> w;
		e[u].push_back(v), ew[u].push_back(w);
		e[v].push_back(u), ew[v].push_back(w);
	}
	dij();
	L(u, 1, n) L(i, 0, sz(e[u]) - 1) if(dis[u] + ew[u][i] == dis[e[u][i]]) se[u].push_back(e[u][i]);
	L(a, 1, idt) {
		int u = ord[a];
		c[zp[u]].push_back(u), dep[u] = dep[zp[u]] + 1, up[u][0] = zp[u];
		L(i, 1, 19) up[u][i] = up[up[u][i - 1]][i - 1];
		for(const int &v : se[u]) 
			zp[v] = (zp[v] ? LCA(zp[v], u) : u);
	}
	R(a, idt, 1) {
		int u = ord[a];
		siz[u] = 1; 
		for(const int  &v : c[u]) siz[u] += siz[v];
		if(u != s) mx = max(mx, siz[u]);
	}
	cout << mx << "\n";
	return 0;
}