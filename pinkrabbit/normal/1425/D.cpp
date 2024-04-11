#include <cstdio>
#include <algorithm>

typedef long long LL;
const int Mod = 1000000007;
const int MN = 2005;

inline int qPow(int b, int e) {
	int a = 1;
	for (; e; e >>= 1, b = (LL)b * b % Mod)
		if (e & 1) a = (LL)a * b % Mod;
	return a;
}
inline int gInv(int b) { return qPow(b, Mod - 2); }

int Inv[MN], Fac[MN], iFac[MN];
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

const int MS = 1005;

int N, M, R, S;
int x[MN], y[MN], v[MN];
int B[MS][MS];

inline int P0(int i, int j) {
	if (i < 1 || j < 1) return 0;
	if (i > S) i = S;
	if (j > S) j = S;
	return B[i][j];
}
inline int P1(int sx, int sy, int tx, int ty) {
	if (sx > tx || sy > ty) return 0;
	return P0(tx, ty) - P0(sx - 1, ty) - P0(tx, sy - 1) + P0(sx - 1, sy - 1);
}
inline int P2(int x, int y) {
	return P1(x - R, y - R, x + R, y + R);
}
inline int P3(int sx, int sy, int tx, int ty) {
	if (sx > tx) std::swap(sx, tx);
	if (sy > ty) std::swap(sy, ty);
	return P1(tx - R, ty - R, sx + R, sy + R);
}

int main() {
	scanf("%d%d%d", &N, &M, &R), S = 1000;
	Init(N);
	for (int i = 1; i <= N; ++i) {
		scanf("%d%d%d", &x[i], &y[i], &v[i]);
		B[x[i]][y[i]] = 1;
	}
	for (int i = 1; i <= S; ++i)
		for (int j = 1; j <= S; ++j)
			B[i][j] += B[i - 1][j] + B[i][j - 1] - B[i - 1][j - 1];
	int Ans = 0;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j) {
			int Coef1 = (LL)v[i] * v[j] % Mod;
			int Coef2 = Binom(N, M);
			Coef2 = (Coef2 - Binom(N - P2(x[i], y[i]), M) + Mod) % Mod;
			Coef2 = (Coef2 - Binom(N - P2(x[j], y[j]), M) + Mod) % Mod;
			Coef2 = (Coef2 + Binom(N - P2(x[i], y[i]) - P2(x[j], y[j]) + P3(x[i], y[i], x[j], y[j]), M)) % Mod;
			Ans = (Ans + (LL)Coef1 * Coef2) % Mod;
		}
	printf("%d\n", Ans);
	return 0;
}