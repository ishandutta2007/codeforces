#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

typedef long long LL;
typedef double db;
const int MN = 200005;
const int MB = 1345;

inline void ckmax(LL &x, const LL &y) { x = x < y ? y : x; }
inline LL Abs(const LL &x) { return x < 0 ? -x : x; }

int N, Q, faz[MN], A[MN], B[MN];
std::vector<int> G[MN];
LL X[MN], Y[MN];
int ldf[MN], rdf[MN], dfc;
void DFS(int u) {
	int id = ldf[u] = ++dfc;
	X[id] = X[ldf[faz[u]]] + B[u];
	Y[id] = Y[ldf[faz[u]]] + A[u];
	for (auto v : G[u]) DFS(v);
	X[id] = Abs(X[id]);
	Y[id] *= X[id];
	rdf[u] = dfc;
}

int S, T, bel[MN], lb[MB], rb[MB], lenk[MB];
int _id[MN], *idk[MB];
int _que1[MN], *que1k[MB], ql1[MB], qr1[MB];
int _que2[MN], *que2k[MB], ql2[MB], qr2[MB];
int rk[MB], tag[MB];
LL ans[MB];

inline db Slope(const int &i, const int &j) {
	if (X[i] == X[j]) {
		if (Y[i] == Y[j]) return 0;
		else if (Y[i] < Y[j]) return 1e99;
		else return -1e99;
	}
	return (db)(Y[j] - Y[i]) / (X[j] - X[i]);
}

inline void Flush(const int &k) {
	if (!tag[k]) return ;
	int *que1 = que1k[k], *que2 = que2k[k];
	int &l1 = ql1[k], &r1 = qr1[k];
	int &l2 = ql2[k], &r2 = qr2[k];
	while (l1 < r1 && Slope(que1[l1], que1[l1 + 1]) > -rk[k]) ++l1;
	while (l2 < r2 && Slope(que2[r2 - 1], que2[r2]) > -rk[k]) --r2;
	int p1 = que1[l1], p2 = que2[r2];
	ans[k] = std::max(Y[p1] + rk[k] * X[p1], -Y[p2] - rk[k] * X[p2]);
	tag[k] = 0;
}

inline void ReBuild(const int &k) {
	int *id = idk[k], *que1 = que1k[k], *que2 = que2k[k];
	int &l1 = ql1[k], &r1 = qr1[k];
	int &l2 = ql2[k], &r2 = qr2[k];
	l1 = l2 = 1, r1 = r2 = 0;
	for (int I = 1; I <= lenk[k]; ++I) {
		int i = id[I];
		while (l1 < r1 && Slope(que1[r1 - 1], que1[r1]) < Slope(que1[r1], i)) --r1;
		while (l2 < r2 && Slope(que2[r2 - 1], que2[r2]) > Slope(que2[r2], i)) --r2;
		que1[++r1] = i, que2[++r2] = i;
	}
	tag[k] = 1, Flush(k);
}

int main() {
	scanf("%d%d", &N, &Q);
	for (int i = 2; i <= N; ++i)
		scanf("%d", &faz[i]),
		G[faz[i]].push_back(i);
	for (int i = 1; i <= N; ++i) scanf("%d", &A[i]);
	for (int i = 1; i <= N; ++i) scanf("%d", &B[i]);
	DFS(1);
	S = 150, T = (N - 1) / S + 1;
	for (int i = 1; i <= N; ++i) bel[i] = (i - 1) / S + 1;
	for (int i = 1; i <= N; ++i) _id[i] = i;
	for (int i = 1; i <= T; ++i) {
		lb[i] = (i - 1) * S + 1;
		rb[i] = std::min(i * S, N);
		lenk[i] = rb[i] - lb[i] + 1;
		idk[i] = _id + lb[i] - 1;
		que1k[i] = _que1 + lb[i] - 1;
		que2k[i] = _que2 + lb[i] - 1;
		auto cmp = [](int i, int j) { return X[i] < X[j]; };
		std::sort(idk[i] + 1, idk[i] + lenk[i] + 1, cmp);
		ReBuild(i);
	}
	while (Q--) {
		int op, u;
		scanf("%d%d", &op, &u);
		int l = ldf[u], r = rdf[u];
		int bl = bel[l], br = bel[r];
		if (op == 1) {
			int val;
			scanf("%d", &val);
			if (bl < br) {
				for (int i = l; i <= rb[bl]; ++i) Y[i] += val * X[i];
				for (int i = lb[br]; i <= r; ++i) Y[i] += val * X[i];
				ReBuild(bl), ReBuild(br);
				for (int k = bl + 1; k < br; ++k) rk[k] += val, tag[k] = 1;
			}
			else {
				for (int i = l; i <= r; ++i) Y[i] += val * X[i];
				ReBuild(bl);
			}
		}
		if (op == 2) {
			LL Ans = 0;
			if (bl < br) {
				for (int i = l; i <= rb[bl]; ++i) ckmax(Ans, Abs(Y[i] + rk[bl] * X[i]));
				for (int i = lb[br]; i <= r; ++i) ckmax(Ans, Abs(Y[i] + rk[br] * X[i]));
				for (int k = bl + 1; k < br; ++k) Flush(k), ckmax(Ans, ans[k]);
			}
			else for (int i = l; i <= r; ++i) ckmax(Ans, Abs(Y[i] + rk[bl] * X[i]));
			printf("%lld\n", Ans);
		}
	}
	return 0;
}