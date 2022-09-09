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
	int n;
	cin >> n;
	vector<int> arr;
	int minv = INF, maxv = -INF;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		arr.push_back(num);
		minv = min(minv, num);
		maxv = max(maxv, num);
	}
	if (minv * 2 >= maxv) {
		for (int i = 0; i < n; ++i) {
			cout << "-1 ";
		}
		cout << "\n";
		return;
	}

	vector<int> vals = arr;
	sort(vals.begin(), vals.end());
	vals.erase(unique(vals.begin(), vals.end()), vals.end());

	for (int i = 0; i < n * 2 + 5; ++i) {
		arr.push_back(arr[i % n]);
	}

	int bpv = 1;
	while (bpv < szof(vals)) {
		bpv *= 2;
	}
	vector<int> segtree(bpv * 2, INF);

	function<void(int, int)> segtree_set = [&](int pos, int val) {
		pos += bpv;
		segtree[pos] = val;
		pos /= 2;
		while (pos) {
			segtree[pos] = min(segtree[pos * 2], segtree[pos * 2 + 1]);
			pos /= 2;
		}
	};

	function<int(int, int)> segtree_get = [&](int l, int r) {
		l += bpv; r += bpv;
		int ret = INF;
		while (l < r) {
			if (l & 1) {
				ret = min(ret, segtree[l++]);
			}
			if (r & 1) {
				ret = min(ret, segtree[--r]);
			}
			l /= 2; r /= 2;
		}

		return ret;
	};

	vector<vector<int>> sparse;
	sparse.push_back(vector<int>(szof(arr)));

	for (int i = szof(arr) - 1; i >= 0; --i) {
		int pos = lower_bound(vals.begin(), vals.end(), (arr[i] + 1) / 2) - vals.begin();
		sparse[0][i] = segtree_get(0, pos);
		segtree_set(lower_bound(vals.begin(), vals.end(), arr[i]) - vals.begin(), i);
	}

	int bp = 1;
	while (1 << bp <= szof(arr)) {
		bp++;
	}

	for (int i = 1; i < bp; ++i) {
		sparse.push_back({});
		for (int j = 0; j + (1 << i) <= szof(arr); ++j) {
			sparse.back().push_back(min(sparse[i - 1][j], sparse[i - 1][j + (1 << (i - 1))]));
		}
	}

	vector<int> maxp(szof(arr) + 5);
	for (int i = 1; i < szof(maxp); ++i) {
		maxp[i] = maxp[i - 1];
		if (1 << (maxp[i] + 1) <= i) {
			++maxp[i];
		}
	}

	auto get_min = [&](int l, int r) {
		int p = maxp[r - l];
		return min(sparse[p][l], sparse[p][r - (1 << p)]);
	};

	for (int i = 0; i < n; ++i) {
		int l = i, r = szof(arr);
		while (r - l > 1) {
			int mid = (r + l) / 2;
			if (get_min(i, mid) < mid) {
				r = mid;
			} else {
				l = mid;
			}
		}
		cout << l - i << " ";
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