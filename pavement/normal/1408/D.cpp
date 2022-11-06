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
typedef tree<iii, null_type, greater<iii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int N, M, curr = 0, ans = LLONG_MAX, A[2005], B[2005], C[2005], D[2005];
vector<int> vec[2000005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> A[i] >> B[i];
	for (int i = 1; i <= M; i++) cin >> C[i] >> D[i];
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++) {
			int xdiff = max(0ll, C[j] - A[i] + 1), ydiff = max(0ll, D[j] - B[i] + 1);
			vec[xdiff].pb(ydiff);
		}
	for (int x = 2000000; x >= 0; x--) {
		// for all pairs where xdiff > x...
		ans = min(ans, x + curr);
		for (auto i : vec[x]) curr = max(curr, i);
	}
	cout << ans << '\n';
}