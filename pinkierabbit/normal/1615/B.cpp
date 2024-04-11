#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

#define F(i, a, b) for(int i=a;i<=(b);++i)
#define F2(i, a, b) for(int i=a;i<(b);++i)
#define dF(i, a, b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
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
	while(tests--) {
		Solve();
	}
	return 0;
}

void Solve() {
	int l, r;
	scanf("%d%d", &l, &r);
	--l;
	int ans = r - l;
	for (int j = 0; j <= 25; ++j) {
		int num = 0;
		num += (r >> (j + 1) << j) + (r >> j & 1 ? 1 + (r ^ (r >> j << j)) : 0);
		num -= (l >> (j + 1) << j) + (l >> j & 1 ? 1 + (l ^ (l >> j << j)) : 0);
		num = r - l - num;
		ans = min(ans, num);
	}
	printf("%d\n", ans);
}