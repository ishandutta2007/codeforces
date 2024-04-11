#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#ifdef _WIN32
#define getchar_unlocked _getchar_nolock
#endif
//#define int long long
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

int T, N, M, ans[4000005], rem[4000005], cls[4000005], mss[4000005], minus2[4000005];
char S[4000005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N >> M;
		for (int i = 1; i <= N * M; i++)
			cin >> S[i + N * M];
		for (int i = 1; i <= N * M; i++)
			S[i] = '0';
		for (int i = 1, prv = 0, add = 0; i <= 2 * N * M; i++) {
			if (S[i] == '1') {
				prv = i;
				cls[i % M] = i;
			} else {
				if (i - (N - 1) * M >= 1 && cls[i % M] < i - (N - 1) * M) {
					add++;
					if (i + M <= 2 * N * M) minus2[i + M]++;
				}
				if (i - prv >= M) {
					rem[i % M]++;
					if (i + N * M <= 2 * N * M) mss[i + N * M]++;
				}
			}
			rem[i % M] -= mss[i];
			add -= minus2[i];
			ans[i] = N + M - rem[i % M] - add;
		}
		for (int i = 1; i <= N * M; i++) cout << ans[i + N * M] << ' ';
		cout << '\n';
		for (int i = 0; i <= 2 * N * M; i++) {
			ans[i] = 0;
			rem[i] = 0;
			cls[i] = 0;
			S[i] = 0;
			mss[i] = minus2[i] = 0;
		}
	}
}