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

void Solve() {
	ll n;
	scanf("%lld", &n);
	if (n % 2 == 1 && n >= 3)
		return puts("2"), void();
	ll a = n & -n;
	if (a == n)
		return puts("-1"), void();
	if (a <= 1e9 && (2 * a) * (2 * a + 1) / 2 <= n)
		return printf("%lld\n", 2 * a), void();
	ll b = n / a;
	printf("%lld\n", b);
}