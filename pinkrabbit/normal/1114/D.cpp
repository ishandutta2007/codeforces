#include <cstdio>
#include <algorithm>
// lg
const int MN = 5005;

int N, c[MN];
int f[MN][MN];

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)
		scanf("%d", &c[i]);
	N = std::unique(c + 1, c + N + 1) - c - 1;
	for (int i = 1; i <= N; ++i)
		f[i][i] = 0;
	for (int Q = 2; Q <= N; ++Q) {
		for (int i = 1; i <= N - Q + 1; ++i) {
			int j = i + Q - 1;
			if (c[i] == c[j]) f[i][j] = f[i + 1][j - 1] + 1;
			else f[i][j] = std::min(f[i + 1][j], f[i][j - 1]) + 1;
		}
	}
	printf("%d\n", f[1][N]);
	return 0;
}