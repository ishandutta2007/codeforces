#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
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

int n, m;
int a[MN];
vector<int> v[MN];

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
	scanf("%d%d", &n, &m);
	F(i, 1, n) scanf("%d", a + i);
	F(i, 1, n) v[i].clear();
	std::sort(a + 1, a + n + 1);
	std::map<int, int> b;
	F(i, 1, n) ++b[a[i]];
	for (auto [c, x] : b)
		v[x].push_back(c);
	vector<int> vv;
	F(i, 1, n) if (!v[i].empty()) {
		std::reverse(v[i].begin(), v[i].end());
		vv.push_back(i);
	}
	std::set<std::pair<int, int>> f;
	F(i, 1, m) {
		int x, y;
		scanf("%d%d", &x, &y);
		f.insert({x, y});
	}
	ll ans = 0;
	for (int i : vv)
		for (int j : vv) if (i <= j) {
			for (int x : v[i]) {
				for (int y : v[j]) if (x != y) {
					if (f.find({x, y}) == f.end() && f.find({y, x}) == f.end()) {
						ans = std::max(ans, (ll)(i + j) * (x + y));
						break;
					}
				}
			}
		}
	printf("%lld\n", ans);
}