#include <cstdio>
#include <algorithm>
#include <vector>
#include <climits>
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

int n;
ll a[MN], k;

void Solve();

int main() {
	int tests = 1;
	scanf("%d", &tests);
	while (tests--) {
		Solve();
	}
	return 0;
}

void Solve() {
	scanf("%d%lld", &n, &k), k = -k;
	F2(i, 0, n) scanf("%lld", a + i), k += a[i];
	if (k <= 0)
		return puts("0"), void();
	sort(a, a + n);
	reverse(a + 1, a + n);
	F2(i, 1, n) a[i] -= a[0];
	a[0] = 0;
//	F2(i, 0, n) printf("%lld%s", a[i], i < n - 1 ? ", " : "\n");
//	printf("k = %lld\n", k);
	ll ans = LLONG_MAX, s = 0;
	F2(i, 0, n) {
		s += a[i];
		ans = min(ans, i + max(k - s + i, 0ll) / (i + 1));
	}
	printf("%lld\n", ans);
}