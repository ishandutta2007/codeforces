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

const int Inf = 0x3f3f3f3f;
const LL InfLL = 0x3f3f3f3f3f3f3f3f;

const int MN = 500005;

int n, a[MN];

void Init() {
}

void Solve() {
	scanf("%d", &n);
	int s = 0;
	F(i, 1, n) scanf("%d", a + i), s += a[i];
	int x = n - s, y = 0;
	int w = 0;
	F(i, 1, n) {
		if (a[i])
			++y;
		else
			--x;
		w = std::max(w, std::min(x, y));
	}
	int m = (int)((LL)n * (n - 1) / 2 % Mod);
	int ans = 0;
	F(i, 1, w)
		ans = (ans + qPow(i, Mod - 3)) % Mod;
	ans = (int)((LL)ans * m % Mod);
	printf("%d\n", ans);
}