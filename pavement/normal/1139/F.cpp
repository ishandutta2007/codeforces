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

int N, M, L[100005], B[100005], P[100005], ans[100005];
vector<iii> ev;
ordered_set<ii> S, S2;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> L[i];
		ev.eb(L[i], 0, i);
	}
	for (int i = 1, R; i <= N; i++) {
		cin >> R;
		ev.eb(R, 2, i);
	}
	for (int i = 1; i <= N; i++) cin >> B[i];
	for (int i = 1, A; i <= M; i++) {
		cin >> A;
		ev.eb(A, 1, i);
	}
	for (int i = 1; i <= M; i++) cin >> P[i];
	sort(ev.begin(), ev.end());
	for (auto [x, ty, idx] : ev) {
		if (ty == 0) {
			S.insert(mp(x - B[idx], idx));
			S2.insert(mp(x + B[idx], idx));
		} else if (ty == 1) {
			ans[idx] = S.order_of_key(mp(x - P[idx], LLONG_MAX));
			ans[idx] += S2.order_of_key(mp(x + P[idx], LLONG_MAX));
			ans[idx] -= S.size();
		} else {
			S.erase(S.find(mp(L[idx] - B[idx], idx)));
			S2.erase(S2.find(mp(L[idx] + B[idx], idx)));
		}
	}
	for (int i = 1; i <= M; i++) cout << ans[i] << ' ';
	cout << '\n';
}