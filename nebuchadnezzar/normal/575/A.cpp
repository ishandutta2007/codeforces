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

int mod;

struct matr {
	int v00, v01, v10, v11;
	matr() : v00(1), v01(0), v10(0), v11(1) {}

	matr(int _v00, int _v01, int _v10, int _v11) : v00(_v00), v01(_v01), v10(_v10), v11(_v11) {}

	matr operator*(matr const& other) const {
		return matr(((ll) v00 * other.v00 + (ll) v01 * other.v10) % mod,
			((ll) v00 * other.v01 + (ll) v01 * other.v11) % mod,
			((ll) v10 * other.v00 + (ll) v11 * other.v10) % mod,
			((ll) v10 * other.v01 + (ll) v11 * other.v11) % mod);
	}
};

matr mpow(matr a, ll b) {
	matr ret;
	while (b) {
		if (b & 1) {
			ret = ret * a;
		}
		a = a * a;
		b >>= 1;
	}
	return ret;
}

void solve() {
	ll k;
	cin >> k >> mod;
	int n;
	cin >> n;
	vector<int> arrs;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		arrs.push_back(num);
	}
	int m;
	cin >> m;
	map<ll, int> special_s;
	set<ll> special_matr;
	for (int i = 0; i < m; ++i) {
		ll pos;
		int val;
		cin >> pos >> val;
		special_s[pos] = val;
		special_matr.insert(pos);
		special_matr.insert(pos - 1);
	}

	int bpv = 1;
	while (bpv < n) {
		bpv *= 2;
	}

	vector<matr> usual_matrs;

	vector<matr> segtree_matrs(bpv * 2);
	for (int i = 0; i < n; ++i) {
		usual_matrs.push_back(matr(0, arrs[i], 1, arrs[(i + 1) % n]));
		segtree_matrs[bpv + i] = usual_matrs[i];
	}

	vector<matr> pref_matr = {matr()};
	vector<matr> suff_matr = {matr()};
	for (int i = 0; i < n; ++i) {
		pref_matr.push_back(pref_matr.back() * usual_matrs[i]);
		suff_matr.push_back(usual_matrs[n - 1 - i] * suff_matr.back());
	}

	matr all_matrs = pref_matr.back();

	for (int i = bpv - 1; i; --i) {
		segtree_matrs[i] = segtree_matrs[i * 2] * segtree_matrs[i * 2 + 1];
	}

	auto get_s = [&](ll pos) {
		if (special_s.count(pos)) {
			return special_s[pos];
		}
		return arrs[pos % n];
	};

	auto get_matr = [&](ll pos) {
		return matr(0, get_s(pos), 1, get_s(pos + 1));
	};

	auto get_seg_matr = [&](ll l, ll r) {
		if (l / n == r / n) {
			l %= n;
			r %= n;
			l += bpv;
			r += bpv;
			matr retl, retr;
			while (l != r) {
				if (l & 1) {
					retl = retl * segtree_matrs[l++];
				}
				if (r & 1) {
					retr = segtree_matrs[--r] * retr;
				}
				l /= 2;
				r /= 2;
			}
			return retl * retr;
		}
		return suff_matr[n - l % n] * mpow(all_matrs, r / n - l / n - 1) * pref_matr[r % n];
	};

	matr cur;
	ll from = 0;
	while (from < k) {
		if (special_matr.count(from)) {
			cur = cur * get_matr(from);
			++from;
			continue;
		}
		ll next = k;
		auto it = special_matr.lower_bound(from);
		if (it != special_matr.end()) {
			next = min(next, *it);
		}
		cur = cur * get_seg_matr(from, next);
		from = next;
	}

	cout << cur.v10 % mod << "\n";
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