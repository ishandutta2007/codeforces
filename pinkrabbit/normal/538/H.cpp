#include <cstdio>
#include <algorithm>
#include <vector>

const int MN = 100005;

int tl, tr, N, M;
int l[MN], r[MN], n1, n2;
int col[MN], ok;
std::vector<int> G[MN];

void DFS(int u) {
	for (auto v : G[u]) {
		if (col[v] == col[u]) ok = 0;
		if (!col[v]) col[v] = 3 - col[u], DFS(v);
	}
}

int main() {
	scanf("%d%d", &tl, &tr);
	scanf("%d%d", &N, &M);
	n1 = 1e9, n2 = 0;
	for (int i = 1; i <= N; ++i) {
		scanf("%d%d", &l[i], &r[i]);
		n1 = std::min(n1, r[i]);
		n2 = std::max(n2, l[i]);
	}
	if (n1 + n2 < tl) n2 = tl - n1;
	if (n1 + n2 > tr) n1 = tr - n2;
	if (n1 < 0 || n2 < 0) return puts("IMPOSSIBLE"), 0;
	for (int i = 1; i <= N; ++i) {
		int p1 = l[i] <= n1 && n1 <= r[i];
		int p2 = l[i] <= n2 && n2 <= r[i];
		if (!p1 && !p2) return puts("IMPOSSIBLE"), 0;
		if (!p2) col[i] = 1;
		if (!p1) col[i] = 2;
	}
	for (int i = 1, x, y; i <= M; ++i)
		scanf("%d%d", &x, &y),
		G[x].push_back(y),
		G[y].push_back(x);
	ok = 1;
	for (int i = 1; i <= N; ++i) if (col[i]) DFS(i);
	for (int i = 1; i <= N; ++i) if (!col[i]) col[i] = 1, DFS(i);
	if (!ok) return puts("IMPOSSIBLE"), 0;
	puts("POSSIBLE");
	printf("%d %d\n", n1, n2);
	for (int i = 1; i <= N; ++i) printf("%d", col[i]);
	puts("");
	return 0;
}