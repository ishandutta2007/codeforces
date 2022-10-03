#include <cstdio>

typedef long long LL;
const int MN = 100005, MM = 250005;

int N, M, d[MN], h[MN], nxt[MM * 2], to[MM * 2], vis[MM * 2], tot;
inline void ins(int x, int y) { nxt[++tot] = h[x], to[tot] = y, h[x] = tot; }

int stk[MM], tp;

void DFS(int u) {
	for (int &i = h[u]; i; i = nxt[i]) if (!vis[i]) vis[i] = vis[i ^ 1] = 1, DFS(to[i]);
	stk[++tp] = u;
}

int main() {
	scanf("%d%d", &N, &M), tot = 1;
	for (int i = 1, x, y; i <= M; ++i)
		scanf("%d%d", &x, &y),
		ins(x, y), ins(y, x),
		++d[x], ++d[y];
	for (int i = 1, o = 0; i <= N; ++i)
		o = d[i] & 1 ? o ? ins(o, i), ins(i, o), 0 : i : o;
	if (tot & 2) ins(1, 1), ins(1, 1);
	DFS(1);
	printf("%d\n", tot >> 1);
	for (int i = 1; i < tp; ++i) printf("%d %d\n", stk[i | 1], stk[i + (i & 1)]);
	return 0;
}