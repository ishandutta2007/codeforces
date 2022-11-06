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

int N, K, ans = LLONG_MIN, curr, cnt, C[500005], AC[500005], SC[500005], P[500005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	K++;
	for (int i = 1; i <= N; i++) cin >> C[i];
	sort(C + 1, C + 1 + N);
	for (int i = N; i >= 1; i--) {
		SC[i] = SC[i + 1] + C[i];
		AC[i] = AC[i + 1] + i * C[i];
		P[i] = AC[i] - SC[i] * i;
	}
	for (int i = 1; i <= N; i++) {
		ans = max(ans, curr + P[i] + SC[i] * ((cnt + K - 1) / K));
		curr += cnt / K * C[i];
		cnt++;
	}
	ans = max(ans, curr);
	cout << ans << '\n';
}