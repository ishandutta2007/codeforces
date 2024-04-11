#include <cstdio>
int N, M, B[4][1001][1001];
inline void I(int x, int y, int v) { int w = x << 1 & 2 | y & 1; for (int i = x; i <= N; i += i & -i) for (int j = y; j <= N; j += j & -j) B[w][i][j] ^= v; }
inline int Q(int x, int y) { int A = 0, w = x << 1 & 2 | y & 1; for (int i = x; i; i -= i & -i) for (int j = y; j; j -= j & -j) A ^= B[w][i][j]; return A; }
int main() {
	scanf("%d%d", &N, &M);
	while (M--) {
		int ty, a, b, c, d, v;
		scanf("%d%d%d%d%d", &ty, &a, &b, &c, &d);
		if (ty == 1) printf("%d\n", Q(a - 1, b - 1) ^ Q(a - 1, d) ^ Q(c, b - 1) ^ Q(c, d));
		if (ty == 2) scanf("%d", &v), I(a, b, v), I(a, d + 1, v), I(c + 1, b, v), I(c + 1, d + 1, v);
	}
	return 0;
}