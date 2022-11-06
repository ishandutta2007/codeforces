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

int T, N, K;
vector<int> vec;
bitset<2005> canmake;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N >> K;
		vec.clear();
		int curr = 0;
		for (int i = K + 1; i <= N; i++) vec.pb(i);
		canmake.reset();
		canmake[0] = 1;
		for (int i = K - 1; i >= 1; i--) {
			canmake |= (canmake << i);
			if (canmake[K]) break;
			vec.pb(i);
		}
		cout << vec.size() << '\n';
		for (int i : vec) cout << i << ' ';
		cout << '\n';
	}
}