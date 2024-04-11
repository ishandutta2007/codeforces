#include <cstdio>
#include <algorithm>

const int Inf = 0x3f3f3f3f;
const int MN = 205, MM = 20005;

int N, M;
int eu[MM], ev[MM], ew[MM];
int dis[MN][MN], Ans = Inf;
int Nx[MN], Ny[MN], P[MN], stk[MN], top;

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			dis[i][j] = i == j ? 0 : Inf;
	for (int i = 1; i <= M; ++i) {
		scanf("%d%d%d", &eu[i], &ev[i], &ew[i]);
		dis[ev[i]][eu[i]] = dis[eu[i]][ev[i]] = std::min(dis[eu[i]][ev[i]], ew[i]);
	}
	for (int k = 1; k <= N; ++k)
		for (int i = 1; i <= N; ++i)
			for (int j = 1; j <= N; ++j)
				dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);
	for (int i = 1; i <= N; ++i) {
		int Max = 0;
		for (int j = 1; j <= N; ++j)
			Max = std::max(Max, dis[i][j]);
		Ans = std::min(Ans, 2 * Max);
	}
	for (int i = 1; i <= M; ++i) {
		for (int j = 1; j <= N; ++j)
			Nx[j] = dis[ev[i]][j] + ew[i] - dis[eu[i]][j],
			Ny[j] = dis[ev[i]][j] + ew[i] + dis[eu[i]][j],
			P[j] = j;
		std::sort(P + 1, P + N + 1, [](int i, int j) { return Nx[i] < Nx[j]; });
		for (int J = 1, j; J <= N; ++J) {
			j = P[J];
			while (top && Ny[stk[top]] - Nx[stk[top]] <= Ny[j] - Nx[j]) --top;
			if (top && Ny[j] + Nx[j] <= Ny[stk[top]] + Nx[stk[top]]) continue;
			stk[++top] = j;
		}
		for (int j = 1; j < top; ++j)
			Ans = std::min(Ans, (Ny[stk[j + 1]] + Ny[stk[j]] - Nx[stk[j + 1]] + Nx[stk[j]]) / 2);
	}
	printf("%d.%d0\n", Ans >> 1, Ans & 1 ? 5 : 0);
	return 0;
}