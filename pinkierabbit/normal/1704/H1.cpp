#include <cstdio>
#include <algorithm>

typedef long long LL;
// ====================================== vvv discarded
// const int Mod = 998244353;
// const int G = 3, iG = 332748118;
// ====================================== ^^^ discarded
int Mod; // input
int G, iG; // compute primitive root
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

int Sz, InvSz, R[MS], ws[MS], MaxSz;
inline int getB(int N) { int Bt = 0; while (1 << Bt < N) ++Bt; return Bt; }
inline void InitFNTT(int N) {
	int Bt = getB(N);
	if (Sz == (1 << Bt)) return ;
	Sz = 1 << Bt, InvSz = Mod - (Mod - 1) / Sz;
	for (int i = 1; i < Sz; ++i) R[i] = R[i >> 1] >> 1 | (i & 1) << (Bt - 1);
	if (!MaxSz) MaxSz = 2, ws[1] = 1;
	while (MaxSz < Sz) {
		int w = qPow(G, (Mod - 1) / (2 * MaxSz));
		for (int i = MaxSz / 2; i < MaxSz; ++i)
			ws[i << 1] = ws[i], ws[i << 1 | 1] = (int)((LL)ws[i] * w % Mod);
		MaxSz <<= 1;
	}
}

inline void FNTT(int *A, int Ty) {
	for (int i = 0; i < Sz; ++i) if (R[i] < i) std::swap(A[R[i]], A[i]);
	for (int j = 1, j2 = 2; j < Sz; j <<= 1, j2 <<= 1) {
		int X, Y;
		for (int i = 0; i < Sz; i += j2) {
			for (int k = 0; k < j; ++k) {
				X = A[i + k], Y = (int)((LL)ws[j + k] * A[i + j + k] % Mod);
				A[i + k] -= (A[i + k] = X + Y) >= Mod ? Mod : 0;
				A[i + j + k] += (A[i + j + k] = X - Y) < 0 ? Mod : 0;
			}
		}
	}
	if (!~Ty) {
		for (int i = 0; i < Sz; ++i) A[i] = (int)((LL)A[i] * InvSz % Mod);
		std::reverse(A + 1, A + Sz);
	}
}

inline void PolyConv(int *A_, int N, int *B_, int M, int *C_, int tN = -1) {
	if (tN == -1) tN = N + M - 1;
	static int A[MS], B[MS];
	InitFNTT(N + M - 1);
	for (int i = 0; i < N; ++i) A[i] = A_[i];
	for (int i = N; i < Sz; ++i) A[i] = 0;
	for (int i = 0; i < M; ++i) B[i] = B_[i];
	for (int i = M; i < Sz; ++i) B[i] = 0;
	FNTT(A, 1), FNTT(B, 1);
	for (int i = 0; i < Sz; ++i) A[i] = (int)((LL)A[i] * B[i] % Mod);
	FNTT(A, -1);
	for (int i = 0; i < tN; ++i) C_[i] = A[i];
}

inline void PolyInv(int *A_, int N, int *B_) {
	static int A[MS], B[MS], tA[MS], tB[MS];
	for (int i = 0; i < N; ++i) A[i] = A_[i];
	for (int i = N, Bt = getB(N); i < 1 << Bt; ++i) A[i] = 0;
	B[0] = gInv(A[0]);
	for (int L = 1; L < N; L <<= 1) {
		int L2 = L << 1, L4 = L << 2;
		InitFNTT(L4);
		for (int i = 0; i < L2; ++i) tA[i] = A[i];
		for (int i = L2; i < Sz; ++i) tA[i] = 0;
		for (int i = 0; i < L; ++i) tB[i] = B[i];
		for (int i = L; i < Sz; ++i) tB[i] = 0;
		FNTT(tA, 1), FNTT(tB, 1);
		for (int i = 0; i < Sz; ++i) tB[i] = (int)(tB[i] * (2 - (LL)tA[i] * tB[i] % Mod + Mod) % Mod);
		FNTT(tB, -1);
		for (int i = 0; i < L2; ++i) B[i] = tB[i];
	}
	for (int i = 0; i < N; ++i) B_[i] = B[i];
}

inline void PolyLn(int *A_, int N, int *B_) {
	static int tA[MS], tB[MS];
	for (int i = 1; i < N; ++i) tA[i - 1] = (int)((LL)A_[i] * i % Mod);
	PolyInv(A_, N - 1, tB);
	InitFNTT(N + N - 3);
	for (int i = N - 1; i < Sz; ++i) tA[i] = 0;
	for (int i = N - 1; i < Sz; ++i) tB[i] = 0;
	FNTT(tA, 1), FNTT(tB, 1);
	for (int i = 0; i < Sz; ++i) tA[i] = (int)((LL)tA[i] * tB[i] % Mod);
	FNTT(tA, -1);
	B_[0] = 0;
	for (int i = 1; i < N; ++i) B_[i] = (int)((LL)tA[i - 1] * Inv[i] % Mod);
}

inline void PolyExp(int *A_, int N, int *B_) {
	static int A[MS], B[MS], tA[MS], tB[MS];
	for (int i = 0; i < N; ++i) A[i] = A_[i];
	for (int i = N, Bt = getB(N); i < 1 << Bt; ++i) A[i] = 0;
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
		for (int i = 0; i < Sz; ++i) tA[i] = (int)((LL)tA[i] * tB[i] % Mod);
		FNTT(tA, -1);
		for (int i = 0; i < L2; ++i) B[i] = tA[i];
	}
	for (int i = 0; i < N; ++i) B_[i] = B[i];
}

inline void NewtonT(int N, int *B_) {
	static int B[MS], tA[MS], tB[MS], tC[MS];
	B[0] = 0;
	for (int L = 1; L < N; L <<= 1) {
		int L2 = L << 1;
		for (int i = L; i < L2; ++i) B[i] = 0;
		PolyExp(B, L2, tA);
		PolyConv(B, L, tA, L2, tB, L2);
		for (int i = L2 - 1; i >= 1; --i) tB[i] = tB[i - 1];
		tB[0] = 0;
		PolyExp(tB, L2, tB);
		for (int i = L2 - 1; i >= 1; --i) tB[i] = tB[i - 1];
		tB[0] = 0;
		tB[0] = 1, B[0] = 1, PolyConv(tB, L2, B, L2, tC, L2), B[0] = 0, tB[0] = 0;
		PolyConv(tC, L2, tA, L2, tC, L2);
		for (int i = L2 - 1; i >= 1; --i) tC[i] = tC[i - 1];
		tC[0] = Mod - 1;
		PolyInv(tC, L2, tC);
		for (int i = L2 - 1; i >= 1; --i) tA[i] = tA[i - 1];
		tA[0] = Mod - 1;
		PolyConv(B, L, tA, L2, tA, L2);
		for (int i = 0; i < L2; ++i) tB[i] = (tB[i] + tA[i]) % Mod;
		PolyConv(tB, L2, tC, L2, tC, L2);
		for (int i = 0; i < L2; ++i) B[i] = (B[i] - tC[i] + Mod) % Mod;
	}
	for (int i = 0; i < N; ++i) B_[i] = B[i];
}

#include <vector>

const int MN = 100005;

int N;
int T[MN], Ts[MN], eT[MN];
int C[MN], Cs[MN];
int A[MN], K[MN];
int Comp[MN], Ans[MN];

int main() {
	scanf("%d%d", &N, &Mod);
	{ // find primitive root
		std::vector<int> pr;
		{ // prime divisors
			int s = Mod - 1;
			for (int i = 2; i * i <= s; ++i)
				if (s % i == 0) {
					pr.push_back(i);
					while (s % i == 0)
						s /= i;
				}
			if (s > 1)
				pr.push_back(s);
		}
		for (int g = 2; ; ++g) {
			bool f = true;
			for (int p : pr)
				if (qPow(g, (Mod - 1) / p) == 1)
					f = false;
			if (f) {
				G = g;
				iG = gInv(G);
				break;
			}
		}
	}
	Init(MS - 1);
	// Solve [ T  = x (exp(Ts) + T exp(T))
	//       [ Ts = x T exp(T)
	// ====> [ T = x (exp(x T exp(T)) + T exp(T))
	NewtonT(N + 1, T);
	// eT = exp(T)
	PolyExp(T, N + 1, eT);
	// Ts = x T eT
	PolyConv(T, N + 1, eT, N + 1, Ts + 1, N), Ts[0] = 0;
	// C = x exp(Ts) + 1
	PolyExp(Ts, N + 1, C + 1), C[0] = 1;
	// Cs = Ts + x exp(T)
	for (int i = 1; i <= N; ++i) Cs[i] = (Ts[i] + eT[i - 1]) % Mod;
	Cs[0] = 0;
	// A = -ln(1 - C Cs) - Cs
	PolyConv(C, N + 1, Cs, N + 1, A, N + 1);
	for (int i = 0; i <= N; ++i) A[i] = (!i - A[i] + Mod) % Mod;
	PolyLn(A, N + 1, A);
	for (int i = 0; i <= N; ++i) A[i] = (2 * Mod - A[i] - Cs[i]) % Mod;
	// K = -ln(1 - x eT) - x eT
	for (int i = 1; i <= N; ++i) K[i] = (Mod - eT[i - 1]) % Mod;
	K[0] = 1;
	PolyLn(K, N + 1, K);
	for (int i = 1; i <= N; ++i) K[i] = (2 * Mod - K[i] - eT[i - 1]) % Mod;
	// Comp = A - K
	for (int i = 0; i <= N; ++i) Comp[i] = (A[i] - K[i] + Mod) % Mod;
	// Ans = exp(Comp)
	PolyExp(Comp, N + 1, Ans);
	printf("%lld\n", (LL)Ans[N] * Fac[N] % Mod);
	return 0;
}