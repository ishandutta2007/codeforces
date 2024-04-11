#include <cstdio>
#include <cmath>

int main() {
	int N, M;
	char A[9][9];
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; ++i) scanf("%s", A[i] + 1);
	int Ans = 0;
	int pi = 1, pj = 1;
	while (1) {
		int ni = 0, nj = 0;
		for (int i = pi; i <= N; ++i)
			for (int j = pj; j <= M; ++j) if (A[i][j] == '*') {
				if (!ni) ni = i, nj = j;
				else if (i + j < ni + nj)
					ni = i, nj = j;
			}
		if (!ni) break;
		++Ans;
		A[ni][nj] = '.';
		pi = ni, pj = nj;
	}
	printf("%d\n", Ans);
	return 0;
}