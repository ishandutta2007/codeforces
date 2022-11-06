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

int N, P[505], out[505][505];

bool valid(int r, int c) {
	if (r < 1 || c < 1 || r > N || c > N) return 0;
	if (out[r][c]) return 0;
	if (r == c) return 0;
	return 1;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> P[i];
	bool inv = 0;
	for (int i = 1; i <= N; i++) {
		int currow = i, curcol = i;
		for (int k = 0; ; ) {
			assert(!out[currow][curcol]);
			out[currow][curcol] = P[i];
			k++;
			if (k >= P[i]) break;
			if (valid(currow, curcol - 1)) curcol--;
			else if (valid(currow + 1, curcol)) currow++;
			else if (valid(currow, curcol + 1)) curcol++;
			else if (valid(currow - 1, curcol)) currow--;
			else inv = 1;
		}
	}
	if (inv) return cout << "-1\n", 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) cout << out[i][j] << ' ';
		cout << '\n';
	}
}