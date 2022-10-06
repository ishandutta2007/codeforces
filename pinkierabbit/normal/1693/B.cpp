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

int n, p[MN], l[MN], r[MN];
int f[MN], g[MN];
ll s[MN];

void Solve() {
	scanf("%d", &n);
	F(i, 2, n) scanf("%d", p + i);
	F(i, 1, n) scanf("%d%d", &l[i], &r[i]);
	F(i, 1, n) f[i] = 0, g[i] = 0, s[i] = 0;
	dF(i, n, 1) {
		if (s[i] < l[i])
			++f[i], g[i] = r[i];
		else
			g[i] = (int)min((ll)r[i], s[i]);
		f[p[i]] += f[i];
		s[p[i]] += g[i];
	}
	printf("%d\n", f[1]);
}