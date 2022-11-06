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

int N, ans, P[5005], A[5005], B[5005], mem[5005][5005];

int dp(int l, int r) {
	if (l == r) return A[l] * B[l];
	if (l > r) return 0;
	if (mem[l][r] != -1) return mem[l][r];
	return mem[l][r] = dp(l + 1, r - 1) + A[l] * B[r] + A[r] * B[l];
}

main() {
	memset(mem, -1, sizeof mem);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= N; i++) cin >> B[i];
	for (int i = 1; i <= N; i++) P[i] = P[i - 1] + A[i] * B[i];
	ans = P[N];
	for (int i = 1; i <= N; i++)
		for (int j = i; j <= N; j++)
			ans = max(ans, P[i - 1] + dp(i, j) + P[N] - P[j]);
	cout << ans << '\n';
}