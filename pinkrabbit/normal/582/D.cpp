#include <cstdio>
#include <cstring>
#include <algorithm>

typedef long long LL;
const int Mod = 1000000007;
const int MN = 3325;

inline void Add(int &x, LL y) { x = (x + y) % Mod; }

int P, Lim;
int N, A[MN];

void Init() {
	static char S[MN]; static LL B[MN];
	scanf("%d%d%s", &P, &Lim, S), N = strlen(S);
	for (int i = 0; i < N; ++i) A[i] = S[N - i - 1] - '0';
	for (int i = N - 1; i >= 0; --i) {
		for (int j = 0; j < MN; ++j) B[j] *= 10;
		B[0] += A[i];
		for (int j = 0; j < MN; ++j)
			if (B[j] >= P) B[j + 1] += B[j] / P, B[j] %= P;
	}
	for (int i = 0; i < MN; ++i) A[i] = B[i];
	N = MN;
	while (N && !A[N - 1]) --N;
}

int f[2][2][MN], g[2][2][MN], Ans;

int main() {
	Init();
	if (!N) return puts("0"), 0;
	f[1][0][0] = 1;
	for (int i = N - 1; i >= 0; --i) {
		int Z0 = (LL)P * (P + 1) / 2 % Mod;
		int Z1 = (LL)P * (P - 1) / 2 % Mod;
		int Z2 = (LL)A[i] * (A[i] + 1) / 2 % Mod;
		int Z3 = (LL)A[i] * (A[i] - 1) / 2 % Mod;
		int Z4 = (LL)A[i] * (P + P - A[i] - 1) / 2 % Mod;
		int Z5 = (LL)A[i] * (P + P - A[i] + 1) / 2 % Mod;
		for (int j = 0; j <= N - i; ++j)
			g[0][0][j] = g[0][1][j] = g[1][0][j] = g[1][1][j] = 0;
		for (int j = 0; j < N - i; ++j) {
			LL f0 = f[0][0][j], f1 = f[0][1][j], f2 = f[1][0][j], f3 = f[1][1][j];
			Add(g[0][0][j], f0 * Z0 + f2 * Z2);
			Add(g[0][1][j], f0 * Z1 + f2 * Z3);
			Add(g[1][0][j], f2 * (A[i] + 1));
			Add(g[1][1][j], f2 * A[i]);
			Add(g[0][0][j + 1], f1 * Z1 + f3 * Z4);
			Add(g[0][1][j + 1], f1 * Z0 + f3 * Z5);
			Add(g[1][0][j + 1], f3 * (P - A[i] - 1));
			Add(g[1][1][j + 1], f3 * (P - A[i]));
		}
		std::swap(f, g);
	}
	for (int i = Lim; i <= N; ++i) Add(Ans, f[0][0][i] + f[1][0][i]);
	printf("%d\n", Ans);
	return 0;
}