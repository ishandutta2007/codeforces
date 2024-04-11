#ifdef LOCAL
#  define _GLIBCXX_DEBUG
#  define _GLIBCXX_DEBUG_PEDANTIC
#endif

#include "bits/stdc++.h"
#define ff first
#define ss second
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9 + 7;
const ll INFL = 1e18 + 123;
const double PI = atan2(0, -1);
mt19937 tw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(tw) % (y - x + 1) + x; }

struct point {
	int x, y;
	point() : x(0), y(0) {}
	point(int _x, int _y) : x(_x), y(_y) {}

	point operator+(point const& other) const {
		return point(x + other.x, y + other.y);
	}

	point operator-(point const& other) const {
		return point(x - other.x, y - other.y);
	}
};

ostream& operator<<(ostream& o, point const& p) {
	o << p.x << " " << p.y;
	return o;
}

ll cross(point const& p1, point const& p2) {
	return (ll) p1.x * p2.y - (ll) p1.y * p2.x;
}

void solve() {
	int n;
	ll s;
	cin >> n >> s;
	vector<point> inp;
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		inp.push_back(point(x, y));
	}

	vector<pair<point, pii>> all;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == j) {
				continue;
			}
			point p = inp[j] - inp[i];
			if (p.y > 0 || (p.y == 0 && p.x > 0)) {
				all.push_back({p, {i, j}});
			}
		}
	}

	//cerr << "before sort " << clock() * 1000 / CLOCKS_PER_SEC << endl;

	sort(all.begin(), all.end(), [](pair<point, pii> const& p1, pair<point, pii> const& p2) {
		//return cross(p1.ff, p2.ff) > 0;
		return (ll) p1.ff.x * p2.ff.y > (ll) p1.ff.y * p2.ff.x;
	});

	//cerr << "after sort " << clock() * 1000 / CLOCKS_PER_SEC << endl;

	vector<int> order(n);
	iota(order.begin(), order.end(), 0);

	sort(order.begin(), order.end(), [&](int p1, int p2) {
		return cross(all[0].ff, inp[p1] - inp[all[0].ss.ff]) < cross(all[0].ff, inp[p2] - inp[all[0].ss.ff]);
	});

	vector<int> where(n);
	for (int i = 0; i < n; ++i) {
		where[order[i]] = i;
	}

	for (auto& p : all) {
		int l = 0, r = n;
		while (r - l > 1) {
			int mid = (l + r) / 2;
			ll tmp = cross(p.ff, inp[order[mid]] - inp[p.ss.ff]);
			if (tmp <= s * 2) {
				l = mid;
			} else {
				r = mid;
			}
		}

		if (cross(p.ff, inp[order[l]] - inp[p.ss.ff]) == s * 2) {
			cout << "Yes\n";
			cout << inp[p.ss.ff] << "\n" << inp[p.ss.ss] << "\n" << inp[order[l]] << "\n";
			return;
		}

		l = -1;
		while (r - l > 1) {
			int mid = (l + r) / 2;
			ll tmp = cross(p.ff, inp[order[mid]] - inp[p.ss.ff]);
			if (tmp < -s * 2) {
				l = mid;
			} else {
				r = mid;
			}
		}

		if (cross(p.ff, inp[order[r]] - inp[p.ss.ff]) == -s * 2) {
			cout << "Yes\n";
			cout << inp[p.ss.ff] << "\n" << inp[p.ss.ss] << "\n" << inp[order[r]] << "\n";
			return;
		}

		int& pos1 = where[p.ss.ff];
		int& pos2 = where[p.ss.ss];
		swap(order[pos1], order[pos2]);
		swap(pos1, pos2);
	}

	cout << "No\n";
}


int main() {
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);
	cerr << fixed << setprecision(15);
	cout << fixed << setprecision(15);
	ios::sync_with_stdio(false);

	int tests = 1;
	// cin >> tests;
	for (int it = 1; it <= tests; ++it) {
		solve();
	}
	
	#ifdef LOCAL
		cerr << "time: " << clock() << " ms\n";
	#endif
	return 0;
}