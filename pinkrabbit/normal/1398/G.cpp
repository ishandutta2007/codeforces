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
	for (int i = 1; i <= N; ++i) Fac[i] = (LL)Fac[i - 1] * i % Mod;
	iFac[N] = gInv(Fac[N]);
	for (int i = N; i >= 1; --i) iFac[i - 1] = (LL)iFac[i] * i % Mod;
	for (int i = 1; i <= N; ++i) Inv[i] = (LL)Fac[i - 1] * iFac[i] % Mod;
}
inline int Binom(int N, int M) {
	if (M < 0 || M > N) return 0;
	return (LL)Fac[N] * iFac[M] % Mod * iFac[N - M] % Mod;
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
			ws[i << 1] = ws[i], ws[i << 1 | 1] = (LL)ws[i] * w % Mod;
		MaxSz <<= 1;
	}
}

inline void FNTT(int *A, int Ty) {
	for (int i = 0; i < Sz; ++i) if (R[i] < i) std::swap(A[R[i]], A[i]);
	for (int j = 1, j2 = 2; j < Sz; j <<= 1, j2 <<= 1) {
		int X, Y;
		for (int i = 0; i < Sz; i += j2) {
			for (int k = 0; k < j; ++k) {
				X = A[i + k], Y = (LL)ws[j + k] * A[i + j + k] % Mod;
				A[i + k] -= (A[i + k] = X + Y) >= Mod ? Mod : 0;
				A[i + j + k] += (A[i + j + k] = X - Y) < 0 ? Mod : 0;
			}
		}
	}
	if (!~Ty) {
		for (int i = 0; i < Sz; ++i) A[i] = (LL)A[i] * InvSz % Mod;
		std::reverse(A + 1, A + Sz);
	}
}

inline void PolyConv(int *_A, int N, int *_B, int M, int *_C, int tN = -1) {
	if (tN == -1) tN = N + M - 1;
	static int A[MS], B[MS];
	InitFNTT(N + M - 1);
	for (int i = 0; i < N; ++i) A[i] = _A[i];
	for (int i = N; i < Sz; ++i) A[i] = 0;
	for (int i = 0; i < M; ++i) B[i] = _B[i];
	for (int i = M; i < Sz; ++i) B[i] = 0;
	FNTT(A, 1), FNTT(B, 1);
	for (int i = 0; i < Sz; ++i) A[i] = (LL)A[i] * B[i] % Mod;
	FNTT(A, -1);
	for (int i = 0; i < tN; ++i) _C[i] = A[i];
}

const int MN = 200005, MV = 200005;

int N, X, Y, Q;
int A[MV], B[MV];
int _C[MV * 2], *C;

int main() {
	scanf("%d%d%d", &N, &X, &Y), C = _C + X;
	for (int i = 0, x; i <= N; ++i)
		scanf("%d", &x),
		A[x] = B[X - x] = 1;
	PolyConv(A, X + 1, B, X + 1, C - X);
	scanf("%d", &Q);
	while (Q--) {
		int L;
		scanf("%d", &L);
		L /= 2;
		int Ans = -1;
		for (int i = 1; i * i <= L; ++i) if (L % i == 0) {
			int u = i;
			int v = L / i;
			if (u > Y && u - Y <= X && C[u - Y]) Ans = std::max(Ans, u);
			if (v > Y && v - Y <= X && C[v - Y]) Ans = std::max(Ans, v);
		}
		printf("%d%c", Ans == -1 ? -1 : Ans * 2, " \n"[!Q]);
	}
	return 0;
}