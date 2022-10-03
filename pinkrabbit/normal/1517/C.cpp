#include <cstdio>
#include <algorithm>

const int MN = 505;

int N, A[MN], B[MN][MN];

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) scanf("%d", &A[i]);
	for (int i = 1; i <= N; ++i) B[i][i] = A[i];
	for (int i = 1; i <= N; ++i) B[N + 1][i] = -1;
	for (int i = N; i >= 1; --i) {
		int k = B[i][i] - 1;
		int x = i, y = i;
		while (k) {
			if (!B[x + 1][y]) ++x;
			else --y;
			B[x][y] = B[i][i];
			--k;
		}
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= i; ++j)
			printf("%d%c", B[i][j], " \n"[j == i]);
	}
	return 0;
}