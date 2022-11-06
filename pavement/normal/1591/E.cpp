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

int T, N, Q, A[1000005], frq[1000005], out[1000005], ft[1000005];
set<int> onec[1000005];
vector<int> adj[1000005];
vector<iii> vec[1000005];

inline int ls(int x) { return x & -x; }

void upd(int p, int v) {
	for (; p <= N; p += ls(p)) ft[p] += v;
}

int qry(int p) {
	int r = 0;
	for (; p; p -= ls(p)) r += ft[p];
	return r;
}

void dfs(int n) {
	if (frq[A[n]]) {
		assert(onec[frq[A[n]]].count(A[n]));
		onec[frq[A[n]]].erase(A[n]);
		upd(frq[A[n]], -1);
	}
	frq[A[n]]++;
	assert(!onec[frq[A[n]]].count(A[n]));
	onec[frq[A[n]]].insert(A[n]);
	upd(frq[A[n]], 1);
	for (auto [i, l, kk] : vec[n]) {
		int cc = qry(l - 1), curr = 0, rs = 0;
		if (qry(N) - cc < kk) {
			out[i] = -1;
			continue;
		}
		for (int k = (1ll << 19ll); k; k >>= 1ll)
			if (curr + k <= N && rs + ft[curr + k] - cc < kk) {
				rs += ft[curr + k];
				curr += k;
			}
		curr++;
		assert(curr <= N);
		//for (int j = 1; j <= N; j++) cout << qry(j) << ' ';
		//cout << '\n';
		//cout << cc << ' ' << i << ' ' << l << ' ' << kk << " FOUND " << curr << '\n';
		//cout << qry(curr) << ' ' << kk << '\n';
		assert(qry(curr) - cc >= kk);
		//onec[curr].clear();
		if (onec[curr].empty()) while(1){}
		out[i] = *onec[curr].begin();
	}
	for (auto u : adj[n]) dfs(u);
	assert(onec[frq[A[n]]].count(A[n]));
	onec[frq[A[n]]].erase(A[n]);
	upd(frq[A[n]], -1);
	frq[A[n]]--;
	if (frq[A[n]]) {
		assert(!onec[frq[A[n]]].count(A[n]));
		onec[frq[A[n]]].insert(A[n]);
		upd(frq[A[n]], 1);
	}
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N >> Q;
		for (int i = 0; i <= max(N, Q); i++) {
			ft[i] = A[i] = out[i] = frq[i] = 0;
			onec[i].clear();
			adj[i].clear();
			vec[i].clear();
		}
		for (int i = 1; i <= N; i++) cin >> A[i];
		for (int i = 2, p; i <= N; i++) {
			cin >> p;
			adj[p].pb(i);
		}
		for (int i = 1, v, l, k; i <= Q; i++) {
			cin >> v >> l >> k;
			vec[v].eb(i, l, k);
		}
		dfs(1);
		for (int i = 1; i <= Q; i++) cout << out[i] << ' ';
		cout << '\n';
		for (int i = 0; i <= max(N, Q); i++) {
			ft[i] = A[i] = out[i] = frq[i] = 0;
			onec[i].clear();
			adj[i].clear();
			vec[i].clear();
		}
	}
}