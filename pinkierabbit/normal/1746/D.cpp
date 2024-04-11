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
int p[MN];
LL s[MN];
std::vector<int> G[MN];

void Init() {
}

std::map<LL, LL> mp[MN];
void Solve(int u, LL k) {
	if (k == 0)
		return mp[u][k] = 0, void();
	int ch = (int)G[u].size();
	if (!ch)
		return mp[u][k] = k * s[u], void();
	if (mp[u].contains(k))
		return ;
	LL k0 = k / ch;
	LL k1 = k / ch + 1;
	int num = (int)(k % ch);
	LL &val = mp[u][k] = k * s[u];
	for (int v : G[u]) {
		Solve(v, k0);
		if (num)
			Solve(v, k1);
	}
	for (int v : G[u])
		val += mp[v][k0];
	if (!num)
		return ;
	static LL dif[MN];
	int c = 0;
	for (int v : G[u])
		dif[c++] = mp[v][k1] - mp[v][k0];
	std::sort(dif, dif + c);
	std::reverse(dif, dif + c);
	F2(i, 0, num)
		val += dif[i];
}

void Solve() {
	LL k;
	scanf("%d%lld", &n, &k);
	F(i, 1, n) G[i].clear();
	F(i, 2, n) {
		scanf("%d", p + i);
		G[p[i]].push_back(i);
	}
	F(i, 1, n) scanf("%lld", s + i);
	F(i, 1, n) mp[i].clear();
	Solve(1, k);
	printf("%lld\n", mp[1][k]);
}