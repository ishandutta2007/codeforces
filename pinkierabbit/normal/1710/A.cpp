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
int a[MN], b[MN], f[MN], g[MN];
vector<int> G[MN];

void Solve() {
	scanf("%d%d%d", &n, &m, &k);
	F(i, 1, k) scanf("%d", a + i);
	F(i, 1, k)
		if (a[i] >= (ll)n * m)
			return puts("Yes"), void();
	ll sum1 = 0, f1 = 0;
	F(i, 1, k)
		if (a[i] / n >= 2) {
			sum1 += a[i] / n;
			if (a[i] / n >= 3)
				f1 = 1;
		}
	if (sum1 >= m && !(m % 2 == 1 && !f1))
		return puts("Yes"), void();
	ll sum2 = 0, f2 = 0;
	F(i, 1, k)
		if (a[i] / m >= 2) {
			sum2 += a[i] / m;
			if (a[i] / m >= 3)
				f2 = 1;
		}
	if (sum2 >= n && !(n % 2 == 1 && !f2))
		return puts("Yes"), void();
	puts("No");
}