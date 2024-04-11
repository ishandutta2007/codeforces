#include <cstdio>
#include <algorithm>

const int MN = 10005;

int Or(int i, int j) {
	printf("or %d %d\n", i, j);
	fflush(stdout);
	int ret;
	scanf("%d", &ret);
	return ret;
}
int And(int i, int j) {
	printf("and %d %d\n", i, j);
	fflush(stdout);
	int ret;
	scanf("%d", &ret);
	return ret;
}

int N, K;
int a[4][4], b[4][4];
int c[MN];

int main() {
	scanf("%d%d", &N, &K);
	for (int i = 1; i <= 2; ++i)
		for (int j = i + 1; j <= 3; ++j)
			a[i][j] = a[j][i] = And(i, j),
			b[i][j] = b[j][i] = Or(i, j);
	for (int j = 0; j <= 30; ++j) {
		for (int p = 1; p <= 2; ++p) {
			for (int q = p + 1; q <= 3; ++q) {
				if ((a[p][q] >> j & 1) == (b[p][q] >> j & 1)) {
					int x = a[p][q] >> j & 1;
					c[p] |= x << j;
					c[q] |= x << j;
					int y = (a[p ^ q][p] >> j & 1) != (b[p ^ q][p] >> j & 1);
					c[p ^ q] |= (x ^ y) << j;
					goto end;
				}
			}
		}
		end: ;
	}
	for (int i = 4; i <= N; ++i)
		c[i] = And(1, i) + Or(1, i) - c[1];
	std::nth_element(c + 1, c + K, c + N + 1);
	printf("finish %d\n", c[K]);
	fflush(stdout);
	return 0;
}