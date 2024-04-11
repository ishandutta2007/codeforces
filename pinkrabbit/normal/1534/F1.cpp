#include <cstdio>
#include <algorithm>
#include <vector>

const int MN = 400005;

int N, M, A[MN], C;
std::vector<char> S[MN];
std::vector<int> Id[MN];

std::vector<int> G[MN];
inline void AddEdge(int x, int y) {
	G[x].push_back(y);
}

void Init() {
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
			if (S[i][j] == '#')
				Id[i][j] = ++C;
//	for (int i = N; i >= 1; --i)
//		for (int j = 1; j <= M; ++j)
//			printf("%2d%c", Id[i][j], " \n"[j == M]);
	static int top[MN];
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) if (S[i][j] == '#') {
			int u = Id[i][j];
			int w[4] = {
				top[j],
				Id[i][j - 1] ? Id[i][j - 1] : top[j - 1],
				Id[i][j + 1] ? Id[i][j + 1] : top[j + 1],
				Id[i + 1][j]
			};
			for (int t = 0; t < 4; ++t)
				if (w[t])
					AddEdge(u, w[t]);
		}
		for (int j = 1; j <= M; ++j)
			if (S[i][j] == '#')
				top[j] = Id[i][j];
	}
}

int stk[MN], top, instk[MN];
int dfn[MN], low[MN], dfc;
int bel[MN], scnt;
void Tarjan(int u) {
	low[u] = dfn[u] = ++dfc;
	instk[stk[++top] = u] = 1;
	for (int v : G[u]) {
		if (!dfn[v]) {
			Tarjan(v);
			low[u] = std::min(low[u], low[v]);
		} else if (instk[v])
			low[u] = std::min(low[u], dfn[v]);
	}
	if (low[u] == dfn[u]) {
		++scnt;
//		printf("# %d : ", scnt);
		while (true) {
			int x = stk[top--];
			bel[x] = scnt;
			instk[x] = 0;
//			printf("%d, ", x);
			if (x == u) break;
		}
//		puts("");
	}
}

void Solve() {
	static int indeg[MN], vis[MN];
	for (int i = 1; i <= C; ++i)
		if (!dfn[i]) Tarjan(i);
	for (int u = 1; u <= C; ++u)
		for (int v : G[u]) if (bel[v] != bel[u])
			++indeg[bel[v]];
	int Ans = 0;
	for (int i = 1; i <= C; ++i)
		if (!vis[bel[i]] && !indeg[bel[i]])
			++Ans, vis[bel[i]] = 1;
	printf("%d\n", Ans);
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i <= N + 1; ++i)
		S[i] = std::vector(M + 2, '.'),
		Id[i].resize(M + 2);
	for (int i = N; i >= 1; --i) {
		static char str[MN];
		scanf("%s", str + 1);
		for (int j = 1; j <= M; ++j)
			S[i][j] = str[j];
	}
//	for (int i = N; i >= 1; --i)
//		for (int j = 1; j <= M; ++j)
//			printf(" %c%c", S[i][j], " \n"[j == M]);
	for (int i = 1; i <= M; ++i)
		scanf("%d", &A[i]);
	Init();
	Solve();
	return 0;
}