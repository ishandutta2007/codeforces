#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#ifdef TEST
#define getchar_unlocked _getchar_nolock
#endif
#define int long long
#define ins insert
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pf push_front
#define pp pop
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
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int Q, N, A[300005], B[300005], dp[300005][3][3];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> Q;
	while (Q--) {
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> A[i] >> B[i];
		}
		for (int j = 0; j <= 2; j++)
			for (int k = 0; k <= 2; k++)
				dp[1][j][k] = k * B[1];
		for (int i = 2; i <= N; i++)
			for (int j = 0; j <= 2; j++) {
				for (int k = 0; k <= 2; k++) {
					if (A[i - 1] + j == A[i] + k) {
						dp[i][j][k] = LLONG_MAX;
						continue;
					}
					assert(min({dp[i - 1][0][j], dp[i - 1][1][j], dp[i - 1][2][j]}) < LLONG_MAX);
					dp[i][j][k] = min({dp[i - 1][0][j], dp[i - 1][1][j], dp[i - 1][2][j]}) + B[i] * k;
					//cout << "DP " << i << ' ' << j << ' ' << k << ' ' << dp[i][j][k] <<'\n';
				}
			}
		int ans = LLONG_MAX;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				ans = min(ans, dp[N][i][j]);
		cout << ans << '\n';
	}
}