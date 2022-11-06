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
#define pf push_front
#define ppb pop_back
#define ppf pop_front
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

int T, X, Y;
string S;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> X >> Y >> S;
		int x = 0, y = 0, u = 0, d = 0, r = 0, l = 0;
		for (char c : S) {
			if (c == 'U') u++, y++;
			else if (c == 'D') d++, y--;
			else if (c == 'R') r++, x++;
			else l++, x--;
		}
		bool cannot = 0;
		if (X - x < 0 && x - X > r) {
			cannot = 1;
		}
		if (X - x > 0 && X - x > l) {
			cannot = 1;
		}
		if (Y - y < 0 && y - Y > u) {
			cannot = 1;
		}
		if (Y - y > 0 && Y - y > d) {
			cannot = 1;
		}
		cout << (cannot ? "NO" : "YES") << '\n';
	}
}