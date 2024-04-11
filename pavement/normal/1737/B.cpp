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

int T, L, R, ans;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		ans = 0;
		cin >> L >> R;
		{
			int lo = 1, hi = (int)1e9, h_1 = -1;
			while (lo <= hi) {
				int mid = (lo + hi) / 2;
				if (mid * mid <= R) h_1 = mid, lo = mid + 1;
				else hi = mid - 1;
			}
			lo = 1, hi = (int)1e9;
			int l_1 = -1;
			while (lo <= hi) {
				int mid = (lo + hi) / 2;
				if (mid * mid >= L) l_1 = mid, hi = mid - 1;
				else lo = mid + 1;
			}
			if (l_1 != -1 && h_1 != -1) ans += h_1 - l_1 + 1;
		}
		{
			int lo = 1, hi = (int)1e9, h_2 = -1;
			while (lo <= hi) {
				int mid = (lo + hi) / 2;
				if (mid * (mid + 1) <= R) h_2 = mid, lo = mid + 1;
				else hi = mid - 1;
			}
			lo = 1, hi = (int)1e9;
			int l_2 = -1;
			while (lo <= hi) {
				int mid = (lo + hi) / 2;
				if (mid * (mid + 1) >= L) l_2 = mid, hi = mid - 1;
				else lo = mid + 1;
			}
			if (l_2 != -1 && h_2 != -1) ans += h_2 - l_2 + 1;
		}
		{
			int lo = 1, hi = (int)1e9, h_3 = -1;
			while (lo <= hi) {
				int mid = (lo + hi) / 2;
				if (mid * (mid + 2) <= R) h_3 = mid, lo = mid + 1;
				else hi = mid - 1;
			}
			lo = 1, hi = (int)1e9;
			int l_3 = -1;
			while (lo <= hi) {
				int mid = (lo + hi) / 2;
				if (mid * (mid + 2) >= L) l_3 = mid, hi = mid - 1;
				else lo = mid + 1;
			}
			if (l_3 != -1 && h_3 != -1) ans += h_3 - l_3 + 1;
		}
		cout << ans << '\n';
	}
}