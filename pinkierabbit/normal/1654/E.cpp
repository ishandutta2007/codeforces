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
#define MN 100005
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
	while (tests--)
		Solve();
	return 0;
}

int n, a[MN];

void Solve() {
	scanf("%d", &n);
	F(i, 1, n) scanf("%d", a + i);
	if (n <= 2) return puts("0"), void();
	int ans = n - 2;
	F(d, -205, 205) {
		static ll b[MN];
		F(i, 1, n)
			b[i] = a[i] - (ll)d * i;
		sort(b + 1, b + n + 1);
		int mx = 0;
		for (int i = 1, c = 0; i <= n; ++i) {
			if (b[i] != b[i - 1])
				c = 0;
			mx = max(mx, ++c);
		}
		ans = min(ans, n - mx);
	}
	F(i, 1, n) {
		int lb = max(i - 505, 1);
		int rb = min(i + 505, n);
		static int b[MN];
		int C = 0;
		F(j, lb, rb) if (j != i && (a[j] - a[i]) % (j - i) == 0)
			b[++C] = (a[j] - a[i]) / (j - i);
		sort(b + 1, b + C + 1);
		int mx = 0;
		for (int j = 1, c = 0; j <= C; ++j) {
			if (b[j] != b[j - 1])
				c = 0;
			mx = max(mx, ++c);
		}
		ans = min(ans, n - mx - 1);
	}
	printf("%d\n", ans);
}