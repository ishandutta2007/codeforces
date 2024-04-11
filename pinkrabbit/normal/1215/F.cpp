#include <cstdio>
#include <algorithm>

const int MN = 400005, MV = 1600005, ME = 8000005;

int N, M1, M2, S, V;
int l[MN], r[MN];
int h[MV], nxt[ME], to[ME], tot;
inline void ins(int x, int y) { nxt[++tot] = h[x], to[tot] = y, h[x] = tot; }

int bel[MV], bcnt;
int dfn[MV], low[MV], dfc;
int stk[MV], top; bool instk[MV];
void Tarjan(int u) {
	low[u] = dfn[u] = ++dfc, stk[++top] = u, instk[u] = 1;
	for (int i = h[u]; i; i = nxt[i])
		if (!dfn[to[i]]) Tarjan(to[i]), low[u] = std::min(low[u], low[to[i]]);
		else if (instk[to[i]]) low[u] = std::min(low[u], dfn[to[i]]);
	if (low[u] == dfn[u]) {
		int x = 0; ++bcnt;
		while (x != u) bel[x = stk[top--]] = bcnt, instk[x] = 0;
	}
}

bool cho[MN * 2];

int main() {
	scanf("%d%d%d%d", &M1, &N, &S, &M2), V = (N + S) * 2 - 1;
	for (int i = 1; i <= M1; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		ins(x << 1, y << 1 | 1);
		ins(y << 1, x << 1 | 1);
	}
	for (int i = 1; i <= N; ++i) scanf("%d%d", &l[i], &r[i]);
	for (int i = 1; i <= M2; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		ins(x << 1 | 1, y << 1);
		ins(y << 1 | 1, x << 1);
	}
	for (int i = 2; i < S; ++i) {
		ins((N + i - 1) << 1 | 1, (N + i) << 1 | 1);
		ins((N + i) << 1, (N + i - 1) << 1);
	}
	for (int i = 1; i <= N; ++i) {
		if (l[i] > 1) {
			ins((N + l[i] - 1) << 1 | 1, i << 1);
			ins(i << 1 | 1, (N + l[i] - 1) << 1);
		}
		if (r[i] < S) {
			ins((N + r[i]) << 1, i << 1);
			ins(i << 1 | 1, (N + r[i]) << 1 | 1);
		}
	}
	for (int i = 2; i <= V; ++i) if (!dfn[i]) Tarjan(i);
	for (int i = 1; i < N + S; ++i)
		if (bel[i << 1] == bel[i << 1 | 1]) return puts("-1"), 0;
		else cho[i] = bel[i << 1] > bel[i << 1 | 1];
	int fc = S, cnt = 0;
	while (fc > 1 && cho[N + fc - 1]) --fc;
	for (int i = 1; i <= N; ++i) if (cho[i]) ++cnt;
	printf("%d %d\n", cnt, fc);
	for (int i = 1; i <= N; ++i) if (cho[i]) printf("%d ", i);
	puts("");
	return 0;
}