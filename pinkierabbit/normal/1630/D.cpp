#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric>
using namespace std;

typedef pair<int, int> pii;
#define F(i, a, b) for(int i = a; i <= (b); ++i)
#define F2(i, a, b) for(int i = a; i < (b); ++i)
#define dF(i, a, b) for(int i = a; i >= (b); --i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n", __FUNCTION__, __LINE__)
#define MN 1000005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mkp make_pair
#define fi first
#define se second

int n, m;
ll a[MN];
int b[MN];
vector<ll> v[MN];

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
	scanf("%d%d", &n, &m);
	F(i, 1, n) scanf("%lld", a + i);
	int g = 0;
	F(i, 1, m) scanf("%d", b + i), g = gcd(g, b[i]);
	F2(j, 0, g) v[j].clear();
	F(i, 1, n) v[i % g].push_back(a[i]);
	ll ans1 = 0, ans2 = 0;
	F2(j, 0, g) {
		auto &w = v[j];
		ll s = 0, mn = infll;
		int c = 0;
		for (ll x : w)
			s += abs(x),
			mn = min(mn, abs(x)),
			c ^= x < 0;
		ans1 +=  c ? s : s - 2 * mn;
		ans2 += !c ? s : s - 2 * mn;
	}
	printf("%lld\n", max(ans1, ans2));
}