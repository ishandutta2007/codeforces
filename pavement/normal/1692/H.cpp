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

int T, N, X[200005];
map<int, vector<int> > vec;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		vec.clear();
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> X[i];
			vec[X[i]].pb(i);
		}
		iii tot = mt(-1e16, -1ll, -1ll);
		for (auto i : vec) {
			ii sf = mp((int)-1e16, -1ll);
			for (int j = 0; j < i.second.size(); j++) {
				sf = max(sf, mp(-2 * j + i.second[j], j));
				tot = max(tot, mt(1 + 2 * j - i.second[j] + sf.first, i.second[sf.second], i.second[j]));
			}
		}
		cout << X[g1(tot)] << ' ' << g1(tot) << ' ' << g2(tot) << '\n';
	}
}