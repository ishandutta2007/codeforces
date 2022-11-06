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

int T, N, P[200005];
map<int, int> M;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		M.clear();
		cin >> N;
		for (int i = 1, A; i <= N; i++) {
			cin >> A;
			M[A]++;
		}
		int ans = 0, ev = 0, odds = 0, ev2 = 0, odds2 = 0;
		for (auto i : M) {
			if (i.second >= 2) ev++;
			else odds++;
		}
		for (auto i : M) {
			if (i.second >= 2) ev--;
			else odds--;
			int tmp = max(
				min((odds + 1) / 2 + odds2 / 2, odds / 2 + (odds2 + 1) / 2), min((odds + 1) / 2 + odds2 / 2, odds / 2 + (odds2 + 1) / 2));
			ans = max(ans, 1 + ev + ev2 + tmp);
			if (i.second >= 2) ev2++;
			else odds2--;
		}
		cout << ans << '\n';
	}
}