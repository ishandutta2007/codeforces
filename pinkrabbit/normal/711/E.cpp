#include <cstdio>

typedef long long LL;
const int Mod = 1000003, Phi = 1000002, Inv2 = 500002;

int qPow(int b, int e) {
	int a = 1;
	for (; e; e >>= 1, b = (LL)b * b % Mod)
		if (e & 1) a = (LL)a * b % Mod;
	return a;
}

LL N, K;

int main() {
	scanf("%lld%lld", &N, &K), --K;
	if (N <= 59 && K >= (1ll << N)) return puts("1 1"), 0;
	LL cnt = K, J = K;
	for (; J; J >>= 1) if (J & 1) --cnt;
	int B = qPow(2, ((N % Phi) * (K % Phi) % Phi - cnt % Phi + Phi) % Phi);
	if (K >= Mod) return printf("%d %d\n", B, B), 0;
	int A = qPow(Inv2, cnt), _2N = qPow(2, N % Phi);
	for (int i = 1; i <= K; ++i)
		A = (LL)A * (_2N - i + Mod) % Mod;
	printf("%d %d\n", (B - A + Mod) % Mod, B);
	return 0;
}