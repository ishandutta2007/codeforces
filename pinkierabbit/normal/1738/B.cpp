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

int n, k;
LL a[MN], s[MN];

void Solve() {
	scanf("%d%d", &n, &k);
	F(i, n - k + 1, n) scanf("%lld", s + i);
	F(i, n - k + 2, n) a[i] = s[i] - s[i - 1];
	F(i, n - k + 3, n)
		if (a[i - 1] > a[i])
			return puts("No"), void();
	int m = n - k + 1;
	LL sum = s[m];
	LL lim = m < n ? a[m + 1] : Inf;
	// Sum of a[1] ~ a[m] = s[m]
	// a[1] <= a[2] <= ... <= a[m] <= a[m + 1]
//	printf("(m, sum, lim) = (%d, %lld, %lld)\n", m, sum, lim);
	puts(lim * m >= sum ? "Yes" : "No");
}