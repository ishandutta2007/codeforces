#include <cstdio>
#include <algorithm>

typedef long long LL;
const int Mod = 998244353;
const int G = 3, iG = 332748118;
const int MN = 200005, MS = 1 << 19;
const int Inf = 0x3f3f3f3f;

inline int qPow(int b, int e) {
	int a = 1;
	for (; e; e >>= 1, b = (LL)b * b % Mod)
		if (e & 1) a = (LL)a * b % Mod;
	return a;
}

int Sz, InvSz, R[MS];

inline void InitFNTT(int N) {
	int Bt = 0;
	while (1 << Bt < N) ++Bt;
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
				A[i + k] = X + Y; if (A[i + k] >= Mod) A[i + k] -= Mod;
				A[i + j + k] = X - Y; if (A[i + j + k] < 0) A[i + j + k] += Mod;
			}
		}
	}
	if (!~Ty) for (int i = 0; i < Sz; ++i) A[i] = (LL)A[i] * InvSz % Mod;
}

int N, M, K;
char S[MN], T[MN];
const char c[4] = {'A', 'C', 'G', 'T'};
int lst[MN], nxt[MN];
int A[MS], B[MS], C[MN], Ans;

int main() {
	scanf("%d%d%d", &N, &M, &K);
	scanf("%s%s", S, T);
	for (int z = 0; z < 4; ++z) {
		char ch = c[z];
		lst[0] = S[0] == ch ? 0 : -Inf;
		for (int i = 1; i < N; ++i)
			lst[i] = S[i] == ch ? i : lst[i - 1];
		nxt[N - 1] = S[N - 1] == ch ? N - 1 : Inf;
		for (int i = N - 2; i >= 0; --i)
			nxt[i] = S[i] == ch ? i : nxt[i + 1];
		InitFNTT(N + M - 1);
		for (int i = 0; i < N; ++i) A[i] = i - lst[i] <= K || nxt[i] - i <= K;
		for (int i = N; i < Sz; ++i) A[i] = 0;
		for (int i = 0; i < M; ++i) B[i] = T[M - i - 1] == ch;
		for (int i = M; i < Sz; ++i) B[i] = 0;
		FNTT(A, 1), FNTT(B, 1);
		for (int i = 0; i < Sz; ++i) A[i] = (LL)A[i] * B[i] % Mod;
		FNTT(A, -1);
		for (int i = 0; i <= N - M; ++i)
			C[i] += A[M + i - 1];
	}
	for (int i = 0; i <= N - M; ++i)
		if (C[i] == M) ++Ans;
	printf("%d\n", Ans);
	return 0;
}