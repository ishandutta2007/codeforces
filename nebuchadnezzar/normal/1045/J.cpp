// Created by Nikolay Budin

#ifdef DEBUG
#  define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ff first
#define ss second
#define szof(x) ((int)x.size())
#ifndef LOCAL
#  define cerr __get_ce
#endif

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef unsigned long long ull;

using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K, typename V> using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;
#ifdef LOCAL
	mt19937 tw(9450189);
#else
	mt19937 tw(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif
uniform_int_distribution<ll> ll_distr;
ll rnd(ll a, ll b) { return ll_distr(tw) % (b - a + 1) + a; }

const ull MOD = 1'000'000'000'000'000'009;

void add(ull& a, ull b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

ull sum(ull a, ull b) {
	add(a, b);
	return a;
}

ull mult(ull a, ull b) {
	ll k = (ll)((long double)a * b / MOD);
	ll r = a * b - MOD * k;
	if (r < 0)
		r += MOD;
	if (r >= MOD)
		r -= MOD;
	return r;
}

ull mpow(ull a, ull b) {
	ull ret = 1;
	while (b) {
		if (b & 1) {
			ret = mult(ret, a);
		}
		a = mult(a, a);
		b /= 2;
	}
	return ret;
}

ull inv(ull num) {
	return mpow(num, MOD - 2);
}

const ull P = 239;
const ull INV_P = inv(P);

const int MAXL = 105;

ull calc_hash(string const& s) {
	ull h = 0;
	for (char c : s) {
		h = sum(mult(h, P), c);
	}
	return h;
}

ull calc_inv_hash(string s) {
	reverse(s.begin(), s.end());
	return calc_hash(s);
}

void solve() {
	int n;
	cin >> n;
	vector<vector<pair<int, char>>> graph(n);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		char c;
		cin >> a >> b >> c;
		--a; --b;
		graph[a].push_back({b, c});
		graph[b].push_back({a, c});
	}

	vector<ull> pp = {1};
	vector<ull> inv_pp = {1};
	for (int i = 0; i < n + 10; ++i) {
		pp.push_back(mult(pp.back(), P));
		inv_pp.push_back(mult(inv_pp.back(), INV_P));
	}

	int bp = 1;
	while (1 << bp < n) {
		++bp;
	}

	vector<int> depth(n);
	vector<vector<int>> binup(bp, vector<int>(n));
	vector<ull> pref_h(n), pref_rh(n);

	function<void(int, int, int)> dfs = [&](int v, int p, int d) {
		depth[v] = d;
		binup[0][v] = p;
		for (int i = 1; i < bp; ++i) {
			binup[i][v] = binup[i - 1][binup[i - 1][v]];
		}
		for (auto to : graph[v]) {
			if (to.ff != p) {
				pref_h[to.ff] = sum(pref_h[v], mult(to.ss, pp[d]));
				pref_rh[to.ff] = sum(mult(pref_rh[v], P), to.ss);
				dfs(to.ff, v, d + 1);
			}
		}
	};

	dfs(0, 0, 0);

	auto get_lca = [&](int a, int b) {
		if (depth[a] > depth[b]) {
			swap(a, b);
		}
		for (int i = bp - 1; i >= 0; --i) {
			if (depth[a] <= depth[b] - (1 << i)) {
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

	auto jump_for = [&](int v, int d) {
		for (int i = bp - 1; i >= 0; --i) {
			if (d >= (1 << i)) {
				d -= 1 << i;
				v = binup[i][v];
			}
		}
		return v;
	};

	vector<vector<vector<tuple<ull, int, int>>>> here(MAXL, vector<vector<tuple<ull, int, int>>>(n));

	int q;
	cin >> q;
	vector<int> ans(q);
	for (int i = 0; i < q; ++i) {
		int a, b;
		string s;
		cin >> a >> b >> s;
		ull sh = calc_hash(s);
		--a; --b;
		int lca = get_lca(a, b);

		if (depth[a] + depth[b] - 2 * depth[lca] < szof(s)) {
			continue;
		}
		int from = a;
		if (depth[a] - depth[lca] >= szof(s)) {
			from = jump_for(a, depth[a] - depth[lca] - szof(s) + 1);
			here[szof(s)][a].push_back({sh, i, 1});
			here[szof(s)][from].push_back({sh, i, -1});
		}

		int to = b;
		if (depth[b] - depth[lca] >= szof(s)) {
			ull rsh = calc_inv_hash(s);
			to = jump_for(b, depth[b] - depth[lca] - szof(s) + 1);
			here[szof(s)][b].push_back({rsh, i, 1});
			here[szof(s)][to].push_back({rsh, i, -1});
		}

		// cerr << from + 1 << " " << to + 1 << endl;

		vector<ull> curh;
		int v = from;
		for (int j = depth[from] - depth[lca]; szof(s) - j <= depth[to] - depth[lca]; --j) {
			ull h = mult(sum(pref_h[v], MOD - pref_h[lca]), inv_pp[depth[lca]]);
			curh.push_back(h);
			v = binup[0][v];
		}
		reverse(curh.begin(), curh.end());
		v = to;
		int cnt = 0;
		for (int j = depth[to] - depth[lca]; szof(s) - j <= depth[from] - depth[lca]; --j) {
			ull h = sum(pref_rh[v], MOD - mult(pref_rh[lca], pp[depth[v] - depth[lca]]));
			ull th = sum(mult(curh[cnt++], pp[depth[v] - depth[lca]]), h);
			if (th == sh) {
				++ans[i];
			}
			v = binup[0][v];
		}
	}

	for (int l = 1; l < MAXL; ++l) {
		unordered_map<ull, int> cnt;
		vector<int> path;
		function<void(int, int)> dfs_calc = [&](int v, int p) {
			path.push_back(v);

			if (szof(path) > l) {
				int u = path[szof(path) - 1 - l];
				ull h = mult(sum(pref_h[v], MOD - pref_h[u]), inv_pp[depth[u]]);
				cnt[h]++;
			}
			// cerr << "v: " << v + 1 << endl;
			for (auto [h, ind, sign] : here[l][v]) {
				// cerr << l << " " << h << " " << ind << " " << sign << endl;
				if (cnt.count(h)) {
					ans[ind] += sign * cnt[h];
					// cerr << sign * cnt[l][h] << endl;
				}
			}

			for (auto to : graph[v]) {
				if (to.ff != p) {
					dfs_calc(to.ff, v);
				}
			}

			if (szof(path) > l) {
				int u = path[szof(path) - 1 - l];
				ull h = mult(sum(pref_h[v], MOD - pref_h[u]), inv_pp[depth[u]]);
				cnt[h]--;
				if (cnt[h] == 0) {
					cnt.erase(h);
				}
			}

			path.pop_back();
		};

		dfs_calc(0, 0);
	}

	for (int num : ans) {
		cout << num << "\n";
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