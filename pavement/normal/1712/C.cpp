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
#define g4(a) get<4>(a)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using db = double;
using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using iiii = tuple<int, int, int, int>;
template<class key, class value = null_type, class cmp = less<key> >
using ordered_set = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

int t, n, ans, ops, a[100005], lst[100005];
bool is_dec[100005];
set<int> bad;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		ans = LLONG_MAX;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			lst[a[i]] = i;
		}
		is_dec[n + 1] = is_dec[n] = 1;
		for (int i = n - 1; i >= 1; i--) {
			if (a[i] <= a[i + 1]) is_dec[i] = is_dec[i + 1];
			else is_dec[i] = 0;
		}
		if (is_dec[1]) ans = 0;
		for (int i = 1; i <= n; i++) {
			bad.insert(a[i]);
			if (lst[a[i]] == i) {
				bad.erase(bad.find(a[i]));
				ops++;
			}
			if (bad.empty() && is_dec[i + 1]) ans = min(ans, ops);
		}
		cout << ans << '\n';
		bad.clear();
		for (int i = 1; i <= n + 1; i++)
			lst[i] = is_dec[i] = a[i] = 0;
		ans = LLONG_MAX;
		ops = 0;
	}
}