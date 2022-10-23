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
char s[MN];
int b[35];

void Solve() {
	scanf("%d%d%s", &n, &k, s + 1);
	F2(j, 0, 26) b[j] = 0;
	F(i, 1, n)
		++b[s[i] - 'a'];
	int m = n / k;
	F(i, 1, k) {
		int p = m;
		F(j, 0, std::min(25, m))
			if (!b[j]) {
				p = j;
				break;
			}
		putchar('a' + p);
		F2(j, 0, p)
			--b[j];
		int l = m - p;
		while (l) {
			--l;
			bool ok = false;
			F2(j, 0, 26)
				if (b[j] && j > p) {
					--b[j];
					ok = true;
					break;
				}
			if (ok)
				continue;
			--*std::max_element(b + 0, b + p);
		}
	}
	puts("");
}