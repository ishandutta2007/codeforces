#include <cstdio>

typedef long long LL;
const int Mod = 998244353;
const int G = 3, iG = 332748118;
const int MS = 1 << 18;

inline int qPow(int b, int e) {
	int a = 1;
	for (; e; e >>= 1, b = (int)((LL)b * b % Mod))
		if (e & 1) a = (int)((LL)a * b % Mod);
	return a;
}
inline int gInv(int b) { return qPow(b, Mod - 2); }

int Inv[MS], Fac[MS], iFac[MS];
inline void Init(int N) {
	Fac[0] = 1;
	for (int i = 1; i <= N; ++i) Fac[i] = (int)((LL)Fac[i - 1] * i % Mod);
	iFac[N] = gInv(Fac[N]);
	for (int i = N; i >= 1; --i) iFac[i - 1] = (int)((LL)iFac[i] * i % Mod);
	for (int i = 1; i <= N; ++i) Inv[i] = (int)((LL)Fac[i - 1] * iFac[i] % Mod);
}
inline int Binom(int N, int M) {
	if (M < 0 || M > N) return 0;
	return (int)((LL)Fac[N] * iFac[M] % Mod * iFac[N - M] % Mod);
}

const int MN = 200005;

int N, Mid;
int A[MN], B[MN];

int main() {
	Init(200000);
	scanf("%d", &N);
	Mid = (N + 1) / 2;
	for (int k = 2; k <= Mid; ++k)
		A[k] = (LL)Fac[N - k] * Fac[Mid - 1] % Mod * iFac[Mid - k] % Mod;
	A[1] = A[2];
	for (int k = 2; k <= Mid; ++k)
		B[k] = (LL)A[k] * Inv[k - 1] % Mod;
	for (int k = Mid - 1; k >= 2; --k)
		B[k] = (B[k + 1] + B[k]) % Mod;
	for (int k = 1; k <= Mid; ++k)
		A[k] = (A[k] - B[k + 1] + Mod) % Mod;
	A[1] = A[2];
	for (int i = Mid + 1; i <= N; ++i)
		A[i] = 0;
	for (int i = 1; i <= N; ++i)
		printf("%d%c", A[i], " \n"[i == N]);
	return 0;
}