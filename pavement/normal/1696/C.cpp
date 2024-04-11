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

int T, N, M, K, x, prv;
vector<ii> A, B, A_r, B_r;
int ss;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		A.clear();
		B.clear();
		A_r.clear();
		B_r.clear();
		x = prv = 0;
		ss = 0;
		cin >> N >> M;
		for (int i = 1; i <= N; i++) {
			cin >> x;
			int ox = x, tot = 0;
			while (x % M == 0) {
				tot++;
				x /= M;
			}
			A.eb(x, ox / x);
		}
		cin >> K;
		for (int i = 1; i <= K; i++) {
			cin >> x;
			int ox = x, tot = 0;
			while (x % M == 0) {
				tot++;
				x /= M;
			}
			B.eb(x, ox / x);
		}
		ss = 0;
		prv = A[0].first;
		for (auto [i, occ] : A) {
			if (i != prv) {
				A_r.eb(prv, ss);
				ss = 0;
			}
			ss += occ;
			prv = i;
		}
		A_r.eb(prv, ss);
		prv = B[0].first;
		ss = 0;
		for (auto [i, occ] : B) {
			if (i != prv) {
				B_r.eb(prv, ss);
				ss = 0;
			}
			ss += occ;
			prv = i;
		}
		B_r.eb(prv, ss);
		if (A_r == B_r) cout << "Yes\n";
		else cout << "No\n";
	}
}