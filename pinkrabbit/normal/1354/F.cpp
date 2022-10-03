#include <cstdio>
#include <algorithm>

const int Inf = 0x3f3f3f3f;
const int MN = 85;

int N, K, A[MN], B[MN], P[MN];
int f[MN][MN];
int cho[MN];

int main() {
	int Tests;
	scanf("%d", &Tests);
	while (Tests--) {
		scanf("%d%d", &N, &K);
		for (int i = 1; i <= N; ++i) scanf("%d%d", &A[i], &B[i]), P[i] = i;
		std::sort(P + 1, P + N + 1, [](int i, int j) { return B[i] > B[j]; });
		f[0][0] = 0;
		for (int j = 1; j <= K; ++j) f[0][j] = -Inf;
		for (int i = 1; i <= N; ++i) {
			f[i][0] = 0;
			for (int j = 0; j < K; ++j)
				f[i][j + 1] = std::max(f[i - 1][j + 1], f[i - 1][j] + A[P[i]] - j * B[P[i]]);
		}
		printf("%d\n", 2 * N - K);
		int now = K, lstc = 0;
		for (int i = N; i >= 1; --i) {
			if (f[i - 1][now] == f[i][now]) cho[i] = 0;
			else lstc = i, cho[i] = 1, --now;
		}
		for (int i = N; i > lstc; --i) if (cho[i]) printf("%d ", P[i]);
		for (int i = 1; i <= N; ++i) if (!cho[i]) printf("%d %d ", P[i], -P[i]);
		printf("%d\n", P[lstc]);
	}
	return 0;
}