#include <cstdio>

typedef long long LL;
const int Mod = 1000000007;
const int MN = 100005;

inline int qPow(int b, int e) {
	int a = 1;
	for (; e; e >>= 1, b = (LL)b * b % Mod)
		if (e & 1) a = (LL)a * b % Mod;
	return a;
}

int Fac[MN], iFac[MN];
void Init(int N) {
	Fac[0] = 1;
	for (int i = 1; i <= N; ++i) Fac[i] = (LL)Fac[i - 1] * i % Mod;
	iFac[N] = qPow(Fac[N], Mod - 2);
	for (int i = N; i >= 1; --i) iFac[i - 1] = (LL)iFac[i] * i % Mod;
}

int N, K;

int main() {
	Init(100000);
	int Tests;
	scanf("%d", &Tests);
	while (Tests--) {
		scanf("%d%d", &N, &K);
		int Ans = Fac[N];
		for (int i = 1; i <= (N + K - 1) / K; ++i) {
			int j = N + K - 1 - i * K;
			int Sum = (LL)Fac[i + j] * iFac[i] % Mod * iFac[j] % Mod;
			Sum = (LL)Sum * Fac[i] % Mod * Fac[N - i] % Mod;
			Ans = (Ans + Sum) % Mod;
		}
		Ans = (LL)Ans * iFac[N] % Mod;
		printf("%d\n", Ans);
	}
	return 0;
}