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
#define MN 250005
#define MS (1 << 19 | 7)
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
int a[MN];

#define li (i << 1)
#define ri (li | 1)
#define mid ((l + r) >> 1)
#define ls tr, li, l, mid
#define rs tr, ri, mid + 1, r
int tr_[2][MS];
void Build(int *tr, int i, int l, int r) {
	tr[i] = inf;
	if (l == r) return ;
	Build(ls), Build(rs);
}
void Mdf(int *tr, int i, int l, int r, int p, int x) {
	if (l == r) return tr[i] = x, void();
	if (p <= mid) Mdf(ls, p, x);
	else Mdf(rs, p, x);
	tr[i] = min(tr[li], tr[ri]);
}
int Qur(int *tr, int i, int l, int r, int a) {
	if (r < a) return inf;
	if (a <= l) return tr[i];
	return min(Qur(ls, a), Qur(rs, a));
}

int f[MN];

void Solve() {
	scanf("%d", &n);
	F(i, 1, n) scanf("%d", a + i);
	Build(tr_[0], 1, 1, n);
	Build(tr_[1], 1, 1, n);
	{
		static int stk1[MN], stk2[MN];
		int tp1 = 1, tp2 = 1;
		stk1[1] = stk2[1] = 1;
		f[1] = 0;
		Mdf(tr_[0], 1, 1, n, 1, 0);
		Mdf(tr_[1], 1, 1, n, 1, 0);
		F(i, 2, n) {
			while (tp1 && a[stk1[tp1]] < a[i]) {
				Mdf(tr_[0], 1, 1, n, stk1[tp1], inf);
				--tp1;
			}
			while (tp2 && a[stk2[tp2]] > a[i]) {
				Mdf(tr_[1], 1, 1, n, stk2[tp2], inf);
				--tp2;
			}
			if (a[i - 1] > a[i])
				f[i] = Qur(tr_[0], 1, 1, n, tp2 ? stk2[tp2] + 1 : 1) + 1;
			else
				f[i] = Qur(tr_[1], 1, 1, n, tp1 ? stk1[tp1] + 1 : 1) + 1;
			stk1[++tp1] = i;
			stk2[++tp2] = i;
			Mdf(tr_[0], 1, 1, n, i, f[i]);
			Mdf(tr_[1], 1, 1, n, i, f[i]);
		}
	}
	printf("%d\n", f[n]);
}