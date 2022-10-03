#include <cstdio>
#include <algorithm>
#include <vector>

typedef std::pair<int, int> pii;
const int MN = 200005;

int N, M;
std::vector<int> G[MN];
int faz[MN * 2], cnt;
std::vector<int> V[MN];
std::vector<pii> E[MN];
int deg[MN];

int stk[MN], tp;
int dfn[MN], low[MN], dfc;
void Tarjan(int u) {
	low[u] = dfn[u] = ++dfc;
	stk[++tp] = u;
	for (auto v : G[u]) {
		if (!dfn[v]) {
			Tarjan(v);
			low[u] = std::min(low[u], low[v]);
			if (low[v] == dfn[u]) {
				++cnt;
				for (int x = 0; x != v; --tp)
					faz[x = stk[tp]] = cnt,
					V[cnt - N].push_back(x);
				faz[cnt] = u;
				V[cnt - N].push_back(u);
			}
		} else low[u] = std::min(low[u], dfn[v]);
	}
}

int key[MN], vis[MN];
int DFS(int u, int f) {
	stk[++tp] = u;
	if (f && key[u]) return 1;
	if (vis[u]) return --tp, 0;
	vis[u] = 1;
	for (auto v : G[u]) if (v != f && DFS(v, u)) return 1;
	return --tp, 0;
}

int main() {
	scanf("%d%d", &N, &M), cnt = N;
	for (int i = 1, x, y; i <= M; ++i)
		scanf("%d%d", &x, &y),
		G[x].push_back(y),
		G[y].push_back(x);
	for (int u = 1; u <= N; ++u)
		if (!dfn[u]) Tarjan(u), --tp;
	for (int u = 1; u <= N; ++u)
		for (auto v : G[u]) if (v > u) {
			int b = faz[u] == faz[v] ? faz[u] : faz[faz[u]] == v ? faz[u] : faz[v];
			E[b - N].push_back({u, v});
		}
	for (int u = 1; u <= N; ++u) G[u].clear();
	cnt -= N;
	for (int i = 1; i <= cnt; ++i) {
		if (V[i].size() >= E[i].size()) continue;
		for (auto e : E[i]) {
			int u = e.first, v = e.second;
			G[u].push_back(v), G[v].push_back(u);
			++deg[u], ++deg[v];
		}
		int p = 0;
		for (auto u : V[i]) if (deg[u] >= 3) p = u;
		key[p] = 1, DFS(p, 0), key[p] = 0;
		static int Ans[MN]; int len = tp;
		for (int j = 1; j <= tp; ++j) Ans[j] = stk[j];
		for (int j = 2; j < len; ++j) key[Ans[j]] = 1;
		for (auto u : V[i]) vis[u] = 0;
		stk[tp = 1] = p, vis[p] = 1;
		for (auto v : G[p]) if (v != Ans[2] && v != Ans[len - 1] && DFS(v, p)) break;
		auto Print = [&](int *a, int x) {
			int c = 1;
			while (a[c] != x) ++c;
			printf("%d", c);
			for (int i = 1; i <= c; ++i) printf(" %d", a[i]);
			putchar('\n');
		};
		puts("YES");
		Print(stk, stk[tp]);
		Print(Ans, stk[tp]);
		std::reverse(Ans + 1, Ans + len + 1);
		Print(Ans, stk[tp]);
		return 0;
	} puts("NO");
	return 0;
}