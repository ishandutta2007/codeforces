#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#ifdef WIN_32
#define getchar_unlocked _getchar_nolock
#endif
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pf push_front
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
typedef long double ld;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int T, N, ans, X[500005], hv[65], nothv[65];
const int MOD = 1e9 + 7;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		ans = 0;
		for (int j = 0; j < 60; j++) hv[j] = nothv[j] = 0;
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> X[i];
			for (int j = 0; j < 60; j++)
				if (!(X[i] & (1ll << j))) nothv[j]++;
				else hv[j]++;
		}
		for (int i = 1; i <= N; i++) {
			int sum = 0;
			for (int j = 0; j < 60; j++) {
				if (X[i] & (1ll << j)) sum += (N * ((1ll << j) % MOD)) % MOD;
				else sum += (hv[j] * ((1ll << j) % MOD)) % MOD;
				sum %= MOD;
			}
			for (int j = 0; j < 60; j++) {
				if (!(X[i] & (1ll << j))) continue;
				ans += ((hv[j] * ((1ll << j) % MOD)) % MOD * sum) % MOD;
				ans %= MOD;
			}
		}
		cout << ans << '\n';
	}
}