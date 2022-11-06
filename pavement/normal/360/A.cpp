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

int N, M, t, l, r, d, m, cnt[5005], lim[5005], tmp[5005];
vector<iiii> vec;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) lim[i] = 1e9;
	for (int i = 1; i <= M; i++) {
		cin >> t;
		if (t == 1) {
			cin >> l >> r >> d;
			for (int j = l; j <= r; j++) cnt[j] += d;
			vec.eb(t, l, r, d);
		} else {
			cin >> l >> r >> m;
			for (int j = l; j <= r; j++) lim[j] = min(lim[j], m - cnt[j]);
			vec.eb(t, l, r, m);
		}
	}
	for (int i = 1; i <= N; i++) tmp[i] = lim[i];
	for (auto [t, l, r, d] : vec) {
		if (t == 1) {
			for (int i = l; i <= r; i++) tmp[i] += d;
		} else {
			int tmp2 = LLONG_MIN;
			for (int i = l; i <= r; i++) tmp2 = max(tmp2, tmp[i]);
			if (tmp2 != d) return cout << "NO\n", 0;
		}
	}
	cout << "YES\n";
	for (int i = 1; i <= N; i++)
		cout << lim[i] << ' ';
	cout << '\n';
}