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

int T, N, U, V, A[105], cnt[1000005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N >> U >> V;
		vector<int> chk;
		int ans = LLONG_MAX;
		for (int i = 1; i <= N; i++) {
			cin >> A[i];
			if (i > 1 && llabs(A[i] - A[i - 1]) > 1) ans = 0;
			cnt[A[i]]++;
			chk.pb(A[i]);
		}
		for (int i : chk) {
			if (cnt[i] == N) {
				ans = min({ans, U + V, V + V});
			} else {
				ans = min({ans, U, V});
			}
			break;
		}
		for (int i : chk) cnt[i] = 0;
		cout << ans << '\n';
	}
}