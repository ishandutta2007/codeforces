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

int T, N, ans, out[105][105];
vector<ii> vec[2];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		if (N == 2) {
			cout << "-1\n";
			continue;
		}
		vec[0].clear();
		vec[1].clear();
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				vec[(i + j) & 1].eb(i, j);
		for (int i = 1; i <= N * N; i++) {
			if (i <= vec[0].size()) out[vec[0][i - 1].first][vec[0][i - 1].second] = i;
			else out[vec[1][i - vec[0].size() - 1].first][vec[1][i - vec[0].size() - 1].second] = i;
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) cout << out[i][j] << ' ';
			cout << '\n';
		}
	}
}