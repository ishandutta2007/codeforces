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

const int MOD = 1'000'000'007;

void add(int& a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

int sum(int a, int b) {
	add(a, b);
	return a;
}

int mult(int a, int b) {
	return (ll) a * b % MOD;
}

void solve() {
	int n;
	cin >> n;
	vector<pii> pairs;
	vector<int> here(n * 2);
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		pairs.push_back({a, b});
		here[a] = i * 2;
		here[b] = i * 2 + 1;
	}

	int t;
	cin >> t;
	vector<int> need;
	for (int i = 0; i < t; ++i) {
		int ind;
		cin >> ind;
		--ind;
		need.push_back(ind);
	}

	sort(need.begin(), need.end(), [&](int a, int b) {
		return pairs[a].ss > pairs[b].ss;
	});

	vector<int> seq;
	vector<bool> in_seq(n);
	int maxl = -1;
	for (int ind : need) {
		if (pairs[ind].ff > maxl) {
			maxl = pairs[ind].ff;
			seq.push_back(ind);
			in_seq[ind] = true;
		}
	}

	vector<int> prev_open(n * 2);
	int last_open = -1;
	for (int i = 0; i < n * 2; ++i) {
		prev_open[i] = last_open;
		if (here[i] % 2 == 0) {
			last_open = i;
		}
	}

	int bpv = 1;
	while (bpv < n * 2) {
		bpv *= 2;
	}

	vector<int> segtree(bpv * 2);

	auto segtree_set = [&](int pos, int val) {
		pos += bpv;
		segtree[pos] = val;
		pos /= 2;
		while (pos) {
			segtree[pos] = sum(segtree[pos * 2], segtree[pos * 2 + 1]);
			pos /= 2;
		}
	};

	auto segtree_get = [&](int l, int r) {
		int ret = 0;
		l += bpv; r += bpv;
		while (l < r) {
			if (l & 1) {
				add(ret, segtree[l++]);
			}
			if (r & 1) {
				add(ret, segtree[--r]);
			}
			l /= 2; r /= 2;
		}
		return ret;
	};

	int ans = 0;
	vector<int> prev_in_seq(n * 2);
	int last_in_seq = 0;
	for (int i = 0; i < n * 2; ++i) {
		prev_in_seq[i] = last_in_seq;
		if (here[i] % 2 == 0 && in_seq[here[i] / 2]) {
			last_in_seq = i;
		}
	}

	for (int i = 0; i < n * 2; ++i) {
		if (here[i] % 2 == 1) {
			int ind = here[i] / 2;
			int pos = pairs[ind].ff;
			int val = segtree_get(0, bpv);
			add(val, 1);
			// cerr << pos + 1 << " " << val << endl;
			
			if (in_seq[ind]) {
				add(ans, sum(val, MOD - segtree_get(0, prev_in_seq[pos])));
			}

			add(val, MOD - segtree_get(0, pos));
			segtree_set(pos, val);
			if (seq.front() == ind) {
				cout << ans << "\n";
				return;
			}
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