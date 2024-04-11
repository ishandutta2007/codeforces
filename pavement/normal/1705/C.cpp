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

int TC, N, C, Q;
char S[200005];
vector<iiii> vec;

char f(int x) {
	if (x <= N) return S[x];
	int lo = 0, hi = (int)vec.size() - 1;
	while (lo <= hi) {
		int mid = (lo + hi) >> 1;
		if (g0(vec[mid]) <= x && x <= g1(vec[mid])) {
			return f(g2(vec[mid]) + x - g0(vec[mid]));
		} else if (g1(vec[mid]) < x) lo = mid + 1;
		else hi = mid - 1;
	}
	assert(0);
	return -1;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> TC;
	while (TC--) {
		vec.clear();
		cin >> N >> C >> Q;
		for (int i = 1; i <= N; i++) {
			cin >> S[i];
		}
		vec.eb(1, N, 1, N);
		for (int i = 1, cur_l = N, l, r; i <= C; i++) {
			cin >> l >> r;
			vec.eb(cur_l + 1, cur_l + r - l + 1, l, r);
			cur_l += r - l + 1;
		}
		for (int i = 1, k; i <= Q; i++) {
			cin >> k;
			cout << f(k) << '\n';
		}
	}
}