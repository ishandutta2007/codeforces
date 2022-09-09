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

int sign(int num) {
	return num < 0 ? -1 : (num > 0 ? 1 : 0);
}

int get_dist(pii const& a, pii const& b) {
	int dx = sign(b.ff - a.ff);
	int dy = sign(b.ss - a.ss);
	int tmp = min((b.ff - a.ff) * dx, (b.ss - a.ss) * dy);
	return tmp + abs(a.ff + dx * tmp - b.ff) + abs(a.ss + dy * tmp - b.ss);
}

pii move_in_dir(pii const& a, pii const& b, int d) {
	int dx = sign(b.ff - a.ff);
	int dy = sign(b.ss - a.ss);
	int tmp = min((b.ff - a.ff) * dx, (b.ss - a.ss) * dy);
	if (tmp >= d) {
		return {a.ff + d * dx, a.ss + d * dy};
	}
	d -= tmp;
	pii na = {a.ff + tmp * dx, a.ss + tmp * dy};
	int ndx = sign(b.ff - na.ff);
	int ndy = sign(b.ss - na.ss);
	return {na.ff + ndx * d, na.ss + ndy * d};
}

// const int MAXC = 2500;

void solve() {
	int n;
	cin >> n;
	vector<pii> points;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		int x = 0, y = 0;
		for (char c : s) {
			if (c == 'B') {
				++x;
			} else {
				++y;
			}
		}
		points.push_back({x, y});
	}

	const int MAXC = 1e6;

	pii ans = {0, 0};
	int l = -1, r = MAXC;
	while (r - l > 1) {
		int mid = (l + r) / 2;
		int lx = 0, rx = MAXC;
		int ly = 0, ry = MAXC;
		int lxmy = -MAXC, rxmy = MAXC;
		for (pii p : points) {
			lx = max(lx, p.ff - mid);
			rx = min(rx, p.ff + mid);
			ly = max(ly, p.ss - mid);
			ry = min(ry, p.ss + mid);
			lxmy = max(lxmy, p.ff - p.ss - mid);
			rxmy = min(rxmy, p.ff - p.ss + mid);
		}
		// cerr << mid << endl;
		// cerr << lx << " " << rx << endl;
		// cerr << ly << " " << ry << endl;
		// cerr << lxmy << " " << rxmy << endl;

		if (lx > rx || ly > ry || lxmy > rxmy) {
			l = mid;
			continue;
		}
		if (rxmy < lx - ry || rx - ly < lxmy) {
			l = mid;
			continue;
		}
		int cl = -1, cr = rx - lx + ry - ly + 1;
		while (cr - cl > 1) {
			int cmid = (cl + cr) / 2;
			int cx, cy;
			if (cmid <= rx - lx) {
				cx = lx + cmid;
				cy = ry;
			} else {
				cx = rx;
				cy = ry - (cmid - (rx - lx));
			}
			if (cx - cy < lxmy) {
				cl = cmid;
			} else {
				cr = cmid;
				// cerr << "upd " << cx << " " << cy << endl;
				ans = {cx, cy};
			}
		}
		r = mid;
	}

	cout << r << "\n";
	string outp = string(ans.ff, 'B') + string(ans.ss, 'N');
	cout << outp << "\n";
	// for (pii p : points) {
	// 	cerr << p.ff << " " << p.ss << " " << get_dist(p, ans) << endl;
	// 	assert(get_dist(p, ans) <= r);
	// }
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