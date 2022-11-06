#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#ifdef TEST
#define getchar_unlocked _getchar_nolock
#endif
#define int long long
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
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int spf[1000005];
bitset<1000005> bs;

main() {
	bs.set();
	bs[0] = bs[1] = 0;
	for (int i = 1; i <= 1e6; i++) spf[i] = i;
	for (int i = 2; i <= 1e6; i++) {
		if (bs[i])
			for (int j = i + i; j <= 1e6; j += i) {
				if (bs[j]) spf[j] = i;
				bs[j] = 0;
			}
	}
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T, N, K;
	cin >> T;
	while (T--) {
		cin >> N >> K;
		while (N & 1)
			N += spf[N], K--;
		cout << N + K * 2 << '\n';
	}
}