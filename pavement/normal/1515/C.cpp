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

int TC, N, M, X, H[100005], idx[100005], out[100005];
ii T[100005];
multiset<ii> val;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> TC;
	while (TC--) {
		val.clear();
		cin >> N >> M >> X;
		for (int i = 1; i <= N; i++) {
			cin >> H[i];
			T[i] = mp(H[i], i);
		}
		sort(T + 1, T + 1 + N);
		for (int i = 1; i <= N; i++) tie(H[i], idx[i]) = T[i];
		for (int i = 1; i <= M; i++) {
			val.emplace(0, i);
		}
		for (int i = 1; i <= N; i++) {
			out[idx[i]] = val.begin()->second;
			//cout << "PUT " << i << ' ' << val.begin()->second << '\n';
			val.emplace(val.begin()->first + H[i], val.begin()->second);
			val.erase(val.begin());
		}
		if (val.rbegin()->first - val.begin()->first <= X) {
			cout << "YES\n";
			for (int i = 1; i <= N; i++) cout << out[i] << ' ';
			cout << '\n';
		} else {
			cout << "NO\n";
		}
	}
}