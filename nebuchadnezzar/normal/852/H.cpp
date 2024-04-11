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
	int x, y;
	point(int _x, int _y) : x(_x), y(_y) {}

	point operator+(point const& other) const {
		return point(x + other.x, y + other.y);
	}

	point operator-(point const& other) const {
		return point(x - other.x, y - other.y);
	}
};

ostream& operator<<(ostream& o, point p) {
	o << "(" << p.x << ", " << p.y << ")";
	return o;
}

ll cross(point const& p1, point const& p2) {
	return (ll) p1.x * p2.y - (ll) p1.y * p2.x;
}

ll dot(point const& p1, point const& p2) {
	return (ll) p1.x * p2.x + (ll) p1.y * p2.y;
}

void upd(ll& a, ll b) {
	a = max(a, b);
}

void solve() {
	int n, k;
	cin >> n >> k;
	vector<point> points;
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		points.push_back(point(x, y));
	}

	vector<int> order(n);
	iota(order.begin(), order.end(), 0);
	shuffle(order.begin(), order.end(), tw);
	vector<vector<map<int, ll>>> vars(n, vector<map<int, ll>>(k - 1));
	ll ans = 0;
	for (int s : order) {
		vector<point> cur_points;
		for (int i = 0; i < n; ++i) {
			if (i != s) {
				cur_points.push_back(points[i] - points[s]);
			}
		}
		sort(cur_points.begin(), cur_points.end(), [&](auto& a, auto& b) {
			bool fla = a.y > 0 || (a.y == 0 && a.x > 0);
			bool flb = b.y > 0 || (b.y == 0 && b.x > 0);
			if (fla != flb) {
				return fla < flb;
			}
			return cross(a, b) > 0;
		});
		auto norm = [&](int num) {
			if (num >= n - 1) {
				num -= n - 1;
			}
			return num;
		};
		bool single = false;
		for (int i = 0; i < n - 1; ++i) {
			int next = norm(i + 1);
			if (cross(cur_points[i], cur_points[next]) < 0) {
				single = true;
				rotate(cur_points.begin(), cur_points.begin() + next, cur_points.end());
			}
		}
		if (!single) {
			rotate(cur_points.begin(), cur_points.begin() + rnd(0, n - 2), cur_points.end());
		}
		vector<vector<int>> is_ok(n - 1, vector<int>(n - 1, -1));
		cur_points.push_back(point(0, 0));
		int last = 0;
		for (int i = 0; i < n - 1; ++i) {
			if (cross(cur_points[0], cur_points[last]) < 0) {
				--last;
				rotate(cur_points.begin(), cur_points.begin() + 1, cur_points.end() - 1);
				continue;
			}
			for (int j = 0; j < n - 1; ++j) {
				if (cross(cur_points[0], cur_points[j]) < 0) {
					break;
				}
				last = j;
				for (int num = 0; num < k - 1; ++num) {
					vars[j][num].clear();
				}
				vars[j][0][n - 1] = 0;
				if (j == 0) {
					continue;
				}
				for (int prev = 0; prev < j; ++prev) {
					int& is_ok_val = is_ok[norm(j + i)][norm(prev + i)];
					if (is_ok_val == -1) {
						bool ok = true;
						for (int q = prev + 1; q < j; ++q) {
							if (cross(cur_points[j] - cur_points[prev], cur_points[q] - cur_points[prev]) > 0) {
								ok = false;
								break;
							}
						}
						is_ok_val = ok;
					}
					if (!is_ok_val) {
						continue;
					}
					for (int num = 0; num < k - 2; ++num) {
						for (auto p : vars[prev][num]) {
							// cerr << "try " << s << " " << cur_points[j] << " " << cur_points[prev] << " " << cur_points[p.ff] << endl;
							if (cross(cur_points[prev] - cur_points[p.ff], cur_points[j] - cur_points[prev]) > 0) {
								// cerr << "upd " << s << " " << cur_points[0] << " " << cur_points[j] << " " << num + 1 << " " << cur_points[prev] << " " << p.ss << " " <<  p.ss + cross(cur_points[prev], cur_points[j]) << endl;
								upd(vars[j][num + 1][prev], p.ss + cross(cur_points[prev], cur_points[j]));
							}
						}
					}
				}

				for (auto p : vars[j][k - 2]) {
					// cerr << s << " " << cur_points[0] << " " << cur_points[j] << " " << p.ss << endl;
					ans = max(ans, p.ss);
					if (clock() > 1.95 * CLOCKS_PER_SEC) {
						if (ans % 2 == 0) {
							cout << ans / 2 << ".00\n";
						} else {
							cout << ans / 2 << ".50\n";
						}
						return;
					}
				}
			}
			if (single) {
				break;
			}
			rotate(cur_points.begin(), cur_points.begin() + 1, cur_points.end() - 1);
		}

		if (clock() > 1.95 * CLOCKS_PER_SEC) {
			break;
		}
	}

	if (ans % 2 == 0) {
		cout << ans / 2 << ".00\n";
	} else {
		cout << ans / 2 << ".50\n";
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