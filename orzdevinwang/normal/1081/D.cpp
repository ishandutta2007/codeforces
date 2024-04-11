#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e5 + 7;
int n, m, k;
int f[N];
int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}
struct edge {
	int u, v, w;
} E[N << 1];
int head[N], edge_id;
struct node {
	int to, val, next;
} e[N << 1];
void add_edge(int u, int v, int val) {
	++edge_id, e[edge_id].to = v, e[edge_id].val = val, e[edge_id].next = head[u], head[u] = edge_id;
}
int s[N], ans[N], Fa[N];
int mxdis[N], sedis[N];
bool flag[N];
void dfs1(int x) {
	if(flag[x]) mxdis[x] = 0;
	for(int i = head[x]; i; i = e[i].next) {
		int v = e[i].to;
		if(v == Fa[x]) continue;
		Fa[v] = x, dfs1(v);
		int V = max(mxdis[v], e[i].val);
		if(mxdis[v] < 0) V = -1e9;
		if(V > mxdis[x]) sedis[x] = mxdis[x], mxdis[x] = V;
		else sedis[x] = max(sedis[x], V);
	}
}
void dfs2(int x, int D) {
	ans[x] = max(D, mxdis[x]);
	for(int i = head[x]; i; i = e[i].next) {
		int v = e[i].to;
		if(v == Fa[x]) continue;
		int V = max(mxdis[v], e[i].val), g = max(D, V == mxdis[x] ? sedis[x] : mxdis[x]);
		if(g >= 0) g = max(g, e[i].val);
		dfs2(v, g);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	memset(mxdis, -0x3f, sizeof(mxdis));
	memset(sedis, -0x3f, sizeof(sedis));
	cin >> n >> m >> k;
	L(i, 1, n) f[i] = i;
	L(i, 1, k) cin >> s[i], flag[s[i]] = 1;
	L(i, 1, m) cin >> E[i].u >> E[i].v >> E[i].w; 
	sort(E + 1, E + m + 1, [&](edge aa, edge bb) { return aa.w < bb.w; });
	L(i, 1, m) {
		if(find(E[i].u) ^ find(E[i].v)) f[find(E[i].u)] = find(E[i].v), add_edge(E[i].u, E[i].v, E[i].w), add_edge(E[i].v, E[i].u, E[i].w);
	}
	dfs1(1), dfs2(1, -1e9);
	L(i, 1, k) {
		cout << ans[s[i]] << " ";
	}
	cout << endl;
	return 0;
}