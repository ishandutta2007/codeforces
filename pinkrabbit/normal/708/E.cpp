#include <cstdio>
#include <algorithm>

typedef long long LL;
const int Mod = 1000000007;
const int MK = 100005, MM = 1505;

inline int qPow(int b, int e) {
	int a = 1;
	for (; e; e >>= 1, b = (LL)b * b % Mod)
		if (e & 1) a = (LL)a * b % Mod;
	return a;
}

int N, M, C, K;
int Fac[MK], iFac[MK];
inline int Binom(int N, int M) {
	if (M < 0 || M > N) return 0;
	return (LL)Fac[N] * iFac[M] % Mod * iFac[N - M] % Mod;
}
int SBinom[MM];

int f[MM], g[MM];

int main() {
	scanf("%d%d", &N, &M);
	{ int a, b; scanf("%d%d", &a, &b); C = (LL)a * qPow(b, Mod - 2) % Mod; }
	scanf("%d", &K);
	if (C == 1) return puts(K + K < M ? "1" : "0"), 0;
	Fac[0] = 1;
	for (int i = 1; i <= K; ++i) Fac[i] = (LL)Fac[i - 1] * i % Mod;
	iFac[K] = qPow(Fac[K], Mod - 2);
	for (int i = K; i >= 1; --i) iFac[i - 1] = (LL)iFac[i] * i % Mod;
	int Tmp = qPow(Mod + 1 - C, K), D = (LL)C * qPow(Mod + 1 - C, Mod - 2) % Mod;
	for (int i = 0; i < M; ++i)
		SBinom[i + 1] = (SBinom[i] + (LL)Binom(K, i) * Tmp) % Mod,
		Tmp = (LL)Tmp * D % Mod;
	f[0] = 1;
	for (int t = 1; t <= N; ++t) {
		for (int i = 0; i <= M; ++i) g[i] = 0;
		int tot = f[0], S = 0;
		Tmp = qPow(Mod + 1 - C, K);
		int Tmp2 = (LL)qPow(C, M - 1) * qPow(Mod + 1 - C, (K - M + Mod) % (Mod - 1)) % Mod, D2 = (LL)(Mod + 1 - C) * qPow(C, Mod - 2) % Mod;
		for (int i = M - 1; i >= 0; --i)
			S = (S + (LL)f[i + 1] * Binom(K, M - i - 1) % Mod * Tmp) % Mod,
			Tmp = (LL)Tmp * D % Mod,
			g[i] = (((LL)(tot - f[M - i] + Mod) * SBinom[M - i] - S + Mod) % Mod * Binom(K, i) % Mod * Tmp2 + g[i + 1]) % Mod,
			Tmp2 = (LL)Tmp2 * D2 % Mod;
		std::swap(f, g);
	}
	printf("%d\n", f[0]);
	return 0;
}