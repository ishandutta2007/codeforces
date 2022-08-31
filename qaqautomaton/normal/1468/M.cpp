#include <cstdio>
#include <algorithm>
#include <vector>

const int MN = 100005;
const int MX = 300005;

int N, K[MN];
std::vector<int> V[MN];
int D[MX], C;

int deg[MX], per[MX];
std::vector<int> G[MX], G2[MX];
std::pair<int, int> cmp[MX];
int buk[MX];

int main() {
	int Tests;
	scanf("%d", &Tests);
	while (Tests--) {
		scanf("%d", &N), C = 0;
		for (int i = 1; i <= N; ++i) {
			scanf("%d", &K[i]);
			V[i].resize(K[i]);
			for (int j = 0; j < K[i]; ++j)
				scanf("%d", &V[i][j]), D[++C] = V[i][j];
		}
		std::sort(D + 1, D + C + 1);
		C = std::unique(D + 1, D + C + 1) - D - 1;
		for (int i = 1; i <= N; ++i)
			for (int j = 0; j < K[i]; ++j)
				V[i][j] = std::lower_bound(D + 1, D + C + 1, V[i][j]) - D + N;
//		for (int i = 1; i <= N; ++i) {
//			printf("%d : ", i);
//			for (int j = 0; j < K[i]; ++j)
//				printf("%d, ", V[i][j]);
//			puts("");
//		}
		for (int u = 1; u <= N + C; ++u) {
			deg[u] = 0;
			buk[u] = 0;
			G[u].clear();
			G2[u].clear();
			per[u] = u;
		}
		for (int i = 1; i <= N; ++i)
			for (int j = 0; j < K[i]; ++j)
				G[i].push_back(V[i][j]),
				G[V[i][j]].push_back(i),
				++deg[i], ++deg[V[i][j]];
		for (int u = 1; u <= N + C; ++u) cmp[u] = {deg[u], u};
		for (int i = 1; i <= N; ++i)
			for (int j = 0; j < K[i]; ++j) {
				int v = V[i][j];
				if (cmp[i] > cmp[v]) G2[i].push_back(v);
				else G2[v].push_back(i);
			}
		for (int u = 1; u <= N + C; ++u) {
			for (int v : G2[u])
				for (int w : G[v]) if (cmp[u] > cmp[w]) {
					if (buk[w]) {
						if (u <= N) printf("%d ", u);
						if (v <= N) printf("%d ", v);
						if (w <= N) printf("%d ", w);
						if (buk[w] <= N) printf("%d ", buk[w]);
						puts("");
						goto end;
					} else buk[w] = v;
				}
			for (int v : G2[u])
				for (int w : G[v]) if (cmp[u] > cmp[w])
					buk[w] = 0;
		}
		puts("-1");
		end: ;
	}
	return 0;
}