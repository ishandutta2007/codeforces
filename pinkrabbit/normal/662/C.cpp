#include <cstdio>
#include <algorithm>

typedef long long LL;
const int Mod = 998244353;
const int MN = 1 << 20, MM = 100005;

int Sz, InvSz;

inline void FWT(int *A, int Ty) {
	for (int j = 1, j2 = 2; j < Sz; j <<= 1, j2 <<= 1)
		for (int i = 0; i < Sz; i += j2)
			for (int k = 0; k < j; ++k) {
				int X = A[i + k], Y = A[i + j + k];
				A[i + k] -= (A[i + k] = X + Y) >= Mod ? Mod : 0; 
				A[i + j + k] += (A[i + j + k] = X - Y) < 0 ? Mod : 0; 
			}
	if (!~Ty) for (int i = 0; i < Sz; ++i) A[i] = (LL)A[i] * InvSz % Mod;
}

int N, M;
char str[MM];
int V[MM], A[MN], B[MN], Ans = 0x3f3f3f3f;

int main() {
	scanf("%d%d", &N, &M);
	Sz = 1 << N, InvSz = Mod - (Mod - 1) / Sz;
	for (int i = 0; i < N; ++i) {
		scanf("%s", str);
		for (int j = 0; j < M; ++j)
			if (str[j] & 1) V[j] |= 1 << i;
	}
	for (int i = 0; i < M; ++i) ++A[V[i]];
	for (int i = 0, x; i < Sz; ++i) x = __builtin_popcount(i), B[i] = std::min(x, N - x);
	FWT(A, 1), FWT(B, 1);
	for (int i = 0; i < Sz; ++i) A[i] = (LL)A[i] * B[i] % Mod;
	FWT(A, -1);
	for (int i = 0; i < Sz; ++i) Ans = std::min(Ans, A[i]);
	printf("%d\n", Ans);
	return 0;
}