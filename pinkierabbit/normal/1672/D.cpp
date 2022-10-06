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
int a[MN], b[MN], c[MN], x[MN], d[MN];

void Solve() {
	scanf("%d", &n);
	F(i, 1, n) d[i] = n + 1;
	F(i, 1, n) scanf("%d", a + i), c[i] = 1;
	dF(i, n, 1) x[i] = d[a[i]], d[a[i]] = i;
	F(i, 1, n) scanf("%d", b + i);
	int j = 1;
	F(i, 1, n) {
		while (a[j] != b[i]) {
			if (x[j] > n)
				return puts("NO"), void();
			c[x[j]] += c[j];
			c[j] = 0;
			++j;
			if (j > n)
				return puts("NO"), void();
		}
		--c[j];
		if (!c[j])
			++j;
	}
	puts("YES");
}