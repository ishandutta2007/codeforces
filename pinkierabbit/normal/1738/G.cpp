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

const int MN = 1005;

int n, k;
int a[MN][MN];
std::vector<int> V[MN];
int f[MN];
int b[MN][MN];

void Solve() {
	scanf("%d%d", &n, &k);
	F(j, 1, n) V[j].clear();
	F(i, 1, n)
		F(j, 1, n) {
			scanf("%1d", &a[i][j]);
			if (n - k + 2 <= i - j && i - j <= n - 1)
				a[i][j] = 1;
			if (n - k + 2 <= j - i && j - i <= n - 1)
				a[i][j] = 1;
			if (n - k + 1 == i - j || n - k + 1 == j - i)
				a[i][j] = 0;
			if (!a[i][j])
				V[j].push_back(i);
		}
	F(j, 1, n)
		V[j].push_back(n + 1),
		std::reverse(V[j].begin(), V[j].end());
	F(i, 1, n)
		F(j, 1, n)
			b[i][j] = 0;
//	F(i, 1, n) {
//		F(j, 1, n)
//			printf("%d", a[i][j]);
//		puts("");
//	}
	--k;
	F(j, 1, n)
		f[j] = V[j].back();
	F(p, 1, k) {
		int now = n;
		F(j, 1, n) {
			if (f[j] <= now) {
				while (V[j].back() <= now)
					a[V[j].back()][j] = 1,
					V[j].pop_back();
				F(i, f[j], now)
					b[i][j] = 1;
				now = f[j];
				f[j] = V[j].back();
			} else {
				b[now][j] = 1;
			}
		}
	}
	F(j, 1, n)
		if (f[j] != n + 1)
			return puts("NO"), void();
	puts("YES");
	F(i, 1, n) {
		F(j, 1, n)
			printf("%d", b[i][j]);
		puts("");
	}
}