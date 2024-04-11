#include <cstdio>
#include <algorithm>

const int Inf = 0x3f3f3f3f;
const int MN = 505, MK = 11;

int N, M, K;
int C1[MN][MN], C2[MN][MN];
int Ans[MN][MN];

int main() {
	scanf("%d%d%d", &N, &M, &K);
	if (K & 1) {
		for (int i = 1; i <= N; ++i)
			for (int j = 1; j <= M; ++j)
				printf("-1%c", " \n"[j == M]);
		return 0;
	}
	K /= 2;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M - 1; ++j)
			scanf("%d", &C1[i][j]);
	for (int i = 1; i <= N - 1; ++i)
		for (int j = 1; j <= M; ++j)
			scanf("%d", &C2[i][j]);
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
			Ans[i][j] = 0;
	for (int k = 1; k <= K; ++k) {
		static int tmp[MN][MN];
		for (int i = 1; i <= N; ++i)
			for (int j = 1; j <= M; ++j) {
				tmp[i][j] = Inf;
				if (i > 1) tmp[i][j] = std::min(tmp[i][j], Ans[i - 1][j] + 2 * C2[i - 1][j]);
				if (j > 1) tmp[i][j] = std::min(tmp[i][j], Ans[i][j - 1] + 2 * C1[i][j - 1]);
				if (i < N) tmp[i][j] = std::min(tmp[i][j], Ans[i + 1][j] + 2 * C2[i][j]);
				if (j < M) tmp[i][j] = std::min(tmp[i][j], Ans[i][j + 1] + 2 * C1[i][j]);
			}
		for (int i = 1; i <= N; ++i)
			for (int j = 1; j <= M; ++j)
				Ans[i][j] = tmp[i][j];
	}
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
			printf("%d%c", Ans[i][j], " \n"[j == M]);
	return 0;
}