#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <cmath>
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

LL S(LL n) {
	if (n <= 4)
		return n;
	LL x = (int)std::sqrt(n);
	while (x * x > n) --x;
	while ((x + 1) * (x + 1) <= n) ++x;
	LL ret = x;
	while (x * (x + 1) > n) --x;
	while ((x + 1) * (x + 2) <= n) ++x;
	ret += x;
	while (x * (x + 2) > n) --x;
	while ((x + 1) * (x + 3) <= n) ++x;
	ret += x;
	return ret;
}

void Solve() {
	LL l, r;
	scanf("%lld%lld", &l, &r);
	printf("%lld\n", S(r) - S(l - 1));
}