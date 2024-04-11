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
#define MN 5005
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
int a[MN];
int f[MN];

void Solve() {
	scanf("%d", &n);
	F(i, 1, n) scanf("%d", a + i);
	a[0] = a[n + 1] = 0;
	f[0] = 0;
	F(i, 1, n + 1) {
		int val = -inf;
		static int buk[MN];
		F(j, 1, i - 1) buk[a[j]] = 0;
		int mx = 0;
		dF(j, i - 1, 0) {
			if (j + 1 < i) {
				++buk[a[j + 1]];
				mx = max(mx, buk[a[j + 1]]);
			}
			if (mx * 2 <= i - j - 1 && ((i ^ j) & 1) && (a[i] == a[j] || !a[i] || !a[j]))
				val = max(val, f[j] + 1);
		}
		f[i] = val;
	}
	printf("%d\n", f[n + 1] - 1);
}