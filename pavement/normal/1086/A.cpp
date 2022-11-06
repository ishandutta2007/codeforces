#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#ifdef _WIN32
#define getchar_unlocked _getchar_nolock
#endif
#define int long long
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define ppb pop_back
#define eb emplace_back
#define g0(a) get<0>(a)
#define g1(a) get<1>(a)
#define g2(a) get<2>(a)
#define g3(a) get<3>(a)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using db = double;
using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using iiii = tuple<int, int, int, int>;
template<class key, class value = null_type, class cmp = less<key> >
using ordered_set = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

int X[3], Y[3];
set<ii> ans;

int sumdist(int x, int y) {
	int ret = 0;
	for (int i = 0; i < 3; i++)
		ret += llabs(x - X[i]) + llabs(y - Y[i]);
	return ret;
}

vector<ii> getpath(int x1, int y1, int x2, int y2) {
	if (x1 > x2) return getpath(x2, y2, x1, y1);
	vector<ii> ret;
	for (int i = x1; i <= x2; i++) {
		ret.eb(i, y1);
	}
	if (y1 < y2) {
		for (int i = y1 + 1; i <= y2; i++)
			ret.eb(x2, i);
	} else {
		for (int i = y1 - 1; i >= y2; i--)
			ret.eb(x2, i);
	}
	return ret;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0; i < 3; i++) cin >> X[i] >> Y[i];
	iii mm = mt((int)1e18, -1ll, -1ll);
	for (int i = 0; i <= 1000; i++)
		for (int j = 0; j <= 1000; j++)
			mm = min(mm, mt(sumdist(i, j), i, j));
	for (int k = 0; k < 3; k++)
		for (auto [i, j] : getpath(g1(mm), g2(mm), X[k], Y[k]))
			ans.emplace(i, j);
	cout << ans.size() << '\n';
	for (auto [i, j] : ans) cout << i << ' ' << j << '\n';
}