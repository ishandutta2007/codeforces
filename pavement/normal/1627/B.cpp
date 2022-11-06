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

int T, N, M, dr[4], dc[4];

inline int conv(int r, int c) {
	return (r - 1) * M + c;
}

inline int calc(int r, int c) {
	int ret = 0;
	for (int i = 0; i < 4; i++)
		ret = max(ret, llabs(dr[i] - r) + llabs(dc[i] - c));
	return ret;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N >> M;
		dr[0] = dc[0] = 1;
		dr[1] = 1;
		dc[1] = M;
		dr[2] = N;
		dc[2] = 1;
		dr[3] = N;
		dc[3] = M;
		vector<int> val;
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++)
				val.pb(calc(i, j));
		sort(val.begin(), val.end());
		for (int i = 0; i < (int)val.size(); i++) cout << val[i] << ' ';
		cout << '\n';
	}
}