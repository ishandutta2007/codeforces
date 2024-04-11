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

int N, mod, mem[55], mem2[55][8005];

int dp2(int n, int cnt) {
	cnt = min(cnt, N * N);
	cnt = max(cnt, -N * N);
	if (n == 0) return cnt <= 0;
	if (mem2[n][cnt + 4000] != -1) return mem2[n][cnt + 4000];
	int ret = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) ret = (ret + dp2(n - 1, cnt - (i - j))) % mod;
	return mem2[n][cnt + 4000] = ret;
}

int dp(int n) {
	if (n == 0) return 0;
	if (mem[n] != -1) return mem[n];
	int ret = dp(n - 1) * n;
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++) ret = (ret + dp2(n - 1, 1 - (i - j))) % mod;
	return mem[n] = ret;
}

main() {
	memset(mem, -1, sizeof mem);
	memset(mem2, -1, sizeof mem2);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> mod;
	cout << dp(N) << '\n';
}