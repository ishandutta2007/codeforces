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

struct point {
	ll x, y;
	point(ll _x, ll _y) : x(_x), y(_y) {}

	point operator+(point const& other) const {
		return point(x + other.x, y + other.y);
	}

	point operator-(point const& other) const {
		return point(x - other.x, y - other.y);
	}

	ull len2() const {
		return (ull) x * x + (ull) y * y;
	}
};

ll cross(point const& p1, point const& p2) {
	return (ull) p1.x * p2.y - (ull) p1.y * p2.x;
}

ll dot(point const& p1, point const& p2) {
	return (ull) p1.x * p2.x + (ull) p1.y * p2.y;
}

void solve() {
	int n;
	cin >> n;
	vector<point> poly, poly2;
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		poly.push_back(point(x, y));
		poly2.push_back(point(-x, -y));
	}
	vector<point> shifts;
	for (int i = 0; i < n; ++i) {
		int next = (i + 1) % n;
		shifts.push_back(poly[next] - poly[i]);
		shifts.push_back(poly2[next] - poly2[i]);
	}

	sort(shifts.begin(), shifts.end(), [&](auto& p1, auto& p2) {
		bool fl1 = p1.y > 0 || (p1.y == 0 && p1.x > 0);
		bool fl2 = p2.y > 0 || (p2.y == 0 && p2.x > 0);
		if (fl1 != fl2) {
			return fl1 < fl2;
		}
		return cross(p1, p2) > 0;
	});

	auto better = [&](auto& p1, auto& p2) {
		if (p1.y != p2.y) {
			return p1.y > p2.y;
		}
		return p1.x > p2.x;
	};

	int pos1 = 0, pos2 = 0;
	for (int i = 0; i < n; ++i) {
		if (better(poly[i], poly[pos1])) {
			pos1 = i;
		}
		if (better(poly2[i], poly2[pos2])) {
			pos2 = i;
		}
	}

	vector<point> res;
	point cur = poly[pos1] + poly2[pos2];
	for (auto v : shifts) {
		while (szof(res) >= 2) {
			auto& a = res[szof(res) - 2];
			auto& b = res[szof(res) - 1];
			if (cross(b - a, cur - b) == 0) {
				res.pop_back();
			} else {
				break;
			}
		}
		res.push_back(cur);
		cur = cur + v;
	}

	while (szof(res) >= 2) {
		auto& a = res[szof(res) - 2];
		auto& b = res[szof(res) - 1];
		if (cross(b - a, res.front() - b) == 0) {
			res.pop_back();
		} else {
			break;
		}
	}

	if (szof(res) != n) {
		cout << "No\n";
		return;
	}

	vector<ull> arr1;
	vector<ull> arr2;
	for (int i = 0; i < n; ++i) {
		int next = (i + 1) % n;
		int prev = (i - 1 + n) % n;
		arr1.push_back((poly[i] - poly[prev]).len2() * 4);
		arr1.push_back(dot(poly[i] - poly[prev], poly[next] - poly[i]) * 4);

		arr2.push_back((res[i] - res[prev]).len2());
		arr2.push_back(dot(res[i] - res[prev], res[next] - res[i]));
	}

	vector<ull> tmp = arr1;
	for (int i = 0; i < n * 2; ++i) {
		tmp.push_back(arr2[i % n]);
	}

	vector<int> z(szof(tmp));
	int l = 0, r = 0;
	for (int i = 1; i < szof(tmp); ++i) {
		if (i < r) {
			z[i] = min(r - i, z[i - l]);
		}
		while (i + z[i] < szof(tmp) && tmp[z[i]] == tmp[i + z[i]]) {
			++z[i];
		}
		if (i + z[i] > r) {
			l = i;
			r = i + z[i];
		}
		if (i >= n && (i - n) % 2 == 0 && z[i] >= n) {
			cout << "Yes\n";
			return;
		}
	}
	cout << "No\n";
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