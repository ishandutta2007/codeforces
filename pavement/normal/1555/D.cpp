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

int N, M, A[3][3][200005][3];
char s[200005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> s[i];
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			if (i == j) continue;
			string tmp;
			tmp.pb('a' + i);
			tmp.pb('a' + j);
			tmp.pb('a' + (i != 0 && j != 0 ? 0 : i != 1 && j != 1 ? 1 : 2));
			for (int k = N; k >= 1; k--)
				for (int l = 0; l < 3; l++)
					A[i][j][k][l] = A[i][j][k + 1][(l + 1) % 3] + (tmp[l] != s[k]);
		}
	for (int l, r; M--; ) {
		cin >> l >> r;
		int ans = LLONG_MAX;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				if (i != j) ans = min(ans, A[i][j][l][0] - A[i][j][r + 1][(r + 1 - l) % 3]);
		cout << ans << '\n';
	}
}