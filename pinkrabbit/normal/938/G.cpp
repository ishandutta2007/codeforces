#include <cstdio>
#include <cstring>
#include <map>

const int MN = 200005, MM = 400005, MQ = 200005, MTS = 524288, MS = 10000005;

struct Basis {
	int b[30];
	void ins(int x) {
		for (int i = 29; ~i; --i) if (x >> i & 1) {
			if (!b[i]) { b[i] = x; return ; }
			x ^= b[i];
		}
	}
	int min(int x) {
		for (int i = 29; ~i; --i) if ((x ^ b[i]) < x) x ^= b[i];
		return x;
	}
} _0;

int N, M, Q, T, eu[MM], ev[MM], ew[MM], es[MM], et[MM];
int qt[MQ], qu[MQ], qv[MQ], Ans[MQ];
std::map<int, int> mp[MN];
int h[MTS], nxt[MS], t1[MS], t2[MS], tot;
inline void ins(int x, int y, int z) {
	nxt[++tot] = h[x], t1[tot] = y, t2[tot] = z, h[x] = tot;
}

#define mid ((l + r) >> 1)
void Mdf(int i, int l, int r, int a, int b, int x, int y) {
	if (r < a || b < l) return ;
	if (a <= l && r <= b) { ins(i, x, y); return ; }
	Mdf(i << 1, l, mid, a, b, x, y), Mdf(i << 1 | 1, mid + 1, r, a, b, x, y);
}

int st[MM], t;
int fa[MN], wgh[MN], sz[MN];
int ff(int x, int &v) {
	if (fa[x]) {
		int d = ff(fa[x], v);
		return v ^= wgh[x], d;
	}
	else return v = 0, x;
}
void Solve(int i, int l, int r, Basis B) {
	int ot = t;
	for (int j = h[i]; j; j = nxt[j]) if (t1[j]) {
		int u = eu[t2[j]], v = ev[t2[j]], w = ew[t2[j]], x, y;
		u = ff(u, x), v = ff(v, y);
		if (u == v) { B.ins(x ^ y ^ w); continue; }
		if (sz[v] < sz[u]) v ^= u ^= v ^= u;
		fa[u] = v, wgh[u] = x ^ y ^ w, sz[v] += sz[u], st[++t] = u;
	}
	if (l == r) {
		for (int j = h[i]; j; j = nxt[j]) if (!t1[j]) {
			int u = qu[t2[j]], v = qv[t2[j]], x, y;
			ff(u, x), ff(v, y);
			Ans[t2[j]] = B.min(x ^ y);
		}
	} else Solve(i << 1, l, mid, B), Solve(i << 1 | 1, mid + 1, r, B);
	while (t != ot) {
		sz[fa[st[t]]] -= sz[st[t]];
		fa[st[t]] = wgh[st[t]] = 0, --t;
	}
}

int main() {
	scanf("%d%d", &N, &M), T = 1;
	for (int i = 1; i <= N; ++i) sz[i] = 1;
	for (int i = 1; i <= M; ++i) {
		scanf("%d%d%d", &eu[i], &ev[i], &ew[i]);
		es[i] = T;
		mp[eu[i]][ev[i]] = i;
	}
	scanf("%d", &Q);
	for (int i = 1; i <= Q; ++i) {
		int op, x, y, z;
		scanf("%d%d%d", &op, &x, &y);
		if (op == 1) {
			scanf("%d", &z), ++M;
			eu[M] = x, ev[M] = y, ew[M] = z;
			es[M] = ++T;
			mp[x][y] = M;
		}
		if (op == 2) et[mp[x][y]] = T++;
		if (op == 3) qt[i] = T, qu[i] = x, qv[i] = y;
	}
	for (int i = 1; i <= M; ++i) Mdf(1, 1, T, es[i], et[i] ? et[i] : T, 1, i);
	for (int i = 1; i <= Q; ++i) if (qt[i]) Mdf(1, 1, T, qt[i], qt[i], 0, i);
	Solve(1, 1, T, _0);
	for (int i = 1; i <= Q; ++i) if (qt[i]) printf("%d\n", Ans[i]);
	return 0;
}