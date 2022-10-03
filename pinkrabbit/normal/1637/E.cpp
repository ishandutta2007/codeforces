#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

#define F(i, a, b) for(int i = a; i <= (b); ++i)

void Solve();

int main() {
	int tests = 1;
	scanf("%d", &tests);
	while (tests--)
		Solve();
	return 0;
}

typedef long long ll;
const int MN = 300005;

int n, m;
int a[MN];
std::vector<int> v[MN];

void Solve() {
	scanf("%d%d", &n, &m);
	F(i, 1, n) scanf("%d", a + i);
	std::map<int, int> b;
	F(i, 1, n) ++b[a[i]];
	F(i, 1, n) v[i].clear();
	for (auto [c, x] : b)
		v[x].push_back(c);
	std::vector<int> vv;
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
		for (int j : vv) if (j >= i)
			for (int x : v[i]) {
				bool ok = false;
				for (int y : v[j]) if (x != y)
					if (f.find({x, y}) == f.end() && f.find({y, x}) == f.end()) {
						ans = std::max(ans, (ll)(i + j) * (x + y));
						if (y == v[j][0]) ok = true;
						break;
					}
				if (ok) break;
			}
	printf("%lld\n", ans);
}