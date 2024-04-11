#include <cstdio>
#include <vector>
#include <algorithm>

// luogu

const int MN = 100005, MD = 55;

int N, M, D;
std::vector<int> G[MN], T[MN];
char s[MD]; int w[MN][MD];

int dfn[MN], low[MN], stk[MN], instk[MN], tp, dfc;
int dep[MN], bel[MN], per[MN], tic[MN], itic[MN], bcnt;
void Tarjan(int u) {
	low[u] = dfn[u] = ++dfc;
	stk[++tp] = u, instk[u] = 1;
	for (auto v : G[u]) {
		if (!dfn[v]) {
			dep[v] = dep[u] + 1, Tarjan(v);
			low[u] = std::min(low[u], low[v]);
		}
		else if (instk[v]) low[u] = std::min(low[u], dfn[v]);
	}
	if (low[u] == dfn[u]) {
		++bcnt;
		for (int x = 0; x != u; --tp) {
			x = stk[tp];
			bel[x] = bcnt;
			T[bcnt].push_back(x);
			instk[x] = 0;
		}
	}
}

int f[MN][MD];

int main() {
	scanf("%d%d%d", &N, &M, &D);
	for (int i = 1; i <= M; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
	}
	for (int i = 1; i <= N; ++i)
		if (!dfn[i]) dep[i] = 1, Tarjan(i);
	for (int i = 1; i <= bcnt; ++i) per[i] = D;
	for (int u = 1; u <= N; ++u)
		for (auto v : G[u]) if (bel[u] == bel[v])
			per[bel[u]] = std::__gcd(per[bel[u]], std::abs(dep[u] - dep[v] + 1));
	for (int i = 1; i <= N; ++i)
		tic[i] = dep[i] % per[bel[i]], itic[i] = tic[i] ? per[bel[i]] - tic[i] : 0;
	for (int i = 1; i <= N; ++i) {
		scanf("%s", s);
		for (int j = 0; j < D; ++j) w[i][j] = s[j] - '0';
	}
	for (int id = 1; id <= bcnt; ++id) {
		int pr = per[id];
		static int cnt[MD];
		for (int j = 0; j < pr; ++j) cnt[j] = 0;
		for (int j = 0; j < pr; ++j) {
			for (auto u : T[id]) for (int k = 0; k < D; k += pr)
				if (w[u][(k + tic[u] + j) % D]) { ++cnt[j]; break; }
		}
		for (int j = 0; j < pr; ++j) {
			f[id][j] = cnt[j];
			for (auto u : T[id]) {
				int ticv = (j + tic[u] + 1) % pr;
				for (auto v : G[u]) if (bel[v] != id) {
					for (int k = 0; k < D; k += pr)
						f[id][j] = std::max(f[id][j], cnt[j] + f[bel[v]][(itic[v] + k + ticv) % per[bel[v]]]);
				}
			}
		}
	}
	printf("%d\n", f[bel[1]][itic[1]]);
	return 0;
}

// 19-03-10 00:18 ~ 19-03-10 00:54