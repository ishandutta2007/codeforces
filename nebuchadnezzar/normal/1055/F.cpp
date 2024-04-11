#ifdef LOCAL
//#  define _GLIBCXX_DEBUG
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

void solve() {
	int n;
	ll k;
	cin >> n >> k;
	vector<ll> vals;
	vector<vector<pii>> graph(n);
	for (int i = 0; i < n - 1; ++i) {
		int p;
		ll w;
		cin >> p >> w;
		vals.push_back(w);
		--p;
		graph[p].push_back({i + 1, i});
		graph[i + 1].push_back({p, i});
	}

	// vector<int> sz(n);
	// vector<int> best(n);
	// vector<int> visited;
	// vector<bool> used(n);

	// function<void(int, int)> calc_sz = [&](int v, int p) {
	// 	visited.push_back(v);
	// 	sz[v] = 1;
	// 	best[v] = 0;
	// 	for (pii to : graph[v]) {
	// 		if (!used[to.ff] && to.ff != p) {
	// 			calc_sz(to.ff, v);
	// 			sz[v] += sz[to.ff];
	// 			best[v] = max(best[v], sz[to.ff]);
	// 		}
	// 	}
	// };

	// vector<ll> masks;
	// unordered_map<ll, int> have;
	// ll rmask;
	// int rshift;


	// function<ll(int, int, ll)> dfs = [&](int v, int p, ll curmask) {
	// 	ll ret = 0;
	// 	if (have.count(rmask ^ curmask)) {
	// 		ret += have[rmask ^ curmask] * 2;
	// 	}
	// 	masks.push_back(curmask);
	// 	for (pii to : graph[v]) {
	// 		if (to.ff != p && !used[to.ff]) {
	// 			ret += dfs(to.ff, v, curmask ^ (vals[to.ss] >> rshift));
	// 		}
	// 	}
	// 	return ret;
	// };

	/*
	function<ll(int)> rec = [&](int v) {
		visited.clear();
		calc_sz(v, v);
		int tbest = INF;
		for (int u : visited) {
			best[u] = max(best[u], szof(visited) - sz[u]);
			if (tbest > best[u]) {
				tbest = best[u];
				v = u;
			}
		}

		used[v] = true;
		have.clear();
		have[0]++;
		ll ret = 0;
		if (rmask == 0) {
			++ret;
		}
		for (pii to : graph[v]) {
			if (!used[to.ff]) {
				masks.clear();
				ret += dfs(to.ff, to.ff, vals[to.ss] >> rshift);
				for (auto num : masks) {
					have[num]++;
				}
			}
		}

		for (pii to : graph[v]) {
			if (!used[to.ff]) {
				ret += rec(to.ff);
			}
		}

		return ret;
	};
	*/

	vector<ll> path_xor(n);

	function<void(int, int, ll)> dfs = [&](int v, int p, ll mask) {
		path_xor[v] = mask;
		for (auto to : graph[v]) {
			if (to.ff != p) {
				dfs(to.ff, v, mask ^ vals[to.ss]);
			}
		}
	};

	dfs(0, 0, 0);
	sort(path_xor.begin(), path_xor.end());
	vector<ll> xored_arr = path_xor;

	vector<map<ll, ll>> mem(63);

	int cnt = 0;
	ll prev = 0;
	function<ll(int, ll)> calc_eq = [&](int shift, ll mask) {
		// cerr << shift << " " << mask << endl;
		if (mem[shift].count(mask)) {
			return mem[shift][mask];
		}

		// rmask = mask;
		// rshift = shift;
		// fill(used.begin(), used.end(), 0);
		// cerr << "run" << endl;
		++cnt;
		// ll ret = rec(0);
		// cerr << shift << " " << mask << endl;
		assert((mask >> 2) == (prev >> 1) && (mask & 1) == 0);
		prev = mask;
		ll ret = 0;
		// if (mask == 0) {
		// 	ret += n;
		// }
		int c = 0;
		if (mask & 2) {
			while (c < n) {
				ll cur = xored_arr[c] >> (shift + 1);
				int from = c;
				while (c < n && (xored_arr[c] >> (shift + 1)) == cur) {
					++c;
				}
				int mid = c;
				while (c < n && (xored_arr[c] >> (shift + 1)) == (cur ^ 1)) {
					++c;
				}
				int to = c;
				rotate(xored_arr.begin() + from, xored_arr.begin() + mid, xored_arr.begin() + to);
			}
		}
		for (int i = 0; i < n - 1; ++i) {
			assert(((xored_arr[i] >> shift) ^ mask) <= ((xored_arr[i + 1] >> shift) ^ mask));
		}
		// for (auto num : xored_arr) {
		// 	cerr << num << " ";
		// }
		// cerr << endl;
		int c1 = 0, c2 = 0;
		while (c1 < n) {
			int from1 = c1;
			ll cur = path_xor[c1] >> shift;
			while (c1 < n && (path_xor[c1] >> shift) == cur) {
				++c1;
			}
			while (c2 < n && ((xored_arr[c2] >> shift) ^ mask) < cur) {
				++c2;
			}
			int from2 = c2;
			while (c2 < n && ((xored_arr[c2] >> shift) ^ mask) == cur) {
				++c2;
			}

			// cerr << "pair " << c1 - from1 << " " << c2 - from2 << endl;
			ret += (ll) (c1 - from1) * (c2 - from2);
		}
		// cerr << "ret " << ret << endl;
		return mem[shift][mask] = ret;
	};

	function<ll(ll)> calc = [&](ll mask) {
		ll ret = 0;
		for (int i = 0; i < 62; ++i) {
			if (mask & (1ll << i)) {
				ret += calc_eq(i, (mask >> i) ^ 1);
			}
		}
		return ret;
	};

	// cerr << calc(2) << endl;
	// return;
	ll mask = 0;
	for (int i = 61; i >= 0; --i) {
		mask |= 1ll << i;
		if (calc(mask) >= k) {
			mask ^= 1ll << i;
		}
	}

	cout << mask << "\n";
	// cerr << cnt << endl;
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