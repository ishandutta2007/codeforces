#include <cstdio>
#include <vector>
#include <algorithm>

const int MN = 200005;

int N, K, d[MN], r;
std::vector<int> G[MN], C[MN];
int Col[MN];

void DFS(int u, int fz, int col) {
	int c = 1;
	for (int i = 0; i < (int)G[u].size(); ++i) {
		int v = G[u][i], id = C[u][i];
		if (v == fz) continue;
		if (c == col) { if (++c > r) c = 1; }
		Col[id] = c;
		DFS(v, u, c);
		if (++c > r) c = 1;
	}
}

int main() {
	scanf("%d%d", &N, &K);
	for (int i = 1; i < N; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		C[u].push_back(i);
		G[v].push_back(u);
		C[v].push_back(i);
		++d[u], ++d[v];
	}
	std::nth_element(d + 1, d + N - K, d + N + 1);
	r = d[N - K];
	printf("%d\n", r);
	DFS(1, 0, 0);
	for (int i = 1; i < N; ++i) printf("%d ", Col[i]);
	return 0;
}

// lg