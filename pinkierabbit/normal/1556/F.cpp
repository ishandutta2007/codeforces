#include <cstdio>

typedef long long LL;
const int Mod = 1000000007;
const int MN = 14;

inline int qPow(int b, int e) {
	int a = 1;
	for (; e; e >>= 1, b = (LL)b * b % Mod)
		if (e & 1) a = (LL)a * b % Mod;
	return a;
}
inline int gInv(int b) { return qPow(b, Mod - 2); }

int N, A[MN];
int W[MN][MN], f[1 << MN];
//double W[MN][MN], f[1 << MN];
int Ans;

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) scanf("%d", &A[i]);
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			W[i][j] = (LL)A[i] * gInv(A[i] + A[j]) % Mod;
//			W[i][j] = A[i] / (double)(A[i] + A[j]);
	for (int S = 1; S < 1 << N; ++S) {
		int c = __builtin_popcount(S);
		f[S] = 1;
		for (int T = (S - 1) & S; T != S; T = (T - 1) & S) {
			int v = f[T];
//			double v = f[T];
			for (int i = 0; i < N; ++i) if (T >> i & 1)
				for (int j = 0; j < N; ++j) if ((S ^ T) >> j & 1)
					v = (LL)v * W[i][j] % Mod;
//					v *= W[i][j];
			f[S] = (f[S] - v + Mod) % Mod;
//			f[S] -= v;
		}
//		printf("f[%d] = %.10f\n", S, f[S]);
		int pr = f[S];
		for (int i = 0; i < N; ++i) if (S >> i & 1)
			for (int j = 0; j < N; ++j) if (~S >> j & 1)
				pr = (LL)pr * W[i][j] % Mod;
		Ans = (Ans + (LL)pr * c) % Mod;
	}
	printf("%d\n", Ans);
	return 0;
}