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
	point(int _x, int _y) : x(_x), y(_y) {}

	point operator-(point other) {
		return point(x - other.x, y - other.y);
	}
	point operator+(point other) {
		return point(x + other.x, y + other.y);
	}

	bool operator<(point other) {
		return x < other.x || (x == other.x && y < other.y);
	}
};

ll cross(point p1, point p2) {
	return (ll) p1.x * p2.y - (ll) p1.y * p2.x;
}

ll scalar(point p1, point p2) {
	return (ll) p1.x * p2.x + (ll) p1.y * p2.y;
}

ll dist2(point p) {
	return (ll) p.x * p.x + (ll) p.y * p.y;
}

vector<pair<ll, ll>> calc(int n) {
	vector<point> points;
	int mem = 0;
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		points.push_back(point(x, y));
		if (points[i] < points[mem]) {
			mem = i;
		}
	}
	point c = points[mem];
	points.erase(points.begin() + mem);
	for (auto& p : points) {
		p = p - c;
	}

	sort(points.begin(), points.end(), [&](point p1, point p2) {
		bool fl1 = p1.y > 0 || (p1.y == 0 && p1.x > 0);
		bool fl2 = p2.y > 0 || (p2.y == 0 && p2.x > 0);
		if (fl1 != fl2) {
			return fl1 < fl2;
		}
		auto tmp = cross(p1, p2);
		if (tmp != 0) {
			return tmp > 0;
		}
		return dist2(p1) < dist2(p2);
	});

	/*
	cerr << "new" << endl;
	for (auto p : points) {
		cerr << p.x << " " << p.y << endl;
	}
	*/

	vector<point> st;
	st.push_back(point(0, 0));
	points.push_back(point(0, 0));
	for (auto p : points) {
		while (szof(st) > 1) {
			ll cr = cross(st.back() - st[szof(st) - 2], p - st.back());
			ll sc = scalar(st.back() - st[szof(st) - 2], p - st.back());
			if (cr < 0 || (cr == 0 && sc > 0)) {
				st.pop_back();
			} else {
				break;
			}
		}
		st.push_back(p);
	}
	st.pop_back();

	/*
	cerr << "convex hull" << endl;
	for (auto p : st) {
		cerr << p.x << " " << p.y << endl;
	}
	*/

	vector<pair<ll, ll>> ret;
	for (int i = 0; i < szof(st); ++i) {
		int next = (i + 1) % szof(st);
		int next2 = (i + 2) % szof(st);
		ret.push_back({dist2(st[next] - st[i]), scalar(st[next] - st[i], st[next2] - st[next])});
	}

	return ret;
}

void solve() {
	int n, m;
	cin >> n >> m;
	auto val1 = calc(n);
	auto val2 = calc(m);

	if (szof(val1) != szof(val2)) {
		cout << "NO\n";
		return;
	}

	auto s = val1;
	for (int i = 0; i < 2; ++i) {
		for (auto p : val2) {
			s.push_back(p);
		}
	}

	vector<int> z(szof(s));
	int l = 0, r = 0;
	for (int i = 1; i < szof(s); ++i) {
		if (i < r) {
			z[i] = min(r - i, z[i - l]);
		}
		while (i + z[i] < szof(s) && s[z[i]] == s[i + z[i]]) {
			++z[i];
		}
		if (i >= szof(val1)) {
			if (z[i] >= szof(val1)) {
				cout << "YES\n";
				return;
			}
		}
		if (i + z[i] > r) {
			l = i;
			r = i + z[i];
		}
	}
	cout << "NO\n";
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