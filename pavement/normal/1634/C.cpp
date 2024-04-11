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

int T, N, K, A[505][505];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		vector<int> odd, even;
		bool cannot = 0;
		cin >> N >> K;
		for (int i = 1; i <= N * K; i++)
			if (i & 1) odd.pb(i);
			else even.pb(i);
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= K; j++)
				if (i & 1) {
					if (odd.empty()) cannot = 1;
					else A[i][j] = odd.back(), odd.ppb();
				} else {
					if (even.empty()) cannot = 1;
					else A[i][j] = even.back(), even.ppb();
				}
		}
		if (cannot) {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= K; j++) cout << A[i][j] << ' ';
			cout << '\n';
		}
	}
}