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
int a[MN], b[MN];
std::vector<int> G[MN];

int dfn;
void DFS(int u) {
	a[dfn++] = u;
	int tch = 0;
	for (int v : G[u])
		if (!G[v].empty())
			tch = v;
	for (int v : G[u])
		if (v != tch)
			DFS(v);
	if (tch)
		DFS(tch);
}

void Solve() {
	scanf("%d", &n);
	F(i, 1, n) scanf("%d", b + i);
	k = 0;
	F(i, 1, n)
		if (b[i] > i)
			k = std::max(k, i);
	F(i, 0, n + 1)
		G[i].clear();
	F(i, 1, n)
		G[b[i]].push_back(i);
	dfn = 0;
	DFS(G[0].empty() ? n + 1 : 0);
	printf("%d\n", k);
	F(i, 1, n)
		printf("%d%c", a[i], " \n"[i == n]);
}