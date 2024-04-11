#include <cstdio>
#include <vector>
#include <algorithm>

typedef long long LL;
typedef std::pair<int, int> pii;
const LL INF = 0x3f3f3f3f3f3f3f3f;
const int MN = 500005;

int N, Q;
int faz[MN], d[MN], rdf[MN], stk[MN], t;
LL w[MN], dis[MN];
std::vector<int> c[MN], q[MN];
int l[MN], r[MN];
LL Ans[MN];

const int MS = 1 << 20;
#define li (i << 1)
#define ri (i << 1 | 1)
#define mid ((l + r) >> 1)
#define ls li, l, mid
#define rs ri, mid + 1, r
LL mn[MS], tg[MS];
inline void P(int i, LL v) { mn[i] += v; tg[i] += v; }
inline void pd(int i) { if (tg[i]) P(li, tg[i]), P(ri, tg[i]), tg[i] = 0; }
void Mdf(int i, int l, int r, int a, int b, LL v) {
	if (r < a || b < l) return ;
	if (a <= l && r <= b) return P(i, v);
	pd(i), Mdf(ls, a, b, v), Mdf(rs, a, b, v);
	mn[i] = std::min(mn[li], mn[ri]);
}
LL Qur(int i, int l, int r, int a, int b) {
	if (r < a || b < l) return INF;
	if (a <= l && r <= b) return mn[i];
	pd(i); return std::min(Qur(ls, a, b), Qur(rs, a, b));
}

void DFS(int u) {
	Mdf(1, 1, N, 1, N, w[u]);
	Mdf(1, 1, N, u, rdf[u], -2 * w[u]);
	for (int i : q[u]) Ans[i] = Qur(1, 1, N, l[i], r[i]);
	for (int i : c[u]) DFS(i);
	Mdf(1, 1, N, 1, N, -w[u]);
	Mdf(1, 1, N, u, rdf[u], 2 * w[u]);
}

int main() {
	scanf("%d%d", &N, &Q);
	stk[t = 1] = 1;
	for (int i = 2; i <= N; ++i) {
		scanf("%d%lld", &faz[i], &w[i]);
		c[faz[i]].push_back(i);
		++d[faz[i]], ++d[i];
		dis[i] = dis[faz[i]] + w[i];
		while (faz[i] != stk[t]) rdf[stk[t--]] = i - 1;
		stk[++t] = i;
	}
	while (t) rdf[stk[t--]] = N;
	for (int i = 1; i <= N; ++i) {
		if (d[i] == 1) Mdf(1, 1, N, i, i, dis[i]);
		else Mdf(1, 1, N, i, i, INF);
	}
	for (int i = 1, u; i <= Q; ++i) {
		scanf("%d%d%d", &u, &l[i], &r[i]);
		q[u].push_back(i);
	}
	DFS(1);
	for (int i = 1; i <= Q; ++i) printf("%lld\n", Ans[i]);
	return 0;
}