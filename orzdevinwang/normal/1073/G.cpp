#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define pll pair<ll, ll> 
#define mkp make_pair
using namespace std;
const int N = 4e5 + 7;
int n, m, ka, kb;
struct SAM {
	int tot = 1, las = 1, len[N], fa[N], ch[N][26];
	void copy(int x, int y) {
		L(i, 0, 25) ch[y][i] = ch[x][i];
		fa[y] = fa[x], len[y] = len[x];
	}
	void ins(int x) {
		int p = las, now = las = ++tot;
		len[now] = len[p] + 1;
		for(; p && !ch[p][x]; p = fa[p]) ch[p][x] = now;
		if(!p) fa[now] = 1;
		else {
			int pto = ch[p][x];
			if(len[pto] == len[p] + 1) fa[now] = pto;
			else {
				int sp = ++tot;
				copy(pto, sp), len[sp] = len[p] + 1;
				fa[pto] = fa[now] = sp;
				for(; p && ch[p][x] == pto; p = fa[p]) ch[p][x] = sp;
			}
		}
	}
} sam;
int id[N], idtot, maxto[N], dep[N], heavy[N], siz[N];
int head[N], edge_id;
struct node {
	int to, next;
} e[N << 1];
void add_edge(int u, int v) {
	++edge_id, e[edge_id].next = head[u], e[edge_id].to = v, head[u] = edge_id;
}
int hed[N], edgeid;
struct edge {
	int to, next;
} E[N << 1];
void addedge(int u, int v) {
	// cout << "add : " << u << " " << v << endl;
	++edgeid, E[edgeid].next = hed[u], E[edgeid].to = v, hed[u] = edgeid;
}
void dfs1(int x) {
	siz[x] = 1;
	for(int i = head[x]; i; i = e[i].next) {
		int v = e[i].to;
		dep[v] = dep[x] + 1, dfs1(v), siz[x] += siz[v];
		if(siz[v] > siz[heavy[x]]) heavy[x] = v;
	}
}
void dfs2(int x) {
	id[x] = ++idtot;
	if(heavy[x]) maxto[heavy[x]] = maxto[x], dfs2(heavy[x]);
	for(int i = head[x]; i; i = e[i].next) {
		int v = e[i].to;
		if(v == heavy[x]) continue;
		maxto[v] = v, dfs2(v);
	}
}
int lca(int x, int y) {
	while(maxto[x] ^ maxto[y]) {
		if(dep[maxto[x]] < dep[maxto[y]]) swap(x, y);
		x = sam.fa[maxto[x]];
	}
	if(dep[x] < dep[y]) swap(x, y);
	return y;
}
bool cmp(int x, int y) { return id[x] < id[y]; }
int f[N], flag[N], stk[N], tot, ftot;
void insert(int x) {
	hed[x] = 0;
	if(!tot) return stk[++tot] = x, void();
	int LCA = lca(stk[tot], x);
	if(LCA == stk[tot]) return stk[++tot] = x, void();
	while(tot > 1 && dep[LCA] < dep[stk[tot - 1]]) addedge(stk[tot - 1], stk[tot]), --tot;
	if(stk[tot - 1] != LCA) hed[LCA] = 0, addedge(LCA, stk[tot]), stk[tot] = LCA;
	else addedge(LCA, stk[tot]), --tot;
	stk[++tot] = x;
}
int pos[N], suma[N], sumb[N];
ll ans;
void DP(int x) {
	suma[x] = sumb[x] = 0;
	if(flag[x]) {
		if(flag[x] & 1) suma[x] = 1;
		if(flag[x] & 2) sumb[x] = 1;
		ans += 1ll * sam.len[x] * suma[x] * sumb[x];
	}
	for(int i = hed[x]; i; i = E[i].next) {
		int v = E[i].to;
		// cout << "x -> " << v << endl;
		DP(v);
		ans += (1ll * suma[x] * sumb[v] + 1ll * sumb[x] * suma[v]) * sam.len[x];
		suma[x] += suma[v], sumb[x] += sumb[v];
	}
	// cout << x << " : " << suma[x] << " " << sumb[x] << endl;
}
char s[N];
int main() {
	scanf("%d%d", &n, &m);
	scanf("%s", s + 1);
	R(i, n, 1) sam.ins(s[i] - 'a'), pos[i] = sam.las;
	L(i, 2, sam.tot) add_edge(sam.fa[i], i); //, cout << sam.fa[i] << " to " << i << endl;
	// puts("");
	dfs1(1), maxto[1] = 1, dfs2(1);
	while(m--) {
		// cout << "-----------------------------\n";
		tot = edgeid = ftot = 0;
		scanf("%d%d", &ka, &kb);
		L(i, 1, ka) scanf("%d", &f[++ftot]), f[ftot] = pos[f[ftot]], flag[f[ftot]] |= 1;
		L(i, 1, kb) scanf("%d", &f[++ftot]), f[ftot] = pos[f[ftot]], flag[f[ftot]] |= 2;
		sort(f + 1, f + ftot + 1, cmp);
		ftot = unique(f + 1, f + ftot + 1) - f - 1;
		insert(1);
		L(i, 1, ftot) insert(f[i]);
		while(tot > 1) addedge(stk[tot - 1], stk[tot]), --tot;
		ans = 0, DP(1);
		L(i, 1, ftot) flag[f[i]] = 0;
		printf("%lld\n", ans);
		// cout << "------------------------------\n";
	}
	return 0;
}
/*
20 10
bccaacbaaaabaaaabbbc
20 2
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
3 5
*/