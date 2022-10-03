#include <cstdio>
#include <algorithm>
#include <vector>

typedef long long LL;
const LL Infll = 0x3f3f3f3f3f3f3f3f;
const int MN = 150005, MS = 1 << 19 | 7;

int N, deg[MN]; LL A[MN], Ans;
std::vector<int> G[MN];

int vis[MN];
int tsz, rt, rsz, sz[MN], dep[MN], leaf[MN];
void getRoot(int u, int p) {
	int mxs = 0; sz[u] = 1;
	for (int v : G[u]) if (!vis[v] && v != p) {
		getRoot(v, u);
		sz[u] += sz[v];
		mxs = std::max(mxs, sz[v]);
	} mxs = std::max(mxs, tsz - sz[u]);
	if (rsz > mxs) rt = u, rsz = mxs;
}
int frm[MN], pos[MN], tp;
LL upk[MN], upb[MN], dwn[MN];
inline void Add(int f, LL sum, LL up, LL dw, int d) {
	frm[++tp] = f, upk[tp] = sum, upb[tp] = up, dwn[tp] = dw, pos[tp] = d;
}
void DFS(int u, int p, int f, LL sum, LL up, LL dw) {
	dep[u] = dep[p] + 1;
	if (u != rt && !f) f = u;
	if (deg[u] == 1) Add(f, sum - A[rt], up, dw, dep[u]);
	leaf[u] = deg[u] == 1;
	for (int v : G[u]) if (!vis[v] && v != p)
		DFS(v, u, f, sum + A[v], up + dep[u] * A[v], dw + sum + A[v]),
		leaf[u] += leaf[v];
}
#define li (i << 1)
#define ri (li | 1)
#define mid ((l + r) >> 1)
#define ls li, l, mid
#define rs ri, mid + 1, r
struct dat {
	LL k, b;
	dat(LL K = 0, LL B = -Infll) : k(K), b(B) {}
	LL at(int p) { return k * p + b; }
} t[MS];
void Build(int i, int l, int r) {
	t[i] = dat();
	if (l == r) return ;
	Build(ls), Build(rs);
}
void Mdf(int i, int l, int r, dat x) {
	LL l0 = t[i].at(l), r0 = t[i].at(r);
	LL l1 = x.at(l), r1 = x.at(r);
	if (l1 <= l0 && r1 <= r0) return ;
	if (l1 >= l0 && r1 >= r0) return t[i] = x, void();
	if (t[i].at(mid) < x.at(mid)) std::swap(t[i], x);
	x.k < t[i].k ? Mdf(ls, x) : Mdf(rs, x);
}
LL Qur(int i, int l, int r, int p) {
	LL ret = t[i].at(p);
	if (l == r) return ret;
	return std::max(ret, p <= mid ? Qur(ls, p) : Qur(rs, p));
}
void Solve(int u) {
	tp = 0, DFS(u, 0, 0, A[u], 0, A[u]);
	int mxdep = *std::max_element(pos + 1, pos + tp + 1);
	Build(1, 1, mxdep);
	for (int i = 1, j; i <= tp; i = j) {
		for (j = i; j <= tp && frm[j] == frm[i]; ++j) Ans = std::max(Ans, Qur(1, 1, mxdep, pos[j]) + dwn[j]);
		for (j = i; j <= tp && frm[j] == frm[i]; ++j) Mdf(1, 1, mxdep, dat(upk[j], upb[j]));
	}
	Build(1, 1, mxdep);
	for (int i = tp, j; i >= 1; i = j) {
		for (j = i; j >= 1 && frm[j] == frm[i]; --j) Ans = std::max(Ans, Qur(1, 1, mxdep, pos[j]) + dwn[j]);
		for (j = i; j >= 1 && frm[j] == frm[i]; --j) Mdf(1, 1, mxdep, dat(upk[j], upb[j]));
	}
	int osz = tsz; vis[u] = 1;
	for (int v : G[u]) if (!vis[v] && leaf[v] >= 2) {
		rsz = tsz = sz[v] < sz[u] ? sz[v] : osz - sz[u];
		getRoot(v, u), Solve(rt);
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 1, x, y; i < N; ++i) {
		scanf("%d%d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
		++deg[x], ++deg[y];
	}
	for (int i = 1; i <= N; ++i) scanf("%lld", &A[i]);
	rsz = tsz = N, getRoot(1, 0), Solve(rt);
	printf("%lld\n", Ans);
	return 0;
}