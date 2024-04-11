#include <cstdio>
#include <algorithm>

const int Inf = 0x3f3f3f3f;
const int MN = 105;

int N;
struct dat {
	int a, l, lb;
	dat() {}
	dat(int _a, int _l) : a(_a), l(_l) {}
} d[MN];
inline bool cmp(dat i, dat j) { return i.a < j.a; }
int idl[MN], lmid[MN];
int st[MN][7];
inline int minid(int l, int r) {
	int j = std::__lg(r - l + 1), x = st[l + (1 << j) - 1][j], y = st[r][j];
	return d[x].lb < d[y].lb ? x : y;
}

int f[MN * 2];
int DP(int u) {
	if (~f[u]) return f[u];
	int v, x;
	if (!u) v = N, x = Inf;
	else if (u & 1) v = idl[u / 2 + 1] - 1, x = d[u / 2 + 1].lb;
	else v = u / 2 - 1, x = d[u / 2].a;
	if (!v) return f[u] = 0;
	f[u] = d[v].a - d[lmid[v]].lb + DP(lmid[v] * 2 - 1);
	for (int i = v; i >= 1; --i) {
		if (d[i].a + d[i].l <= d[v].a) continue;
		int id = i < v ? minid(i + 1, v) : 0;
		if (!id || d[id].lb > d[i].a) f[u] = std::max(f[u], std::min(d[i].l, x - d[i].a) + DP(i * 2));
		else {
			int iid = idl[id] < i ? lmid[minid(idl[id], i - 1)] : id;
			if (d[iid].lb > d[id].lb) iid = id;
			f[u] = std::max(f[u], std::min(d[i].a + d[i].l, x) - d[iid].lb + DP(iid * 2 - 1));
		}
	}
	return f[u];
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) scanf("%d%d", &d[i].a, &d[i].l), d[i].lb = d[i].a - d[i].l;
	std::sort(d + 1, d + N + 1, cmp);
	for (int i = 1; i <= N; ++i)
		idl[i] = std::lower_bound(d + 1, d + N + 1, dat(d[i].lb, 0), cmp) - d;
	for (int i = 1; i <= N; ++i) st[i][0] = i;
	for (int j = 0; j < 6; ++j)
		for (int i = 2 << j; i <= N; ++i) {
			int x = st[i - (1 << j)][j], y = st[i][j];
			st[i][j + 1] = d[x].lb < d[y].lb ? x : y;
		}
	for (int i = 1; i <= N; ++i) {
		int x = minid(idl[i], i);
		lmid[i] = x == i ? i : lmid[x];
	}
	for (int i = 0; i <= N + N; ++i) f[i] = -1;
	printf("%d\n", DP(0));
	return 0;
}