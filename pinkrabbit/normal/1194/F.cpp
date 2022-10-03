#include <cstdio>

typedef long long LL;
const int Mod = 1000000007;
const int Inv2 = (Mod + 1) / 2;
const int MN = 200005;

inline int qPow(int b, int e) {
	int a = 1;
	for (; e; e >>= 1, b = (LL)b * b % Mod)
		if (e & 1) a = (LL)a * b % Mod;
	return a;
}

int Inv[MN], Fac[MN], iFac[MN];
inline int Binom(int N, int M) {
	if (M < 0 || M > N) return 0;
	return (LL)Fac[N] * iFac[M] % Mod * iFac[N - M] % Mod;
}
inline void Init(int N) {
	Inv[1] = 1;
	for (int i = 2; i <= N; ++i) Inv[i] = (LL)(Mod - Mod / i) * Inv[Mod % i] % Mod;
	Fac[0] = iFac[0] = 1;
	for (int i = 1; i <= N; ++i) {
		Fac[i] = (LL)Fac[i - 1] * i % Mod;
		iFac[i] = (LL)iFac[i - 1] * Inv[i] % Mod;
	}
}

int N, x, Ans, Now, X, P2;
LL T, S;

int main() {
	scanf("%d%lld", &N, &T);
	Init(N);
	Now = 1, X = N, P2 = 1;
	for (int i = 1; i <= N; ++i) {
		scanf("%d", &x), S += x;
		if (S > T) break;
		P2 = (LL)P2 * Inv2 % Mod;
		Now = Now - (LL)Binom(i - 1, X) * P2 % Mod;
		if (Now < 0) Now += Mod;
		int Y = T - S < N ? T - S : N;
		while (X > Y) {
			Now = Now - (LL)Binom(i, X) * P2 % Mod;
			if (Now < 0) Now += Mod;
			--X;
		}
		Ans += Now;
		if (Ans >= Mod) Ans -= Mod;
	}
	printf("%d\n", Ans);
	return 0;
}