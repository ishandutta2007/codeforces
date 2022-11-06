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

int T, N, ans[200005];
vector<iii> vec[200005];
vector<iiii> tmp;
multiset<int> S, cov;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 1, L, R, C; i <= N; i++) {
			cin >> L >> R >> C;
			vec[C].eb(L, R, i);
			S.insert(L);
			S.insert(R);
			tmp.eb(L, C, i, 0);
			tmp.eb(R, C, i, 1);
		}
		for (int i = 1; i <= N; i++) {
			for (auto [L, R, idx] : vec[i]) S.erase(S.find(L)), S.erase(S.find(R));
			for (auto [L, R, idx] : vec[i]) {
				auto it = S.lower_bound(L);
				if (it != S.end() && *it <= R) ans[idx] = 0;
				else {
					ans[idx] = LLONG_MAX;
					auto it = S.lower_bound(R);
					if (it != S.end()) ans[idx] = min(ans[idx], *it - R);
					it = S.lower_bound(L);
					if (it != S.begin()) {
						--it;
						ans[idx] = min(ans[idx], L - *it);
					}
				}
			}
			for (auto [L, R, idx] : vec[i]) S.insert(L), S.insert(R);
		}
		sort(tmp.begin(), tmp.end());
		for (auto [x, c, idx, ty] : tmp) {
			if (ty == 0) {
				cov.insert(c);
			} else {
				if (*cov.begin() != c || *cov.rbegin() != c) ans[idx] = 0;
				cov.erase(cov.find(c));
			}
		}
		for (int i = 1; i <= N; i++) cout << ans[i] << ' ';
		cout << '\n';
		for (int i = 1; i <= N; i++) {
			vec[i].clear();
		}
		S.clear();
		cov.clear();
		tmp.clear();
	}
}