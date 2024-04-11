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
int a[MN], b[MN];

void Solve() {
	scanf("%d%d", &n, &k);
	ll ans = 0;
	F(i, 1, n) scanf("%d", a + i), ans += a[i], a[i] = (n - i) - a[i];
	sort(a + 1, a + n + 1);
	ll mn = 0, s = 0;
	F(i, 1, k) {
		s += a[i];
		s -= i - 1;
		mn = min(mn, s);
	}
	printf("%lld\n", ans + mn);
}