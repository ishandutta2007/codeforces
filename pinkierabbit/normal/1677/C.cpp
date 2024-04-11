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

int n;
int a[MN], b[MN];
int p[MN], v[MN];

void Solve() {
	scanf("%d", &n);
	F(i, 1, n) scanf("%d", a + i);
	F(i, 1, n) scanf("%d", b + i);
	F(i, 1, n) p[a[i]] = b[i], v[i] = 0;
	int cnt = 0;
	F(i, 1, n) if (!v[i]) {
		v[i] = 1;
		int t = 1;
		for (int x = p[i]; x != i; x = p[x])
			v[x] = 1,
			++t;
		cnt += t / 2;
	}
	printf("%lld\n", 2ll * cnt * (n - cnt));
}