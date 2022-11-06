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
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
#define g0(a) get<0>(a)
#define g1(a) get<1>(a)
#define g2(a) get<2>(a)
#define g3(a) get<3>(a)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef double db;
typedef long long ll;
typedef long double ld;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int T, N, K, P[105];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N >> K;
		for (int i = 1; i <= N; i++) cin >> P[i];
		int lo = 0, hi = 1e15, ans = -1;
		while (lo <= hi) {
			int mid = (lo + hi) / 2, cur = P[1] + mid;
			bool cannot = 0;
			for (int i = 2; i <= N; i++) {
				if (P[i] * 100 > K * cur) cannot = 1;
				cur += P[i];
			}
			if (cannot) lo = mid + 1;
			else ans = mid, hi = mid - 1;
		}
		cout << ans << '\n';
	}
}