#include <cstdio>
#include <algorithm>

#define max std::max
#define min std::min
const int MN = 200005;
const int MS = 1 << 19 | 7;

int N, Q;
char S[MN];
int A[MN];

struct dat {
	int maxv, minv, num1, num2, numf;
	dat() {}
	dat(int a, int b, int c, int d, int e)
		: maxv(a), minv(b), num1(c), num2(d), numf(e) {}
	inline friend dat operator + (dat a, dat b) {
		return dat(max(a.maxv, b.maxv), min(a.minv, b.minv),
			max(max(a.num1, b.num1), a.maxv - 2 * b.minv), max(max(a.num2, b.num2), b.maxv - 2 * a.minv),
			max(max(a.numf, b.numf), max(a.num1 + b.maxv, a.maxv + b.num2)));
	}
} seg[MS];

int l[MS], r[MS], tg[MS];
inline void P(int i, int x) {
	seg[i].maxv += x, seg[i].minv += x;
	seg[i].num1 -= x, seg[i].num2 -= x;
	tg[i] += x;
}
inline void pd(int i) { if (tg[i]) P(i << 1, tg[i]), P(i << 1 | 1, tg[i]), tg[i] = 0; }
void Build(int i) {
	if (l[i] == r[i]) { int p = l[i]; seg[i] = dat(A[p], A[p], -A[p], -A[p], 0); return ; }
	l[i << 1] = l[i], r[i << 1 | 1] = r[i];
	int mid = (l[i] + r[i]) >> 1;
	r[i << 1] = mid, l[i << 1 | 1] = mid + 1;
	Build(i << 1), Build(i << 1 | 1);
	seg[i] = seg[i << 1] + seg[i << 1 | 1];
}
void Mdf(int i, int a, int b, int x) {
	if (r[i] < a || b < l[i]) return ;
	if (a <= l[i] && r[i] <= b) return P(i, x);
	pd(i), Mdf(i << 1, a, b, x), Mdf(i << 1 | 1, a, b, x);
	seg[i] = seg[i << 1] + seg[i << 1 | 1];
}

int main() {
	scanf("%d%d", &N, &Q), N = N * 2 - 2;
	scanf("%s", S + 1);
	for (int i = 1; i <= N; ++i) A[i] = A[i - 1] + (S[i] == '(' ? 1 : -1);
	l[1] = 1, r[1] = N, Build(1);
	printf("%d\n", seg[1].numf);
	while (Q--) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (x > y) std::swap(x, y);
		if (S[x] != S[y])
			std::swap(S[x], S[y]),
			Mdf(1, x, y - 1, S[x] == '(' ? 2 : -2);
		printf("%d\n", seg[1].numf);
	}
	return 0;
}