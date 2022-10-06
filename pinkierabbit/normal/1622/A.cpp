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
	F(i, 1, 3) scanf("%d", a + i);
	sort(a + 1, a + 3 + 1);
	if (a[3] == a[1] + a[2]) {
		puts("YES");
	} else if (a[1] == a[2]) {
		if (a[3] % 2 == 0)
			puts("YES");
		else
			puts("NO");
	} else if (a[2] == a[3]) {
		if (a[1] % 2 == 0)
			puts("YES");
		else
			puts("NO");
	} else {
		puts("NO");
	}
}