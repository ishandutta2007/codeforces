#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <functional>
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

int n;
int a[MN], b[MN];

void Solve() {
	LL s = 0;
	scanf("%d", &n);
	F(i, 1, n) scanf("%d", a + i);
	F(i, 1, n) scanf("%d", b + i), s += b[i];
	std::vector<int> x, y;
	LL sx = 0, sy = 0;
	F(i, 1, n)
		if (a[i])
			y.push_back(b[i]), sy += b[i];
		else
			x.push_back(b[i]), sx += b[i];
	std::sort(x.begin(), x.end(), std::greater<int>());
	std::sort(y.begin(), y.end(), std::greater<int>());
	int u = (int)x.size();
	int v = (int)y.size();
	if (u < v) {
		LL ans = s + sx;
		for (int i = 0; i < u; ++i)
			ans += y[i];
		printf("%lld\n", ans);
	} else if (v < u) {
		LL ans = s + sy;
		for (int i = 0; i < v; ++i)
			ans += x[i];
		printf("%lld\n", ans);
	} else {
		LL ans = 2 * s;
		ans -= std::min(x.back(), y.back());
		printf("%lld\n", ans);
	}
}