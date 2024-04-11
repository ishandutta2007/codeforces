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
using iii = tuple<int, int, ll>;
using iiii = tuple<int, int, int, int>;
template<class key, class value = null_type, class cmp = less<key> >
using ordered_set = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

const ll BIG = 1e13;
int N, Q;
ll ans = LLONG_MIN, P[4][500005], U[500005], V[500005], dist[500005];
vector<pair<int, ll> > adj[500005];
map<ii, int> mpp;
priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int>> > pq;

void simplify(vector<iii> &v) {
	mpp.clear();
	for (auto [l, r, k] : v) {
		if (mpp.find(mp(l, r)) == mpp.end()) mpp[mp(l, r)] = k;
		else mpp[mp(l, r)] = min((int)mpp[mp(l, r)], (int)k);
	}
	vector<iii> ret;
	for (auto i : mpp)
		ret.eb(i.first.first, i.first.second, i.second);
	v = ret;
}

void dnc(int l, int r, vector<iii> &v) {
	simplify(v);
	if (l >= r || v.empty()) return;
	int m = (l + r) >> 1;
	vector<iii> lv, rv;
	for (auto x : v) {
		if (g1(x) <= m) lv.pb(x);
		else if (g0(x) > m) rv.pb(x);
		else lv.eb(g0(x), m, g2(x)), rv.eb(m + 1, g1(x), g2(x));
		adj[g0(x)].eb(g1(x), g2(x));
	}
	for (int i = l; i <= m; i++)
		adj[N + 1].eb(i, -U[i] + BIG);
	for (int i = m + 1; i <= r; i++)
		adj[i].eb(N + 2, -V[i] + BIG);
	dist[N + 1] = 0;
	dist[N + 2] = 1e16;
	for (int i = l; i <= r; i++) dist[i] = 1e16;
	for (int i = l + 1; i <= r; i++) adj[i].eb(i - 1, 0);
	pq.emplace(0, N + 1);
	while (!pq.empty()) {
		auto [d, u] = pq.top();
		pq.pop();
		if (d != dist[u]) continue;
		// cout << "DIST " << u << ' ' << d << '\n';
		for (auto [v, w] : adj[u])
			if (dist[v] > d + w) {
				// cout << "UPD " << v << ' ' << u << ' ' << w << '\n';
				dist[v] = d + w;
				pq.emplace(dist[v], v);
			}
	}
	// cout << l << ' ' << r << ' ' << m << ": " << -(dist[N + 2] - 2 * BIG) << '\n';
	ans = max(ans, -(dist[N + 2] - 2 * BIG));
	for (int i = l; i <= r; i++) adj[i].clear();
	adj[N + 1].clear();
	adj[N + 2].clear();
	dnc(l, m, lv);
	dnc(m + 1, r, rv);
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> Q;
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= N; j++) {
			cin >> P[i][j];
			P[i][j] += P[i][j - 1];
		}
	for (int i = 1; i <= N; i++) {
		U[i] = P[1][i] - P[2][i - 1];
		V[i + 1] = P[2][i] - P[3][i - 1] + P[3][N];
		// cout << "@ " << i << ": " << U[i] << ' ' << V[i] << '\n';
	}
	vector<iii> tmp;
	for (int i = 1, L, R, K; i <= Q; i++) {
		cin >> L >> R >> K;
		R++;
		tmp.eb(L, R, K);
	}
	N++;
	dnc(1, N, tmp);
	cout << ans << '\n';
}