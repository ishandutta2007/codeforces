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

int T, N, K;
char S[100005], OS[100005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N >> K;
		int ones = 0;
		for (int i = 1; i <= N; i++) {
			cin >> S[i];
			OS[i] = S[i];
			ones += S[i] == '1';
		}
		int ans = 1e16, OK = K;
		for (int i = 0; i < 4; i++) {
			bool inv = 0;
			K = OK;
			for (int j = 1; j <= N; j++)
				S[j] = OS[j];
			if (i & 1) {
				int pos = -1;
				for (int j = 1; j <= N; j++)
					if (S[j] == '1') {
						pos = j;
						break;
					}
				if (pos != -1) {
					K -= pos - 1;
					S[pos] = '0';
					S[1] = '1';
				} else inv = 1;
			}
			if (i & 2) {
				int pos = -1;
				for (int j = N; j >= 1; j--)
					if (S[j] == '1') {
						pos = j;
						break;
					}
				if (pos != -1 && !(pos == 1 && (i & 1))) {
					K -= N - pos;
					S[pos] = '0';
					S[N] = '1';
				} else inv = 1;
			}
			inv |= K < 0;
			if (!inv) ans = min(ans, ones * 11 - ((i & 1) ? 1 : 0) - ((i & 2) ? 10 : 0));
		}
		cout << (ans == (int)1e16 ? 0 : ans) << '\n';
	}
}