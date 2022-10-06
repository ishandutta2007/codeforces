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
	scanf("%d", &n);
	F(i, 1, n) scanf("%d", a + i);
	F(i, 1, n - 1)
		b[i] = a[i] == a[i + 1];
	int p1 = 1;
	int p2 = n - 1;
	while (p1 <= n - 1 && !b[p1]) ++p1;
	while (p2 >= 1 && !b[p2]) --p2;
	printf("%d\n", p1 >= p2 ? 0 : max(p2 - p1 - 1, 1));
}