#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long
typedef pair<ll, ll> pllll;
#define F(i, a, b) for(int i = a; i <= (b); ++i)
#define F2(i, a, b) for(int i = a; i < (b); ++i)
#define dF(i, a, b) for(int i = a; i >= (b); --i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n", __FUNCTION__, __LINE__)
#define MN 300005
#define MM 600005
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

void f(ll *a, int n, ll m, vector<pllll> &v) {
	v.clear();
	F(i, 1, n) {
		ll x = a[i];
		ll c = 1;
		while (x % m == 0)
			x /= m,
			c *= m;
		if (!v.empty() && v.back().fi == x)
			v.back().se += c;
		else
			v.push_back({x, c});
	}
}

int n, k;
ll m, a[MN], b[MN];

void Solve() {
	scanf("%d%lld", &n, &m);
	F(i, 1, n) scanf("%lld", a + i);
	scanf("%d", &k);
	F(i, 1, k) scanf("%lld", b + i);
	vector<pllll> A, B;
	f(a, n, m, A);
	f(b, k, m, B);
	puts(A == B ? "Yes" : "No");
}