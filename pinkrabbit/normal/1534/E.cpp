#include <cstdio>
#include <algorithm>

const int MN = 505;

int N, K;
int f[MN][MN], g[MN][MN];

int cL(int x) {
	return x < K ? K - x : x - K;
}
int cR(int x) {
	return N - x < K ? 2 * N - K - x : x + K;
}

int main() {
	scanf("%d%d", &N, &K);
	if (~K & 1 && N & 1)
		return puts("-1"), 0;
	f[0][N] = 1;
	for (int i = 1; ; ++i) {
		for (int j = 0; j <= N; ++j) if (f[i - 1][j]) {
			int l = cL(j), r = cR(j);
			for (int k = l; k <= r; k += 2)
				f[i][k] = 1, g[i][k] = j;
		}
		if (f[i][0]) {
			int Ans = 0;
			int lb = 1, rb = N, now = 0;
			for (int id = i; id >= 1; --id) {
				int nnow = g[id][now];
				int a = (nnow - now + K) / 2;
				int b = (K - nnow + now) / 2;
				printf("?");
				while (a--)
					rb = rb % N + 1, printf(" %d", rb);
				while (b--)
					printf(" %d", lb), lb = lb % N + 1;
				puts("");
				fflush(stdout);
				int tmp;
				scanf("%d", &tmp);
				Ans ^= tmp;
				now = nnow;
			}
			printf("! %d\n", Ans);
			fflush(stdout);
			break;
		}
	}
	return 0;
}