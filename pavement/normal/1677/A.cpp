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

int T, N, P[5005], cnt[5005][5005], cnt2[5005][5005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 1; i <= N; i++) cin >> P[i];
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= i; j++) cnt[i][P[j]]++;
			for (int j = 1; j <= N; j++) cnt[i][j] += cnt[i][j - 1];
		}
		for (int i = 1; i <= N; i++) {
			for (int j = i; j <= N; j++) cnt2[i][P[j]]++;
			for (int j = 1; j <= N; j++) cnt2[i][j] += cnt2[i][j - 1];
		}
		ll ans = 0;
		for (int i = 1; i <= N; i++)
			for (int j = i + 1; j <= N; j++)
				ans += (ll)cnt[i - 1][P[j] - 1] * (ll)cnt2[j + 1][P[i] - 1];
		cout << ans << '\n';
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				cnt[i][j] = cnt2[i][j] = 0;
	}
}