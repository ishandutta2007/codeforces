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
//	scanf("%d", &tests);
	while (tests--)
		Solve();
	return 0;
}

typedef long long LL;
const int Mod = 998244353;

const int Inf = 0x3f3f3f3f;
const LL InfLL = 0x3f3f3f3f3f3f3f3f;

const int MV = 500005;

int n, x;
int b[MV];

void Init() {
}

void Solve() {
	scanf("%d%d", &n, &x);
	F(i, 1, x) b[i] = 0;
	F(i, 1, n) {
		int y;
		scanf("%d", &y);
		++b[y];
	}
	F(i, 2, x) {
		if (b[i - 1] % i)
			return puts("No"), void();
		b[i] += b[i - 1] / i;
	}
	puts("Yes");
}