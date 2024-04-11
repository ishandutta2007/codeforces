#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define repe for(int i = head[u], v; i; i = e[i].nxt) if((v = e[i].v) ^ fa)
 
using namespace std;
const int N = 2e5 + 5, MI = 1e6;
typedef long long ll;
int read() {
	static streambuf* in = cin.rdbuf();
	#define gc (p1 == p2 && (p2 = (p1 = buf) + in -> sgetn(buf, MI), p1 == p2) ? -1 : *p1++)
	static char buf[MI], *p1, *p2;
	int c = gc, r = 0;
	while(c < 48) c = gc;
	while(c > 47) r = (r << 3) + (r << 1) + (c & 15), c = gc;
	return r;
}
void wrt(ll x) {
	static streambuf* out = cout.rdbuf();
	#define pc out -> sputc
	static char ch[20]; int sz = 0;
	if(!x) pc(48);
	else {
		while(x) ch[++sz] = x % 10, x /= 10;
		while(sz) pc(ch[sz--] + 48);
	} pc(32);
}
int n, cnt, head[N], sz[N], g[N][18];
int len, in[N], rnd[N], wrnd[N], tp;
struct edge { int v, nxt, w; } e[N*2];
ll sum, ans[N], f1[N], f2[N], p[N][18], w[N][18], d[N][18];
void add(int u, int v, int w) {
	e[++cnt] = (edge){ v, head[u], w };
	head[u] = cnt;
}
void dfs(int u, int fa) {
	if(in[u]) {
		int p = find(rnd + 1, rnd + tp + 1, u) - rnd;
		len = tp - p + 1;
		rep(i, 1, p - 1) in[rnd[i]] = 0;
		rep(i, 1, len) rnd[i] = rnd[i+p-1], wrnd[i] = wrnd[i+p-1];
		return;
	}
	in[u] = 1, rnd[++tp] = u;
	repe {
		wrnd[tp] = e[i].w, dfs(v, u);
		if(len) return;
	}
	in[u] = 0, tp--;
}
void dp1(int u, int fa) {
	sz[u] = 1;
	repe if(!in[v]) {
		dp1(v, u), sz[u] += sz[v];
		f1[u] += f1[v] + (ll)e[i].w * sz[v];
	}
}
void dp2(int u, int fa, int n) {
	repe if(!in[v]) {
		f2[v] = f2[u] + f1[u] - (f1[v] + (ll)e[i].w * sz[v])
		+ e[i].w * (n - sz[v]);
		dp2(v, u, n);
	}
}
void slv(int n, int ty) {
	rep(i, 1, n) {
		int v = rnd[p[i][0] = i % n + 1];
		w[i][0] = wrnd[i], g[i][0] = sz[v];
		d[i][0] = f1[v] + w[i][0] * sz[v];
	}
	rep(i, 1, 17) rep(j, 1, n) {
		int v = p[j][i-1]; p[j][i] = p[v][i-1];
		w[j][i] = w[j][i-1] + w[v][i-1];
		g[j][i] = g[j][i-1] + g[v][i-1];
		d[j][i] = d[j][i-1] + d[v][i-1] + w[j][i-1] * g[v][i-1];
	}
	rep(i, 1, n) {
		int u = i; ll sw = 0;
		per(j, 17, 0) if((sw + w[u][j]) * 2 + ty <= sum) {
			ans[rnd[i]] += d[u][j] + sw * g[u][j];
			sw += w[u][j], u = p[u][j];
		}
	}
}
void calc(int u, int fa, int m, ll sum) {
	f1[u] += f2[u] + sum;
	repe if(!in[v]) calc(v, u, m, sum + (ll)e[i].w * m);
}
int main() {
	#ifdef local
		freopen("in.txt", "r", stdin);
	#endif
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	per(i, n = read(), 1) {
		int u = read(), v = read(), w = read();
		add(u, v, w), add(v, u, w);
	}
	dfs(1, 0);
	rep(i, 1, len) {
		dp1(rnd[i], 0), dp2(rnd[i], 0, sz[rnd[i]]);
		sum += wrnd[i];
	}
	slv(len, 0), reverse(rnd + 1, rnd + len + 1);
	reverse(wrnd + 1, wrnd + len + 1);
	rep(i, 2, len) swap(wrnd[i], wrnd[i-1]);
	slv(len, 1);
	rep(i, 1, len) calc(rnd[i], 0, n - sz[rnd[i]], ans[rnd[i]]);
	rep(i, 1, n) wrt(f1[i]);
	return 0;
}