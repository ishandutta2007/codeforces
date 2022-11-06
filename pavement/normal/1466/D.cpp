#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#ifdef WIN_32
#define getchar_unlocked _getchar_nolock
#endif
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
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int T, N, deg[200005], W[200005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		int cursum = 0;
		for (int i = 1; i <= N; i++) deg[i] = 0, cin >> W[i], cursum += W[i];
		for (int i = 1, u, v; i < N; i++) {
			cin >> u >> v;
			deg[u]++;
			deg[v]++;
		}
		vector<int> tmp;
		for (int i = 1; i <= N; i++)
			for (int j = 1; j < deg[i]; j++) tmp.pb(W[i]);
		sort(tmp.begin(), tmp.end(), greater<int>());
		for (int i = 1; i <= N - 1; i++) {
			cout << cursum << ' ';
			cursum += (tmp.size() >= i ? tmp[i - 1] : 0);
		}
		cout << '\n';
	}
}