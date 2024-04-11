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
using db = double;
using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using iiii = tuple<int, int, int, int>;
template<class key, class value = null_type, class cmp = less<key> >
using ordered_set = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

int T, N, P[205];
char S[205];
bool vis[205];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		int ans = 1;
		for (int i = 1; i <= N; i++) cin >> S[i];
		for (int i = 1; i <= N; i++) {
			cin >> P[i];
			vis[i] = 0;
		}
		for (int i = 1; i <= N; i++) {
			if (vis[i]) continue;
			int pos = i, len = 0;
			string tmp = "", tmp2;
			do {
				vis[pos] = 1;
				tmp.pb(S[pos]);
				pos = P[pos];
			} while (pos != i);
			tmp2 = tmp;
			int can = -1;
			for (int i = 1; i <= tmp.size(); i++) {
				string tmp3 = tmp2.substr(1, tmp.size() - 1);
				tmp3.pb(tmp2[0]);
				tmp2 = tmp3;
				if (tmp2 == tmp) {
					can = i;
					break;
				}
			}
			assert(can != -1);
			ans = ans / __gcd(ans, can) * can;
		}
		cout << ans << '\n';
	}
}