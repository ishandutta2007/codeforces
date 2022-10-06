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

int n, k;
int a[MN];

void Solve() {
	scanf("%d%d", &n, &k);
	F(i, 1, n) scanf("%d", a + i);
	if (n == 1) {
		printf("%d\n", a[1] + k - 1);
		return ;
	}
	ll ans = 0;
	if (k <= n) {
		static ll b[MN];
		F(i, 1, n) b[i] = b[i - 1] + a[i];
		F(i, k, n) ans = max(ans, b[i] - b[i - k]);
		ans += (ll)k * (k - 1) / 2;
		printf("%lld\n", ans);
		return ;
	}
	F(i, 1, n) ans += a[i];
	ans += (ll)(2 * k - n - 1) * n / 2;
	printf("%lld\n", ans);
}