#include <stdio.h>
#include <algorithm>

typedef long long LL;
const int Mod = 998244353;
const int G = 3;

inline int qPow(int b, int e) {
	int a = 1;
	for (e < 0 ? e += Mod - 1 : 0; e; b = (LL)b * b % Mod, e >>= 1)
		if (e & 1) a = (LL)a * b % Mod;
	return a;
}

inline int chkto(int x) { return x >= Mod ? x - Mod : x; }
inline int chkuo(int x) { return x < 0 ? x + Mod : x; }

int A[1 << 21 | 1], B[1 << 21 | 1], R[1 << 21 | 1];

void NTT(int *A, int Sz, int t) {
	for (int i = 0; i < Sz; ++i)
		if (R[i] < i) std::swap(A[R[i]], A[i]);
	for (int j = 1; j < Sz; j <<= 1) {
		int j2 = j << 1;
		int gn = qPow(G, t * (Mod - 1) / j2);
		for (int i = 0; i < Sz; i += j2) {
			int g = 1;
			for (int k = 0; k < j; ++k, g = (LL)g * gn % Mod) {
				int X = A[i + k], Y = (LL)g * A[i + j + k] % Mod;
				A[i + k] = chkto(X + Y);
				A[i + j + k] = chkuo(X - Y);
			}
		}
	}
	if (t == -1)
		for (int i = 0, InvSz = qPow(Sz, Mod - 2); i < Sz; ++i)
			A[i] = (LL)A[i] * InvSz % Mod;
}

int main() {
	int N, K, Sz, Bt;
	scanf("%d%d", &N, &K);
	for (int i = 1, x; i <= K; ++i)
		scanf("%d", &x), A[x] = 1;
	int Len = 9 * N / 2 + 1;
	for (Sz = 1, Bt = 0; Sz < Len; Sz <<= 1, ++Bt) ;
	for (int i = 0; i < Sz; ++i) R[i] = R[i >> 1] >> 1 | (i & 1) << (Bt - 1);
	NTT(A, Sz, 1);
	for (int i = 0; i < Sz; ++i) A[i] = qPow(A[i], N / 2);
	NTT(A, Sz, -1);
	int Ans = 0;
	for (int i = 0; i < Len; ++i) Ans = (Ans + (LL)A[i] * A[i]) % Mod;
	printf("%d\n", Ans);
	return 0;
}