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
const int Mod = 1000000007;
const int Inv2 = (Mod + 1) / 2;

const int Inf = 0x3f3f3f3f;
const LL InfLL = 0x3f3f3f3f3f3f3f3f;

const int MN = 1000005;

int n;
int pwi2[MN];
int ans[MN];

void Init() {
	pwi2[0] = 1;
	F(i, 1, 1000000)
		pwi2[i] = (int)((LL)pwi2[i - 1] * Inv2 % Mod);
}

void Solve() {
	scanf("%d", &n);
	if (n == 1) {
		puts("1");
		return ;
	}
	if (n == 2) {
		puts("0");
		puts("1");
		return ;
	}
	ans[1] = 0;
	static int coef[MN];
	coef[n + 1] = 1;
	dF(i, n, 2) {
		int basic = (i + 1) / 2;
		if (i == n)
			--basic;
		coef[i] = coef[i + 1];
		if (i * 2 <= n)
			coef[i] = (int)((coef[i] + (LL)(Mod - pwi2[i - (i * 2 == n)]) * coef[i * 2]) % Mod);
		if (i * 2 + 1 <= n)
			coef[i] = (int)((coef[i] + (LL)(Mod - pwi2[i + 1 - (i * 2 + 1 == n)]) * coef[i * 2 + 1]) % Mod);
//		printf("(basic, coef)[%d] = (%d, %d)\n", i, basic, coef[i]);
		ans[i] = (int)((LL)pwi2[basic] * coef[i] % Mod);
	}
	F(i, 1, n)
		printf("%d\n", ans[i]);
}

// [5 - 9]
// [5 - 8]
// [4 - 7]
// [4 - 6]
// [3 - 5]
// [3 - 4]
// [2 - 3]
// [2 - 2]