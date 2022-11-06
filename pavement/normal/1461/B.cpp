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

int T, N, M, ans, P[505][505];
char C[505][505];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		ans = 0;
		memset(P, 0, sizeof P);
		cin >> N >> M;
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++) {
				cin >> C[i][j];
				if (C[i][j] == '.') P[i][j] = P[i][j - 1] + 1;
				else P[i][j] = P[i][j - 1];
			}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				bool cannot = 0;
				for (int k = i; k <= N; k++) {
					if ((j - (k - i + 1) + 1) < 1 || j + (k - i + 1) - 1 > M) {
						cannot = 1;
					} else {
						if (P[k][j + (k - i + 1) - 1]  - P[k][(j - (k - i + 1))]) cannot = 1;
					}
					if (cannot) {
						ans += (k - i);
						break;
					}
				}
				//cout << cannot << ' ';
				if (!cannot) ans += (N - i + 1);
			}
		}
		cout << ans << '\n';
	}
}