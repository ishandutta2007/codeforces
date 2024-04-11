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
typedef double db;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int T, N;

int qry(int l, int r) {
	int x;
	cout << "? " << l << ' ' << r << endl;
	cin >> x;
	return x;
}

main() {
	cin >> T;
	while (T--) {
		cin >> N;
		int lo = 1, hi = N, ans = -1;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			if (qry(mid, N)) lo = mid + 1;
			else ans = mid, hi = mid - 1;
		}
		assert(ans != -1);
		int k = ans;
		int j = k - (qry(1, ans) - qry(1, ans - 1));
		int tmp = qry(1, ans) - (k - j + 1) * (k - j) / 2;
		int i = (1 + sqrt(1 + 8 * (tmp))) / 2;
		cout << "! " << j - i << ' ' << j << ' ' << k << endl;
	}
}