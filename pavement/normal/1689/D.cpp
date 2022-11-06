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

int T, N, M, P[4][1005][1005];
char C[1005][1005];
iii out;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N >> M;
		out = mt((int)1e16, -1ll, -1ll);
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++)
				cin >> C[i][j];
		for (int i = 0; i <= max(N, M); i++)
			for (int k = 0; k < 4; k++)
				P[k][0][i] = P[k][i][0] = P[k][N + 1][i] = P[k][i][M + 1] = (int)-1e16;
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++)
				P[0][i][j] = max({P[0][i - 1][j], P[0][i][j - 1], C[i][j] == 'B' ? - i - j : (int)-1e16});
		for (int i = 1; i <= N; i++)
			for (int j = M; j >= 1; j--)
				P[1][i][j] = max({P[1][i - 1][j], P[1][i][j + 1], C[i][j] == 'B' ? - i + j : (int)-1e16});
		for (int i = N; i >= 1; i--)
			for (int j = 1; j <= M; j++)
				P[2][i][j] = max({P[2][i + 1][j], P[2][i][j - 1], C[i][j] == 'B' ? i - j : (int)-1e16});
		for (int i = N; i >= 1; i--)
			for (int j = M; j >= 1; j--)
				P[3][i][j] = max({P[3][i + 1][j], P[3][i][j + 1], C[i][j] == 'B' ? i + j : (int)-1e16});
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++) {
				int tmp = max({P[0][i][j] + i + j, P[1][i][j] + i - j, P[2][i][j] - i + j, P[3][i][j] - i - j});
				out = min(out, mt(tmp, i, j));
			}
		cout << g1(out) << ' ' << g2(out) << '\n';
	}
}