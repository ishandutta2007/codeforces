#ifdef LOCAL
#  define _GLIBCXX_DEBUG
#else
#  define cerr __get_ce
#endif
#include <bits/stdc++.h>
#define ff first
#define ss second
#define szof(x) ((int)x.size())

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;
mt19937 tw(9450189);
uniform_int_distribution<ll> ll_distr;
ll rnd(ll a, ll b) { return ll_distr(tw) % (b - a + 1) + a; }

typedef pair<pair<pii, pii>, pair<pii, pii>> T;

vector<pii> tmp_arr(4);

T f(T const& a, T const& b) {
	tmp_arr[0] = a.ff.ff;
	tmp_arr[1] = a.ff.ss;
	tmp_arr[2] = b.ff.ff;
	tmp_arr[3] = b.ff.ss;
	sort(tmp_arr.begin(), tmp_arr.end());
	pair<pii, pii> lowest = {tmp_arr[0], tmp_arr[1]};
	tmp_arr[0] = a.ss.ff;
	tmp_arr[1] = a.ss.ss;
	tmp_arr[2] = b.ss.ff;
	tmp_arr[3] = b.ss.ss;
	sort(tmp_arr.begin(), tmp_arr.end());
	pair<pii, pii> largest = {tmp_arr[3], tmp_arr[2]};
	return {lowest, largest};
}

void solve() {
	int n, q;
	cin >> n >> q;
	vector<vector<int>> graph(n);
	for (int i = 1; i < n; ++i) {
		int p;
		cin >> p;
		--p;
		graph[p].push_back(i);
	}

	vector<int> tin(n), tout(n);

	int t = 0;
	int bp = 0;
	while ((1 << bp) < n) {
		++bp;
	}
	vector<vector<int>> binup(bp, vector<int>(n));
	vector<int> depth(n);

	function<void(int, int, int)> dfs = [&](int v, int p, int d) {
		binup[0][v] = p;
		for (int i = 1; i < bp; ++i) {
			binup[i][v] = binup[i - 1][binup[i - 1][v]];
		}
		depth[v] = d;
		tin[v] = t++;
		for (int to : graph[v]) {
			dfs(to, v, d + 1);
		}
		tout[v] = t;
	};

	dfs(0, 0, 0);

	function<int(int, int)> get_lca = [&](int a, int b) {
		if (depth[a] > depth[b]) {
			swap(a, b);
		}
		for (int i = bp - 1; i >= 0; --i) {
			if (depth[b] - (1 << i) >= depth[a]) {
				b = binup[i][b];
			}
		}
		if (a == b) {
			return a;
		}
		for (int i = bp - 1; i >= 0; --i) {
			if (binup[i][a] != binup[i][b]) {
				a = binup[i][a];
				b = binup[i][b];
			}
		}
		return binup[0][a];
	};

	int bpv = 1;
	while (bpv < n) {
		bpv *= 2;
	}
	vector<T> rmq(bpv * 2);
	for (int i = 0; i < n; ++i) {
		rmq[i + bpv] = {{{tin[i], i}, {INF, -1}}, {{tin[i], i}, {-INF, -1}}};
		// cerr << i << " " << tout[i] << " " << tin[i] << endl;
	}
	for (int i = bpv - 1; i; --i) {
		rmq[i] = f(rmq[i * 2], rmq[i * 2 + 1]);
	}

	// cerr << rmq[bpv + 1].ff.ff.ff << " " << rmq[bpv + 1].ff.ff.ss << " " << rmq[bpv + 1].ff.ss.ff << " " << rmq[bpv + 1].ff.ss.ss << endl;

	function<T(int, int, int, int, int)> segtree_get = [&](int v, int vl, int vr, int l, int r) {
		if (vr <= l || r <= vl) {
			return make_pair(make_pair(make_pair(INF, -1), make_pair(INF, -1)), make_pair(make_pair(-INF, -1), make_pair(-INF, -1)));
		}
		if (l <= vl && vr <= r) {
			return rmq[v];
		}
		int vm = (vl + vr) / 2;
		return f(segtree_get(v * 2, vl, vm, l, r), segtree_get(v * 2 + 1, vm, vr, l, r));
	};

	for (int j = 0; j < q; ++j) {
		int l, r;
		cin >> l >> r;
		--l;
		// cerr << l << " " << r << endl;
		auto tmp = segtree_get(1, 0, bpv, l, r);
		// cerr << tmp.ff.ff.ff << " " << tmp.ff.ff.ss << endl;
		pii ans = {depth[get_lca(tmp.ff.ss.ss, tmp.ss.ff.ss)], tmp.ff.ff.ss};
		ans = max(ans, {depth[get_lca(tmp.ff.ff.ss, tmp.ss.ss.ss)], tmp.ss.ff.ss});
		cout << ans.ss + 1 << " " << ans.ff << "\n";
	}
}


int main() {
#ifdef LOCAL
	auto start_time = clock();
	cerr << setprecision(3) << fixed;
#endif
	cout << setprecision(15) << fixed;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int test_count = 1;
	// cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}
	
#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}