#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#ifdef WIN_32
#define getchar_unlocked _getchar_nolock
#endif
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
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int T, N, P, K, X, Y;
map<int, int> pref[100005];
map<int, int> prefs;
char A[100005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N >> P >> K;
		for (int i = 1; i <= N; i++) cin >> A[i];
		cin >> X >> Y;
		for (int i = 1; i <= N; i++) {
			prefs[i % K] += (A[i] == '0');
			pref[i][i % K] = prefs[i % K];
		}
		int ans = LLONG_MAX;
		for (int i = 0; i < N; i++) {
			int st = P + i, ed = ((N - (P + i)) / K) * K + (P + i);
			if (st > N) continue;
			//cout << i << ' ' << st << ' ' << ed << ' ' << pref[ed][ed % K] - pref[st][st % K] + (A[st] == '0') << '\n';
			ans = min(ans, (pref[ed][ed % K] - pref[st][st % K] + (A[st] == '0')) * X + Y * i);
		}
		cout << ans << '\n';
	}
}