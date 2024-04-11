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

int T, N, M, K, X[100005], dp[200005];
vector<iii> vec[100005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N >> M >> K;
		for (int i = 1; i <= N; i++) {
			vec[i].clear();
			cin >> X[i];
		}
		for (int i = 1, a, b, c, d, h; i <= K; i++) {
			cin >> a >> b >> c >> d >> h;
			vec[a].eb(b, (i << 1) - 1, -h);
			vec[c].eb(d, i << 1, -h);
		}
		for (int i = 0; i <= (K << 1 | 1); i++) dp[i] = (int)1e18;
		vec[1].eb(1, 0, -1);
		vec[N].eb(M, K << 1 | 1, -1);
		dp[K << 1 | 1] = 0;
		for (int i = N; i >= 1; i--) {
			sort(vec[i].begin(), vec[i].end());
			for (auto [pos, id, cst] : vec[i])
				if (1 <= id && id <= (K << 1) && (id & 1))
					dp[id] = dp[id + 1] + cst;
			for (int j = 0, curr = (int)1e18; j < vec[i].size(); j++) {
				curr = min(curr, dp[g1(vec[i][j])] - g0(vec[i][j]) * X[i]);
				dp[g1(vec[i][j])] = min(dp[g1(vec[i][j])], g0(vec[i][j]) * X[i] + curr);
			}
			for (int j = (int)vec[i].size() - 1, curr = (int)1e18; j >= 0; j--) {
				curr = min(curr, dp[g1(vec[i][j])] + g0(vec[i][j]) * X[i]);
				dp[g1(vec[i][j])] = min(dp[g1(vec[i][j])], -g0(vec[i][j]) * X[i] + curr);
			}
		}
		if (dp[0] > (int)1e16) cout << "NO ESCAPE\n";
		else cout << dp[0] << '\n';
	}
}