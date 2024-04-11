#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db long double
#define pii pair<int, int>
#define mkp make_pair
#define sz(x) ((int) x.size())
#define be(x) x.begin()
#define en(x) x.end()
using namespace std;
const int N = 2e5 + 7;
int head[N], edge_id;
struct edge {
	int to, next; 
} e[N << 1];
void add_edge(int u, int v) {
	++edge_id, e[edge_id].to = v, e[edge_id].next = head[u], head[u] = edge_id;
}
vector<int> E[N];
int fa[N], dfn[N], hv[N], sz[N], dep[N], mxto[N], idtot, Mp[N];
bool vis[N], vs[N];
int las[N], flag[N];
void dfs(int x, int Fa = 0) {
	vis[x] = 1;
	for(int i = head[x]; i; i = e[i].next) {
		int v = e[i].to;
		if(v != Fa && vis[v]) flag[x] ++, flag[v] --;
	}
	for(int i = head[x]; i; i = e[i].next) {
		int v = e[i].to;
		if(!vis[v]) fa[v] = x, E[x].push_back(v), E[v].push_back(x), dfs(v, x); //, cout << x << " " << v << endl;
	}
}
void DFS1(int x) {
	sz[x] = 1;
	for(int v : E[x]) if(v != fa[x]) {
		dep[v] = dep[x] + 1, DFS1(v), flag[x] += flag[v], sz[x] += sz[v];
		if(sz[v] > sz[hv[x]]) hv[x] = v;
	}
}
void DFS2(int x) {
	dfn[x] = ++idtot, Mp[idtot] = x;
	// cout << x << " : " << dfn[x] << endl;
	if(hv[x]) mxto[hv[x]] = mxto[x], DFS2(hv[x]);
	for(int v : E[x]) if(v != fa[x] && v != hv[x]) mxto[v] = v, DFS2(v);
}
int lca(int x, int y) {
	while(mxto[x] ^ mxto[y]) {
		if(dep[mxto[x]] < dep[mxto[y]]) swap(x, y);
		x = fa[mxto[x]];
	}
	if(dep[x] < dep[y]) swap(x, y);
	return y;
}
int up(int x, int k) {
	int todep = dep[x] + k;
	while(dep[mxto[x]] > todep) x = fa[mxto[x]];
	return Mp[dfn[x] - (k - dep[x])];
}
bool isson(int x, int y) {
	return dfn[x] <= dfn[y] && dfn[y] <= dfn[x] + sz[x] - 1;
}
int fr1, to1, fr2, to2, rt, f1[N], f2[N], len1, len2;
void DFS3(int x) {
	for(int i = head[x]; i; i = e[i].next) {
		int v = e[i].to;
		if(v == fa[x]) continue;
		if(!isson(rt, v)) {
			if(!fr1) fr1 = x, to1 = v;
			else fr2 = x, to2 = v;
		}
	}
	for(int v : E[x]) if(v != fa[x]) DFS3(v);
}
void work(int x) {
	rt = x, DFS3(x);
	int LCA = lca(fr1, fr2), l1, l2, r1, r2;
	for(int v = fr1; ; v = fa[v]) {
		f1[++len1] = v;
		if(v == LCA) l1 = len1;
		if(v == to1) break;
	}
	for(int v = fr2; ; v = fa[v]) {
		f2[++len2] = v;
		if(v == LCA) l2 = len2;
		if(v == to2) break;
	}
	r1 = l1, r2 = l2;;
	while(r1 < len1 && r2 < len2 && f1[r1 + 1] == f2[r2 + 1]) ++ r1, ++ r2;
	cout << r1 - l1 + 1 << " ";
	L(i, l1, r1) cout << f1[i] << " ";
	cout << endl;
	
	cout << len1 - (r1 - l1) + 1 << " ";
	R(i, l1, 1) cout << f1[i] << " ";
	R(i, len1, r1) cout << f1[i] << " ";
	cout << endl;

	cout << len2 - (r2 - l2) + 1 << " ";
	R(i, l2, 1) cout << f2[i] << " ";
	R(i, len2, r2) cout << f2[i] << " ";
	cout << endl;
}
int A[N], B[N], C[N], lena, lenb, lenc;
int n, m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
	cin >> n >> m;
	L(i, 1, m) {
		int u, v; cin >> u >> v;
		add_edge(u, v), add_edge(v, u);
	}
	L(i, 1, n) if(!vis[i]) dfs(i), dep[i] = 1, DFS1(i), mxto[i] = 1, DFS2(i);
	L(i, 2, n) if(flag[i] >= 2) return cout << "YES\n", work(i), 0;
	cout << "NO\n";
	return 0;
}