// Created by Nikolay Budin

#ifdef DEBUG
#  define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
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
int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;
#ifdef LOCAL
	mt19937 tw(9450189);
#else
	mt19937 tw(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif
uniform_int_distribution<ll> ll_distr;
ll rnd(ll a, ll b) { return ll_distr(tw) % (b - a + 1) + a; }

const int MOD = 1000000007;

void add(int& a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

bool check(ll a, ll b) {
	if (b == 0) {
		return a == 0;
	}
	return a % b == 0;
}

void solve() {
	int n;
	cin >> n;
	vector<ll> arr;
	for (int i = 0; i < n; ++i) {
		ll num;
		cin >> num;
		arr.push_back(num);
	}
	vector<vector<int>> graph(n);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	int bpv = 1;
	while (bpv < n) {
		bpv *= 2;
	}

	vector<ll> segtree(bpv * 2);

	auto segtree_set = [&](int pos, ll val) {
		pos += bpv;
		segtree[pos] = val;
		pos /= 2;
		while (pos) {
			segtree[pos] = __gcd(segtree[pos * 2], segtree[pos * 2 + 1]);
			pos /= 2;
		}
	};

	function<ll(int, int, int, int, int)> segtree_get = [&](int v, int vl, int vr, int l, int r) {
		if (vr <= l || r <= vl) {
			return 0ll;
		}
		if (l <= vl && vr <= r) {
			return segtree[v];
		}
		int vm = (vl + vr) / 2;
		return __gcd(segtree_get(v * 2, vl, vm, l, r), segtree_get(v * 2 + 1, vm, vr, l, r));
	};

	int ans = 0;

	function<void(int, int, int)> dfs = [&](int v, int p, int d) {
		segtree_set(d, arr[v]);
		ll val = arr[v];
		int pos = d;
		while (true) {
			// int l = -1, r = pos;
			// while (r - l > 1) {
			// 	int mid = (l + r) / 2;
			// 	if (segtree_get(1, 0, bpv, mid, d + 1) != val) {
			// 		l = mid;
			// 	} else {
			// 		r = mid;
			// 	}
			// }
			int v = pos + bpv;
			while (v > 1) {
				int p = v / 2;
				if (v & 1) {
					if (!check(segtree[p * 2], val)) {
						v = p * 2;
						break;
					}
				}
				v = p;
			}
			while (v < bpv) {
				if (check(segtree[v * 2 + 1], val)) {
					v = v * 2;
				} else {
					v = v * 2 + 1;
				}
			}
			v -= bpv;
			if (v == 0) {
				if (segtree_get(1, 0, bpv, 0, d + 1) == val) {
					--v;
				}
			}
			add(ans, (pos - v) * val % MOD);
			if (v == -1) {
				break;
			}
			val = segtree_get(1, 0, bpv, v, d + 1);
			pos = v;
		}
		for (int to : graph[v]) {
			if (to != p) {
				dfs(to, v, d + 1);
			}
		}
		segtree_set(d, 0);
	};
	dfs(0, 0, 0);
	cout << ans << "\n";
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