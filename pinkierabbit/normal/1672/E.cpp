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
//	scanf("%d", &tests);
	while (tests--)
		Solve();
	return 0;
}

void Solve() {
	int n;
	scanf("%d", &n);
	int lb = 2 * n - 1, rb = 2001 * n - 1, ans = -1;
	while (lb <= rb) {
		int mid = (lb + rb) / 2;
		printf("? %d\n", mid), fflush(stdout);
		int k;
		scanf("%d", &k);
		if (k == 1) ans = mid, rb = mid - 1;
		else lb = mid + 1;
	}
	int tans = ans;
	for (int i = 2; i <= n; ++i) {
		int p = (ans - 1) / i;
		printf("? %d\n", p), fflush(stdout);
		int k;
		scanf("%d", &k);
		if (k)
			tans = min(tans, p * k);
	}
	printf("! %d\n", tans), fflush(stdout);
}