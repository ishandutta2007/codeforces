#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

typedef long long LL;
const int MN = 100005;

int N, l[MN], r[MN];
std::vector<int> G[MN];

LL f[MN][2];
void DFS(int u, int p) {
	f[u][0] = f[u][1] = 0;
	for (int v : G[u]) if (v != p) {
		DFS(v, u);
		f[u][0] += std::max(f[v][0] + std::abs(l[u] - l[v]), f[v][1] + std::abs(l[u] - r[v]));
		f[u][1] += std::max(f[v][0] + std::abs(r[u] - l[v]), f[v][1] + std::abs(r[u] - r[v]));
	}
}

inline void Work() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)
		scanf("%d%d", &l[i], &r[i]),
		G[i].clear();
	for (int i = 1; i <= N - 1; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	DFS(1, 0);
	printf("%lld\n", std::max(f[1][0], f[1][1]));
}

int main() {
	int Tests;
	scanf("%d", &Tests);
	while (Tests--) Work();
	return 0;
}