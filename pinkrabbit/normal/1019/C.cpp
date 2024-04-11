#include <cstdio>
#include <vector>

const int MN = 1000005;

int N, M, C;
std::vector<int> G[MN];

int Ans[MN], del[MN];

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1, x, y; i <= M; ++i) {
		scanf("%d%d", &x, &y);
		G[x].push_back(y);
	}
	for (int i = 1; i <= N; ++i) if (!del[i]) {
		++C, Ans[i] = 1;
		for (int x : G[i]) del[x] = 1;
	}
	for (int i = N; i >= 1; --i) if (Ans[i])
		for (int x : G[i]) if (Ans[x]) --C, Ans[x] = 0;
	printf("%d\n", C);
	for (int i = 1; i <= N; ++i) if (Ans[i]) printf("%d ", i);
	puts("");
	return 0;
}