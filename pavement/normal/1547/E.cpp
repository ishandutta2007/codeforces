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

int Q, N, K, a[300005], ans[300005], c[300005], t[300005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> Q;
	while (Q--) {
		cin >> N >> K;
		for (int i = 1; i <= N; i++) c[i] = 0;
		for (int i = 1; i <= K; i++) cin >> a[i];
		for (int i = 1; i <= K; i++) cin >> t[i];
		for (int i = 1; i <= K; i++) c[a[i]] = t[i];
		for (int i = 1, pf = 1e16; i <= N; i++) {
			if (c[i]) pf = min(pf, c[i] - i);
			ans[i] = pf + i;
		}
		for (int i = N, sf = 1e16; i >= 1; i--) {
			if (c[i]) sf = min(sf, c[i] + i);
			ans[i] = min(ans[i], sf - i);
		}
		for (int i = 1; i <= N; i++) cout << ans[i] << ' ';
		cout << '\n';
	}
}