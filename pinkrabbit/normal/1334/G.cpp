#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline")
#pragma GCC option("arch=native","tune=native","no-zero-upper")
#pragma GCC target("avx2")

#include <cstdio>
#include <cstring>
#include <random>
#include <chrono>
#include <algorithm>

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

template<typename T>
inline T range(T l, T r) {
	return std::uniform_int_distribution<T>(l, r)(rng);
}

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

int PolyConvA[MS], PolyConvB[MS];
inline void PolyConv(int *_A, int N, int *_B, int M, int *_C, int tN = -1) {
	if (tN == -1) tN = N + M - 1;
	InitFNTT(N + M - 1);
	for (int i = 0; i < N; ++i) PolyConvA[i] = _A[i];
	for (int i = N; i < Sz; ++i) PolyConvA[i] = 0;
	for (int i = 0; i < M; ++i) PolyConvB[i] = _B[i];
	for (int i = M; i < Sz; ++i) PolyConvB[i] = 0;
	FNTT(PolyConvA, 1), FNTT(PolyConvB, 1);
	for (int i = 0; i < Sz; ++i) PolyConvA[i] = (LL)PolyConvA[i] * PolyConvB[i] % Mod;
	FNTT(PolyConvA, -1);
	for (int i = 0; i < tN; ++i) _C[i] = PolyConvA[i];
}

const int MN = 200005;

int N, M, per[26], rnd[26];
char s[MN], t[MN];
int S[MN], T[MN];
int A[MS], B[5][MS], C[MS];

int main() {
	for (int i = 0; i < 26; ++i) scanf("%d", &per[i]), --per[i], rnd[i] = range(0, Mod - 1);
	scanf("%s%s", s, t), N = strlen(s), M = strlen(t);
	for (int i = 0; i < N; ++i) S[i] = s[i] - 'a';
	for (int i = 0; i < M; ++i) T[i] = t[i] - 'a';
	InitFNTT(N + M - 1);
	for (int i = 0; i < M; ++i) {
		B[0][i] = 1;
		for (int j = 1; j <= 4; ++j)
			B[j][i] = (LL)B[j - 1][i] * rnd[T[i]] % Mod;
	}
	for (int j = 0; j <= 4; ++j) FNTT(B[j], 1);
	for (int a = 0; a <= 2; ++a)
		for (int b = 0; b <= 2; ++b) {
			for (int i = 0; i < N; ++i) {
				A[i] = 1;
				for (int j = 1; j <= a; ++j) A[i] = (LL)A[i] * rnd[S[N - i - 1]] % Mod;
				for (int j = 1; j <= b; ++j) A[i] = (LL)A[i] * rnd[per[S[N - i - 1]]] % Mod;
			}
			for (int i = N; i < Sz; ++i) A[i] = 0;
			FNTT(A, 1);
			for (int i = 0; i < Sz; ++i) C[i] = (C[i] + (LL)(a == 1 ? -2 : 1) * (b == 1 ? -2 : 1) * A[i] * B[4 - a - b][i]) % Mod;
		}
	for (int i = 0; i < Sz; ++i) C[i] = (C[i] + Mod) % Mod;
	FNTT(C, -1);
	for (int i = 0; i < M - N + 1; ++i) printf("%d", !C[N + i - 1]);
	return 0;
}