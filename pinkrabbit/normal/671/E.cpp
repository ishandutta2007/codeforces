#include <cstdio>
#include <algorithm>
#include <vector>

typedef long long LL;
const LL Infll = 0x3f3f3f3f3f3f3f3f;
const int MN = 100005, MS = 1 << 18 | 7;

LL K, W[MN], G[MN], pre[MN], suf[MN];
int N, nxt[MN], Ans;
std::vector<int> T[MN];

#define li (i << 1)
#define ri (li | 1)
#define mid ((l + r) >> 1)
#define ls li, l, mid
#define rs ri, mid + 1, r
LL amn[MS], bmn[MS], ans[MS], tg[MS];
inline void P(int i, LL x) { bmn[i] += x, ans[i] -= x, tg[i] += x; }
inline void Pushdown(int i) { if (tg[i]) P(li, tg[i]), P(ri, tg[i]), tg[i] = 0; }
LL Calc(int i, int l, int r, LL p) {
	if (l == r) return amn[i] - p;
	Pushdown(i);
	if (bmn[li] < p) return std::min(Calc(ls, p), ans[i]);
	else return std::min(amn[li] - p, Calc(rs, p));
}
void Build(int i, int l, int r) {
	if (l == r) { amn[i] = bmn[i] = suf[l]; return ; }
	Build(ls), Build(rs);
	amn[i] = std::min(amn[li], amn[ri]);
	bmn[i] = std::min(bmn[li], bmn[ri]);
	ans[i] = Calc(rs, bmn[li]);
}
void Mdf(int i, int l, int r, int a, int b, LL x) {
	if (r < a || b < l) return ;
	if (a <= l && r <= b) return P(i, x);
	Pushdown(i), Mdf(ls, a, b, x), Mdf(rs, a, b, x);
	bmn[i] = std::min(bmn[li], bmn[ri]);
	ans[i] = Calc(rs, bmn[li]);
}
int Solve2(int i, int l, int r, LL v) {
	if (l == r) return l;
	return amn[ri] <= v ? Solve2(rs, v) : Solve2(ls, v);
}
int Solve(int i, int l, int r, LL &p) {
	if (l == r) {
		int ret = amn[i] - p <= K ? l : 0;
		p = std::min(p, bmn[i]);
		return ret;
	}
	Pushdown(i);
	if (bmn[li] < p) {
		if (ans[i] <= K) return Solve(rs, p = bmn[li]);
		else {
			int ret = Solve(ls, p);
			p = std::min(p, bmn[i]);
			return ret;
		}
	} else {
		int ret = amn[li] <= K + p ? Solve2(ls, K + p) : 0;
		return std::max(ret, Solve(rs, p));
	}
}
#undef li
#undef ri
#undef mid
#undef ls
#undef rs

inline void DFS(int u) {
	static int stk[MN], tp;
	stk[++tp] = u;
	if (nxt[u] <= N) Mdf(1, 1, N, nxt[u] - 1, N, pre[u] - pre[nxt[u]]);
	if (u <= N) {
		int lb = 2, rb = tp - 1, mid, ret = 1;
		while (lb <= rb) {
			mid = (lb + rb) >> 1;
			if (pre[stk[mid]] - pre[u] > K) ret = mid, lb = mid + 1;
			else rb = mid - 1;
		}
		int rmax = stk[ret] - 1; LL _ = Infll;
		if (u > 1) Mdf(1, 1, N, 1, u - 1, Infll);
		Mdf(1, 1, N, rmax, N, -Infll);
		int pos = Solve(1, 1, N, _);
		Mdf(1, 1, N, rmax, N, Infll);
		if (u > 1) Mdf(1, 1, N, 1, u - 1, -Infll);
		Ans = std::max(Ans, pos - u + 1);
	}
	for (auto v : T[u]) DFS(v);
	if (nxt[u] <= N) Mdf(1, 1, N, nxt[u] - 1, N, pre[nxt[u]] - pre[u]);
	--tp;
}

inline void Init() {
	static int stk[MN], tp;
	scanf("%d%lld", &N, &K), Ans = 1;
	for (int i = 1; i < N; ++i) scanf("%lld", &W[i]);
	for (int i = 1; i <= N; ++i) scanf("%lld", &G[i]);
	for (int i = 2; i <= N; ++i)
		pre[i] = pre[i - 1] - G[i - 1] + W[i - 1],
		suf[i] = suf[i - 1] - G[i] + W[i - 1];
	pre[N + 1] = Infll, nxt[N + 1] = stk[tp = 1] = N + 1;
	for (int i = N; i >= 1; --i) {
		while (pre[stk[tp]] <= pre[i]) --tp;
		nxt[i] = stk[tp], stk[++tp] = i;
		T[nxt[i]].push_back(i);
	}
}

int main() {
	Init();
	Build(1, 1, N);
	DFS(N + 1);
	printf("%d\n", Ans);
	return 0;
}