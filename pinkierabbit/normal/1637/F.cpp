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
#define MN 400005
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
	while (tests--) {
		Solve();
	}
	return 0;
}

int n, h[MN];
vector<int> G[MN];

int mx[MN];
ll s[MN];
void DFS1(int u, int p) {
	mx[u] = 0;
	s[u] = 0;
	for (int v : G[u]) if (v != p) {
		DFS1(v, u);
		mx[u] = max(mx[u], mx[v]);
		s[u] += s[v];
	}
	s[u] += max(h[u] - mx[u], 0);
	mx[u] = max(mx[u], h[u]);
}

int mx2[MN];
ll s2[MN], an[MN];
void DFS2(int u, int p) {
	static int seq[MN];
	int c = 0;
	for (int v : G[u]) if (v != p)
		seq[++c] = v;
	static int premx[MN], sufmx[MN];
	static ll pres[MN], sufs[MN];
	premx[0] = 0;
	pres[0] = 0;
	sufmx[c + 1] = 0;
	sufs[c + 1] = 0;
	F(i, 1, c)
		premx[i] = max(premx[i - 1], mx[seq[i]]),
		pres[i] = pres[i - 1] + s[seq[i]];
	dF(i, c, 1)
		sufmx[i] = max(sufmx[i + 1], mx[seq[i]]),
		sufs[i] = sufs[i + 1] + s[seq[i]];
	an[u] = pres[c] + s2[u] + max(h[u] - max(premx[c], mx2[u]), 0);
	F(i, 1, c) {
		int v = seq[i];
		int mxi = max(max(premx[i - 1], sufmx[i + 1]), mx2[u]);
		s2[v] = pres[i - 1] + sufs[i + 1] + s2[u] + max(h[u] - mxi, 0);
		mx2[v] = max(mxi, h[u]);
	}
	for (int v : G[u]) if (v != p)
		DFS2(v, u);
}

void Solve() {
	scanf("%d", &n);
	F(i, 1, n) scanf("%d", h + i);
	F(i, 2, n) {
		int x, y;
		scanf("%d%d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	DFS1(1, 0);
	mx2[1] = 0;
	s2[1] = 0;
	DFS2(1, 0);
	ll ans = infll;
	F(i, 1, n)
		ans = min(ans, an[i]);
	ans += mx[1];
	printf("%lld\n", ans);
}