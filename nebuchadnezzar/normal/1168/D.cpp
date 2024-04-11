// Created by Nikolay Budin

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
typedef unsigned long long ull;
int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;
#ifdef LOCAL
	mt19937 tw(9450189);
#else
	mt19937 tw(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif
uniform_int_distribution<ll> ll_distr;
ll rnd(ll a, ll b) { return ll_distr(tw) % (b - a + 1) + a; }

int get_ind(char c) {
	return c - 'a';
}

void solve() {
	int n, q;
	cin >> n >> q;
	vector<vector<pair<int, char>>> graph(n);
	vector<char> was_chars(n);
	for (int i = 0; i < n - 1; ++i) {
		int p;
		char c;
		cin >> p >> c;
		--p;
		graph[p].push_back({i + 1, c});
		was_chars[i + 1] = c;
	}

	int leafs_depth = -1;

	vector<int> who_par(n);
	vector<int> lr_anc(n);
	vector<vector<vector<ll>>> node_cnt(n);
	vector<vector<vector<ll>>> on_edge(n);
	int lr_flag = 0;
	vector<ll> cur_cnt(26);
	vector<int> depth(n);
	vector<int> is_ok(n);
	vector<int> sum_here(n);

	vector<vector<int>> anc(n);

	function<void(int, int, int)> dfs = [&](int v, int d, int p) {
		depth[v] = d;
		if (szof(graph[v]) == 0) {
			if (leafs_depth == -1) {
				leafs_depth = d;
			} else {
				if (leafs_depth != d) {
					for (int i = 0; i < q; ++i) {
						cout << "Fou\n";
					}
					exit(0);
				}
			}
		}

		if (szof(graph[v]) == 2 || v == 0) {
			node_cnt[v] = on_edge[v] = vector<vector<ll>>(szof(graph[v]));
		}

		who_par[v] = p;
		lr_anc[v] = lr_flag;

		if (v == 0) {
			int tmp = 0;
			for (pii to : graph[v]) {
				lr_flag = tmp++;
				if (to.ss != '?') {
					cur_cnt[get_ind(to.ss)]++;
				}
				dfs(to.ff, d + 1, v);
			}
			for (int i = 0; i < 26; ++i) {
				sum_here[v] += max(node_cnt[v][0][i], node_cnt[v][szof(graph[v]) - 1][i]);
			}
			is_ok[v] = sum_here[v] <= (leafs_depth - depth[v]);
			for (int to : anc[v]) {
				is_ok[v] &= is_ok[to];
			}
			return;
		}

		if (szof(graph[v]) == 1) {
			if (graph[v][0].ss != '?') {
				cur_cnt[get_ind(graph[v][0].ss)]++;
			}
			dfs(graph[v][0].ff, d + 1, p);
			return;
		}

		auto& par_cnt = node_cnt[p][lr_flag];
		on_edge[p][lr_flag] = cur_cnt;
		par_cnt = cur_cnt;
		anc[p].push_back(v);

		fill(cur_cnt.begin(), cur_cnt.end(), 0);

		if (!szof(graph[v])) {
			is_ok[v] = true;
			return;
		}

		int tmp = 0;
		for (pii to : graph[v]) {
			lr_flag = tmp++;
			if (to.ss != '?') {
				cur_cnt[get_ind(to.ss)]++;
			}
			dfs(to.ff, d + 1, v);
		}

		for (int i = 0; i < 26; ++i) {
			sum_here[v] += max(node_cnt[v][0][i], node_cnt[v][1][i]);
		}
		is_ok[v] = sum_here[v] <= (leafs_depth - depth[v]);
		for (int to : anc[v]) {
			is_ok[v] &= is_ok[to];
		}

		for (int i = 0; i < 26; ++i) {
			par_cnt[i] += max(node_cnt[v][0][i], node_cnt[v][1][i]);
		}
	};

	dfs(0, 0, -1);

	for (int i = 0; i < q; ++i) {
		int v;
		char c;
		cin >> v >> c;
		--v;
		vector<int> changed;
		{
			int par = who_par[v];
			auto& par_cnt = node_cnt[par][lr_anc[v]];
			auto& on_edge_par = on_edge[par][lr_anc[v]];
			if (was_chars[v] != '?') {
				int ind = get_ind(was_chars[v]);
				par_cnt[ind]--;
				on_edge_par[ind]--;
				changed.push_back(ind);
			}
			if (c != '?') {
				int ind = get_ind(c);
				par_cnt[ind]++;
				on_edge_par[ind]++;
				changed.push_back(ind);
			}

			sum_here[par] = 0;
			for (int j = 0; j < 26; ++j) {
				sum_here[par] += max(node_cnt[par][0][j], node_cnt[par][szof(graph[par]) - 1][j]);
			}

			is_ok[par] = (sum_here[par] <= leafs_depth - depth[par]);
			for (int u : anc[par]) {
				is_ok[par] &= is_ok[u];
			}

			sort(changed.begin(), changed.end());
			changed.erase(unique(changed.begin(), changed.end()), changed.end());
			was_chars[v] = c;
			v = par;
		}
		while (v != 0) {
			int par = who_par[v];
			auto& par_cnt = node_cnt[par][lr_anc[v]];
			auto& on_edge_par = on_edge[par][lr_anc[v]];
			for (int ind : changed) {
				sum_here[par] -= max(node_cnt[par][0][ind], node_cnt[par][szof(graph[par]) - 1][ind]);
				par_cnt[ind] = on_edge_par[ind] + max(node_cnt[v][0][ind], node_cnt[v][1][ind]);
				sum_here[par] += max(node_cnt[par][0][ind], node_cnt[par][szof(graph[par]) - 1][ind]);
			}

			is_ok[par] = (sum_here[par] <= leafs_depth - depth[par]);
			for (int u : anc[par]) {
				is_ok[par] &= is_ok[u];
			}

			v = par;
		}

		if (!is_ok[0]) {
			cout << "Fou\n";
		} else {
			cout << "Shi ";
			ll ans = 0;
			for (int j = 0; j < 26; ++j) {
				ans += (j + 1) * (max(node_cnt[0][0][j], node_cnt[0][szof(graph[0]) - 1][j]) + leafs_depth - sum_here[0]);
			}

			cout << ans << "\n";
		}
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