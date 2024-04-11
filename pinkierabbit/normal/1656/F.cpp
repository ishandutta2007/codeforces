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
	scanf("%d", &tests);
	while (tests--)
		Solve();
	return 0;
}

int n;
ll a[MN];

void Solve() {
	scanf("%d", &n);
	F(i, 1, n) scanf("%lld", a + i);
	sort(a + 1, a + n + 1);
//	F(i, 1, n) printf("%lld%c", a[i], " \n"[i == n]);
	int p = 1;
	ll s = a[1] * (n - 1);
	F(i, 2, n) s += a[i];
	if (s > 0) return puts("INF"), void();
	F(i, 2, n - 1) {
		s -= a[1];
		s += a[n];
		if (s < 0)
			p = i;
	}
	if (s < 0) return puts("INF"), void();
	ll t = -a[p + 1];
//	printf("p = %d\nt = %lld\n", p, t);
	ll ans = 0;
	F(i, 1, p)
		ans += a[i] * a[n] + t * (a[i] + a[n]);
	F(i, p + 1, n - 1)
		ans += a[1] * a[i] + t * (a[1] + a[i]);
	printf("%lld\n", ans);
}