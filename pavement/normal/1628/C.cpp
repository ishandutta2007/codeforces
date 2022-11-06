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

int T, N, zzz[1005][1005], cnt[1005][1005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		memset(zzz, 0, sizeof zzz);
		memset(cnt, 0, sizeof cnt);
		for (int j = 0; j < N; j++) zzz[0][j] = 1;
		for (int j = 0; j < N; j++)
			cnt[0][j] = (j ? zzz[0][j - 1] : 0) + (j + 1 < N ? zzz[0][j + 1] : 0);
		for (int i = 1; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (cnt[i - 1][j] % 2 == 0) {
					zzz[i][j] = 1;
					cnt[i - 1][j]++;
				}
			}
			for (int j = 0; j < N; j++)
				cnt[i][j] = (j ? zzz[i][j - 1] : 0) + (j + 1 < N ? zzz[i][j + 1] : 0) + zzz[i - 1][j];
		}
		bool cannot = 0;
		for (int j = 0; j < N; j++)
			for (int k = 0; k < N; k++) {
				if (cnt[j][k] % 2 == 0) cannot = 1;
			}
		assert(!cannot);
		int ans = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0, x; j < N; j++) {
				cin >> x;
				if (zzz[i][j]) ans ^= x;
			}
		cout << ans << '\n';
	}
}