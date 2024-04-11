#include <cstdio>

const int MS = 1 << 19 | 7;

int N, Q, K;

#define li (i << 1)
#define ri (li | 1)
#define mid ((l + r) >> 1)
#define ls li, l, mid
#define rs ri, mid + 1, r
struct dat {
	int z[6], c[6];
	#define F(i) for (int i = 0; i < K; ++i)
	dat() { F(i) z[i] = c[i] = 0; }
	friend dat operator + (dat p, dat q) {
		F(j) {
			int ok = 0;
			F(i) if (p.z[i] == q.z[j]) { p.c[i] += q.c[j]; ok = 1; break; }
			if (ok) continue;
			p.c[K] = q.c[j];
			int o = K, mn;
			F(i) if (p.c[i] < p.c[o]) o = i;
			mn = p.c[o];
			F(i) p.c[i] -= mn;
			if (o < K) p.z[o] = q.z[j], p.c[o] = q.c[j] - mn;
		}
		return p;
	}
	void print() {
		int t = 0;
		F(i) if (z[i]) ++t;
		printf("%d", t);
		F(i) if (z[i]) printf(" %d", z[i]);
		puts("");
	}
} tr[MS];
int len[MS], tg[MS];
inline void P(int i, int x) { tr[i] = dat(), tr[i].z[0] = tg[i] = x, tr[i].c[0] = len[i]; }
inline void Pushdown(int i) { if (tg[i]) P(li, tg[i]), P(ri, tg[i]), tg[i] = 0; }
void Build(int i, int l, int r) {
	len[i] = r - l + 1;
	if (l == r) {
		scanf("%d", &tr[i].z[0]);
		tr[i].c[0] = 1;
		return ;
	}
	Build(ls), Build(rs);
	tr[i] = tr[li] + tr[ri];
}
void Mdf(int i, int l, int r, int a, int b, int x) {
	if (r < a || b < l) return ;
	if (a <= l && r <= b) return P(i, x);
	Pushdown(i);
	Mdf(ls, a, b, x), Mdf(rs, a, b, x);
	tr[i] = tr[li] + tr[ri];
}
dat Qur(int i, int l, int r, int a, int b) {
	if (r < a || b < l) return dat();
	if (a <= l && r <= b) return tr[i];
	Pushdown(i);
	return Qur(ls, a, b) + Qur(rs, a, b);
}

int main() {
	scanf("%d%d%d", &N, &Q, &K), K = 100 / K;
	Build(1, 1, N);
	while (Q--) {
		int op, l, r, x;
		scanf("%d%d%d", &op, &l, &r);
		if (op == 2) Qur(1, 1, N, l, r).print();
		else scanf("%d", &x), Mdf(1, 1, N, l, r, x);
	}
	return 0;
}