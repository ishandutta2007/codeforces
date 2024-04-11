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
typedef double db;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int T, W, H, x_1, y_1, x_2, y_2, w, h;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> W >> H >> x_1 >> y_1 >> x_2 >> y_2 >> w >> h;
		int x = LLONG_MAX;
		if (w + (x_2 - x_1) <= W) x = min({x, max(0ll, w - x_1), max(0ll, x_2 - (W - w))});
		if (h + (y_2 - y_1) <= H) x = min({x, max(0ll, h - y_1), max(0ll, y_2 - (H - h))});
		cout << (x == LLONG_MAX ? -1 : x) << '\n';
	}
}