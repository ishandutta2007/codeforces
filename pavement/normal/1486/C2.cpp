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

int N, S;

main() {
	cin >> N;
	cout << "? " << 1 << ' ' << N << endl;
	cin >> S;
	int lo = 1, hi = N - 1, ans = -1;
	while (lo <= hi) {
		int mid = (lo + hi) >> 1, L = max(1ll, S - mid), R = min(N, S + mid), tmp;
		cout << "? " << L << ' ' << R << endl;
		cin >> tmp;
		if (tmp == S) ans = mid, hi = mid - 1;
		else lo = mid + 1;
	}
	int L = max(1ll, S - ans), R = min(N, S + ans), tmp;
	if (L < S) {
		cout << "? " << L << ' ' << S << endl;
		cin >> tmp;
	} else tmp = -1;
	if (tmp == S) cout << "! " << L << endl;
	else cout << "! " << R << endl;
}