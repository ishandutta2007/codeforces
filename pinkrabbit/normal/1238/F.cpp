#include <cstdio>
#include <algorithm>

const int MN = 300005;

int N, Ans, root, deg[MN], h[MN], nxt[MN * 2], to[MN * 2], tot;
inline void ins(int x, int y) { nxt[++tot] = h[x], to[tot] = y, h[x] = tot; }

int cnt[MN], f[MN];
void DFS(int u, int fz) {
	cnt[u] = 0;
	int Mx1 = 0, Mx2 = 0;
	for (int i = h[u]; i; i = nxt[i]) if (to[i] != fz) {
		DFS(to[i], u), ++cnt[u];
		Mx2 = std::max(Mx2, f[to[i]]);
		if (Mx2 > Mx1) std::swap(Mx1, Mx2);
	}
	Ans = std::max(Ans, Mx1 + Mx2 + cnt[u] + 1 + (u != root));
	f[u] = Mx1 + cnt[u];
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &N), tot = Ans = 0;
		for (int i = 1; i <= N; ++i) h[i] = deg[i] = 0;
		for (int i = 1; i < N; ++i) {
			int x, y;
			scanf("%d%d", &x, &y);
			ins(x, y), ins(y, x);
			++deg[x], ++deg[y];
		}
		if (N <= 6) { printf("%d\n", N); continue; }
		for (int i = 1; i <= N; ++i) if (deg[i] > 1) root = i;
		DFS(root, 0);
		printf("%d\n", Ans);
	}
	return 0;
}

// 23:45 ~ 23:58