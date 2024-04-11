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

int n, a[MN];

void Solve() {
	scanf("%d", &n);
	F(i, 1, n) scanf("%d", a + i);
	sort(a + 1, a + n + 1);
	ll s = 0;
	F(i, 1, n)
		s += a[i];
	ll a1 = s, a2 = s + 1;
	ll c1 = 1, c2 = 0;
	int j = n;
	while (j >= 1) {
		if (a1 > a[j]) {
			if (a1 & 1)
				a1 /= 2, a2 = a1 + 1,
				c2 = c2 * 2 + c1;
			else
				a1 /= 2, a2 = a1 + 1,
				c1 = c1 * 2 + c2;
		} else if (a1 + 1 < a[j]) {
			return puts("No"), void();
		} else {
			if (a[j] == a1) {
				if (c1)
					--c1, --j;
				else {
					if (a1 & 1)
						a1 /= 2, a2 = a1 + 1,
						c2 = c2 * 2 + c1;
					else
						a1 /= 2, a2 = a1 + 1,
						c1 = c1 * 2 + c2;
				}
			} else {
				if (c2)
					--c2, --j;
				else {
					if (a1 & 1)
						a1 /= 2, a2 = a1 + 1,
						c2 = c2 * 2 + c1;
					else
						a1 /= 2, a2 = a1 + 1,
						c1 = c1 * 2 + c2;
				}
			}
		}
	}
//	printf("a : ");
//	F(i, 1, j)
//		printf("%d%c", a[i], " \n"[i == j]);
//	printf("(a1, a2) (c1, c2) = (%lld, %lld) (%lld, %lld)\n", a1, a2, c1, c2);
	puts("YES");
}