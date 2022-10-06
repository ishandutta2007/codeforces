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

int n, m;

void Solve() {
	scanf("%d%d", &n, &m);
	vector<vector<int>> a(n + 2, vector<int>(m + 2, 0));
	F(i, 1, n) F(j, 1, m) scanf("%d", &a[i][j]);
//	F(i, 1, n) F(j, 1, m) printf("%d%c", a[i][j], " \n"[j == m]);
	vector<vector<pii>> b(100005);
	F(i, 1, n) F(j, 1, m) b[a[i][j]].push_back({i, j});
	ll ans = 0;
	F(c, 1, 100000) {
		auto &v = b[c];
		int l = (int)v.size();
		if (l <= 1) continue;
		sort(v.begin(), v.end(), [](pii x, pii y) {
			return x.fi < y.fi;
		});
		for (int i = 1; i < l; ++i)
			ans += (ll)(v[i].fi - v[i - 1].fi) * (i) * (l - i);
		sort(v.begin(), v.end(), [](pii x, pii y) {
			return x.se < y.se;
		});
		for (int i = 1; i < l; ++i)
			ans += (ll)(v[i].se - v[i - 1].se) * (i) * (l - i);
	}
	printf("%lld\n", ans);
}