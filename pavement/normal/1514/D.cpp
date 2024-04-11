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

int N, Q, A[300005];
vector<int> vec[300005];

int cnt(int v, int l, int r) {
	auto it = upper_bound(vec[v].begin(), vec[v].end(), r);
	if (it == vec[v].begin()) return 0;
	auto it2 = lower_bound(vec[v].begin(), vec[v].end(), l);
	if (it2 == vec[v].end()) return 0;
	return it - it2;
}

int rnd(int x, int y) {
	y = y - x + 1;
	return rng() % y + x;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		vec[A[i]].pb(i);
	}
	for (int i = 1, l, r; i <= Q; i++) {
		int mx = 0;
		cin >> l >> r;
		for (int k = 0; k < 30; k++) {
			int x = rnd(l, r), tmp = cnt(A[x], l, r);
			mx = max(mx, tmp);
		}
		if (mx > (r - l + 2) / 2) {
			int y = (r - l + 1) - mx;
			cout << mx - (y + 1) + 1 << '\n';
		} else cout << "1\n";
	}
}