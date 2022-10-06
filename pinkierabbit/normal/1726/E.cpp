#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
using std::scanf, std::printf;

#define F(i, a, b) for(int i = a; i <= (b); ++i)
#define F2(i, a, b) for(int i = a; i < (b); ++i)
#define dF(i, a, b) for(int i = a; i >= (b); --i)
#define debug(...) std::fprintf(stderr, __VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n", __FUNCTION__, __LINE__)

void Init();
void Solve();
int main() {
	Init();
	int tests = 1;
	scanf("%d", &tests);
	while (tests--)
		Solve();
	return 0;
}

typedef long long LL;
const int Mod = 998244353;

inline int qPow(int b, int e) {
	int a = 1;
	for (; e; e >>= 1, b = (int)((LL)b * b % Mod))
		if (e & 1) a = (int)((LL)a * b % Mod);
	return a;
}
inline int gInv(int b) { return qPow(b, Mod - 2); }

const int MN = 300005;

int Inv[MN], Fac[MN], iFac[MN];
inline void bInit(int N) {
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

int f[MN], g[MN];
void Init() {
	int n = MN - 5;
	bInit(n);
	f[0] = f[1] = 1;
	F(i, 2, n)
		f[i] = (int)((f[i - 1] + (LL)(i - 1) * f[i - 2]) % Mod);
	g[0] = 1;
	F(i, 1, n)
		g[i] = (int)(2ll * (2 * i - 1) * g[i - 1] % Mod);
}

int n;

void Solve() {
	scanf("%d", &n);
	int ans = 0;
	F(k, 0, n / 4)
		ans = (int)((ans + (LL)Binom(n - 2 * k, 2 * k) * g[k] % Mod * f[n - 4 * k]) % Mod);
	printf("%d\n", ans);
}