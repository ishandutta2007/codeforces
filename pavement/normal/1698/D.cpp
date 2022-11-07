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

int T, N, A[10005];

main() {
	cin >> T;
	while (T--) {
		cin >> N;
		int lo = 1, hi = N, ans = -1;
		while (lo <= hi) {
			int mid = (lo + hi) >> 1, out = 0;
			cout << "? 1 " << mid << endl;
			for (int j = 1; j <= mid; j++) cin >> A[j];
			for (int j = 1; j <= mid; j++)
				if (!binary_search(A + 1, A + 1 + mid, j)) out++;
			if ((mid - out) % 2 == 0) lo = mid + 1;
			else ans = mid, hi = mid - 1;
		}
		cout << "! " << ans << endl;
	}
}