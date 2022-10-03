#include <cstdio>
#include <algorithm>
#include <vector>

const int MN = 300005, MM = 300005;

int N;
std::vector<int> G[MN];
int par[19][MN], dep[MN], ldf[MN], rdf[MN], dfc;
void DFS(int u, int p) {
	ldf[u] = ++dfc;
	dep[u] = dep[par[0][u] = p] + 1;
	for (int j = 0; 2 << j < dep[u]; ++j)
		par[j + 1][u] = par[j][par[j][u]];
	for (int v : G[u]) if (v != p) DFS(v, u);
	rdf[u] = dfc;
}
int LCA(int x, int y) {
	if (dep[x] < dep[y]) std::swap(x, y);
	for (int d = dep[x] - dep[y], j = 0; d; d >>= 1, ++j)
		if (d & 1) x = par[j][x];
	if (x == y) return x;
	for (int j = 18; j >= 0; --j)
		if (par[j][x] != par[j][y])
			x = par[j][x], y = par[j][y];
	return par[0][x];
}
int cnt = 0;
int kpar(int x, int k) {
	if (k < 0) return ++cnt;
	for (int j = 0; k; k >>= 1, ++j)
		if (k & 1) x = par[j][x];
	return x;
}

int M;
struct path {
	int x, y;
	int lca, a, b;
} q[MM];

int bit[MN];
void Add(int i) { for (; i <= N; i += i & -i) ++bit[i]; }
int Qur(int i) { int s = 0; for (; i; i -= i & -i) s += bit[i]; return s; }

long long Ans;

int main() {
	scanf("%d", &N), cnt = N;
	for (int i = 1; i < N; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	DFS(1, 0);
	scanf("%d", &M);
	for (int i = 1; i <= M; ++i) {
		scanf("%d%d", &q[i].x, &q[i].y);
		q[i].lca = LCA(q[i].x, q[i].y);
		q[i].a = kpar(q[i].x, dep[q[i].x] - dep[q[i].lca] - 1);
		q[i].b = kpar(q[i].y, dep[q[i].y] - dep[q[i].lca] - 1);
		if (q[i].a > q[i].b)
			std::swap(q[i].x, q[i].y),
			std::swap(q[i].a, q[i].b);
	}
	std::sort(q + 1, q + M + 1, [](path i, path j) {
		if (dep[i.lca] != dep[j.lca]) return dep[i.lca] < dep[j.lca];
		if (i.lca != j.lca) return i.lca < j.lca;
		if (i.a != j.a) return i.a > j.a;
		return i.b > j.b;
	});
//	for (int i = 1; i <= M; ++i)
//		printf("%d %d %d %d %d\n", q[i].x, q[i].y, q[i].lca, q[i].a, q[i].b);
	for (int i = 1; i <= M; ++i) {
		int j = i;
		while (j < M && q[j + 1].lca == q[i].lca) ++j;
		static int buk[MN + MM * 2];
		int Cnt = 0;
		for (int k = i; k <= j; ++k) {
			int k2 = k;
			while (k2 < j && q[k2 + 1].a == q[k].a) ++k2;
			for (int p = k; p <= k2; ++p)
				Ans += Cnt - buk[q[p].b];
			for (int p = k; p <= k2; ++p)
				++buk[q[p].a], ++buk[q[p].b];
			Cnt += k2 - k + 1;
			k = k2;
		}
		for (int k = i; k <= j; ++k)
			buk[q[k].a] = buk[q[k].b] = 0;
		for (int k = i; k <= j; ++k) {
			Ans += Qur(rdf[q[k].lca]) - Qur(ldf[q[k].lca] - 1);
			if (q[k].a <= N) Ans -= Qur(rdf[q[k].a]) - Qur(ldf[q[k].a] - 1);
			if (q[k].b <= N) Ans -= Qur(rdf[q[k].b]) - Qur(ldf[q[k].b] - 1);
		}
		for (int k = i; k <= j; ++k)
			Add(ldf[q[k].x]), Add(ldf[q[k].y]);
		i = j;
	}
	printf("%lld\n", Ans);
	return 0;
}