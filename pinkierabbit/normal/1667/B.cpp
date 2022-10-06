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
#define MN 500005
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
int a[MN], b[MN];
ll s[MN];
ll d[MN]; int c;

int b1[MN], b2[MN], b3[MN];
void Mdf(int *b, int i, int x) {
	for (; i <= c; i += i & -i)
		b[i] = max(b[i], x);
}
int Qur(int *b, int i) {
	int r = -inf;
	for (; i; i -= i & -i)
		r = max(r, b[i]);
	return r;
}

void Solve() {
	scanf("%d", &n);
	s[0] = 0;
	F(i, 1, n) scanf("%d", a + i), s[i] = s[i - 1] + a[i];
	c = 0;
	d[0] = s[0];
	F(i, 1, n) d[++c] = s[i];
	sort(d, d + n + 1);
	c = unique(d, d + n + 1) - d;
	F(i, 0, n) b[i] = lower_bound(d, d + c, s[i]) - d + 1;
//	F(i, 0, n) printf("%lld%c", s[i], " \n"[i == n]);
//	F(i, 0, n) printf("%d%c", b[i], " \n"[i == n]);
	F(i, 1, c) b1[i] = b2[i] = b3[i] = -inf;
	Mdf(b1, b[0], 0 - 0);
	Mdf(b2, c - b[0] + 1, 0 + 0);
	b3[b[0]] = 0;
	F(i, 1, n) {
		int f = -inf;
		f = max(f, b3[b[i]]);
		f = max(f, Qur(b1, b[i] - 1) + i);
		f = max(f, Qur(b2, c - b[i]) - i);
		Mdf(b1, b[i], f - i);
		Mdf(b2, c - b[i] + 1, f + i);
		b3[b[i]] = max(b3[b[i]], f);
		if (i == n)
			printf("%d\n", f);
	}
}