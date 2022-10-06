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

int n, m, q, k;
int a[MN], b[MN], f[MN], g[MN];
vector<int> G[MN];

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
	scanf("%d", &n);
	F(i, 1, n) scanf("%d", a + i);
	if (n == 1)
		return puts("0"), void();
	int ans = 0;
	F(i, 1, n) F(j, i + 1, n) {
		int len = j - i;
		// a[k] * len = (a[i] * (j - k) + a[j] * (k - i))
		int cnt = 0;
		F(k, 1, n)
			if (a[k] * len == a[i] * (j - k) + a[j] * (k - i))
				++cnt;
		ans = max(ans, cnt);
	}
	printf("%d\n", n - ans);
}