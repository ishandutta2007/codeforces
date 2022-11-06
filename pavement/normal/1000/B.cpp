#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#ifdef TEST
#define getchar_unlocked _getchar_nolock
#endif
#define ins insert
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pf push_front
#define pp pop
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
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tree<pair<ll, int>, null_type, less<pair<ll, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int N, M, A[100005], pref[100005], rpref[100005];
vector<int> con;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		if (A[i] != 1) con.pb(A[i] - 1);
		if (A[i] != M - 1) con.pb(A[i] + 1);
	}
	A[N + 1] = M;
	for (int i = 1; i <= N + 1; i++) {
		pref[i] = pref[i - 1];
		rpref[i] = rpref[i - 1];
		if (i & 1) pref[i] += A[i] - A[i - 1];
		else rpref[i] += A[i] - A[i - 1];
	}
	int ans = pref[N + 1];
	for (int k : con) {
		if (binary_search(A + 1, A + 1 + N, k)) continue;
		int cnt = upper_bound(A + 1, A + 1 + N, k) - A - 1;
		if (cnt <= 0) ans = max(ans, rpref[N + 1] + A[1] - k);
		else ans = max(ans, pref[cnt] + rpref[N + 1] - rpref[cnt + 1] + (cnt & 1 ? 0 : k - A[cnt]) + (cnt & 1 ? A[cnt + 1] - k : 0));
	}
	cout << ans << '\n';
}