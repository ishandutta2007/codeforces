#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

#define F(i, a, b) for(int i=a;i<=(b);++i)
#define MN 300005
#define ll long long

int n, k;
vector<int> G[MN];

void Solve();

int main() {
	int tests = 1;
	while(tests--) {
		Solve();
	}
	return 0;
}

int nl, par[MN], ldf[MN], rdf[MN], idf[MN], dfc;

void DFS(int u, int p) {
	par[u] = p;
	ldf[u] = dfc + 1;
	int cc = 0;
	for (const auto &v : G[u]) if (v != p) {
		DFS(v, u);
		++cc;
	}
	if (!cc) {
		++nl;
		idf[++dfc] = u;
	}
	rdf[u] = dfc;
}

#define li (i << 1)
#define ri (li | 1)
#define mid ((l + r) >> 1)
#define ls li, l, mid
#define rs ri, mid + 1, r
const int MS = 1 << 19 | 7;
int mx[MS], id[MS], tg[MS];
void Build(int i, int l, int r) {
	mx[i] = 0, id[i] = l, tg[i] = 0;
	if (l == r) return ;
	Build(ls);
	Build(rs);
}
inline void P(int i, int x) {
	mx[i] += x, tg[i] += x;
}
inline void Pushdown(int i) {
	if (tg[i])
		P(li, tg[i]),
		P(ri, tg[i]),
		tg[i] = 0;
}
void Add(int i, int l, int r, int a, int b, int x) {
	if (r < a || b < l) return ;
	if (a <= l && r <= b) return P(i, x);
	Pushdown(i);
	Add(ls, a, b, x);
	Add(rs, a, b, x);
	mx[i] = max(mx[li], mx[ri]);
	id[i] = mx[i] == mx[li] ? id[li] : id[ri];
}

int del[MN];

void Solve() {
	scanf("%d%d", &n, &k);
	F(i, 2, n) {
		int x, y;
		scanf("%d%d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	nl = 0, dfc = 0;
	DFS(1, 0);
//	F(i, 1, n) printf("%d : [%d -- %d]\n", i, ldf[i], rdf[i]);
	if (k >= nl) {
		int red = min(max(n / 2, nl), k);
		printf("%lld\n", (ll)(n - red) * red);
		return ;
	}
	// red : color leaves
	Build(1, 1, dfc);
	F(i, 1, n)
		Add(1, 1, dfc, ldf[i], rdf[i], 1);
	int cnt = n;
	F(i, 1, k) {
		int u = idf[id[1]];
		while (u && !del[u])
			Add(1, 1, dfc, ldf[u], rdf[u], -1),
			del[u] = 1, --cnt,
			u = par[u];
	}
	int blue = min(cnt, n / 2);
	int white = n - k - blue;
	printf("%lld\n", (ll)white * (k - blue));
}

// red : leaves do equivalent job
// blue : when fixed red, the optimal is (n/2)
// continuity on integers
// red : when the set of leaves is fixed, which means blue is fixed, the optimal is (n/2), too
// red : there's no non-leaf red vertex, if at least one leaf remains