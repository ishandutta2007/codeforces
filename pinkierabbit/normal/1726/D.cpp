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

const int MN = 200005;
const int MM = MN + 2;

int n, m, eu[MM], ev[MM];
std::vector<int> G[MN];

int col[MM];

int vis[MN];
void DFS(int u) {
	vis[u] = 1;
	for (int e : G[u]) {
		int v = eu[e] ^ ev[e] ^ u;
		if (!vis[v]) {
			col[e] = 0;
			DFS(v);
		}
	}
}

int DFS2(int u, int p, int d) {
	for (int e : G[u]) if (!col[e]) {
		int v = eu[e] ^ ev[e] ^ u;
		if (v == p)
			continue;
		if (v == d)
			return e;
		int r = DFS2(v, u, d);
		if (r)
			return e;
	}
	return 0;
}

void Solve() {
	scanf("%d%d", &n, &m);
	F(i, 1, n) G[i].clear(), vis[i] = 0;
	F(i, 1, m) {
		scanf("%d%d", &eu[i], &ev[i]);
		G[eu[i]].push_back(i);
		G[ev[i]].push_back(i);
		col[i] = 1;
	}
	DFS(1);
	{
		std::map<int, int> c;
		int j = 0;
		F(i, 1, m)
			if (col[i])
				++c[eu[i]],
				++c[ev[i]],
				j = i;
		if ((int)c.size() == 3) {
			int u = eu[j], v = ev[j];
			int k = DFS2(u, 0, v);
			col[j] = 0;
			col[k] = 1;
		}
	}
	F(i, 1, m) printf("%d", col[i]);
	puts("");
}