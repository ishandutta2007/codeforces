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

int n;
int a[MN], b[MN];

void Init() {
}

void Solve() {
	scanf("%d", &n);
	int s = 0;
	F(i, 1, n) scanf("%d", a + i), s += a[i];
	if (s & 1)
		return puts("-1"), void();
	int lst = 0;
	F(i, 1, n) {
		if (a[i]) {
			int v = a[i];
			if (lst) {
				int u = a[lst];
				if (u == v)
					b[lst] = 1,
					b[i] = -1;
				else
					b[lst] = 1,
					b[i] = 1;
				lst = 0;
			} else {
				lst = i;
			}
		} else {
			b[i] = 1;
		}
	}
//	F(i, 1, n)
//		printf("%c", b[i] == 1 ? '+' : '-');
//	puts("");
	int k = 1;
	F(i, 2, n)
		if (b[i - 1] == 1 && b[i] == 1)
			++k;
	printf("%d\n1 ", k);
	F(i, 2, n)
		if (b[i - 1] == 1 && b[i] == 1)
			printf("%d\n%d ", i - 1, i);
	printf("%d\n", n);
}