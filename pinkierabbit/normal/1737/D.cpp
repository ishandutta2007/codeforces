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

const int MN = 505;
const int MM = 250005;

int n, m;
int dis[MN][MN];

void Solve() {
	static int x[MM], y[MM], z[MM];
	scanf("%d%d", &n, &m);
	F(i, 1, n)
		F(j, 1, n)
			dis[i][j] = i == j ? 0 : Inf;
	F(i, 1, m) {
		scanf("%d%d%d", &x[i], &y[i], &z[i]);
		dis[x[i]][y[i]] = 1;
		dis[y[i]][x[i]] = 1;
	}
	F(k, 1, n)
		F(i, 1, n)
			F(j, 1, n)
				dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);
	LL ans = InfLL;
	F(i, 1, m) {
		ans = std::min(ans, (LL)(dis[1][x[i]] + dis[n][y[i]] + 1) * z[i]);
		ans = std::min(ans, (LL)(dis[n][x[i]] + dis[1][y[i]] + 1) * z[i]);
		F(u, 1, n) {
			ans = std::min(ans, (LL)(dis[x[i]][u] + dis[u][1] + dis[u][n] + 2) * z[i]);
			ans = std::min(ans, (LL)(dis[y[i]][u] + dis[u][1] + dis[u][n] + 2) * z[i]);
		}
	}
	printf("%lld\n", ans);
}