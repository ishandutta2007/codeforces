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
#define g4(a) get<4>(a)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using db = double;
using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using iiii = tuple<int, int, int, int>;
template<class key, class value = null_type, class cmp = less<key> >
using ordered_set = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

int t, n, m, cnt;
bool can;
char C[505][505];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		can = cnt = 0;
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> C[i][j];
				if (j > 1 && C[i][j] == '0' && C[i][j - 1] == '0') can = 1;
				if (i > 1 && C[i][j] == '0' && C[i - 1][j] == '0') can = 1;
				cnt += (C[i][j] == '1');
			}
		}
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) C[i][j] -= '0';
		if (can) cout << cnt << '\n';
		else {
			int first_move = LLONG_MAX;
			for (int i = 1; i < n; i++) {
				for (int j = 1; j < m; j++) {
					int tmp = 0;
					for (int k = 0; k < 2; k++)
						for (int l = 0; l < 2; l++)
							tmp += C[i + k][j + l];
					for (int k = 0; k < 2; k++)
						for (int l = 0; l < 2; l++) {
							tmp -= C[i + k][j + l];
							first_move = min(first_move, tmp);
							tmp += C[i + k][j + l];
						}
				}
			}
			cout << cnt - first_move + 1 << '\n';
		}
	}
}