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

int n;
int a[MN], b[MN], deg[MN];
vector<int> G[MN];
bool vis[MN], instk[MN];
bool gg;

void DFS(int u) {
	vis[u] = true;
	instk[u] = true;
	for (int v : G[u])
		if (!vis[v])
			DFS(v);
		else if (instk[v])
			gg = true;
	instk[u] = false;
}

void Solve() {
	scanf("%d", &n);
	F(i, 1, n) G[i].clear(), deg[i] = 0;
	F(i, 1, n) scanf("%d", a + i), ++deg[a[i]];
	int f = max_element(deg + 1, deg + n + 1) - deg;
	F(i, 1, n) scanf("%d", b + i);
	F(i, 1, n)
		if (a[i] != f && b[i] != f)
			G[a[i]].push_back(b[i]);
	F(i, 1, n) vis[i] = false;
	gg = false;
	F(i, 1, n)
		if (!vis[i])
			DFS(i);
	puts(gg ? "WA" : "AC");
}