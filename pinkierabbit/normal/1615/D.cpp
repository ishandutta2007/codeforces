#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> pii;
#define F(i, a, b) for(int i=a;i<=(b);++i)
#define F2(i, a, b) for(int i=a;i<(b);++i)
#define dF(i, a, b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 300005
#define MM 600005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mkp make_pair
#define fi first
#define se second

int n, m;
vector<pii> G[MN];

void Solve();

int main() {
	int tests = 1;
	scanf("%d", &tests);
	while(tests--) {
		Solve();
	}
	return 0;
}

int par[MN], wgh[MN], sum[MN], top[MN];
std::vector<pii> G2[MN];

void DFS(int u, int p, int t, int s) {
	par[u] = p;
	top[u] = t;
	sum[u] = s;
	for (const auto &[v, w] : G[u]) if (v != p) {
		wgh[v] = w;
		if (w == -1)
			DFS(v, u, v, s);
		else
			DFS(v, u, t, s ^ __builtin_parity(w));
	}
}

int ok;
int col[MN];
void DFS2(int u, int c) {
	col[u] = c;
	for (const auto &[v, w] : G2[u]) {
		int k = c ^ w;
		if (col[v] == -1)
			DFS2(v, k);
		else if (col[v] != k)
			ok = 0;
	}
}

void Solve() {
	scanf("%d%d", &n, &m);
	F(i, 1, n)
		G[i].clear(),
		G2[i].clear();
	F(i, 2, n) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	DFS(1, 0, 1, 0);
//	F(i, 1, n) printf("%d%c", top[i], " \n"[i == n]);
//	F(i, 1, n) printf("%d%c", sum[i], " \n"[i == n]);
	F(i, 1, m) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		int c = z ^ sum[x] ^ sum[y];
		x = top[x], y = top[y];
		G2[x].push_back({y, c});
		G2[y].push_back({x, c});
//		printf("%d -- %d : %d\n", x, y, c);
	}
	F(i, 1, n) col[i] = -1;
	ok = 1;
	F(i, 1, n) if (top[i] == i && col[i] == -1)
		DFS2(i, 0);
	if (!ok)
		return puts("NO"), void();
	puts("YES");
	F(i, 2, n)
		printf("%d %d %d\n", par[i], i, wgh[i] != -1 ? wgh[i] : col[i] ^ col[top[par[i]]]);
}

// bin-graph-col