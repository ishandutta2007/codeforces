#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
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

int n, m;
ll X[MN], P[MN];
map<ll, ll> mp;

void Solve() {
	mp.clear();
	scanf("%d%d", &n, &m);
	F(i, 1, n) {
		scanf("%lld%lld", &X[i], &P[i]);
		mp[X[i] - P[i]] += 1;
		mp[X[i]] -= 2;
		mp[X[i] + P[i]] += 1;
	}
	ll ansx0 = 0, ansval = -infll;
	ll x0 = -infll, val = 0, k = 0;
	for (const auto &[x, d] : mp) {
		val += k * (x - x0);
		x0 = x;
		k += d;
//		printf("\t%lld, %lld\n", x0, val);
		if (val > m) {
			ll tx0 = 2 * x0;
			ll tval = 2 * (val - m);
			if (ansx0 < tx0)
				swap(ansx0, tx0),
				swap(ansval, tval);
			if (tval >= ansval + (ansx0 - tx0))
				ansx0 = tx0, ansval = tval;
			else if (ansval < tval + (ansx0 - tx0)) {
				ll aa = (ansx0 + ansval + tx0 - tval) / 2;
				ll bb = (ansx0 + ansval - tx0 + tval) / 2;
				ansx0 = aa;
				ansval = bb;
			}
		}
	}
//	printf("%lld, %lld\n", ansx0, ansval);
	F(i, 1, n)
		if (2 * P[i] >= ansval + abs(ansx0 - 2 * X[i]))
			printf("1");
		else
			printf("0");
	puts("");
}