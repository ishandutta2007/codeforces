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

int T, N, M, G, ans, A[1000005];
vector<int> vec[500005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		G = 0;
		ans = LLONG_MIN;
		cin >> N >> M;
		for (int i = 0; i < N; i++) cin >> A[i];
		for (int i = 1, B; i <= M; i++) {
			cin >> B;
			G = __gcd(G, B);
		}
		for (int i = 0; i < N; i++) vec[i % G].pb(A[i]);
		int case0 = 0, case1 = 0;
		for (int i = 0; i < G; i++) {
			sort(vec[i].begin(), vec[i].end());
			int tot = 0;
			for (int j : vec[i]) tot += j;
			int cur0 = tot, cur1 = LLONG_MIN;
			for (int j = 0, pf = 0; j < vec[i].size(); j++) {
				pf += vec[i][j];
				if ((j + 1) % 2 == 0) cur0 = max(cur0, tot - 2 * pf);
				else cur1 = max(cur1, tot - 2 * pf);
			}
			case0 += cur0;
			case1 += cur1;
		}
		cout << max(case0, case1) << '\n';
		for (int i = 0; i < G; i++) vec[i].clear();
	}
}