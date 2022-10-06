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
	int n, x;
	static int a[MN];
	static ll s[MN];
	scanf("%d", &n);
	F(i, 1, n) scanf("%d", a + i);
	scanf("%d", &x);
	F(i, 1, n) a[i] -= x;
	F(i, 1, n) s[i] = s[i - 1] + a[i];
	int cnt = 0;
	ll mx = LLONG_MIN;
	F(i, 1, n) {
		if (s[i] >= mx)
			++cnt, mx = max(mx, s[i - 1]);
		else
			mx = LLONG_MIN;
	}
	printf("%d\n", cnt);
}