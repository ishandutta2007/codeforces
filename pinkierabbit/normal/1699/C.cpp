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
#define mod 1000000007
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
int a[MN], ia[MN], b[MN], f[MN], g[MN];
vector<int> G[MN];

void Solve() {
	scanf("%d", &n);
	F(i, 1, n) scanf("%d", a + i), ia[a[i]] = i;
	int ans = 1;
	int lb = ia[0], rb = ia[0];
	F(i, 1, n - 1) {
		int p = ia[i];
		if (lb <= p && p <= rb) {
			ans = (ll)ans * (rb - lb + 1 - i) % mod;
		} else {
			lb = min(lb, p);
			rb = max(rb, p);
		}
	}
	printf("%d\n", ans);
}