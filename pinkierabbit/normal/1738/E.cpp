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

const int Inf = 0x3f3f3f3f;
const LL InfLL = 0x3f3f3f3f3f3f3f3f;

const int MN = 500005;

inline int qPow(int b, int e) {
	int a = 1;
	for (; e; e >>= 1, b = (int)((LL)b * b % Mod))
		if (e & 1) a = (int)((LL)a * b % Mod);
	return a;
}
inline int gInv(int b) { return qPow(b, Mod - 2); }

int Inv[MN], Fac[MN], iFac[MN];
inline void InitFacs(int N) {
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

void Init() {
	InitFacs(MN - 5);
}

int n;
int a[MN];
LL s[MN], is[MN];

void Solve() {
	scanf("%d", &n);
	F(i, 1, n) scanf("%d", a + i);
	s[0] = 0;
	is[0] = 0;
	F(i, 1, n) s[i] = s[i - 1] + a[i];
	F(i, 1, n) is[i] = is[i - 1] + a[n - i + 1];
	LL sum = s[n];
	if (sum == 0) {
		printf("%d\n", qPow(2, n - 1));
		return ;
	}
	int ans = 1;
	LL m = (sum - 1) / 2;
	for (int i = 0; s[i] <= m; ++i) {
		if (i >= 1 && s[i - 1] == s[i])
			continue;
		int j = i;
		while (s[j + 1] == s[i])
			++j;
		int num1 = j - i + 1;
		auto it1 = std::lower_bound(is, is + n + 1, s[i]);
		auto it2 = std::upper_bound(is, is + n + 1, s[i]);
		int num2 = (int)(it2 - it1);
		if (s[i] == 0)
			--num1, --num2;
		if (!num1 || !num2)
			continue;
//		printf("(num1, num2) = (%d, %d)\n", num1, num2);
		ans = (int)((LL)ans * Binom(num1 + num2, num1) % Mod);
	}
	if (sum % 2 == 0) {
		auto it1 = std::lower_bound(is, is + n + 1, sum / 2);
		auto it2 = std::upper_bound(is, is + n + 1, sum / 2);
		int num = (int)(it2 - it1);
		ans = (int)((LL)ans * qPow(2, num) % Mod);
	}
	printf("%d\n", ans);
}