// Created by Nikolay Budin

#ifdef LOCAL
#  define _GLIBCXX_DEBUG
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

struct point {
	int x, y;
	point(int _x, int _y) : x(_x), y(_y) {}
	point operator-(point const& other) const {
		return point(x - other.x, y - other.y);
	}
	bool operator<(point const& other) const {
		return x < other.x || (x == other.x && y < other.y);
	}
};

ll cross(point const& p1, point const& p2) {
	return (ll) p1.x * p2.y - (ll) p1.y * p2.x;
}

void solve() {
	int n;
	cin >> n;
	vector<point> points;
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		points.push_back(point(x, y));
	}
	string s;
	cin >> s;

	vector<int> order;
	vector<bool> used(n);
	int mem = 0;
	for (int i = 0; i < n; ++i) {
		if (points[i] < points[mem]) {
			mem = i;
		}
	}

	used[mem] = true;
	order.push_back(mem);

	for (int i = 1; i < n - 1; ++i) {
		int prev = order.back();
		int l = -1, r = -1;
		for (int j = 0; j < n; ++j) {
			if (used[j]) {
				continue;
			}
			if (l == -1) {
				l = j;
				r = j;
			} else {
				if (cross(points[l] - points[prev], points[j] - points[prev]) < 0) {
					l = j;
				}
				if (cross(points[r] - points[prev], points[j] - points[prev]) > 0) {
					r = j;
				}
			}
		}
		int next;
		if (s[i - 1] == 'L') {
			next = l;
		} else {
			next = r;
		}
		used[next] = true;
		order.push_back(next);
	}
	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			order.push_back(i);
		}
	}

	for (int num : order) {
		cout << num + 1 << " ";
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