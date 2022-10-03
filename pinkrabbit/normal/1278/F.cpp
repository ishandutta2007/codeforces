#include <cstdio>

typedef long long LL;
const int Mod = 998244353;
const int MK = 5005;

inline int qPow(int b, int e) {
	int a = 1;
	for (; e; e >>= 1, b = (LL)b * b % Mod)
		if (e & 1) a = (LL)a * b % Mod;
	return a;
}

int N, M, K;
int S[MK][MK], Ans;

int main() {
	scanf("%d%d%d", &N, &M, &K);
	M = qPow(M, Mod - 2);
	S[0][0] = 1;
	for (int i = 1; i <= K; ++i)
		for (int j = 1; j <= i; ++j)
			S[i][j] = (S[i - 1][j - 1] + (LL)j * S[i - 1][j]) % Mod;
	for (int i = 1, C = 1; i <= K; ++i)
		C = (LL)C * (N - i + 1) % Mod * M % Mod,
		Ans = (Ans + (LL)S[K][i] * C) % Mod;
	printf("%d\n", Ans);
	return 0;
}