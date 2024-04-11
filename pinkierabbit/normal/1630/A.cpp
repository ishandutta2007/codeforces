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

int n, k;

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
	scanf("%d%d", &n, &k);
	if (k == 0)
		F2(i, 0, n / 2)
			printf("%d %d\n", i, n - 1 - i);
	else if (k <= n - 2)
		F2(i, 0, n / 2) {
			int a = i, b = n - 1 - i;
			if (a == 0) a = k;
			else if (a == k) a = 0;
			if (b == 0) b = k;
			else if (b == k) b = 0;
			printf("%d %d\n", a, b);
		}
	else if (n == 4)
		puts("-1");
	else {
		puts("0 2");
		printf("%d %d\n", n - 1, n - 2);
		printf("%d 1\n", n - 3);
		F2(i, 3, n / 2)
			printf("%d %d\n", i, n - 1 - i);
	}
}