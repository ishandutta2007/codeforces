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

const int MOD = 1e9 + 7;
int N, ans, A[1005], mem[1005][20005];

int dp(int n, int k) {
	if (n == 0) return 0;
	if (k < -10000 || k > 10000) return 0;
	if (mem[n][k + 10000] != -1) return mem[n][k + 10000];
	mem[n][k + 10000] = dp(n - 1, k - A[n]) + dp(n - 1, k + A[n]) + (k + A[n] == 0) + (k - A[n] == 0);
	mem[n][k + 10000] %= MOD;
	return mem[n][k + 10000];
}

main() {
	memset(mem, -1, sizeof mem);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= N; i++) ans += dp(i, 0), ans %= MOD;
	assert(ans >= 0);
	cout << ans << '\n';
}