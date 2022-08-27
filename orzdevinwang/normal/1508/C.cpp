#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j), i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = k; i >= i##E; i--)
#define mkp make_pair
#define pii pair<int, int>
#define ll long long
#define db double
#define sz(a) a.size()
#define x first
#define y second
#define vi vector<int>
using namespace std;
const int N = 4e5 + 7, M = 1123;
int n, m, f[N], deg[N], all, tot, eqid;
ll ns;
bool vis[N];
struct edge {
	int u, v, w;
} e[N], q[N], eq[N];
vi s[N];
int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
void init() { L(i, 1, n) f[i] = i; }
int rmain1() {
	L(i, 1, m) ++ deg[e[i].u], ++ deg[e[i].v];
	L(i, 1, n) s[i].reserve(deg[i]);
	L(i, 1, m) s[e[i].u].push_back(e[i].v), s[e[i].v].push_back(e[i].u);
	int mx = 1;
	L(i, 2, n) if(deg[i] < deg[mx]) mx = i;
	L(i, 1, n) vis[i] = true;
	for(const int &u : s[mx]) vis[u] = false;
	L(i, 1, n) if(vis[i] && i != mx) f[find(i)] = mx;
	for(const int &u : s[mx]) {
		L(v, 1, n) vis[v] = true;
		for(const int &v : s[u]) vis[v] = false;
		L(v, 1, n) if(vis[v] && find(u) != find(v)) f[find(u)] = v;
	}
	L(i, 1, m) if(find(e[i].u) ^ find(e[i].v)) f[find(e[i].u)] = e[i].v, ns += e[i].w;
	return 0;
}
bool ie[M][M];
int rmain2() {
	ns = 1e18;
	L(i, 1, m) if(find(e[i].u) ^ find(e[i].v)) f[find(e[i].u)] = e[i].v, q[++tot] = e[i];
	L(i, 1, m) ie[e[i].u][e[i].v] = ie[e[i].v][e[i].u] = true;
	L(u, 1, n) L(v, u + 1, n) if(!ie[u][v]) ++eqid, eq[eqid].u = u, eq[eqid].v = v, eq[eqid].w = 0;
	L(u, 1, n) L(v, u + 1, n) if(!ie[u][v]) {
		init();
		L(i, 1, eqid) 
			if(eq[i].u == u && eq[i].v == v) e[i].u = u, e[i].v = v, e[i].w = all;
			else e[i] = eq[i];
		L(i, 1, tot) e[i + eqid] = q[i];
		ll res = 0;
		sort(e + 1, e + tot + eqid + 1, [&] (edge aa, edge bb) { return aa.w < bb.w; });
		L(i, 1, tot + eqid) if(find(e[i].u) ^ find(e[i].v)) f[find(e[i].u)]	= e[i].v, res += e[i].w;
		ns = min(ns, res);
	}
	return 0;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m, init();
	L(i, 1, m) cin >> e[i].u >> e[i].v >> e[i].w, all ^= e[i].w;
	sort(e + 1, e + m + 1, [&] (edge aa, edge bb) { return aa.w < bb.w; });
	if((ll) n * (n - 1) / 2 - m > n) rmain1();
	else rmain2();
	cout << ns << "\n";
	return 0;
}