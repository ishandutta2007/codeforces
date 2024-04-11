#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 4e5 + 7;
int n, a[N], vis[N];
ll ns;
vi e[N];
void eadd (int u, int v) { e[u].push_back(v), e[v].push_back(u); }
int st[20][N], dep[N], siz[N], To[20][N], lg[N], tp, df[N];
void dfs (int x, int fa) {
	++tp, st[0][tp] = dep[x], df[x] = tp;
	for(const int &v : e[x]) if(v != fa) To[0][v] = x, dep[v] = dep[x] + 1, dfs (v, x), st[0][++tp] = dep[x];
}
void make () {
	dfs(1, 0);
	L(i, 1, 19) L(j, 1, tp - (1 << i) + 1) st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
	L(i, 1, 19) L(j, 1, n * 2 - 1) To[i][j] = To[i - 1][To[i - 1][j]];
}
inline int query (int x, int y) {
	x = df[x], y = df[y], ((x > y) && (x ^= y ^= x ^= y)); 
	int p = lg[y - x + 1];  
	return min(st[p][x], st[p][y - (1 << p) + 1]);
}
int up (int x, int k) { R(i, 19, 0) if(k >> i & 1) x = To[i][x]; return x; }
inline int Dis (int x, int y) { return dep[x] + dep[y] - query (x, y) * 2; }
struct Cir { int x, r; Cir (int xx = 0, int rr = 0) { x = xx, r = rr; } }; 
inline Cir operator + (Cir a, Cir b) { 
	int ep = query (a.x, b.x), dis = dep[a.x] + dep[b.x] - ep * 2, cr = (dis + a.r + b.r) / 2, p = cr - a.r;
	if(dis + b.r <= a.r) return a;
	if(dis + a.r <= b.r) return b;
	return Cir (dep[a.x] - p >= ep ? up(a.x, p) : up(b.x, dis - p), cr); 
}
int Fa[N], rt, rtmax, FN;
void Count (int x, int fa) { ++FN; for(const int &v : e[x]) if (v != fa && ! vis[v]) Count (v, x); }
void findrt (int x, int fa) { 
	int mx = 0;
	siz[x] = 1; 
	for(const int &v : e[x]) if(v != fa && ! vis[v]) findrt (v, x), siz[x] += siz[v], mx = max(mx, siz[v]); 
	mx = max(mx, FN - siz[x]); 
	if (mx < rtmax) rtmax = mx, rt = x;  
}
int sdep[N];
void divi (int x, int qfa) {
	FN = 0, Count (x, 0), rtmax = 1e9, findrt (x, 0), vis[rt] = true, Fa[rt] = qfa; 
	sdep[rt] = sdep[qfa] + 1;
	if(sdep[rt] > 20) assert(0);
	int w = rt;
	for(const int &v : e[w]) if(!vis[v]) divi (v, w);
}
ll cntd[N], fcntd[N], cnt[N];
void add (int x, int w) {
	for (int u = x; u; u = Fa[u]) {
		cnt[u] += w, cntd[u] += w * Dis (x, u);
		if(Fa[u]) fcntd[u] += w * Dis (x, Fa[u]);
	}
}
ll query (int x) {
	ll res = 0;
	for(int u = x; u; u = Fa[u]) {
		res += cnt[u] * Dis (x, u) + cntd[u];
		if(Fa[u]) res -= cnt[u] * Dis (x, Fa[u]) + fcntd[u];
	}
	return res;
}
Cir cq[N];
ll qz[N];
void solve (int l, int r) {
	if(l == r) return ;
	int mid = (l + r) >> 1, sl = mid + 1, sr = mid + 1; 
	cq[mid + 1] = Cir (mid + 1, 0), cq[mid] = Cir (mid, 0), qz[mid] = 0;
	L(j, mid + 2, r) cq[j] = cq[j - 1] + Cir (j, 0);
	R(i, mid - 1, l) cq[i] = cq[i + 1] + Cir (i, 0);
	L(i, mid + 1, r) qz[i] = cq[i].r, qz[i] += qz[i - 1];
	ll sum = qz[r];
	R(i, mid, l) {
		while (sr <= r && Dis (cq[sr].x, cq[i].x) + cq[i].r > cq[sr].r) sum -= cq[sr].r, add (cq[sr].x, 1), ++sr; 
		while (sl <= r && Dis (cq[sl].x, cq[i].x) + cq[sl].r <= cq[i].r) add (cq[sl].x, -1), ++sl;
		ns += (qz[sr - 1] - qz[sl - 1] + (ll) (sr - sl) * cq[i].r + query (cq[i].x)) / 2 + 
			(ll) cq[i].r * (sl - mid - 1) + sum;
	}
	while (sl <= r) add(cq[sl].x, -1), ++sl;
	while (sr <= r) add(cq[sr].x, 1), ++sr;
	solve (l, mid), solve (mid + 1, r);
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	L(i, 2, n * 4) lg[i] = lg[i >> 1] + 1; 
	L(i, 1, n - 1) {
		int u, v;
		cin >> u >> v, eadd(u, i + n), eadd(v, i + n);
	}
	make(), divi(1, 0), solve(1, n), cout << ns << "\n";
	return 0;
}