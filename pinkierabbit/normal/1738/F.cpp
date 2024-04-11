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

int n;
int d[MN], per[MN];
int pa[MN];
int fp(int x) { return pa[x] ? pa[x] = fp(pa[x]) : x; }
int vis[MN];

void Solve() {
	scanf("%d", &n);
	F(i, 1, n) scanf("%d", d + i);
	F(i, 1, n) per[i] = i;
	std::sort(per + 1, per + n + 1, [&](int i, int j) {
		return d[i] > d[j];
	});
	F(i, 1, n) pa[i] = 0, vis[i] = 0;
	F(id, 1, n) {
		int i = per[id];
		if (d[i] && !vis[i]) {
			int cnt = 0;
			while (true) {
				++cnt;
				if (cnt > d[i])
					break;
				printf("? %d\n", i);
				std::fflush(stdout);
				int x;
				scanf("%d", &x);
				pa[fp(x)] = fp(i);
				if (!vis[x])
					vis[x] = 1;
				else
					break;
			}
			vis[i] = 1;
		}
	}
	printf("! ");
	F(i, 1, n) printf("%d%c", fp(i), " \n"[i == n]);
	std::fflush(stdout);
}