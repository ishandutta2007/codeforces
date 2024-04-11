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

void Solve();
int main() {
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

void Solve() {
	int n, tx, ty;
	int r[3], c[3];
	scanf("%d", &n);
	F(i, 0, 2)
		scanf("%d%d", &r[i], &c[i]);
	scanf("%d%d", &tx, &ty);
	int R, C;
	F(i, 0, 2)
		if (std::abs(r[(i + 1) % 3] - r[i]) + std::abs(r[(i + 2) % 3] - r[i]) + std::abs(c[(i + 1) % 3] - c[i]) + std::abs(c[(i + 2) % 3] - c[i]) == 2)
			R = r[i], C = c[i];
	if ((R == 1 || R == n) && (C == 1 || C == n))
		return puts(tx == R || ty == C ? "YES" : "NO"), void();
	puts((((tx ^ R) & 1) && ((ty ^ C) & 1)) ? "NO" : "YES");
}