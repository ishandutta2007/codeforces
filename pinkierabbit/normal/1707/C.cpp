#include <cstdio>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

typedef pair<int, int> pii;
#define F(i, a, b) for(int i = a; i <= (b); ++i)
#define F2(i, a, b) for(int i = a; i < (b); ++i)
#define dF(i, a, b) for(int i = a; i >= (b); --i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n", __FUNCTION__, __LINE__)
#define MN 100005
#define MM 200005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mkp make_pair
#define fi first
#define se second

void Solve();

int main() {
	int tests = 1;
//	scanf("%d", &tests);
	while (tests--)
		Solve();
	return 0;
}

int n, m;
int eu[MM], ev[MM], gg[MM];
int pa[MN];
int fp(int x) { return pa[x] ? pa[x] = fp(pa[x]) : x; }
std::vector<int> G[MN], V[MN];

int ldf[MN], rdf[MN], idf[MN], dfc;
void DFS(int u, int p) {
	idf[ldf[u] = ++dfc] = u;
	for (int v : G[u]) if (v != p)
		DFS(v, u),
		V[u].push_back(ldf[v]);
	rdf[u] = dfc;
}

int tg[MN];
void DFS1(int u, int p) {
	for (int v : G[u]) if (v != p)
		tg[v] += tg[u],
		DFS1(v, u);
}

void Solve() {
	scanf("%d%d", &n, &m);
	F(i, 1, m) {
		scanf("%d%d", &eu[i], &ev[i]);
		int x = fp(eu[i]), y = fp(ev[i]);
		if (x != y)
			pa[y] = x,
			G[eu[i]].push_back(ev[i]),
			G[ev[i]].push_back(eu[i]);
		else
			gg[i] = 1;
	}
	DFS(1, 0);
	int ttg = 0;
	F(i, 1, m) if (gg[i]) {
		int x = eu[i], y = ev[i];
		if (ldf[y] <= ldf[x] && ldf[x] <= rdf[y]) swap(x, y);
		if (ldf[x] <= ldf[y] && ldf[y] <= rdf[x]) {
			int z = idf[*prev(upper_bound(V[x].begin(), V[x].end(), ldf[y]))];
			++tg[z];
			--tg[y];
		} else {
			--tg[x];
			--tg[y];
			++ttg;
		}
	}
	DFS1(1, 0);
	F(i, 1, n)
		printf("%d", !(tg[i] + ttg));
}