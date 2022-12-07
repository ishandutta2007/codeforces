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

int t, n, a[200005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		sort(a + 1, a + 1 + n);
		vector<ii> seg;
		int prv = -1;
		for (int i = 1; i <= n; i++) {
			if (prv == -1 || a[prv] != a[i]) {
				if (prv != -1) seg.eb(prv, i - 1);
				prv = i;
			}
		}
		seg.eb(prv, n);
		int tot = 0;
		for (auto i : seg) {
			tot += i.second - i.first + 1;
		}
		int ans = 0, curr = 0;
		for (auto i : seg) {
			curr += i.second - i.first + 1;
			ans = max(ans, curr * (tot - curr));
		}
		if (seg.size() == 1) ans = n / 2;
		cout << ans << '\n';
	}
}