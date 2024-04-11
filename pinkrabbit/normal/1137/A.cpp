#include <cstdio>
#include <algorithm>

const int MN = 1005;

int N, M, A[MN][MN];
int X[MN][MN], Y[MN][MN];
int B[MN], C1[MN], C2[MN], C;

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
			scanf("%d", &A[i][j]);
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) B[j] = A[i][j];
		std::sort(B + 1, B + M + 1), C1[i] = C = std::unique(B + 1, B + M + 1) - B - 1;
		for (int j = 1; j <= M; ++j) X[i][j] = std::lower_bound(B + 1, B + C + 1, A[i][j]) - B;
	}
	for (int j = 1; j <= M; ++j) {
		for (int i = 1; i <= N; ++i) B[i] = A[i][j];
		std::sort(B + 1, B + N + 1), C2[j] = C = std::unique(B + 1, B + N + 1) - B - 1;
		for (int i = 1; i <= N; ++i) Y[i][j] = std::lower_bound(B + 1, B + C + 1, A[i][j]) - B;
	}
	for (int i = 1; i <= N; ++i, puts(""))
		for (int j = 1; j <= M; ++j)
			printf("%d ", std::max(X[i][j], Y[i][j]) + std::max(C1[i] - X[i][j], C2[j] - Y[i][j]));
	return 0;
}