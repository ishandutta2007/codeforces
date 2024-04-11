#include <algorithm>
#include <stdio.h>
#include <string.h>
#define N 105
int n, m, K;
long long f[N][N][N], pr[N][N][N], su[N][N][N];
int p[N][N], c[N];
int main() {
	int i, j, k;
	scanf("%d%d%d", &n, &m, &K);
	for(i = 1; i <= n; ++i) {
		scanf("%d", &c[i]);
	}
	for(i = 1; i <= n; ++i) {
		for(j = 1; j <= m; ++j) {
			scanf("%d", &p[i][j]);
		}
	}
	memset(f, 127, sizeof(f));
	memset(pr, 127, sizeof(pr));
	memset(su, 127, sizeof(su));
	memset(f[0][0], 0, sizeof(f[0][0]));
	memset(pr[0][0], 0, sizeof(pr[0][0]));
	memset(su[0][0], 0, sizeof(su[0][0]));
	for(i = 1; i <= n; ++i) {
		for(j = 1; j <= K; ++j) {
			#define without(k) std::min(pr[i - 1][j - 1][k - 1], su[i - 1][j - 1][k + 1])
			if(c[i]) {
				f[i][j][c[i]] = std::min(f[i - 1][j][c[i]], without(c[i]));
			} else {
				for(k = 1; k <= m; ++k) {
					f[i][j][k] = std::min(f[i - 1][j][k], without(k)) + p[i][k];
				}
			}
/*			for(k = 1; k <= m; ++k) {
				printf("f(%d, %d, %d) = ", i, j, k);
				if(f[i][j][k] == 0x7f7f7f7f7f7f7f7fll) puts("INF");
				else printf("%lld\n", f[i][j][k]);
			}*/
			for(k = 1; k <= m; ++k) pr[i][j][k] = std::min(pr[i][j][k - 1], f[i][j][k]);
			for(k = m; k >= 1; --k) su[i][j][k] = std::min(su[i][j][k + 1], f[i][j][k]);
		}
	}
	printf("%I64d", pr[n][K][m] == 0x7f7f7f7f7f7f7f7fll ? -1 : pr[n][K][m]);
	return 0;
}