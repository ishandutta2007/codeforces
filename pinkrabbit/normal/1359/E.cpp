#include <cstdio>
#include <algorithm>

typedef long long LL;
const int Mod = 998244353;
const int MS = 1 << 20;

inline int qPow(int b, int e) {
	int a = 1;
	for (; e; e >>= 1, b = (LL)b * b % Mod)
		if (e & 1) a = (LL)a * b % Mod;
	return a;
}
inline int gInv(int b) { return qPow(b, Mod - 2); }

int Inv[MS], Fac[MS], iFac[MS];
inline void Init(int N) {
	Fac[0] = 1;
	for (int i = 1; i < N; ++i) Fac[i] = (LL)Fac[i - 1] * i % Mod;
	iFac[N - 1] = gInv(Fac[N - 1]);
	for (int i = N - 1; i >= 1; --i) iFac[i - 1] = (LL)iFac[i] * i % Mod;
	for (int i = 1; i < N; ++i) Inv[i] = (LL)Fac[i - 1] * iFac[i] % Mod;
}
inline int Binom(int N, int M) {
	if (M < 0 || M > N) return 0;
	return (LL)Fac[N] * iFac[M] % Mod * iFac[N - M] % Mod;
}

int N, K, Ans;

int main() {
	scanf("%d%d", &N, &K);
	if (K > N) return puts("0"), 0;
	Init(N + 1);
	for (int i = 1; i <= N; ++i) {
		if (K > N / i) break;
		Ans = (Ans + Binom(N / i - 1, K - 1)) % Mod;
	}
	printf("%d\n", Ans);
	return 0;
}