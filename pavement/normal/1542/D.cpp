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
int ans, cc, N, X[505], mem[505][505];
char C[505];

int dp(int n, int b) {
	if (n == N + 1) return 1;
	if (mem[n][b] != -1) return mem[n][b];
	int ret;
	if (n == cc) {
		ret = dp(n + 1, b);
	} else if (n < cc) {
		if (C[n] == '-') ret = dp(n + 1, max(0ll, b - 1)) + dp(n + 1, b);
		else if (X[n] > X[cc]) ret = dp(n + 1, b) * 2;
		else ret = dp(n + 1, b + 1) + dp(n + 1, b);
	} else {
		if (C[n] == '-') ret = (b > 0 ? dp(n + 1, b - 1) : 0) + dp(n + 1, b);
		else if (X[n] >= X[cc]) ret = dp(n + 1, b) * 2;
		else ret = dp(n + 1, b + 1) + dp(n + 1, b);
	}
	return mem[n][b] = ret % MOD;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> C[i];
		if (C[i] == '+') cin >> X[i];
	}
	for (int i = 1; i <= N; i++) {
		if (C[i] == '+') {
			// if X[j] > X[i] or (X[j] == X[i] && j >= i), val[j] = 1
			// else val[j] = 0
			// ensure that count of val[j] = 0 always positive when hit '-'
			cc = i;
			memset(mem, -1, sizeof mem);
			ans += X[i] * dp(1, 0) % MOD;
			ans %= MOD;
		}
	}
	cout << ans << '\n';
}