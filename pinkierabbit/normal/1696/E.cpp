#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long LL;
const int Mod = 1000000007;
const int MS = 1 << 19;

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

#define F(i, a, b) for(int i = a; i <= (b); ++i)

void Solve();

int main() {
	Init(MS - 1);
	int tests = 1;
//	scanf("%d", &tests);
	while (tests--)
		Solve();
	return 0;
}

const int MN = 200005;
int n, a[MN];

void Solve() {
	scanf("%d", &n);
	int ans = 0;
	F(i, 0, n) scanf("%d", a + i), ans = (ans + Binom(a[i] + i, i + 1)) % Mod;
	printf("%d\n", ans);
}