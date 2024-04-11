#include <cstdio>
#include <cstring>

const int MN = 2005;

int N, M;
int l[MN], s[MN], c[MN * 2];
int f[MN * 2][MN];

inline void chkmx(int &x, int y) { x = x > y ? x : y; }

int main() {
	scanf("%d%d", &N, &M);
	for (int i = N; i >= 1; --i) scanf("%d", &l[i]);
	for (int i = N; i >= 1; --i) scanf("%d", &s[i]);
	for (int i = 1; i <= M + N; ++i) scanf("%d", &c[i]);
	memset(f, 0xc0, sizeof f);
	for (int j = 1; j <= M + N; ++j) f[j][0] = 0;
	for (int i = 1; i <= N; ++i) {
		for (int k = N; k >= 1; --k) chkmx(f[l[i]][k], f[l[i]][k - 1] + c[l[i]] - s[i]);
		for (int j = l[i], k = N; j < M + N; ++j, k >>= 1)
			for (int z = 0; z <= k; ++z) chkmx(f[j + 1][z / 2], f[j][z] + z / 2 * c[j + 1]);
	}
	printf("%d\n", f[M + N][0]);
	return 0;
}