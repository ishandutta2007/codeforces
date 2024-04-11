#include <cstdio>
#define eF(i, u) for (int i = eh[u]; i; i = nxt[i])

inline int max(int i, int j) { return i > j ? i : j; }

typedef long long LL;
const int INF = 0x3f3f3f3f;
const int MN = 200005;

int N, col[MN];
char str[MN];

int eh[MN], nxt[MN * 2], to[MN * 2], tot;
inline void ins(int x, int y) {
	nxt[++tot] = eh[x]; to[tot] = y; eh[x] = tot;
}

int siz[MN], w[MN], vis[MN];

int GetRoot(int u, int fa, int Tsiz) {
	int Root = 0;
	siz[u] = 1; int Mx = 0;
	eF(i, u) if (to[i] != fa && !vis[to[i]]) {
		int tRoot = GetRoot(to[i], u, Tsiz);
		siz[u] += siz[to[i]];
		if (Mx < siz[to[i]])
			Mx = siz[to[i]];
		if (w[tRoot] < w[Root])
			Root = tRoot;
	}
	w[u] = max(Mx, Tsiz - siz[u]);
	if (w[u] < w[Root])
		Root = u;
	return Root;
}

LL Ans[MN];

int bc[1 << 20 | 1];
int stk[MN], top;

void Dfs0(int u, int fa, int d) {
	d ^= col[u];
	++bc[d]; stk[++top] = d;
	eF(i, u) if (!vis[to[i]] && to[i] != fa)
		Dfs0(to[i], u, d);
}

LL Dfs1(int u, int fa, int d, int f) {
	d ^= col[u];
	LL Sum = bc[d];
	for (int j = 0; j < 20; ++j)
		Sum += bc[d ^ 1 << j];
	eF(i, u) if (!vis[to[i]] && to[i] != fa)
		Sum += Dfs1(to[i], u, d, f);
	Ans[u] += f * Sum;
	return Sum;
}

LL solve(int u, int d, int f) {
	Dfs0(u, 0, 0);
	LL tmp = Dfs1(u, 0, d, f);
	while (top)
		--bc[stk[top--]];
	return tmp;
}

void DFS(int u) {
	LL LstAns = Ans[u];
	solve(u, col[u], 1);
	vis[u] = 1;
	eF(i, u) if (!vis[to[i]])
		Ans[u] -= solve(to[i], col[u], -1);
	Ans[u] = LstAns + (Ans[u] - LstAns + 1 >> 1);
	eF(i, u) if (!vis[to[i]]) {
		int Root = GetRoot(to[i], 0, siz[to[i]]);
		DFS(Root);
	}
}

int main() {
	int x, y;
	scanf("%d", &N);
	for (int i = 1; i < N; ++i)
		scanf("%d%d", &x, &y),
		ins(x, y), ins(y, x);
	scanf("%s", str);
	for (int i = 1; i <= N; ++i)
		col[i] = 1 << str[i - 1] - 'a';
	w[0] = INF;
	int Root = GetRoot(1, 0, N);
	DFS(Root);
	for (int i = 1; i <= N; ++i)
		printf("%lld ", Ans[i]);
	return 0;
}