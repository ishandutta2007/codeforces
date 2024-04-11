#include <cstdio>
#include <algorithm>
#include <vector>

typedef long long LL;
const int Inf = 0x3f3f3f3f;
const int Mod = 998244353;
const int MN = 405;

int N, M;
std::vector<int> G[MN];
int Dis[MN][MN];

int Calc(int x, int y) {
	for (int i = 2; i <= N; ++i)
		if ((Dis[x][i] ^ Dis[y][i] ^ Dis[x][1] ^ Dis[y][1]) & 1)
			return 0;
	int cnt = 0;
	for (int i = 1; i <= N; ++i)
		if (Dis[x][i] + Dis[y][i] == Dis[x][y])
			++cnt;
	if (cnt != Dis[x][y] + 1) return 0;
	int Ans = 1;
	for (int i = 1; i <= N; ++i) {
		if (Dis[x][i] + Dis[y][i] == Dis[x][y]) continue;
		int c = 0;
		for (int v : G[i]) {
			if (Dis[x][v] != Dis[x][i] - 1) continue;
			if (Dis[y][v] != Dis[y][i] - 1) continue;
			++c;
		}
		if (!c) return 0;
		Ans = (LL)Ans * c % Mod;
	}
	return Ans;
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			Dis[i][j] = i == j ? 0 : Inf;
	for (int i = 1; i <= M; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
		Dis[u][v] = 1;
		Dis[v][u] = 1;
	}
	for (int k = 1; k <= N; ++k)
		for (int i = 1; i <= N; ++i)
			for (int j = 1; j <= N; ++j)
				Dis[i][j] = std::min(Dis[i][j], Dis[i][k] + Dis[k][j]);
//	for (int i = 1; i <= N; ++i)
//		for (int j = 1; j <= N; ++j)
//			printf("%d%s", Dis[i][j], j == N ? "\n" : ", ");
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			printf("%d%c", Calc(i, j), " \n"[j == N]);
	return 0;
}