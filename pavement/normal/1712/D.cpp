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

int tc, n, k, ans, a[100005], d[100005];
ii t[100005];
multiset<int> tmp, diff;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> tc;
	while (tc--) {
		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			t[i] = mp(a[i], i);
			tmp.insert(a[i]);
		}
		for (int i = 2; i <= n; i++) {
			d[i] = min(a[i - 1], a[i]);
			diff.insert(d[i]);
		}
		sort(t + 1, t + 1 + n);
		for (int i = 1; i <= n; i++) {
			// change a[i]
			tmp.erase(tmp.find(a[i]));
			int sm = *tmp.begin();
			if (i > 1) {
				diff.erase(diff.find(d[i]));
				diff.insert(a[i - 1]);
			}
			if (i < n) {
				diff.erase(diff.find(d[i + 1]));
				diff.insert(a[i + 1]);
			}
			
			//~ cout << "@ " << i << ":\n";
			//~ for (int j : diff) cout << j << ' ';
			//~ cout << '\n';
			//~ for (int j : tmp) cout << j << ' ';
			//~ cout << '\n';
			
			int max_diff = *diff.rbegin();
			if (i > 1) {
				diff.insert(d[i]);
				diff.erase(diff.find(a[i - 1]));
			}
			if (i < n) {
				diff.insert(d[i + 1]);
				diff.erase(diff.find(a[i + 1]));
			}
			tmp.insert(a[i]);
			//~ cout << "# " << sm << ' ' << max_diff << '\n';
			ans = max(ans, min(2 * sm, max_diff));
		}
		for (int i = 1; i <= k; i++) {
			// change t[i].second
			a[t[i].second] = (int)1e9;
			if (t[i].second > 1) {
				diff.erase(diff.find(d[t[i].second]));
				d[t[i].second] = a[t[i].second - 1];
				diff.insert(d[t[i].second]);
			}
			if (t[i].second < n) {
				diff.erase(diff.find(d[t[i].second + 1]));
				d[t[i].second + 1] = a[t[i].second + 1];
				diff.insert(d[t[i].second + 1]);
			}
			int sm = (i == n ? (int)1e9 : t[i + 1].first);
			int max_diff = (i < k ? (int)1e9 : *diff.rbegin());
			ans = max(ans, min(2 * sm, max_diff));
		}
		cout << ans << '\n';
		
		ans = 0;
		for (int i = 1; i <= n; i++) {
			a[i] = d[i] = 0;
			t[i] = mp(0, 0);
		}
		tmp.clear();
		diff.clear();
	}
}