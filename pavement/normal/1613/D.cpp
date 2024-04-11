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

const int MOD = 998244353;
int T, N, ans, A[500005], dp[500005], dp2[500005][2], cdp[500005], cdp2[500005][2];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		ans = 1;
		for (int i = 1; i <= N; i++) {
			cin >> A[i];
			if (A[i] == 1) ans = (ans * 2) % MOD;
		}
		ans--;
		for (int i = 1; i <= N; i++) {
			dp[i] = cdp[A[i]] + (A[i] ? cdp[A[i] - 1] : 0) + !A[i];
			dp[i] %= MOD;
			cdp[A[i]] += dp[i];
			cdp[A[i]] %= MOD;
		}
		for (int i = N; i >= 1; i--) {
			dp2[i][1] = cdp2[A[i] + 2][0] + 1 + cdp2[A[i]][1];
			dp2[i][1] %= MOD;
			dp2[i][0] = cdp2[A[i] - 2][1] + 1 + cdp2[A[i]][0];
			dp2[i][0] %= MOD;
			ans += dp[i] * (cdp2[A[i] + 2][0] + 1);
			ans %= MOD;
			cdp2[A[i]][1] += dp2[i][1];
			cdp2[A[i]][1] %= MOD;
			cdp2[A[i]][0] += dp2[i][0];
			cdp2[A[i]][0] %= MOD;
		}
		for (int i = 0; i <= N; i++) {
			dp[i] = cdp[i] = 0;
			for (int j : {0, 1})
				dp2[i][j] = cdp2[i][j] = 0;
		}
		cout << (ans + MOD) % MOD << '\n';
	}
}