#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <map>
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
int a[MN], s[MN];
int f[MN];

void Solve() {
	scanf("%d", &n);
	F(i, 1, n) scanf("%d", a + i), s[i] = s[i - 1] ^ a[i];
	f[0] = 0;
	std::map<int, int> g;
	g[0] = 0;
	F(i, 1, n) {
		f[i] = f[i - 1];
		auto it = g.find(s[i]);
		if (it != g.end())
			f[i] = std::max(f[i], it->second + 1);
		g[s[i]] = std::max(g[s[i]], f[i]);
	}
	printf("%d\n", n - f[n]);
}