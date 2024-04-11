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
	int x, y, col, ind;
	point(int _x, int _y, int _col, int _ind) : x(_x), y(_y), col(_col), ind(_ind) {}
	point(int _x, int _y) : x(_x), y(_y), col(-1), ind(-1) {}

	point operator+(point const& other) const {
		return point(x + other.x, y + other.y);
	}

	point operator-(point const& other) const {
		return point(x - other.x, y - other.y);
	}

	point operator+=(point const& other) {
		x += other.x;
		y += other.y;
		return *this;
	}

	point operator-=(point const& other) {
		x -= other.x;
		y -= other.y;
		return *this;
	}

	bool operator<(point const& other) {
		if (x != other.x) {
			return x < other.x;
		}
		return y < other.y;
	}

	bool operator==(point const& other) {
		return x == other.x && y == other.y;
	}

	bool operator!=(point const& other) {
		return !operator==(other);
	}
};

int cross(point const& p1, point const& p2) {
	return p1.x * p2.y - p1.y * p2.x;
}

int scalar(point const& p1, point const& p2) {
	return p1.x * p2.x + p1.y * p2.y;
}

vector<point> build_convex_hull(vector<point> points) {
	point center = *min_element(points.begin(), points.end());
	vector<point> ret;
	for (point& p : points) {
		if (p != center) {
			p -= center;
			ret.push_back(p);
		}
	}
	swap(ret, points);
	sort(points.begin(), points.end(), [&](auto& a, auto& b) {
		return cross(a, b) > 0;
	});
	ret.clear();
	ret.push_back(point(0, 0, center.col, center.ind));
	for (auto p : points) {
		while (szof(ret) >= 2 && cross(ret.back() - ret[szof(ret) - 2], p - ret.back()) < 0) {
			ret.pop_back();
		}
		ret.push_back(p);
	}
	for (auto& p : ret) {
		p += center;
	}
	return ret;
}

int sign(int num) {
	return num > 0 ? 1 : (num < 0 ? -1 : 0);
}

bool inside_triangle(point const& a, point const& b, point const& c, point const& d) {
	static int arrs[3];
	arrs[0] = sign(cross(b - a, d - a));
	arrs[1] = sign(cross(c - b, d - b));
	arrs[2] = sign(cross(a - c, d - c));
	sort(arrs, arrs + 3);
	return arrs[0] == arrs[2] && arrs[0];
}

void solve() {
	int n;
	cin >> n;
	vector<point> inp;
	for (int i = 0; i < n; ++i) {
		int x, y, c;
		cin >> x >> y >> c;
		inp.push_back(point(x, y, c, i));
	}

	auto hull = build_convex_hull(inp);

	int cnt = 0;
	for (int i = 0; i < szof(hull); ++i) {
		int next = (i + 1) % szof(hull);
		if (hull[i].col == 0 && hull[next].col == 1) {
			++cnt;
		}
	}

	if (cnt >= 2) {
		cout << "Impossible\n";
		return;
	}

	vector<pii> ans;

	function<void(int, int, int)> triangle_solve = [&](int a, int b, int c) {
		vector<vector<int>> cur(2);
		for (int i = 0; i < n; ++i) {
			if (inside_triangle(inp[a], inp[b], inp[c], inp[i])) {
				cur[inp[i].col].push_back(i);
			}
		}
		if (szof(cur[0]) == 0) {
			int any = -1;
			for (int x : {a, b, c}) {
				if (inp[x].col == 1) {
					any = x;
					break;
				}
			}
			for (int i : cur[1]) {
				ans.push_back({i, any});
			}
		} else if (szof(cur[1]) == 0) {
			int any = -1;
			for (int x : {a, b, c}) {
				if (inp[x].col == 0) {
					any = x;
					break;
				}
			}
			for (int i : cur[0]) {
				ans.push_back({i, any});
			}
		} else {
			vector<vector<int>> angles(2);
			for (int x : {a, b, c}) {
				angles[inp[x].col].push_back(x);
			}
			int need = szof(angles[0]) == 2 ? 1 : 0;
			int any = angles[need][0];
			int other = cur[need][0];
			ans.push_back({any, other});
			triangle_solve(any, other, angles[1 - need][0]);
			triangle_solve(any, other, angles[1 - need][1]);
			triangle_solve(angles[1 - need][0], angles[1 - need][1], other);
		}
	};

	if (cnt == 0) {
		for (int i = 0; i < szof(hull) - 1; ++i) {
			ans.push_back({hull[i].ind, hull[i + 1].ind});
		}
		int other = -1;
		for (int i = 0; i < n; ++i) {
			if (inp[i].col != hull[0].col) {
				other = i;
				break;
			}
		}

		if (other == -1) {
			vector<bool> in_hull(n);

			for (int i = 0; i < szof(hull); ++i) {
				in_hull[hull[i].ind] = true;
			}

			for (int i = 0; i < n; ++i) {
				if (!in_hull[i]) {
					ans.push_back({i, hull[0].ind});
				}
			}
		} else {
			for (int i = 0; i < szof(hull); ++i) {
				int next = (i + 1) % szof(hull);
				triangle_solve(hull[i].ind, hull[next].ind, other);
			}
		}
	} else {
		for (int i = 0; i < szof(hull); ++i) {
			int next = (i + 1) % szof(hull);
			if (hull[i].col == 0 && hull[next].col == 1) {
				rotate(hull.begin(), hull.begin() + next, hull.end());
				break;
			}
		}
		int from = -1;
		for (int i = 0; i < szof(hull); ++i) {
			int next = (i + 1) % szof(hull);
			if (hull[i].col == 0 && from == -1) {
				from = i;
			}
			if (hull[i].col == hull[next].col) {
				ans.push_back({hull[i].ind, hull[next].ind});
			}
		}
		for (int i = 0; i + 1 < from; ++i) {
			triangle_solve(hull[i].ind, hull[i + 1].ind, hull[from].ind);
		}
		for (int i = from; i + 1 < szof(hull); ++i) {
			triangle_solve(hull[0].ind, hull[i].ind, hull[i + 1].ind);
		}
	}

	cout << szof(ans) << "\n";
	for (auto p : ans) {
		cout << p.ff << " " << p.ss << "\n";
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