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


void solve() {
	int n, w;
	cin >> n >> w;
	vector<ll> res(w + 1);
	for (int i = 0; i < n; ++i) {
		int l;
		cin >> l;
		vector<int> cur;
		int tot = 0;
		for (int j = 0; j < l; ++j) {
			int num;
			cin >> num;
			cur.push_back(num);
			tot = max(tot, num);
		}

		int bpv = 1;
		while (bpv < l) {
			bpv *= 2;
		}
		
		vector<int> segtree(bpv * 2);
		for (int j = 0; j < l; ++j) {
			segtree[bpv + j] = cur[j];
		}

		for (int j = bpv - 1; j; --j) {
			segtree[j] = max(segtree[j * 2], segtree[j * 2 + 1]);
		}

		auto segtree_getmax = [&](int l, int r) {
			// cerr << l << " " << r << endl;
			l += bpv;
			r += bpv;
			int ret = -INF;
			while (l < r) {
				if (l & 1) {
					ret = max(ret, segtree[l++]);
				}
				if (r & 1) {
					ret = max(ret, segtree[--r]);
				}
				l /= 2;
				r /= 2;
			}
			// cerr << ret << endl;
			return ret;
		};

		int lg = l, rg = w - l;
		if (lg < rg) {
			res[lg] += tot;
			res[rg] -= tot;
		}

		auto get_val = [&](int pos) {
			int ret = segtree_getmax(max(0, pos - (w - l)), min(pos + 1, l));
			if (pos >= l || pos < w - l) {
				ret = max(ret, 0);
			}
			return ret;
		};

		for (int j = 0; j < l; ++j) {
			int val = get_val(j);
			res[j] += val;
			res[j + 1] -= val;
		}
		for (int j = max(l, w - l); j < w; ++j) {
			int val = get_val(j);
			res[j] += val;
			res[j + 1] -= val;
		}
	}

	for (int i = 0; i < w; ++i) {
		cout << res[i] << " ";
		res[i + 1] += res[i];
	}
	cout << "\n";
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