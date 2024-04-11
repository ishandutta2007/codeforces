#include <cstdio>
#include <algorithm>

typedef long long LL;
const int Mod = 998244353;
const int G = 3, iG = 332748118;
const int MS = 1 << 19;

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

int Sz, InvSz, R[MS];

inline int getB(int N) { int Bt = 0; while (1 << Bt < N) ++Bt; return Bt; }

inline void InitFNTT(int N) {
	int Bt = getB(N);
	if (Sz == (1 << Bt)) return ;
	Sz = 1 << Bt, InvSz = Mod - (Mod - 1) / Sz;
	for (int i = 1; i < Sz; ++i) R[i] = R[i >> 1] >> 1 | (i & 1) << (Bt - 1);
}

inline void FNTT(int *A, int Ty) {
	for (int i = 0; i < Sz; ++i) if (R[i] < i) std::swap(A[R[i]], A[i]);
	for (int j = 1, j2 = 2; j < Sz; j <<= 1, j2 <<= 1) {
		int wn = qPow(~Ty ? G : iG, (Mod - 1) / j2), w, X, Y;
		for (int i = 0, k; i < Sz; i += j2) {
			for (k = 0, w = 1; k < j; ++k, w = (LL)w * wn % Mod) {
				X = A[i + k], Y = (LL)w * A[i + j + k] % Mod;
				A[i + k] -= (A[i + k] = X + Y) >= Mod ? Mod : 0;
				A[i + j + k] += (A[i + j + k] = X - Y) < 0 ? Mod : 0;
			}
		}
	}
	if (!~Ty) for (int i = 0; i < Sz; ++i) A[i] = (LL)A[i] * InvSz % Mod;
}

inline void PolyConv(int *_A, int N, int *_B, int M, int *_C) {
	static int A[MS], B[MS];
	InitFNTT(N + M - 1);
	for (int i = 0; i < N; ++i) A[i] = _A[i];
	for (int i = N; i < Sz; ++i) A[i] = 0;
	for (int i = 0; i < M; ++i) B[i] = _B[i];
	for (int i = M; i < Sz; ++i) B[i] = 0;
	FNTT(A, 1), FNTT(B, 1);
	for (int i = 0; i < Sz; ++i) A[i] = (LL)A[i] * B[i] % Mod;
	FNTT(A, -1);
	for (int i = 0; i < N + M - 1; ++i) _C[i] = A[i];
}

inline void PolyInv(int *_A, int N, int *_B) {
	static int A[MS], B[MS], tA[MS], tB[MS];
	for (int i = 0; i < N; ++i) A[i] = _A[i];
	for (int i = N, B = getB(N); i < 1 << B; ++i) A[i] = 0;
	B[0] = gInv(A[0]);
	for (int L = 1; L < N; L <<= 1) {
		int L2 = L << 1, L4 = L << 2;
		InitFNTT(L4);
		for (int i = 0; i < L2; ++i) tA[i] = A[i];
		for (int i = L2; i < Sz; ++i) tA[i] = 0;
		for (int i = 0; i < L; ++i) tB[i] = B[i];
		for (int i = L; i < Sz; ++i) tB[i] = 0;
		FNTT(tA, 1), FNTT(tB, 1);
		for (int i = 0; i < Sz; ++i) tB[i] = tB[i] * (2 - (LL)tA[i] * tB[i] % Mod + Mod) % Mod;
		FNTT(tB, -1);
		for (int i = 0; i < L2; ++i) B[i] = tB[i];
	}
	for (int i = 0; i < N; ++i) _B[i] = B[i];
}

inline void PolyLn(int *_A, int N, int *_B) {
	static int tA[MS], tB[MS];
	for (int i = 1; i < N; ++i) tA[i - 1] = (LL)_A[i] * i % Mod;
	PolyInv(_A, N - 1, tB);
	InitFNTT(N + N - 3);
	for (int i = N - 1; i < Sz; ++i) tA[i] = 0;
	for (int i = N - 1; i < Sz; ++i) tB[i] = 0;
	FNTT(tA, 1), FNTT(tB, 1);
	for (int i = 0; i < Sz; ++i) tA[i] = (LL)tA[i] * tB[i] % Mod;
	FNTT(tA, -1);
	_B[0] = 0;
	for (int i = 1; i < N; ++i) _B[i] = (LL)tA[i - 1] * Inv[i] % Mod;
}

inline void PolyExp(int *_A, int N, int *_B) {
	static int A[MS], B[MS], tA[MS], tB[MS];
	for (int i = 0; i < N; ++i) A[i] = _A[i];
	for (int i = N, B = getB(N); i < 1 << B; ++i) A[i] = 0;
	B[0] = 1;
	for (int L = 1; L < N; L <<= 1) {
		int L2 = L << 1, L4 = L << 2;
		for (int i = L; i < L2; ++i) B[i] = 0;
		PolyLn(B, L2, tA);
		InitFNTT(L4);
		for (int i = 0; i < L2; ++i) tA[i] = (!i + A[i] - tA[i] + Mod) % Mod;
		for (int i = L2; i < Sz; ++i) tA[i] = 0;
		for (int i = 0; i < L; ++i) tB[i] = B[i];
		for (int i = L; i < Sz; ++i) tB[i] = 0;
		FNTT(tA, 1), FNTT(tB, 1);
		for (int i = 0; i < Sz; ++i) tA[i] = (LL)tA[i] * tB[i] % Mod;
		FNTT(tA, -1);
		for (int i = 0; i < L2; ++i) B[i] = tA[i];
	}
	for (int i = 0; i < N; ++i) _B[i] = B[i];
}

int N, M, buk[3000005], buk2[MS];
int A[MS];

int main() {
	scanf("%d", &N), M = N / 2;
	Init(M + 1);
	for (int i = 1, x; i <= N; ++i) scanf("%d", &x), ++buk[x];
	for (int i = 1; i <= 3000000; ++i) if (buk[i]) --buk2[buk[i] + 1], ++buk2[1];
	for (int i = 1; i <= N + 1; ++i) if (buk2[i]) {
		for (int j = 1; j * i <= M; ++j) A[j * i] = (A[j * i] + (LL)(buk2[i] + Mod) * Inv[j]) % Mod;
	}
	PolyExp(A, M + 1, A);
	printf("%d\n", A[M]);
	return 0;
}