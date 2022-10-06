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

int n, m, q, k;
ll a[MN];
vector<int> G[MN];

void Solve() {
	scanf("%d", &n);
	ll s = 0;
	F(i, 1, n) scanf("%lld", a + i), s += a[i];
	if (s) return puts("No"), void();
	while (n >= 1 && !a[n]) --n;
	if (!n) return puts("Yes"), void();
	if (a[1] <= 0 || a[n] > 0) return puts("No"), void();
	while (n >= 2) {
		if (a[n] >= 0) return puts("No"), void();
		a[n - 1] += a[n];
		--n;
	}
	puts("Yes");
}