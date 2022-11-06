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
typedef tuple<int, int, int, int> iiii;
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int N, X[200005], Y[200005], rev[400005];
string ins[200005];
set<ii> ft[400005];
iii T[400005];

inline int ls(int x) { return x & -x; }

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int X, Y, i = 1; i <= N; i++) {
		cin >> ins[i] >> X >> Y;
		T[(i << 1) - 1] = mt(X, 1, i);
		T[i << 1] = mt(Y, 0, i);
	}
	sort(T + 1, T + 1 + (N << 1));
	g0(T[0]) = -1e16;
	for (int i = 1, cnt = 0; i <= N << 1; i++) {
		cnt += g0(T[i - 1]) != g0(T[i]);
		rev[cnt] = g0(T[i]);
		if (g1(T[i])) X[g2(T[i])] = cnt;
		else Y[g2(T[i])] = cnt;
	}
	for (int i = 1; i <= N; i++) {
		if (ins[i] == "add") {
			for (int cy = (N << 1) - Y[i] + 1; cy <= N << 1; cy += ls(cy)) ft[cy].emplace(X[i], Y[i]);
		} else if (ins[i] == "remove") {
			for (int cy = (N << 1) - Y[i] + 1; cy <= N << 1; cy += ls(cy)) ft[cy].erase(mp(X[i], Y[i]));
		} else {
			ii r = mp((int)1e9, (int)1e9);
			for (Y[i] = (N << 1) - Y[i]; Y[i]; Y[i] -= ls(Y[i])) {
				auto it = ft[Y[i]].upper_bound(mp(X[i], (int)1e9));
				if (it != ft[Y[i]].end()) r = min(r, *it);
			}
			if (r.first == 1e9) cout << "-1\n";
			else cout << rev[r.first] << ' ' << rev[r.second] << '\n';
		}
	}
}