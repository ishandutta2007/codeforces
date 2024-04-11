#include <cstdio>

const int MN = 200005;

int N, Q, id[MN];

int ch[MN][26], pa[MN], fail[MN], cnt;
int Insert(char *s) {
	int now = 0;
	for (; *s; ++s) {
		int j = *s - 'a';
		if (!ch[now][j]) pa[ch[now][j] = ++cnt] = now;
		now = ch[now][j];
	} return now;
}
int h[MN], q[MN], nxt[1200005], to[1200005], tot;
inline void ins(int *a, int x, int y) { nxt[++tot] = a[x], to[tot] = y, a[x] = tot; }
int ldf[MN], rdf[MN], dfc;
void DFS(int u) {
	ldf[u] = ++dfc;
	for (int i = h[u]; i; i = nxt[i]) DFS(to[i]);
	rdf[u] = dfc;
}
void BuildAC() {
	static int que[MN]; int l, r;
	fail[0] = -1, que[l = r = 1] = 0;
	while (l <= r) {
		int u = que[l++];
		for (int j = 0; j < 26; ++j) {
			int v = u ? ch[fail[u]][j] : 0;
			if (ch[u][j]) fail[ch[u][j]] = v, ins(h, v, ch[u][j]), que[++r] = ch[u][j];
			else ch[u][j] = v;
		}
	}
	DFS(0);
}

int b[MN];
void Add(int i) { for (; i <= dfc; i += i & -i) ++b[i]; }
int Qur(int i) { int a = 0; for (; i; i -= i & -i) a += b[i]; return a; }
int k[500005], Ans[500005];

int main() {
	scanf("%d%d", &N, &Q);
	for (int i = 1; i <= N; ++i) {
		static char str[MN];
		scanf("%s", str);
		id[i] = Insert(str);
	} BuildAC();
	for (int i = 1, x, y; i <= Q; ++i) {
		scanf("%d%d%d", &x, &y, &k[i]);
		if (x > 1) ins(q, x - 1, -i);
		ins(q, y, i);
	}
	for (int i = 1; i <= N; ++i) {
		int x = id[i];
		while (x) Add(ldf[x]), x = pa[x];
		for (int j = q[i]; j; j = nxt[j]) {
			int o = to[j] < 0 ? -1 : 1, u = o * to[j], v = id[k[u]];
			Ans[u] += o * (Qur(rdf[v]) - Qur(ldf[v] - 1));
		}
	}
	for (int i = 1; i <= Q; ++i) printf("%d\n", Ans[i]);
	return 0;
}