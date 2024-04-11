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
#define MN 300005
#define MM 600005
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
//	scanf("%d", &tests);
	while (tests--)
		Solve();
	return 0;
}

int n, q, d;
int buk[MN], b[MN];
void Add(int i, int x) {
	for (; i <= n; i += i & -i)
		b[i] += x;
}
int Qur(int i) {
	int s = 0;
	for (; i; i -= i & -i)
		s += b[i];
	return s;
}

const int MS = 1 << 19 | 7;
#define li (i << 1)
#define ri (li | 1)
#define mid ((l + r) >> 1)
#define ls li, l, mid
#define rs ri, mid + 1, r
int cnt[MS], tag[MS];
ll sum[MS];
void P(int i, int x) { sum[i] += (ll)x * cnt[i], tag[i] += x; };
void Pushdown(int i) { if (tag[i]) P(li, tag[i]), P(ri, tag[i]), tag[i] = 0; }
void Mdf1(int i, int l, int r, int p, int x) {
	if (l == r) {
		if (cnt[i])
			cnt[i] = 0,
			sum[i] = 0;
		else
			cnt[i] = 1,
			sum[i] = x;
		return ;
	}
	Pushdown(i);
	if (p <= mid)
		Mdf1(ls, p, x);
	else
		Mdf1(rs, p, x);
	cnt[i] = cnt[li] + cnt[ri];
	sum[i] = sum[li] + sum[ri];
}
void Mdf2(int i, int l, int r, int a, int b, int x) {
	if (r < a || b < l) return ;
	if (a <= l && r <= b) return P(i, x);
	Pushdown(i);
	Mdf2(ls, a, b, x);
	Mdf2(rs, a, b, x);
	sum[i] = sum[li] + sum[ri];
}
ll Qur(int i, int l, int r, int a, int b) {
	if (r < a || b < l) return 0ll;
	if (a <= l && r <= b) return sum[i];
	Pushdown(i);
	return Qur(ls, a, b) + Qur(rs, a, b);
}

ll calc(int x) {
	int numl = Qur(x - 1) - Qur(max(x - d - 1, 0));
	int numr = Qur(min(x + d, n)) - Qur(x);
	ll ret = ((ll)numl * (numl - 1) + (ll)numr * (numr - 1)) / 2;
	ret += Qur(1, 1, n, x - d, x - 1) - (ll)numl * (numl - 1) / 2;
	return ret;
}

void Solve() {
	n = 200000;
	scanf("%d%d", &q, &d);
	ll ans = 0;
	F(i, 1, q) {
		int x;
		scanf("%d", &x);
		if (!buk[x]) {
			ans += calc(x);
			Add(x, 1);
			Mdf2(1, 1, n, x - d, x - 1, 1);
			Mdf1(1, 1, n, x, Qur(min(x + d, n)) - Qur(x));
			buk[x] = 1;
		} else {
			buk[x] = 0;
			Mdf1(1, 1, n, x, 0);
			Mdf2(1, 1, n, x - d, x - 1, -1);
			Add(x, -1);
			ans -= calc(x);
		}
		printf("%lld\n", ans);
	}
}