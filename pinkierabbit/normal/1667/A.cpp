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

int n;
int a[MN];
ll b[MN];

void Solve() {
	scanf("%d", &n);
	F(i, 1, n) scanf("%d", &a[i]);
	ll ans = infll;
	F(i, 1, n) {
		ll sum = 0;
		b[i] = 0;
		F(j, i + 1, n) {
			sum += b[j - 1] / a[j] + 1;
			b[j] = (b[j - 1] / a[j] + 1) * a[j];
		}
		dF(j, i - 1, 1) {
			sum += b[j + 1] / a[j] + 1;
			b[j] = (b[j + 1] / a[j] + 1) * a[j];
		}
		ans = min(ans, sum);
	}
	printf("%lld\n", ans);
}