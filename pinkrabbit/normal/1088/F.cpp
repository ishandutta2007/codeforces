#include <cstdio>
#include <algorithm>
#include <vector>

typedef long long LL;
const int MN = 500005;

int N, A[MN], S;
std::vector<int> G[MN];
int dep[MN], faz[MN][19];
LL Ans;

void DFS(int u, int f) {
	dep[u] = dep[faz[u][0] = f] + 1;
	for (int j = 0; 2 << j < dep[u]; ++j)
		faz[u][j + 1] = faz[faz[u][j]][j];
	if (u != S) {
		LL mn = 0x3f3f3f3f3f3f3f3f;
		int j = 0;
		for (; 1 << j < dep[u]; ++j)
			mn = std::min(mn, (LL)A[faz[u][j]] * (j + 1));
		mn = std::min(mn, (LL)A[S] * (j + 1));
		Ans += mn + A[u];
	}
	for (auto v : G[u]) if (v != f) DFS(v, u);
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) scanf("%d", &A[i]);
	S = std::min_element(A + 1, A + N + 1) - A;
	for (int i = 1; i < N; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	DFS(S, 0);
	printf("%lld\n", Ans);
	return 0;
}