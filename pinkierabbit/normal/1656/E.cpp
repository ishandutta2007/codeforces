#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> pii;
#define F(i, a, b) for(int i = a; i <= (b); ++i)
#define F2(i, a, b) for(int i = a; i < (b); ++i)
#define dF(i, a, b) for(int i = a; i >= (b); --i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n", __FUNCTION__, __LINE__)
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

void Solve();

int main() {
	int tests = 1;
	scanf("%d", &tests);
	while (tests--)
		Solve();
	return 0;
}

int n, d[MN], c[MN];
vector<int> G[MN];

void DFS(int u, int x) {
	c[u] = x;
	for (int v : G[u])
		if (!c[v])
			DFS(v, 3 - x);
}

void Solve() {
	scanf("%d", &n);
	F(i, 1, n) d[i] = c[i] = 0, G[i].clear();
	F(i, 2, n) {
		int x, y;
		scanf("%d%d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
		++d[x], ++d[y];
	}
	DFS(1, 1);
	F(i, 1, n) printf("%d%c", c[i] == 1 ? d[i] : -d[i], " \n"[i == n]);
}