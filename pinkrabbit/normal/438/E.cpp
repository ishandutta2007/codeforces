#include <cstdio>
#include <algorithm>

typedef long long LL;
const int Mod = 998244353;
const int G = 3, iG = 332748118;
const int MS = 1 << 19 | 1;

inline LL qPow(LL b, int e) {
	LL a = 1;
	for (; e; e >>= 1, b = b * b % Mod)
		if (e & 1) a = a * b % Mod;
	return a;
}

int Sz, R[MS]; LL InvSz;

inline void InitFNTT(int N) {
	int Bt = 0;
	for (; 1 << Bt < N; ++Bt) ;
	if (Sz == (1 << Bt)) return ;
	Sz = 1 << Bt; InvSz = -(Mod - 1) / Sz;
	for (int i = 1; i < Sz; ++i) R[i] = R[i >> 1] >> 1 | (i & 1) << (Bt - 1);
}

inline void FNTT(LL *A, int Ty) {
	for (int i = 0; i < Sz; ++i) if (R[i] < i) std::swap(A[R[i]], A[i]);
	for (int j = 1, j2 = 2; j < Sz; j <<= 1, j2 <<= 1) {
		LL gn = qPow(~Ty ? G : iG, (Mod - 1) / j2), g, X, Y;
		for (int i = 0, k; i < Sz; i += j2) {
			for (k = 0, g = 1; k < j; ++k, g = g * gn % Mod) {
				X = A[i + k], Y = g * A[i + j + k] % Mod;
				A[i + k] = (X + Y) % Mod, A[i + j + k] = (X - Y) % Mod;
			}
		}
	}
	if (!~Ty) for (int i = 0; i < Sz; ++i) A[i] = A[i] * InvSz % Mod;
}

inline void PolyInv(LL *A, int N, LL *B) {
	static LL tA[MS], tB[MS];
	B[0] = qPow(A[0], Mod - 2);
	for (int L = 1; L < N; L <<= 1) {
		int L2 = L << 1, L4 = L << 2;
		InitFNTT(L4);
		for (int i = 0; i < L2; ++i) tA[i] = A[i];
		for (int i = L2; i < Sz; ++i) tA[i] = 0;
		for (int i = 0; i < L; ++i) tB[i] = B[i];
		for (int i = L; i < Sz; ++i) tB[i] = 0;
		FNTT(tA, 1), FNTT(tB, 1);
		for (int i = 0; i < Sz; ++i) tB[i] = tB[i] * (2 - tA[i] * tB[i] % Mod) % Mod;
		FNTT(tB, -1);
		for (int i = 0; i < L2; ++i) B[i] = tB[i];
	}
}

inline void PolySqrt(LL *A, int N, LL *B) {
	static LL tA[MS], tB[MS]; LL Inv2 = (Mod + 1) / 2;
	B[0] = 1ll;
	for (int L = 1; L < N; L <<= 1) {
		int L2 = L << 1, L4 = L << 2;
		for (int i = L; i < L2; ++i) B[i] = 0;
		PolyInv(B, L2, tB);
		InitFNTT(L4);
		for (int i = L2; i < Sz; ++i) tB[i] = 0;
		for (int i = 0; i < L2; ++i) tA[i] = A[i];
		for (int i = L2; i < Sz; ++i) tA[i] = 0;
		FNTT(tA, 1), FNTT(tB, 1);
		for (int i = 0; i < Sz; ++i) tB[i] = tA[i] * tB[i] % Mod;
		FNTT(tB, -1);
		for (int i = 0; i < L2; ++i) B[i] = Inv2 * (tB[i] + B[i]) % Mod;
	}
}

int N, M;
LL A[MS], B[MS], C[MS];

int main() {
	scanf("%d%d", &N, &M);
	while (N--) {
		int x; scanf("%d", &x);
		if (x <= M) A[x] = -4;
	} A[0] = 1;
	PolySqrt(A, M + 1, B);
	++B[0];
	PolyInv(B, M + 1, A);
	for (int i = 1; i <= M; ++i)
		printf("%lld\n", (2 * A[i] % Mod + Mod) % Mod);
	return 0;
}