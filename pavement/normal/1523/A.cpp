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
typedef tree<iii, null_type, greater<iii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int T, N, M, dst[1005];
bool vis[1005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N >> M;
		char c;
		queue<ii> Q;
		for (int i = 1; i <= N; i++) {
			cin >> c;
			vis[i] = 0;
			dst[i] = LLONG_MAX;
			if (c == '1') dst[i] = 0, Q.emplace(0, i);
		}
		while (!Q.empty()) {
			auto [d, x] = Q.front();
			Q.pop();
			if (d > M || d != dst[x] || (x != 1 && x != N && dst[x - 1] < dst[x] && dst[x] > dst[x + 1])) continue;
			vis[x] = 1;
			if (x != 1 && d + 1 < dst[x - 1]) {
				dst[x - 1] = d + 1;
				Q.emplace(d + 1, x - 1);
			}
			if (x != N && d + 1 < dst[x + 1]) {
				dst[x + 1] = d + 1;
				Q.emplace(d + 1, x + 1);
			}
		}
		for (int i = 1; i <= N; i++)
			cout << (vis[i] ? 1 : 0);
		cout << '\n';
	}
}