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
typedef double db;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int N, K, M, Q, cc[100005], out[100005], link[100005][4], sz[100005][4], ww[100005][3], L[100005], R[100005];
vector<int> _qu, le[100005], re[100005];
vector<ii> _ed;
stack<tuple<int, int, int, int, int> > rb[3];
stack<iiii> srb;

int find(int x, int p) {
	if (x == link[x][p]) return x;
	return find(link[x][p], p);
}

int lift(int x, int k, int p) {
	if (x == link[x][p] || ww[x][p] > k) return x;
	return lift(link[x][p], k, p);
}

void unite(int a, int b, int t, int p) {
	assert(p <= 2);
	a = find(a, p);
	b = find(b, p);
	if (sz[b][p] > sz[a][p]) swap(a, b);
	rb[p].emplace(sz[a][p], link[b][p], ww[b][p], a, b);
	sz[a][p] += sz[b][p];
	link[b][p] = a;
	ww[b][p] = t;
}

void unite(int a, int b, int p) {
	assert(p == 3);
	a = find(a, p);
	b = find(b, p);
	if (sz[b][p] > sz[a][p]) swap(a, b);
	srb.emplace(sz[a][p], link[b][p], a, b);
	sz[a][p] += sz[b][p];
	link[b][p] = a;
}

void rollback(int p) {
	if (p <= 2) {
		auto [sa, lb, wb, a, b] = rb[p].top();
		sz[a][p] = sa;
		link[b][p] = lb;
		ww[b][p] = wb;
		rb[p].pop();
	} else {
		auto [sa, lb, a, b] = srb.top();
		sz[a][p] = sa;
		link[b][p] = lb;
		srb.pop();
	}
}

void dnc(int l, int r, vector<ii> &ed, vector<int> &qu) {
	if (l >= r || qu.empty()) return;
	int m = (l + r) / 2;
	vector<int> lqu, rqu;
	vector<ii> led, red, cross;
	for (int i = l; i <= r; i++) le[i].clear(), re[i].clear();
	for (auto [u, v] : ed) {
		if (v <= m) re[u].pb(v), led.eb(u, v);
		else if (u > m) le[v].pb(u), red.eb(u, v);
		else cross.eb(u, v);
	}
	while (!rb[1].empty()) rollback(1);
	for (int i = m, curr_cc = 0; i >= l; i--) {
		curr_cc++;
		for (int j : re[i])
			if (find(i, 1) != find(j, 1)) unite(i, j, -i, 1), curr_cc--;
		cc[i] = curr_cc;
	}
	while (!rb[2].empty()) rollback(2);
	for (int i = m + 1, curr_cc = 0; i <= r; i++) {
		curr_cc++;
		for (int j : le[i])
			if (find(i, 2) != find(j, 2)) unite(i, j, i, 2), curr_cc--;
		cc[i] = curr_cc;
	}
	for (auto idx : qu) {
		if (R[idx] <= m) lqu.pb(idx);
		else if (L[idx] > m) rqu.pb(idx);
		else {
			while (!srb.empty()) rollback(3);
			int dec = 0, ru, rv;
			for (auto [u, v] : cross)
				if (L[idx] <= u && v <= R[idx]) {
					ru = lift(u, -L[idx], 1);
					rv = lift(v, R[idx], 2);
					if (find(ru, 3) != find(rv, 3)) {
						unite(ru, rv, 3);
						dec++;
					}
				}
			out[idx] = cc[L[idx]] + cc[R[idx]] - dec;
		}
	}
	dnc(l, m, led, lqu);
	dnc(m + 1, r, red, rqu);
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K >> M;
	for (int i = 1; i <= N; i++)
		for (int k = 1; k <= 3; k++)
			link[i][k] = i, sz[i][k] = 1;
	for (int i = 1, u, v; i <= M; i++) {
		cin >> u >> v;
		if (u > v) swap(u, v);
		_ed.eb(u, v);
	}
	cin >> Q;
	for (int i = 1; i <= Q; i++) {
		cin >> L[i] >> R[i];
		if (L[i] == R[i]) out[i] = 1;
		else _qu.pb(i);
	}
	dnc(1, N, _ed, _qu);
	for (int i = 1; i <= Q; i++) cout << out[i] << '\n';
}