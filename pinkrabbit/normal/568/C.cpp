#include <cstdio>
#include <cstring>
#include <vector>
#include <bitset>

const int MN = 205;

char VC[27];
int nx[27][2];
int N, M, Sig;
int bel[MN * 2], cnt;
std::vector<int> G[MN * 2], Dom[MN * 2];

int instk[MN * 2], stk[MN * 2], tp;
int dfn[MN * 2], low[MN * 2], dfc;
void Tarjan(int u) {
	low[u] = dfn[u] = ++dfc, stk[++tp] = u, instk[u] = 1;
	for (auto v : G[u])
		if (!dfn[v]) Tarjan(v), low[u] = std::min(low[u], low[v]);
		else if (instk[v]) low[u] = std::min(low[u], dfn[v]);
	if (low[u] == dfn[u]) {
		++cnt;
		for (int x = -1; x != u; --tp)
			bel[x = stk[tp]] = cnt,
			Dom[cnt].push_back(x),
			instk[x] = 0;
	}
}

std::bitset<400> Forbid[MN * 2], Tmp, Now[MN];

char A[MN], B[MN];
bool DFS(int i, int t) {
	if (i == N) return printf("%s\n", B), 1;
	int c = 0;
	if (!t) {
		int k = VC[A[i] - 'a'] == 'C';
		if (!Now[i][i << 1 | k]) {
			Now[i + 1] = Now[i] | Forbid[i << 1 | k];
			B[i] = A[i];
			if (DFS(i + 1, 0)) return 1;
		}
		c = A[i] - 'a' + 1;
	}
	int o = nx[c][0] > nx[c][1];
	if (nx[c][o] < Sig && !Now[i][i << 1 | o]) {
		Now[i + 1] = Now[i] | Forbid[i << 1 | o];
		B[i] = nx[c][o] + 'a';
		if (DFS(i + 1, 1)) return 1;
	} o ^= 1;
	if (nx[c][o] < Sig && !Now[i][i << 1 | o]) {
		Now[i + 1] = Now[i] | Forbid[i << 1 | o];
		B[i] = nx[c][o] + 'a';
		if (DFS(i + 1, 1)) return 1;
	}
	return 0;
}

int main() {
	scanf("%s", VC), Sig = strlen(VC);
	nx[Sig][0] = nx[Sig][1] = Sig;
	for (int i = Sig - 1; i >= 0; --i)
		nx[i][0] = VC[i] == 'V' ? i : nx[i + 1][0],
		nx[i][1] = VC[i] == 'C' ? i : nx[i + 1][1];
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= M; ++i) {
		int u, v; char U[3], V[3];
		scanf("%d%s%d%s", &u, U, &v, V), --u, --v;
		(u <<= 1) |= *U == 'C', (v <<= 1) |= *V == 'C';
		G[u].push_back(v), G[v ^ 1].push_back(u ^ 1);
	}
	for (int i = 0; i < N + N; ++i) if (!dfn[i]) Tarjan(i);
	for (int i = 0; i < N; ++i)
		if (bel[i << 1] == bel[i << 1 | 1])
			return puts("-1"), 0;
	for (int i = 1; i <= cnt; ++i) {
		Tmp.reset();
		for (auto u : Dom[i]) Tmp[u ^ 1] = 1;
		for (auto u : Dom[i]) for (auto v : G[u]) Tmp |= Forbid[v];
		for (auto u : Dom[i]) Forbid[u] = Tmp;
	}
	scanf("%s", A);
	if (!DFS(0, 0)) puts("-1");
	return 0;
}