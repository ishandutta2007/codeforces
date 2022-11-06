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

int T, N;
bool vis[1445][105], cannot[1445][105];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		memset(cannot, 0, sizeof cannot);
		memset(vis, 0, sizeof vis);
		cin >> N;
		int R = -1;
		char C;
		for (int i = 1, r, t1, t2, r1, r2, t; i <= N; i++) {
			cin >> C;
			if (C == 'C') {
				cin >> r >> t1 >> t2;
				r *= 4;
				R = max(R, r);
				t1 *= 4;
				t2 *= 4;
				while (t1 != t2) {
					cannot[t1][r] = 1;
					t1 = (t1 + 1) % 1440;
				}
				cannot[t2][r] = 1;
			} else {
				cin >> r1 >> r2 >> t;
				t *= 4;
				r1 *= 4;
				r2 *= 4;
				for (int j = r1; j <= r2; j++)
					cannot[t][j] = 1;
			}
		}
		if (R == -1) {
			cout << "YES\n";
			continue;
		}
		queue<ii> Q;
		Q.emplace(0, 0);
		bool can = 0;
		while (!Q.empty()) {
			auto [ang, rad] = Q.front();
			Q.pop();
			if (cannot[ang][rad]) continue;
			if (rad > R) {
				can = 1;
				break;
			}
			for (int k : {-1, 1}) {
				int nang = ang + k;
				nang = (nang % 1440 + 1440) % 1440;
				if (!vis[nang][rad]) {
					vis[nang][rad] = 1;
					Q.emplace(nang, rad);
				}
				int nrad = rad + k;
				if (nrad >= 0 && !vis[ang][nrad]) {
					vis[ang][nrad] = 1;
					Q.emplace(ang, nrad);
				}
			}
		}
		cout << (can ? "YES" : "NO") << '\n';
	}
}