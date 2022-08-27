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
int n, m, f[N], siz[N], cmax[N], maxn[N];
int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
void Merge(int x, int y) {
	if(x == y) return;
	siz[x] += siz[y], f[y] = x;
}
int head[N], edge_id;
ll ans[N], vcmax[N], vmaxn[N];
struct node {
	int to, next, val;
} e[N << 1];
void add_edge(int u, int v, int val) {
	++edge_id, e[edge_id].next = head[u], e[edge_id].to = v, e[edge_id].val = val, head[u] = edge_id;
}
void dfs1(int x, int fa) {
	maxn[x] = cmax[x] = 0, vmaxn[x] = vcmax[x] = 0;
	for(int i = head[x]; i; i = e[i].next) {
		int v = e[i].to;
		if(v == fa) continue;
		dfs1(v, x); ll Val = vmaxn[v] + e[i].val;
		if(Val > vmaxn[x]) vcmax[x] = vmaxn[x], cmax[x] = maxn[x], vmaxn[x] = Val, maxn[x] = v;
		else if(Val > vcmax[x]) vcmax[x] = Val, cmax[x] = v;
	}
}
void dfs2(int x, int fa) {
	ans[x] = vmaxn[x];
	for(int i = head[x]; i; i = e[i].next) {
		int v = e[i].to;
		if(v == fa) continue;
		ll Val;
		if(maxn[x] == v) Val = vcmax[x] + e[i].val;
		else Val = vmaxn[x] + e[i].val;
		if(Val > vmaxn[v]) vmaxn[v] = Val, maxn[v] = x;
		else if(Val > vcmax[v]) vcmax[v] = Val, cmax[v] = x;
		dfs2(v, x);
	}
}
struct PII { int id; ll val; } G[N];
bool cmp(PII aa, PII bb) { return aa.val > bb.val; }
bool vis[N];
int main() {
	scanf("%d", &n);
	L(i, 1, n - 1) {
		int u, v, val; scanf("%d%d%d", &u, &v, &val);
		add_edge(u, v, val), add_edge(v, u, val);
	}
	dfs1(1, -1), dfs2(1, -1);
	L(i, 1, n) G[i].id = i, G[i].val = ans[i];
	sort(G + 1, G + n + 1, cmp);
	int Q; scanf("%d", &Q);
	while(Q--) {
		ll L; scanf("%lld", &L);
		int Ans = 1, j = 0;
		L(i, 1, n) f[i] = i, siz[i] = 1, vis[i] = 0;
		L(i, 1, n) {
			if(i != 1) siz[find(G[i - 1].id)]--, vis[G[i - 1].id] = 0;
			while(j <= n && G[j + 1].val >= G[i].val - L) {
				++j; int now = G[j].id;
				vis[now] = 1;
				for(int t = head[now]; t; t = e[t].next) {
					int v = e[t].to;
					if(!vis[v]) continue;
					Merge(find(now), find(v)), Ans = max(Ans, siz[find(now)]);
				}
			}
		}
		printf("%d\n", Ans);
	}
	return 0;
}