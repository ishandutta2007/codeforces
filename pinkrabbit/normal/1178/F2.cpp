#include <cstdio>
#include <vector>
#include <algorithm>

typedef long long LL;
const int Mod = 998244353;
const int MN = 1005;
const int MM = 1000005;

int N, M, A[MM], t;
std::vector<int> V[MN];

int f[MN][MN];

int main() {
	scanf("%d%d", &N, &M);
	int lst = 0, x;
	while (M--) {
		scanf("%d", &x);
		if (x != lst) A[++t] = x, lst = x;
	} M = t;
	if (M >= N + N) return puts("0"), 0;
	for (int i = 1; i <= M; ++i) V[A[i]].push_back(i);
	for (int i = 0; i <= M; ++i) f[i + 1][i] = 1;
	for (int q = 1; q <= M; ++q) {
		for (int i = 1; i <= M - q + 1; ++i) {
			int j = i + q - 1;
			int mn = N + 1;
			for (int k = i; k <= j; ++k) mn = std::min(mn, A[k]);
			int a = V[mn].front(), b = V[mn].back();
			if (a < i || j < b) { f[i][j] = 0; continue; }
			int s1 = 0, s2 = 0;
			for (int k = i; k <= a; ++k) s1 = (s1 + (LL)f[i][k - 1] * f[k][a - 1]) % Mod;
			for (int k = b; k <= j; ++k) s2 = (s2 + (LL)f[b + 1][k] * f[k + 1][j]) % Mod;
			f[i][j] = (LL)s1 * s2 % Mod;
			for (int k = 1; k < (int)V[mn].size(); ++k)
				f[i][j] = (LL)f[i][j] * f[V[mn][k - 1] + 1][V[mn][k] - 1] % Mod;
		}
	}
	printf("%d\n", f[1][M]);
	return 0;
}