#include <cstdio>
#include <algorithm>

typedef long long LL;
const int MN = 100005;

int N, h[MN], nxt[MN * 2], to[MN * 2], w[MN * 2], tot;
inline void ins(int x, int y, int z) {
	nxt[++tot] = h[x], to[tot] = y, w[tot] = z, h[x] = tot;
}

LL d[MN], d0[MN], d1[MN]; int p[MN], q[MN];
void DFS0(int u, int fz) {
	for (int i = h[u]; i; i = nxt[i]) if (to[i] != fz)
		DFS0(to[i], u), d0[u] = std::max(d0[u], d0[to[i]] + w[i]);
}
void DFS1(int u, int fz) {
	static LL pre[MN], suf[MN]; int t = 0;
	for (int i = h[u]; i; i = nxt[i]) if (to[i] != fz)
		++t, pre[t] = suf[t] = d0[to[i]] + w[i];
	pre[0] = suf[t + 1] = d1[u];
	for (int i = 1; i <= t; ++i) pre[i] = std::max(pre[i], pre[i - 1]);
	for (int i = t; i >= 1; --i) suf[i] = std::max(suf[i], suf[i + 1]);
	t = 0;
	for (int i = h[u]; i; i = nxt[i]) if (to[i] != fz)
		++t, d1[to[i]] = std::max(pre[t - 1], suf[t + 1]) + w[i];
	for (int i = h[u]; i; i = nxt[i]) if (to[i] != fz) DFS1(to[i], u);
	d[u] = std::max(d0[u], d1[u]);
}

struct dsue { int fa, rk, cnt; } dsu[MN];
inline int ff(int x) {
	int y = x, z, r;
	while (dsu[y].fa) y = dsu[y].fa;
	r = y, y = x;
	while (dsu[y].fa) z = y, y = dsu[y].fa, dsu[z].fa = r;
	return r;
}
inline void merge(int x, int y) {
	x = ff(x), y = ff(y);
	if (x == y) return ;
	if (dsu[x].rk < dsu[y].rk) std::swap(x, y);
	dsu[y].fa = x, dsu[x].rk += dsu[y].rk, dsu[x].cnt += dsu[y].cnt;
}
inline void dec(int x) { --dsu[ff(x)].cnt; }

int main() {
	scanf("%d", &N);
	for (int i = 1, x, y, z; i < N; ++i)
		scanf("%d%d%d", &x, &y, &z),
		ins(x, y, z), ins(y, x, z);
	DFS0(1, 0), DFS1(1, 0);
	for (int u = 1; u <= N; ++u) p[u] = u;
	std::sort(p + 1, p + N + 1, [](int u, int v) { return d[u] > d[v]; });
	for (int u = 1; u <= N; ++u) q[p[u]] = u;
	int Q; scanf("%d", &Q);
	while (Q--) {
		LL l; scanf("%lld", &l);
		int Ans = 0;
		for (int u = 1; u <= N; ++u) dsu[u].fa = 0, dsu[u].rk = dsu[u].cnt = 1;
		int J = 1;
		for (int I = 1; I <= N; ++I) {
			int u = p[I];
			for (int i = h[u]; i; i = nxt[i])
				if (q[to[i]] < I) merge(to[i], u);
			while (d[p[J]] > d[u] + l) dec(p[J++]);
			Ans = std::max(Ans, dsu[ff(u)].cnt);
		} printf("%d\n", Ans);
	}
	return 0;
}