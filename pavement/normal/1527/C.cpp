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

int T, N, ans, A[100005];
map<int, vector<int> > vec;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		vec.clear();
		cin >> N;
		for (int i = 1; i <= N; i++) cin >> A[i], vec[A[i]].pb(i);
		ans = 0;
		for (auto i : vec) {
			int p = 0, sump = 0, sump2 = 0;
			for (int j = 0; j < i.second.size(); j++) {
				int gap = (j == (int)i.second.size() - 1 ? N : i.second[j + 1] - 1) - i.second[j] + 1;
				p++;
				int tmp = i.second[j] * p * p - 2 * p * sump - i.second[j] * p + sump2 + sump;
				sump += p * gap;
				sump2 += p * p * gap;
				ans += tmp * gap;
			}
		}
		cout << ans / 2 << '\n';
	}
}