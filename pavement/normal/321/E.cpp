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

int N, K, u[4005][4005], cost[4005][4005], dp[2][4005];

void go(int l, int r, int x, int y, int k) {
	if (l > r || x > y) return;
	int m = (l + r) >> 1, opt = -1;
	dp[k & 1][m] = LLONG_MAX;
	for (int i = x; i <= min(m, y); i++)
		if (dp[k & 1 ^ 1][i - 1] + cost[i][m] < dp[k & 1][m]) {
			dp[k & 1][m] = dp[k & 1 ^ 1][i - 1] + cost[i][m];
			opt = i;
		}
	assert(opt != -1);
	go(l, m - 1, x, opt, k);
	go(m + 1, r, opt, y, k);
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			cin >> u[i][j];
			u[i][j] += u[i][j - 1] + u[i - 1][j] - u[i - 1][j - 1];
		}
	for (int i = 1; i <= N; i++)
		for (int j = i; j <= N; j++) {
			cost[i][j] = u[j][j] - u[i - 1][j] - u[j][i - 1] + u[i - 1][i - 1];
			cost[i][j] /= 2;
		}
	for (int i = 1; i <= N; i++) dp[1][i] = cost[1][i];
	for (int i = 2; i <= K; i++) go(1, N, 1, N, i);
	cout << dp[K & 1][N] << '\n';
}