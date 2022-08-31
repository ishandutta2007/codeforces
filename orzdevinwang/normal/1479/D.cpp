#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
char buf[1<<23],*p1=buf,*p2=buf,obuf[1<<22],*O=obuf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while(!isdigit(ch)) { if(ch == '-') f = -1; ch = getchar(); }
	while(isdigit(ch)) x = x * 10 + (ch ^ 48), ch = getchar();
	return x * f;
}
void print(int x) {
	if(x < 0) *O ++ = '-', x = -x;
    if(x > 9) print(x / 10);
    *O++ = x % 10 + '0';
}
mt19937_64 orz(355);
const int N = 3e5 + 7;
const int M = N * 40; 
int n, m, Ans[N], a[N], fa[N], ans;
ull key[M], sum[M];
int ch[M][2], tot, hd[N];
int query(int a, int b, int c, int d, int L, int R, int l, int r) {
	if(!(sum[a] ^ sum[b] ^ sum[c] ^ sum[d])) return -1;
	if(L == R) return L;
	int mid = (L + R) >> 1; int res = -1;
	if(l <= mid) {
		res = query(ch[a][0], ch[b][0], ch[c][0], ch[d][0], L, mid, l, r);
		if(res != -1) return res;
	}
	if(r > mid) {
		res = query(ch[a][1], ch[b][1], ch[c][1], ch[d][1], mid + 1, R, l, r);
		if(res != -1) return res;
	}
	return -1;
}
void add(int &ida, int idb, int L, int R, int wz, ull val) {
	if(!ida) ida = ++tot;
	sum[ida] = (sum[idb] ^ val);
	if(L == R) return;
	int mid = (L + R) >> 1;
	if(wz <= mid) ch[ida][1] = ch[idb][1], add(ch[ida][0], ch[idb][0], L, mid, wz, val);
	else ch[ida][0] = ch[idb][0], add(ch[ida][1], ch[idb][1], mid + 1, R, wz, val);
}
int head[N], edge_id;
struct edge { 
	int to, next; 
} e[N << 1];
void add_edge(int u, int v) { 
	++edge_id, e[edge_id].next = head[u], e[edge_id].to = v, head[u] = edge_id; 
}
int hv[N], siz[N], dep[N], mxto[N];
void dfs1(int x) {
	add(hd[x], hd[fa[x]], 1, n, a[x], key[a[x]]);
	siz[x] = 1;
	for(int i = head[x]; i; i = e[i].next) {
		int v = e[i].to; if(v == fa[x]) continue;
		dep[v] = dep[x] + 1, fa[v] = x, dfs1(v), siz[x] += siz[v];
		if(siz[v] > siz[hv[x]]) hv[x] = v;
	}
} 
void dfs2(int x) {
	if(hv[x]) mxto[hv[x]] = mxto[x], dfs2(hv[x]);
	for(int i = head[x]; i; i = e[i].next) {
		int v = e[i].to; if(v == fa[x] || v == hv[x]) continue;
		mxto[v] = v, dfs2(v);
	}
}
int lca(int u, int v) {
	while(mxto[u] ^ mxto[v]) {
		if(dep[mxto[u]] < dep[mxto[v]]) swap(u, v);
		u = fa[mxto[u]];
	}
	if(dep[u] < dep[v]) swap(u, v);
	return v;
}
int main() {
	n = read(), m = read();
	L(i, 1, n) a[i] = read(), key[i] = orz();
	L(i, 1, n - 1) {
		int u = read(), v = read();
		add_edge(u, v), add_edge(v, u);
	}
	dfs1(1), mxto[1] = 1, dfs2(1);
	while(m--) {
		int u = read(), v = read(), sl = read(), sr = read(), LCA = lca(u, v);
		print(query(hd[u], hd[v], hd[LCA], hd[fa[LCA]], 1, n, sl, sr)), *O ++ = '\n'; 
	}
	fwrite(obuf, O-obuf, 1, stdout);
	return 0;
}