#include <cstdio>
#include <vector>
#include <algorithm>

typedef long long LL;
const int MN = 200005;

int N, sz[MN];
std::vector<int> G[MN];
LL Sum, Ans;

void Dfs(int u, int f) {
	sz[u] = 1;
	for (auto v : G[u]) if (v != f) Dfs(v, u), sz[u] += sz[v];
}

void Dfs2(int u, int f) {
	Ans = std::max(Ans, Sum);
	for (auto v : G[u]) if (v != f) {
		Sum += N - sz[v] - sz[u] + N - sz[v];
		sz[u] = N - sz[v], sz[v] = N;
		Dfs2(v, u);
		Sum += N - sz[u] - sz[v] + N - sz[u];
		sz[v] = N - sz[u], sz[u] = N;
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i < N; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	Dfs(1, 0);
	for (int i = 1; i <= N; ++i) Sum += sz[i];
	Dfs2(1, 0);
	printf("%lld\n", Ans);
	return 0;
}