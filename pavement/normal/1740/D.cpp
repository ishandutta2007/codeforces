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

int T, N, M, K, A[100005], p[100005], ft[100005];

int ls(int x) { return x & -x; }

int qry(int p) {
	int r = 0;
	for (; p; p -= ls(p)) r += ft[p];
	return r;
}

void upd(int p, int v) {
	for (; p <= K; p += ls(p)) ft[p] += v;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N >> M >> K;
		for (int i = 1; i <= K; i++) {
			cin >> A[i];
			p[A[i]] = i;
		}
		int l = N + M - 3;
		for (int i = 1; i <= K; i++) {
			ft[i] = 1;
		}
		for (int i = 1; i <= K; i++) {
			if (i + ls(i) <= K) ft[i + ls(i)] += ft[i];
		}
		bool cannot = 0;
		//~ cout << N * M - l << '\n';
		for (int i = K; i >= 1; i--) {
			//~ cout << p[i] << ' ' << qry(p[i] - 1) << '\n';
			if (qry(p[i] - 1) > N * M - 4) {
				cannot = 1;
				//~ cout << i << '\n';
			}
			upd(p[i], -1);
		}
		if (cannot) cout << "TIDAK\n";
		else cout << "YA\n";
	}
}