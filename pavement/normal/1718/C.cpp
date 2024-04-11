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

int t, n, q, ans, a[200005], f[134][200005];
multiset<int> ss[134];
bitset<200005> ip;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	ip.set();
	ip[0] = ip[1] = 0;
	for (int i = 2; i <= 2e5; i++) {
		if (!ip[i]) continue;
		for (int j = i + i; j <= 2e5; j += i) ip[j] = 0;
	}
	cin >> t;
	while (t--) {
		cin >> n >> q;
		vector<int> fac;
		for (int i = 1; i <= n; i++)
			if (n % i == 0 && ip[i]) fac.pb(n / i);
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < fac.size(); j++)
				f[j][i % fac[j]] += a[i];
		for (int i = 0; i < fac.size(); i++)
			for (int j = 0; j < fac[i]; j++) {
				ss[i].insert(f[i][j]);
				ans = max(ans, f[i][j] * fac[i]);
			}
		cout << ans << '\n';
		for (int p, x; q--; ) {
			cin >> p >> x;
			p--;
			x -= a[p];
			ans = 0;
			for (int i = 0; i < fac.size(); i++) {
				int j = fac[i];
				ss[i].erase(ss[i].find(f[i][p % j]));
				f[i][p % j] += x;
				ss[i].insert(f[i][p % j]);
				ans = max(ans, j * *ss[i].rbegin());
			}
			cout << ans << '\n';
			a[p] += x;
		}
		ans = 0;
		for (int i = 0; i < fac.size(); i++) {
			ss[i].clear();
			for (int j = 0; j < n; j++) f[i][j] = 0;
		}
	}
}