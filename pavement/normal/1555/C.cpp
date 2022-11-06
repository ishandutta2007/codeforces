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

int T, N, x, a[3][100005], P[100005], S[100005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		x = LLONG_MAX;
		for (int i = 0; i <= N + 5; i++) P[i] = S[i] = 0;
		for (int i = 1; i <= 2; i++)
			for (int j = 1; j <= N; j++) cin >> a[i][j];
		for (int i = 1; i <= N; i++) P[i] = P[i - 1] + a[2][i];
		for (int i = N; i >= 1; i--) S[i] = S[i + 1] + a[1][i];
		for (int i = 1; i <= N; i++) x = min(x, max(S[i + 1], P[i - 1]));
		cout << x << '\n';
	}
}