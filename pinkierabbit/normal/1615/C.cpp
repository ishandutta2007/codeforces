#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

#define F(i, a, b) for(int i=a;i<=(b);++i)
#define F2(i, a, b) for(int i=a;i<(b);++i)
#define dF(i, a, b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
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
int a[MN], b[MN], c[MN];
vector<int> G[MN];

void Solve();

int main() {
	int tests = 1;
	scanf("%d", &tests);
	while(tests--) {
		Solve();
	}
	return 0;
}

void Solve() {
	int s1 = 0, s2 = 0;
	scanf("%d", &n);
	F(i, 1, n) scanf("%1d", a + i), s1 += a[i];
	F(i, 1, n) scanf("%1d", b + i), s2 += b[i];
	if (s1 != s2 && s1 != n + 1 - s2)
		return puts("-1"), void();
	int ans = 10 * n + 9;
	if (s1 == s2) {
		int num = 0;
		F(i, 1, n)
			if (a[i] != b[i])
				++num;
		ans = min(ans, num);
	}
	if (s1 == n + 1 - s2) {
		F(i, 1, n)
			c[i] = b[i] ^ 1;
		int num = 0;
		F(i, 1, n)
			if (a[i] != c[i])
				++num;
		ans = min(ans, num);
	}
	printf("%d\n", ans == 10 * n + 9 ? -1 : ans);
}

// c -> (n + 1) - c
// 2 opts : change i to j