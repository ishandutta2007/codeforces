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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int N, a, A[105][105];
vector<ii> odd, even;

main() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			if ((i + j) & 1) odd.eb(i, j);
			else even.eb(i, j);
	for (int t = 1; t <= N * N; t++) {
		int b = -1, oi, oj;
		cin >> a;
		if (a == 3) {
			if (odd.size() < even.size()) {
				b = 2;
				oi = even.back().first, oj = even.back().second;
				A[even.back().first][even.back().second] = 2;
				even.ppb();
			} else {
				b = 1;
				oi = odd.back().first, oj = odd.back().second;
				A[odd.back().first][odd.back().second] = 1;
				odd.ppb();
			}
		} else {
			if (a == 2) {
				if (odd.size()) {
					b = 1;
					oi = odd.back().first, oj = odd.back().second;
					A[odd.back().first][odd.back().second] = 1;
					odd.ppb();
				} else {
					b = 3;
					oi = even.back().first, oj = even.back().second;
					A[even.back().first][even.back().second] = 3;
					even.ppb();
				}
			} else {
				if (even.size()) {
					b = 2;
					oi = even.back().first, oj = even.back().second;
					A[even.back().first][even.back().second] = 2;
					even.ppb();
				} else {
					b = 3;
					oi = odd.back().first, oj = odd.back().second;
					A[odd.back().first][odd.back().second] = 3;
					odd.ppb();
				}
			}
		}
		cout << b << ' ' << oi << ' ' << oj << endl;
	}
}