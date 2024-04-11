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
int a[MN], b[MN];

void Solve() {
	scanf("%d%d", &n, &q);
	F(i, 1, n) scanf("%d", a + i);
	F(i, 1, n) b[i] = 0;
	int t = 0;
	dF(i, n, 1) {
		if (a[i] > t)
			b[++t] = 1;
		else
			++b[a[i]];
	}
	F(i, 1, n) {
		if (q >= a[i])
			printf("1");
		else if (q >= t)
			printf("1"), --q;
		else
			printf("0");
		if (a[i] > t || b[a[i]] == 1) {
			--t;
		} else {
			--b[a[i]];
		}
	}
	puts("");
}