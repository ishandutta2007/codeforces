#include <cstdio>
#include <vector>

const int MN = 800005;

int N, Q, dep[MN], ch[MN][26], fail[MN], cnt;
int itu[MN], Ans[MN];
int h[MN], nxt[MN], to[MN], id[MN], tot;
inline void ins(int x, int y, int z) { nxt[++tot] = h[x], to[tot] = y, id[tot] = z, h[x] = tot; }

std::vector<int> G[MN];
inline void BuildFail() {
	static int que[MN];
	int l, r;
	que[l = r = 1] = 0, fail[0] = -1;
	while (l <= r) {
		int u = que[l++];
		for (int j = 0; j < 26; ++j) {
			if (ch[u][j]) {
				fail[ch[u][j]] = u ? ch[fail[u]][j] : 0;
				G[fail[ch[u][j]]].push_back(ch[u][j]);
				que[++r] = ch[u][j];
			}
			else ch[u][j] = u ? ch[fail[u]][j] : 0;
		}
	}
}

int ldf[MN], rdf[MN], dfc;
void DFS0(int u) { ldf[u] = ++dfc; for (auto v : G[u]) DFS0(v); rdf[u] = dfc; }

int bit[MN];
inline void Add(int i, int x) { for (; i <= cnt + 1; i += i & -i) bit[i] += x; }
inline int Qur(int i) { int a = 0; for (; i; i -= i & -i) a += bit[i]; return a; }

void DFS1(int u) {
	Add(ldf[u], 1);
	for (int i = h[u]; i; i = nxt[i]) Ans[id[i]] = Qur(rdf[to[i]]) - Qur(ldf[to[i]] - 1);
	for (int j = 0; j < 26; ++j) if (dep[ch[u][j]] > dep[u]) DFS1(ch[u][j]);
	Add(ldf[u], -1);
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) {
		int op, x = 0, j; char s[3];
		scanf("%d", &op);
		if (op == 2) scanf("%d", &x), x = itu[x];
		scanf("%s", s), j = *s - 'a';
		if (!ch[x][j]) ch[x][j] = ++cnt, dep[cnt] = dep[x] + 1;
		itu[i] = ch[x][j];
	}
	scanf("%d", &Q);
	for (int i = 1; i <= Q; ++i) {
		static char str[MN];
		int x, y, now = 0;
		scanf("%d%s", &x, str), x = itu[x];
		for (char *s = str; *s; ++s) {
			int j = *s - 'a';
			if (!ch[now][j]) ch[now][j] = ++cnt, dep[cnt] = dep[now] + 1;
			now = ch[now][j];
		}
		y = now;
		ins(x, y, i);
	}
	BuildFail();
	DFS0(0);
	DFS1(0);
	for (int i = 1; i <= Q; ++i) printf("%d\n", Ans[i]);
	return 0;
}