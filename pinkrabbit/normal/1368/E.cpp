#include <cstdio>
#include <vector>

const int MN = 200005;

int N, M, typ[MN], Ans;
std::vector<int> G[MN];

int main() {
	int Tests;
	scanf("%d", &Tests);
	while (Tests--) {
		scanf("%d%d", &N, &M), Ans = 0;
		for (int i = 1; i <= N; ++i) G[i].clear(), typ[i] = 0;
		for (int i = 1, x, y; i <= M; ++i)
			scanf("%d%d", &x, &y),
			G[y].push_back(x);
		for (int i = 1; i <= N; ++i)
			for (int j : G[i])
				if (typ[j] == 1) { ++Ans, typ[i] = 2; break; }
				else if (!typ[j]) typ[i] = 1;
		printf("%d\n", Ans);
		for (int i = 1; i <= N; ++i) if (typ[i] == 2) printf("%d ", i);
		puts("");
	}
	return 0;
}