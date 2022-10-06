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

int n, m, q, k;
int a[MN], b[MN], f[MN], g[MN];
std::vector<int> G[MN];

void Solve() {
	scanf("%d%d", &n, &m);
	if (m < n)
		return puts("No"), void();
	if (n % 2 == 0 && m % 2 == 1)
		return puts("No"), void();
	puts("Yes");
	if (n % 2 == 1) {
		F(i, 1, n - 1) printf("1 ");
		printf("%d\n", m - (n - 1));
	} else {
		F(i, 1, n - 2) printf("1 ");
		int num = (m - (n - 2)) / 2;
		printf("%d %d\n", num, num);
	}
}