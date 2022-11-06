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
using db = double;
using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using iiii = tuple<int, int, int, int>;
template<class key, class value = null_type, class cmp = less<key> >
using ordered_set = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

int T, N, ldp[2][200005], rdp[2][200005];
bool B[2][200005];
char C;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		int hv = 1e16, hv2 = -1e16, ans = 1e16;
		for (int i = 0; i < 2; i++)
			for (int j = 1; j <= N; j++) {
				cin >> C;
				B[i][j] = (C == '*');
				if (B[i][j]) hv = min(hv, j), hv2 = max(hv2, j);
			}
		for (int j = 1; j <= N; j++)
			for (int i = 0; i < 2; i++) {
				if (j > hv) ldp[i][j] = min(ldp[i][j - 1] + B[!i][j] + 1, ldp[!i][j - 1] + 2);
				else ldp[i][j] = B[!i][j];
			}
		for (int j = N; j >= 1; j--)
			for (int i = 0; i < 2; i++) {
				if (j < hv2) rdp[i][j] = min(rdp[i][j + 1] + B[!i][j] + 1, rdp[!i][j + 1] + 2);
				else rdp[i][j] = B[!i][j];
			}
		for (int i = 0; i < 2; i++)
			for (int j = 0; j <= N; j++)
				ans = min({ans, ldp[i][j] + rdp[i][j + 1] + (j >= hv && j + 1 <= hv2), ldp[i][j] + rdp[!i][j + 1] + 2 * (j >= hv && j + 1 <= hv2)});
		cout << ans << '\n';
	}
}