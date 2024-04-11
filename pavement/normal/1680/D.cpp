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

int N, K, ans, A[3005], _A[3005];
vector<int> pos;

int cnt(int l, int r) {
	if (l > r) return 0;
	return upper_bound(pos.begin(), pos.end(), r) - lower_bound(pos.begin(), pos.end(), l);
}

void run() {
	for (int i = 0; i <= N; i++)
		for (int j = i; j <= N; j++) {
			// things from [1, i] do +K
			// things from (i, j] do -K
			int c1 = cnt(1, i), c2 = cnt(i + 1, j), out = cnt(j + 1, N);
			int ss = A[N] + c1 * K - c2 * K;
			if (-out * K <= ss && ss <= out * K) {
				// all good
				ans = max(ans, A[i] + c1 * K - (A[j] + c1 * K - c2 * K) + 1);
			} else if (ss < -out * K) {
				// increase stuff
				int to_inc = -out * K - ss;
				ans = max(ans, A[i] + c1 * K - (A[j] + c1 * K - c2 * K + to_inc) + 1);
			} else {
				// decrease stuff
				int to_dec = ss - out * K;
				ans = max(ans, A[i] + c1 * K - to_dec - (A[j] + c1 * K - c2 * K) + 1);
			}
		}
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		_A[i] = A[i];
		if (A[i] == 0) pos.pb(i);
		A[i] += A[i - 1];
	}
	if (llabs(A[N]) > K * pos.size()) return cout << "-1\n", 0;
	run();
	for (int i = 1; i <= N; i++) A[i] = -_A[i];
	pos.clear();
	for (int i = 1; i <= N; i++) {
		if (A[i] == 0) pos.pb(i);
		A[i] += A[i - 1];
	}
	run();
	cout << ans << '\n';
}