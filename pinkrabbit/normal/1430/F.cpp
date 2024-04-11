#include <cstdio>
#include <algorithm>

typedef long long LL;
const int MN = 2005;

int N, K, l[MN], r[MN], a[MN];
int w[MN][MN];
LL sum, f[MN];

int main() {
	scanf("%d%d", &N, &K);
	for (int i = 1; i <= N; ++i) scanf("%d%d%d", &l[i], &r[i], &a[i]), sum += a[i];
	for (int i = 1; i <= N; ++i) {
		int rem = K;
		for (int j = i; j <= N; ++j) {
			int tim, rem2;
			if (a[j] <= rem)
				tim = 0,
				rem2 = rem - a[j];
			else if ((a[j] - rem) % K == 0)
				tim = (a[j] - rem) / K,
				rem2 = 0;
			else
				tim = (a[j] - rem) / K + 1,
				rem2 = K - (a[j] - rem) % K;
			rem = rem2;
			if (tim > r[j] - l[j]) {
				for (int k = j; k <= N; ++k)
					w[i][k] = -1;
				break;
			} else if (j == N) w[i][j] = 0;
			else if (tim == r[j] - l[j] && r[j] == l[j + 1]) w[i][j] = -1;
			else w[i][j] = rem;
		}
//		for (int j = i; j <= N; ++j) printf("w[%d][%d] = %d\n", i, j, w[i][j]);
	}
	f[0] = 0;
	for (int i = 1; i <= N; ++i) {
		f[i] = -1;
		for (int j = i; j >= 1; --j) if (w[j][i] != -1 && f[j - 1] != -1)
			f[i] = f[i] == -1 ? f[j - 1] + w[j][i] : std::min(f[i], f[j - 1] + w[j][i]);
//		printf("f[%d] = %lld\n", i, f[i]);
	}
	if (f[N] == -1) puts("-1");
	else printf("%lld\n", sum + f[N]);
	return 0;
}