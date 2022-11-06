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
#define g4(a) get<4>(a)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using db = double;
using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using iiii = tuple<int, int, int, int>;
template<class key, class value = null_type, class cmp = less<key> >
using ordered_set = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

int T, N, H[100005], V[100005], P[100005], S[100005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> H[i];
		}
		int ans = LLONG_MAX;
		for (int i = 2; i < N; i++) {
			V[i] = max(0ll, max(H[i - 1], H[i + 1]) + 1 - H[i]);
			P[i] = P[i - 1] + (i % 2 == 0 ? V[i] : 0ll);
		}
		for (int i = N - 1; i > 1; i--)
			S[i] = S[i + 1] + ((N - 1 - i) % 2 == 0 ? V[i] : 0ll);
		for (int i = 1; i < N; i++)
			ans = min(ans, P[i] + S[i + 1]);
		for (int i = 1; i <= N; i++) {
			P[i] = S[i] = 0;
		}
		cout << ans << '\n';
	}
}