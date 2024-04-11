#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>

const int Inf = 0x3f3f3f3f;
const int MN = 450005;

int N, M, E;
int eu[MN], ev[MN], ew[MN];
struct Cmp { inline bool operator () (int a, int b) { return ew[a] == ew[b] ? a > b : ew[a] > ew[b]; } };
std::set<int, Cmp> ste;

int f[MN], c[MN][2], r[MN], val[MN], mxv[MN], key[MN], vky[MN], tky[MN];

#define iv inline void
#define ii inline int
#define lc c[x][0]
#define rc c[x][1]
ii nrt(int x) { return c[f[x]][0] == x || c[f[x]][1] == x; }
iv upd(int x) {
	mxv[x] = x;
	if (val[mxv[x]] < val[mxv[lc]]) mxv[x] = mxv[lc];
	if (val[mxv[x]] < val[mxv[rc]]) mxv[x] = mxv[rc];
	tky[x] = tky[lc] + tky[rc] + key[x] + vky[x];
}
iv rv(int x) { std::swap(lc, rc), r[x] ^= 1; }
iv psd(int x) { if (r[x]) { if (lc) rv(lc); if (rc) rv(rc); r[x] = 0; } }
iv rtt(int x) {
	int y = f[x], z = f[y], d = c[y][1] == x, a = c[x][!d];
	if (nrt(y)) c[z][c[z][1] == y] = x;
	c[x][!d] = y, c[y][d] = a;
	if (a) f[a] = y;
	f[x] = z, f[y] = x;
	upd(y);
}
iv splay(int x) {
	static int st[MN], t;
	int y = x, z;
	st[t = 1] = y;
	while (nrt(y)) st[++t] = y = f[y];
	while (t) psd(st[t--]);
	while (nrt(x)) {
		y = f[x], z = f[y];
		if (nrt(y)) rtt((c[y][1] == x) ^ (c[z][1] == y) ? x : y);
		rtt(x);
	} upd(x);
}
iv acs(int x) { for (int y = 0; x; x = f[y = x]) splay(x), vky[x] += tky[rc] - tky[y], rc = y, upd(x); }
iv mkrt(int x) { acs(x), splay(x), rv(x); }
ii fdrt(int x) { acs(x), splay(x); while (lc) x = lc; splay(x); return x; }

iv dele(int i) {
	ste.erase(i), mkrt(i), acs(i);
	splay(eu[i]), f[eu[i]] = 0;
	splay(ev[i]), f[ev[i]] = 0;
}

int main() {
	scanf("%d%d", &N, &M);
	if (N & 1) { while (M--) puts("-1"); return 0; }
	E = N;
	for (int i = 1; i <= N; ++i) tky[i] = key[i] = 1;
	for (int i = 1; i <= N / 2; ++i) {
		++E, eu[E] = i * 2 - 1, ev[E] = i * 2, ew[E] = Inf;
		mxv[E] = E, val[E] = Inf;
		f[i * 2 - 1] = E, vky[E] += tky[i * 2 - 1];
		f[i * 2] = E, vky[E] += tky[i * 2];
		ste.insert(E);
	}
	while (M--) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		++E, eu[E] = u, ev[E] = v, ew[E] = w;
		mkrt(u);
		if (fdrt(v) != u) {
			mxv[E] = val[E] = w;
			mkrt(v), f[u] = f[v] = E;
			vky[E] += tky[u] + tky[v];
			ste.insert(E);
		} else {
			acs(v), splay(v);
			int del = mxv[v];
			if (ew[del] > w) {
				mxv[E] = E, val[E] = w;
				dele(del);
				mkrt(u), mkrt(v), f[u] = f[v] = E;
				vky[E] += tky[u] + tky[v];
				ste.insert(E);
			}
		}
		while (1) {
			int e = *ste.begin();
			mkrt(eu[e]), acs(e);
			if (~vky[e] & 1) dele(e);
			else break;
		}
		int ans = ew[*ste.begin()];
		printf("%d\n", ans == Inf ? -1 : ans);
	}
	return 0;
}