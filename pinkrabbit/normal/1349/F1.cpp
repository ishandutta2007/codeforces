#include <cstdio>

typedef long long LL;
const int Mod = 998244353;
const int MN = 5005;

int N;
int E[MN][MN];
// E[i][j] = Eulerian number(i, j - 1)

int main() {
	scanf("%d", &N);
	E[1][1] = 1;
	for (int i = 2; i <= N; ++i)
		for (int j = 1; j <= i; ++j)
			E[i][j] = ((LL)(i - j + 1) * E[i - 1][j - 1] + (LL)j * E[i - 1][j]) % Mod;
	for (int i = 1; i <= N; ++i) {
		int Sum = 0, Coef = 1;
		for (int j = N; j >= 1; Coef = (LL)Coef * j % Mod, --j)
			Sum = (Sum + (LL)Coef * E[j][i]) % Mod;
		printf("%d%c", Sum, " \n"[i == N]);
	}
	return 0;
}