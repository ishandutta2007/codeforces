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

int N, L, K, D[505], A[505], mem[505][505];

int dp(int n, int k) {
	if (k < 0) return 1e16;
	if (mem[n][k] != -1) return mem[n][k];
	int ans = (N - n <= k ? (L - D[n]) * A[n] : (int)1e16);
	for (int i = n + 1; i <= N; i++)
		ans = min(ans, (D[i] - D[n]) * A[n] + dp(i, k - (i - n - 1)));
	return mem[n][k] = ans;
}

main() {
	memset(mem, -1, sizeof mem);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> L >> K;
	for (int i = 1; i <= N; i++) cin >> D[i];
	for (int i = 1; i <= N; i++) cin >> A[i];
	cout << dp(1, K) << '\n';
}