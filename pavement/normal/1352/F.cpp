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

int T, N0, N1, N2;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N0 >> N1 >> N2;
		string s = "";
		for (int i = 0; i < N0; i++) s.pb('0');
		if (N0) {
			for (int i = 0; i <= N1; i++)
				if (i & 1) s.pb('1');
				else s.pb('0');
		} else {
			for (int i = 0; i <= N1; i++)
				if (i & 1) s.pb('0');
				else s.pb('1');
		}
		if (N2) {
			bool can = 0;
			if (s.back() == '0') {
				s.ppb();
				can = 1;
			}
			for (int i = 0; i < N2; i++) s.pb('1');
			if (can) s.pb('0');
		}
		cout << s << '\n';
	}
}