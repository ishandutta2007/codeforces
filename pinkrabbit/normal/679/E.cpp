#include <cstdio>
#include <algorithm>

typedef long long LL;
const LL Infll = 0x3f3f3f3f3f3f3f3f;
const int MN = 100005, MS = 1 << 18 | 7;

LL Z[10];
void Init() { Z[0] = 1; for (int i = 1; i <= 9; ++i) Z[i] = Z[i - 1] * 42; }
inline int gv(LL x) { return std::lower_bound(Z, Z + 10, x) - Z; }

int N, Q, A[MN];

#define li (i << 1)
#define ri (li | 1)
#define mid ((l + r) >> 1)
#define ls li, l, mid
#define rs ri, mid + 1, r
LL t1[MS], t3[MS], mn[MS]; int t2[MS];
inline void P1(int i, LL df, int vl) {
	mn[i] = t1[i] = df, t2[i] = vl, t3[i] = 0;
}
inline void P2(int i, LL tg) {
	if (t2[i]) {
		t1[i] -= tg;
		while (t1[i] < 0) t1[i] += Z[t2[i] + 1] - Z[t2[i]], ++t2[i];
		mn[i] = t1[i];
	} else mn[i] -= tg, t3[i] += tg;
}
inline void Pushdown(int i) {
	if (t1[i]) P1(li, t1[i], t2[i]), P1(ri, t1[i], t2[i]), t1[i] = t2[i] = 0;
	if (t3[i]) P2(li, t3[i]), P2(ri, t3[i]), t3[i] = 0;
}
void Mdf(int i, int l, int r, int a, int b, LL df, int vl) {
	if (r < a || b < l) return ;
	if (a <= l && r <= b) return P1(i, df, vl);
	Pushdown(i), Mdf(ls, a, b, df, vl), Mdf(rs, a, b, df, vl);
	mn[i] = std::min(mn[li], mn[ri]);
}
LL Add(int i, int l, int r, int a, int b, LL x) {
	if (r < a || b < l) return Infll;
	if (a <= l && r <= b && (mn[i] >= x || t2[i])) return P2(i, x), mn[i];
	Pushdown(i), Add(ls, a, b, x), Add(rs, a, b, x);
	return mn[i] = std::min(mn[li], mn[ri]);
}
LL Get(int i, int l, int r, int p) {
	if (l == r) return Z[t2[i]] - t1[i];
	Pushdown(i);
	return p <= mid ? Get(ls, p) : Get(rs, p);
}

int main() {
	Init();
	scanf("%d%d", &N, &Q);
	for (int i = 1, x; i <= N; ++i) {
		scanf("%d", &x);
		Mdf(1, 1, N, i, i, Z[gv(x)] - x, gv(x));
	}
	while (Q--) {
		int o, l, r, x;
		scanf("%d%d", &o, &l);
		if (o == 1) printf("%lld\n", Get(1, 1, N, l));
		else if (o == 2) {
			scanf("%d%d", &r, &x);
			Mdf(1, 1, N, l, r, Z[gv(x)] - x, gv(x));
		} else {
			scanf("%d%d", &r, &x);
			while (!Add(1, 1, N, l, r, x)) ;
		}
	}
	return 0;
}