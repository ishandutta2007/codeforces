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

int T, N, A[105], B[105], P[105], mem[105][10005];

int dp(int n, int s) {
	if (n == N + 1) return 0;
	if (mem[n][s] != -1) return mem[n][s];
	return mem[n][s] = min(dp(n + 1, s + A[n]) + s * A[n] + (P[n - 1] - s) * B[n], dp(n + 1, s + B[n]) + s * B[n] + (P[n - 1] - s) * A[n]);
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		memset(mem, -1, sizeof mem);
		cin >> N;
		int tmp = 0;
		for (int i = 1; i <= N; i++) cin >> A[i], tmp += (N - 1) * A[i] * A[i];
		for (int i = 1; i <= N; i++) cin >> B[i], tmp += (N - 1) * B[i] * B[i];
		for (int i = 1; i <= N; i++) P[i] = P[i - 1] + A[i] + B[i];
		cout << 2 * dp(1, 0) + tmp << '\n';
	}
}