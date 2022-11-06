#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#ifdef TEST
#define getchar_unlocked _getchar_nolock
#endif
#define ins insert
#define int long long
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

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T, N, K;
	cin >> T;
	while (T--) {
		cin >> N >> K;
		vector<ii> fac;
		for (int i = 1; i * i <= N; i++)
			if (N % i == 0)
				fac.eb(i, N / i), fac.eb(N / i, i);
		int ans = LLONG_MAX;
		for (auto i : fac)
			if (i.first <= K) ans = min(ans, i.second);
		cout << ans << '\n';
	}
}