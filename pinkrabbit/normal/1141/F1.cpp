#include <cstdio>
#include <algorithm>

const int MN = 1505;
const int MS = 1125755;

int N, A[MN], C;
struct dat {
	int w, l, r;
	dat() {}
	dat(int w, int l, int r) : w(w), l(l), r(r) {}
} B[MS];

struct p{
	int l, r;
	p() {}
	p(int l, int r) : l(l), r(r) {}
};

int f[MN][MN]; p g[MN][MN];
p b[MN];
inline void Clr(int i) { for (; i <= N; i += i & -i) b[i] = p(0, 0); }
inline void Mdf(int i, p x) { for (; i <= N; i += i & -i) if (f[b[i].l][b[i].r] < f[x.l][x.r]) b[i] = x; }
inline p Qur(int i) { p a(0, 0); for (; i; i -= i & -i) if (f[a.l][a.r] < f[b[i].l][b[i].r]) a = b[i]; return a; }

int stk[MS], tp;
int Ans; p Ansi;

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) scanf("%d", &A[i]);
	for (int i = 1; i <= N; ++i) {
		int Sum = 0;
		for (int j = i; j <= N; ++j) {
			Sum += A[j];
			B[++C] = dat(Sum, i, j);
		}
	}
	std::sort(B + 1, B + C + 1, [](dat i, dat j) { return i.w == j.w ? i.r < j.r : i.w < j.w; });
	for (int i = 1; i <= C; ++i) {
		if (i == 1 || B[i].w != B[i - 1].w)
			while (tp) Clr(stk[tp--]);
		g[B[i].l][B[i].r] = Qur(B[i].l - 1);
		f[B[i].l][B[i].r] = f[g[B[i].l][B[i].r].l][g[B[i].l][B[i].r].r] + 1;
		Mdf(B[i].r, p(B[i].l, B[i].r));
		stk[++tp] = B[i].r;
		if (Ans < f[B[i].l][B[i].r])
			Ansi = p(B[i].l, B[i].r),
			Ans = f[B[i].l][B[i].r];
	}
	printf("%d\n", Ans);
	while (Ansi.l && Ansi.r) {
		printf("%d %d\n", Ansi.l, Ansi.r);
		Ansi = g[Ansi.l][Ansi.r];
	}
	return 0;
}