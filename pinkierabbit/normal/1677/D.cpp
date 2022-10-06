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
#define MN 1000005
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

int n, k;
int v[MN];

void Solve() {
	scanf("%d%d", &n, &k);
	F(i, 1, n) scanf("%d", v + i);
	bool flg = true;
	dF(i, n, n - k + 1) {
		if (v[i] == -1) v[i] = 0;
		if (v[i] != 0) flg = false;
	}
	if (!flg) return puts("0"), void();
	int ans = 1;
	F(i, 1, n - k) {
		if (v[i] == -1) ans = (ll)ans * (i + k) % mod;
		if (v[i] == 0) ans = (ll)ans * (k + 1) % mod;
	}
	F(i, 1, k) ans = (ll)ans * i % mod;
	printf("%d\n", ans);
}