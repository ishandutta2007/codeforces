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

int n, k, l;
int a[MN], b[MN];

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
	scanf("%d%d", &n, &k), l = (n + k + 1) / 2;
	F(i, 1, n) scanf("%d", a + i), b[i] = a[i];
	sort(b + 1, b + n + 1);
	int ans = inf, x = 0, y = 0;
	F(i, l, n) {
		int dif = b[i] - b[i - l + 1];
		if (dif < ans)
			ans = dif,
			x = b[i - l + 1],
			y = b[i];
	}
	printf("%d %d\n", x, y);
	int s = 0, lb = 1, c = k;
	F(i, 1, n) {
		s += x <= a[i] && a[i] <= y ? 1 : -1;
		if (s >= 1 && c >= 2)
			printf("%d %d\n", lb, i),
			lb = i + 1, --c,
			s = 0;
	}
	printf("%d %d\n", lb, n);
}