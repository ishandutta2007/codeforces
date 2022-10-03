#include <cstdio>
#include <algorithm>

const int Inf = 0x3f3f3f3f;
const int MN = 100005, MS = 1 << 18 | 7;

inline void chmin(int &x, int y) { x = x < y ? x : y; }

int N, M, Q;
char str[2][MN];

int Coef;
struct SegmentTree {
	int mycoef;
#define F(i) for (int i = 0; i < 2; ++i)
	struct dat {
		int f[2][2][2];
		int c[2][2];
		dat() {}
		dat(int v0, int v1) {
			f[0][0][0] = v0 + v1, f[0][1][1] = !v0 + !v1;
			f[1][0][0] = v0 + !v1, f[1][1][1] = !v0 + v1;
			f[0][0][1] = f[0][1][0] = f[1][0][1] = f[1][1][0] = Inf;
			c[0][v0] = 1, c[0][!v0] = 0;
			c[1][v1] = 1, c[1][!v1] = 0;
		}
		friend dat operator + (dat a, dat b) {
			dat c;
			F(k) F(x) F(y) {
				c.f[k][x][y] = Inf;
				F(z) F(w) chmin(c.f[k][x][y], a.f[k][x][z] + b.f[k][w][y] + (z != w) * Coef);
			}
			F(k) F(x) c.c[k][x] = a.c[k][x] + b.c[k][x];
			return c;
		}
	} tr[MS];
	int tag[MS];
#define li (i << 1)
#define ri (li | 1)
#define mid ((l + r) >> 1)
#define ls li, l, mid
#define rs ri, mid + 1, r
	inline void P(int i, int rev) {
		tag[i] ^= rev;
		if (rev & 1) {
			std::swap(tr[i].c[0][0], tr[i].c[0][1]);
			std::swap(tr[i].c[1][0], tr[i].c[1][1]);
			F(k) F(y) std::swap(tr[i].f[k][0][y], tr[i].f[k][1][!y]);
			rev ^= 3;
		}
		if (rev & 2) {
			std::swap(tr[i].c[1][0], tr[i].c[1][1]);
			F(x) F(y) std::swap(tr[i].f[0][x][y], tr[i].f[1][x][y]);
		}
	}
	inline void Pushdown(int i) {
		if (tag[i]) P(li, tag[i]), P(ri, tag[i]), tag[i] = 0;
	}
	void Build(int i, int l, int r) {
		if (l == r) return tr[i] = dat(str[0][l] == 'R', str[1][l] == 'R'), void();
		Build(ls), Build(rs);
		Coef = mycoef, tr[i] = tr[li] + tr[ri];
	}
	void Mdf(int i, int l, int r, int a, int b, int x) {
		if (r < a || b < l) return ;
		if (a <= l && r <= b) return P(i, x), void();
		Pushdown(i), Mdf(ls, a, b, x), Mdf(rs, a, b, x);
		Coef = mycoef, tr[i] = tr[li] + tr[ri];
	}
} A, B;

inline int Ans() {
	int ret = Inf;
	F(x) F(y) chmin(ret, A.tr[1].f[0][x][y] + B.tr[1].c[0][!x] + B.tr[1].c[1][!y]);
	F(x) F(y) chmin(ret, B.tr[1].f[0][x][y] + A.tr[1].c[0][!x] + A.tr[1].c[1][!y]);
	return ret;
}

int main() {
	scanf("%d%d%d", &N, &M, &Q);
	scanf("%s%s", str[0] + 1, str[1] + 1), A.mycoef = M, A.Build(1, 1, N);
	scanf("%s%s", str[0] + 1, str[1] + 1), B.mycoef = N, B.Build(1, 1, M);
	printf("%d\n", Ans());
	while (Q--) {
		char s[3]; int l, r;
		scanf("%s%d%d", s, &l, &r);
		if (*s == 'L') A.Mdf(1, 1, N, l, r, 1);
		if (*s == 'R') A.Mdf(1, 1, N, l, r, 2);
		if (*s == 'U') B.Mdf(1, 1, M, l, r, 1);
		if (*s == 'D') B.Mdf(1, 1, M, l, r, 2);
		printf("%d\n", Ans());
	}
	return 0;
}