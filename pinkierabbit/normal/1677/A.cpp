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
#define MN 5005
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

int n;
int a[MN];
int s[MN][MN];

void Solve() {
	scanf("%d", &n);
	F(i, 1, n) scanf("%d", a + i);
	F(i, 0, n + 1) F(j, 0, n + 1) s[i][j] = 0;
	F(i, 1, n - 1) F(j, i + 1, n)
		if (a[i] < a[j])
			s[i][j] = 1;
	F(j, 1, n) F(i, 1, n)
		s[i][j] += s[i - 1][j];
	F(i, 1, n) dF(j, n, 1)
		s[i][j] += s[i][j + 1];
	ll ans = 0;
	F(i, 2, n - 2) F(j, i + 2, n)
		if (a[i] > a[j])
			ans += s[i - 1][i + 1] - s[i - 1][j];
	printf("%lld\n", ans);
}