#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

const int MN = 300005, MQ = 300005;

int N, Q, A[MN];
std::vector<int> G[MN];
int S1, S2;

int par[MN], dep[MN], siz[MN], pref[MN], top[MN], ldf[MN], rdf[MN], idf[MN * 2], val[MN * 2], dfc;
inline void Top(int x) { for (int y = x; y; y = pref[y]) top[y] = x; }
void DFS(int u, int p) {
	dep[u] = dep[par[u] = p] + 1, siz[u] = 1;
	idf[ldf[u] = ++dfc] = u;
	for (int v : G[u]) if (v != p) {
		DFS(v, u);
		siz[u] += siz[v];
		if (siz[pref[u]] < siz[v])
			pref[u] = v;
		idf[++dfc] = u;
	}
	rdf[u] = dfc;
	for (int v : G[u]) if (v != p && v != pref[u]) Top(v);
	if (!p) Top(u);
}
inline int LCA(int x, int y) {
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) std::swap(x, y);
		x = par[top[x]];
	}
	return dep[x] < dep[y] ? x : y;
}
int seq[MN], len;
inline void calcSeq(int x, int y) {
	for (len = 0; x != y; ) seq[++len] = x;
	std::reverse(seq + 1, seq + len + 1);
}

int be2[MN];
int buk[MN], num[MN];
inline void Add(int c) {
	buk[c] ^= 1;
	num[be2[c]] += buk[c] ? 1 : -1;
}
inline int Query(int l, int r) {
	int bl = be2[l], br = be2[r];
	if (bl == br) {
		for (int i = l; i <= r; ++i) if (buk[i]) return i;
		return -1;
	}
	for (int i = l; be2[i] == bl; ++i) if (buk[i]) return i;
	for (int i = r; be2[i] == br; --i) if (buk[i]) return i;
	for (int i = bl + 1; i <= br - 1; ++i) if (num[i])
		for (int j = (i - 1) * S2 + 1; j <= i * S2; ++j) if (buk[j]) return j;
	return -1;
}

int qx[MQ], qy[MQ], ql[MQ], qr[MQ], qp[MQ], Ans[MQ];
int bel[MN];

int main() {
	scanf("%d%d", &N, &Q);
	S1 = std::max(1, std::min(N, (int)(N / sqrt(Q * 2 / 3.))));
	S2 = std::max(1, std::min(N, (int)std::sqrt(N)));
	for (int i = 1; i <= N; ++i) scanf("%d", &A[i]);
	for (int i = 1, x, y; i < N; ++i) {
		scanf("%d%d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	DFS(1, 0);
	for (int i = 1; i < dfc; ++i) val[i] = A[idf[dep[idf[i]] > dep[idf[i + 1]] ? i : i + 1]];
	for (int i = 1; i <= N; ++i) bel[i] = (ldf[i] - 1) / S1 + 1;
	for (int i = 1; i <= N; ++i) be2[i] = (i - 1) / S2 + 1;
	for (int i = 1; i <= Q; ++i) {
		scanf("%d%d%d%d", &qx[i], &qy[i], &ql[i], &qr[i]);
		if (ldf[qx[i]] > ldf[qy[i]]) std::swap(qx[i], qy[i]);
		Ans[i] = -1, qp[i] = i;
	}
	std::sort(qp + 1, qp + Q + 1, [](int i, int j) {
		if (bel[qx[i]] != bel[qx[j]]) return bel[qx[i]] < bel[qx[j]];
		return (bool)((~bel[qx[i]] & 1) ^ (ldf[qy[i]] < ldf[qy[j]]));
	});
	int nx = 1, ny = 1;
	for (int i = 1; i <= Q; ++i) {
		int pnx = ldf[nx], pqx = ldf[qx[qp[i]]];
		int pny = ldf[ny], pqy = ldf[qy[qp[i]]];
		while (pqx < pnx) Add(val[--pnx]);
		while (pny < pqy) Add(val[pny++]);
		while (pnx < pqx) Add(val[pnx++]);
		while (pqy < pny) Add(val[--pny]);
		nx = qx[qp[i]], ny = qy[qp[i]];
		int lca = LCA(nx, ny);
		Add(A[lca]);
		Ans[qp[i]] = Query(ql[qp[i]], qr[qp[i]]);
		Add(A[lca]);
	}
	for (int i = 1; i <= Q; ++i) printf("%d\n", Ans[i]);
	return 0;
}