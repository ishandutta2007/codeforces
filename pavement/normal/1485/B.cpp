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
#define pf push_front
#define ppb pop_back
#define ppf pop_front
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

int N, Q, K, A[100005], tmp[100005], pref[100005], l, r;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> Q >> K;
	for (int i = 1; i <= N; i++) cin >> A[i];
	A[0] = 1;
	A[N + 1] = K;
	for (int i = 1; i <= N; i++) {
		tmp[i] = max(0ll, A[i + 1] - A[i - 1] - 2);
		pref[i] = pref[i - 1] + tmp[i];
	}
	for (int i = 1; i <= Q; i++) {
		cin >> l >> r;
		if (l == r) cout << K - 1 << '\n';
		else cout << (r - 1 > l ? pref[r - 1] - pref[l] : 0) + (A[l + 1] - 2) + (K - A[r - 1] - 1) << '\n';
	}
}