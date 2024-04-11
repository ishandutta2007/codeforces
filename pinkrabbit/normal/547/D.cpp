#include <cstdio>

const int MN = 400005, MM = 1200005, X = 200000;

int N, deg[MN], h[MN], nxt[MM], to[MM], usd[MM], tot;
inline void ins(int x, int y) { nxt[++tot] = h[x], to[tot] = y, h[x] = tot; }
inline void insw(int x, int y) { ++deg[x], ++deg[y], ins(x, y), ins(y, x); }

char Ans[200005];

int vis[MN], cnt;
void Euler(int u, int e) {
	for (int &i = h[u]; i; i = nxt[i]) if (!usd[i])
		usd[i] = usd[i ^ 1] = 1, Euler(to[i], i / 2);
	if (e) {
		cnt ^= 1;
		if (e <= N) Ans[e] = "rb"[cnt];
	}
}

int main() {
	scanf("%d", &N), tot = 1;
	for (int i = 1, x, y; i <= N; ++i) {
		scanf("%d%d", &x, &y);
		insw(x, X + y);
	}
	for (int i = 1; i <= X + X; ++i)
		if (deg[i] & 1) insw(i, i <= X ? X + X + 2 : X + X + 1);
	if (deg[X + X + 1] & 1) insw(X + X + 1, X + X + 2);
	for (int i = 1; i <= X + X; ++i) if (!vis[i]) Euler(i, 0);
	printf("%s\n", Ans + 1);
	return 0;
}