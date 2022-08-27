#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
char buf[1<<26], *p1=buf, *p2=buf, obuf[1<<25], *O=obuf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<26,stdin),p1==p2)?EOF:*p1++)
inline int read() {
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
	return x*f;
}
void print(int x) {
	if(x>9) print(x/10);
	*O++=x%10+'0';
}
const int N = 3e5 + 7;
const int mod = 998244353;
const int G = 917120411;
int Getny(int x) {
	int res = 1, y = mod - 2;
	for(; y; x = 1ll * x * x % mod, y >>= 1) if(y & 1) res = 1ll * res * x % mod;
	return res;
}
int qpow[N], npow[N];
void init(int x) {
	qpow[0] = npow[0] = 1;
	int iG = Getny(G);
	L(i, 1, x) qpow[i] = 1ll * qpow[i - 1] * G % mod, npow[i] = 1ll * npow[i - 1] * iG % mod;
}
int MOD(int x) { if(x >= mod) x -= mod; return x; }
void Mod(int &x) { if(x >= mod) x -= mod; }
void ad(int &x, int y) { x += y; if(x >= mod) x -= mod; }
int n, m, maxto[N], fa[N], id[N], dy[N], heavy[N], siz[N], idtot, dep[N];
int f[N], g[N];
char s[N];
int head[N], edge_id;
struct node {
	int to, next;
} e[N << 1];
void add_edge(int u, int v) {
	++edge_id, e[edge_id].next = head[u], e[edge_id].to = v, head[u] = edge_id;
}
void dfs1(int x) {
	siz[x] = 1;
	f[x] = MOD(f[fa[x]] + 1ll * (s[x] - 'a' + 1) * qpow[dep[x]] % mod), g[x] = MOD(1ll * g[fa[x]] * G % mod + s[x] - 'a' + 1);
	for(int i = head[x]; i; i = e[i].next) {
		int v = e[i].to; 
		if(v == fa[x]) continue;
		fa[v] = x;
		dep[v] = dep[x] + 1, dfs1(v), siz[x] += siz[v];
		if(siz[v] > siz[heavy[x]]) heavy[x] = v;
	}
}
void dfs2(int x) {
	id[x] = ++idtot, dy[idtot] = x;
	if(siz[x] != 1) {
		maxto[heavy[x]] = maxto[x];
		dfs2(heavy[x]);
	}
	for(int i = head[x]; i; i = e[i].next) {
		int v = e[i].to;
		if(v == fa[x] || v == heavy[x]) continue;
		maxto[v] = v, dfs2(v);
	}
}
int up(int x, int k) {
	int todep = dep[x] - k;
	while(dep[maxto[x]] > todep) x = fa[maxto[x]];
	return dy[id[x] - dep[x] + todep];
}
int lca(int u, int v) {
	while(maxto[u] != maxto[v]) {
		if(dep[maxto[u]] < dep[maxto[v]]) swap(u, v);
		u = fa[maxto[u]];
	}
	if(dep[u] < dep[v]) swap(u, v);
	return v;
} 
int u1, v1, lca1, flca1, len1, flen1, P1;
int g1;
int get1(int k) {
	if(k < flen1) return MOD(g[u1] + mod - 1ll * g[up(u1, k)] * qpow[k] % mod);
	else if(P1 >= 0) return MOD(g1 + 1ll * f[up(v1, len1 - k)] * qpow[P1] % mod);
	else return MOD(g1 + 1ll * f[up(v1, len1 - k)] * npow[-P1] % mod);
}
int u2, v2, lca2, flca2, len2, flen2, P2;
int g2;
int get2(int k) {
	if(k < flen2) return MOD(g[u2] + mod - 1ll * g[up(u2, k)] * qpow[k] % mod);
	else if(P2 >= 0) return MOD(g2 + 1ll * f[up(v2, len2 - k)] * qpow[P2] % mod);
	else return MOD(g2 + 1ll * f[up(v2, len2 - k)] * npow[-P2] % mod);
}
int main() {
	n = read();
	L(i, 1, n) {
		char ch = getchar();
		while('a' > ch && ch > 'z') ch = getchar();
		s[i] = ch;
	}
	init(n);
	L(i, 1, n - 1) {
		int u = read(), v = read(); 
		add_edge(u, v), add_edge(v, u);
	}
	f[0] = 0, dep[0] = -1;
	dfs1(1), dfs2(1);
	int m = read();
	while(m--) {
		u1 = read(), v1 = read(), u2 = read(), v2 = read();
		lca1 = lca(u1, v1), lca2 = lca(u2, v2);
		len1 = dep[u1] + dep[v1] - dep[lca1] * 2 + 1, flen1 = dep[u1] - dep[lca1] + 1, P1 = flen1 - dep[lca1] - 1;
		len2 = dep[u2] + dep[v2] - dep[lca2] * 2 + 1, flen2 = dep[u2] - dep[lca2] + 1, P2 = flen2 - dep[lca2] - 1;
		g1 = MOD(g[u1] + mod - 1ll * g[fa[lca1]] * qpow[flen1] % mod);
		if(P1 >= 0) g1 = MOD(g1 + mod - 1ll * f[lca1] * qpow[P1] % mod);
		else g1 = MOD(g1 + mod - 1ll * f[lca1] * npow[-P1] % mod);
		g2 = MOD(g[u2] + mod - 1ll * g[fa[lca2]] * qpow[flen2] % mod);
		if(P2 >= 0) g2 = MOD(g2 + mod - 1ll * f[lca2] * qpow[P2] % mod);
		else g2 = MOD(g2 + mod - 1ll * f[lca2] * npow[-P2] % mod);
		int L = 1, R = min(len1, len2), ans = 0;
		while(L <= R) {
			int mid = (L + R) / 2;
			if(get1(mid) == get2(mid)) ans = mid, L = mid + 1;
			else R = mid - 1;
		}
		print(ans), *O++ = '\n';
	}
	fwrite(obuf,O-obuf,1,stdout);
	return 0;
}