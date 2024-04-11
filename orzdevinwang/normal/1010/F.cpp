#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int mod = 998244353, G = 3, iG = (mod + 1) / G;
const int N = 3e5 + 7;
int qpow(int x, int y = mod - 2) {
	int res = 1;
	for(; y; x = (ll) x * x % mod, y >>= 1) if(y & 1) res = (ll) res * x % mod;
	return res;
}
int Lim, lim, pp[N], PowG[N], iPowG[N];
void revlim() { 
	L(i, 0, lim - 1) pp[i] = ((pp[i >> 1] >> 1) | ((i & 1) * (lim >> 1))); 
}
void up(int x) { 
	lim = 1; 
	for(; lim <= x; lim <<= 1); 
}
void cle(int *f) { 
	L(i, 0, lim - 1) f[i] = 0; 
}
void init(int x) {
	int Pw;
	up(x), Lim = lim;
	Pw = qpow(G, (mod - 1) / Lim), PowG[0] = 1;
	L(i, 1, lim - 1) PowG[i] = (ll) PowG[i - 1] * Pw % mod;
	Pw = qpow(iG, (mod - 1) / Lim), iPowG[0] = 1;
	L(i, 1, lim - 1) iPowG[i] = (ll) iPowG[i - 1] * Pw % mod;
}
void NTT(int *f, int flag) {
	L(i, 0, lim - 1) if(pp[i] < i) swap(f[pp[i]], f[i]);
	for(int i = 2; i <= lim; i <<= 1) 
		for(int j = 0, l = (i >> 1), ch = Lim / i; j < lim; j += i) 
			for(int k = j, now = 0; k < j + l; k ++) {
				int pa = f[k], pb = (ll) f[k + l] * (flag == 1 ? PowG[now] : iPowG[now]) % mod;
				f[k] = (pa + pb) % mod, f[k + l] = (pa + mod - pb) % mod, now += ch;
			}
	if(flag == -1) {
		int nylim = qpow(lim);
		L(i, 0, lim - 1) f[i] = (ll) f[i] * nylim % mod;
	}
}
void Mul(int *f, int *g, int *ans, int n, int m) {
	static int A[N], B[N];
	up(n + m - 1), revlim(), cle(A), cle(B), copy(f, f + n, A), copy(g, g + m, B);
	NTT(A, 1), NTT(B, 1);
	L(i, 0, lim - 1) A[i] = (ll) A[i] * B[i] % mod;
	NTT(A, -1), copy(A, A + n + m - 1, ans);
}
int n, m, fa[N];
int head[N], edge_id;
struct edge { 
	int to, next; 
} e[N << 1];
void add_edge(int u, int v) { 
	++edge_id, e[edge_id].next = head[u], e[edge_id].to = v, head[u] = edge_id; 
}
int id[N], mp[N], hv[N], siz[N], idtot, dep[N];
void dfs1(int x) {
	id[x] = ++idtot, mp[idtot] = x, siz[x] = 1;
	for(int i = head[x]; i; i = e[i].next) {
		int v = e[i].to; 
		if(v == fa[x]) continue;
		dep[v] = dep[x] + 1, fa[v] = x, dfs1(v), siz[x] += siz[v];
		if(siz[v] > siz[hv[x]]) hv[x] = v;
	}
} 
int sav[N];
int tmp[N * 100], *Id = tmp, *ans[N], *lig[N], *g[N];
int szli[N], tot, sz[N], *ss[N], stot;
void divide1(int l, int r, int *a) {
	if(l == r) return copy(g[l], g[l] + sz[l] - sz[l - 1] + 1, a), void(); 
	int mid = (l + r) >> 1, *a1, *a2, len1 = sz[mid] - sz[l - 1] + 1, len2 = sz[r] - sz[mid] + 1;
	a1 = Id, Id += len1, a2 = Id, Id += len2;
	divide1(l, mid, a1), divide1(mid + 1, r, a2), Mul(a1, a2, a, len1, len2);
}
void divide2(int l, int r, int *a, int *b) {
	if(l == r) {
		int len = szli[l] - szli[l - 1] + 1;
		copy(ss[l], ss[l] + len, a), copy(ss[l], ss[l] + len, b);
		return; 
	}
	int mid = (l + r) >> 1, *a1, *a2, *b1, *b2, len1 = szli[mid] - szli[l - 1] + 1, len2 = szli[r] - szli[mid] + 1;
	a1 = Id, Id += len1, a2 = Id, Id += len2, b1 = Id, Id += len1, b2 = Id, Id += len2;
	divide2(l, mid, a1, b1), divide2(mid + 1, r, a2, b2);
	Mul(b1, b2, b, len1, len2), Mul(a1, b2, a, len1, len2);
	L(i, 0, len2 - 1) (a[i] += a2[i]) %= mod;
}
void dfs2(int x, bool flag) {
	for(int i = head[x]; i; i = e[i].next) {
		int v = e[i].to;
		if(v == fa[x] || v == hv[x]) continue;
		dfs2(v, 0);
	} 
	if(hv[x]) dfs2(hv[x], 1);
	
	tot = 1;
	for(int i = head[x]; i; i = e[i].next) {
		int v = e[i].to;
		if(v == fa[x] || v == hv[x]) continue; 
		++tot, g[tot] = ans[v], sz[tot] = siz[v];
	}
	L(i, 1, tot) sz[i] += sz[i - 1]; 
	lig[x] = Id, Id += sz[tot] + 2, divide1(1, tot, lig[x]);
	R(i, sz[tot], 0) lig[x][i + 1] = lig[x][i];
	lig[x][0] = 0;
	++stot, szli[stot] = sz[tot] + 1, ss[stot] = lig[x];
	if(flag == 0) {
		L(i, 1, stot) szli[i] += szli[i - 1];
		ans[x] = Id, Id += szli[stot] + 1;
		divide2(1, stot, ans[x], sav), ans[x][0] ++;
		stot = 0;
	}
}
ll x;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	sz[1] = 1, g[1] = Id, g[1][0] = 1, Id++;
	cin >> n >> x, init(n << 1 | 1);
	L(i, 1, n - 1) {
		int u, v; cin >> u >> v;
		add_edge(u, v), add_edge(v, u);
	}
	dfs1(1), dfs2(1, 0);
	int Ans = 0, res = 1;
	L(i, 1, n) (Ans += (ll) res * ans[1][i] % mod) %= mod, res = (x + i) % mod * res % mod * qpow(i) % mod;
	cout << Ans << "\n";
	return 0;
}