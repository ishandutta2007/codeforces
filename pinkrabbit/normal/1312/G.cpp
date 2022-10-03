#include <cstdio>
#include <algorithm>

const int MN = 1000005;

int N, nx[MN][26], key[MN];
int K, id[MN];

int f[MN], stk[MN], tp, tg;
void DFS(int u) {
	if (key[u]) f[u] = std::min(f[u], stk[tp] + ++tg);
	++tp, stk[tp] = std::min(stk[tp - 1], f[u] - tg + key[u]);
	for (int j = 0, v; j < 26; ++j)
		if ((v = nx[u][j])) f[v] = f[u] + 1, DFS(v);
	--tp;
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) {
		int j; char ch;
		scanf("%d %c", &j, &ch);
		nx[j][ch - 'a'] = i;
	}
	scanf("%d", &K);
	for (int i = 1; i <= K; ++i) scanf("%d", &id[i]), key[id[i]] = 1;
	DFS(0);
	for (int i = 1; i <= K; ++i) printf("%d%c", f[id[i]], " \n"[i == K]);
	return 0;
}