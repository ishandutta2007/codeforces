#include "bits/stdc++.h"
#define ff first
#define ss second
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

#ifdef LOCAL
#  define _GLIBCXX_DEBUG
#  define _GLIBCXX_DEBUG_PEDANTIC
#endif


using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9 + 7;
const ll INFL = 1e18 + 123;
const double PI = atan2(0, -1);
mt19937 tw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(tw) % (y - x + 1) + x; }

const int MAXL = 1000000, MAXLANS = 1500000;
const ll MAXL2 = (ll) MAXL * MAXL, MAXLANS2 = (ll) MAXLANS * MAXLANS;

struct point {
	ll x, y;
	int ind;
	point() : x(0), y(0), ind(-1) {}
	point(ll _x, ll _y, int _ind = -1) : x(_x), y(_y), ind(_ind) {}
	point(point const& other) : x(other.x), y(other.y), ind(other.ind) {}

	point operator-(point const& other) const {
		return point(x - other.x, y - other.y);
	}

	point operator+(point const& other) const {
		return point(x + other.x, y + other.y);
	}

	ll operator*(point const& other) const {
		return x * other.y - y * other.x;
	}

	ll len2() {
		return x * x + y * y;
	}

	bool operator<(point const& other) const {
		bool fl1 = y > 0 || (y == 0 && x > 0);
		bool fl2 = other.y > 0 || (other.y == 0 && other.x > 0);
		if (fl1 != fl2) {
			return fl1 < fl2;
		}
		ll tmp = operator*(other);
		if (tmp != 0) {
			return tmp > 0;
		}
		return ind < other.ind;
	}

	bool operator==(point const& other) const {
		return x == other.x && y == other.y && ind == other.ind;
	}

	bool operator!=(point const& other) const {
		return !(x == other.x && y == other.y && ind == other.ind);
	}
};

void solve() {
	int n;
	cin >> n;
	vector<pii> ans(n, {0, -1});
	set<point> all;
	vector<point> inp;
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		inp.push_back({x, y});
		if (x == 0 && y == 0) {
			ans[i].ff = 1;
			continue;
		}
		all.insert(point(x, y, i));
	}

	int cnt = n;
	int cnt_not_found = 0;
	while (szof(all) > 5) {
		auto it = all.begin();
		for (int i = 0; i < cnt_not_found; ++i) {
			++it;
		}
		auto it2 = it;
		++it2;
		if ((*it - *it2).len2() <= MAXL2) {
			auto res = *it - *it2;
			ans[it->ind] = {1, cnt};
			ans[it2->ind] = {-1, cnt};
			ans.push_back({0, -1});
			auto mem = *it;
			assert(*it != *it2);
			all.erase(it2);
			it = all.begin();
			while (*it != mem) {
				++it;
			}
			all.erase(it);
			res.ind = cnt++;
			if (res.len2()) {
				all.insert(res);
			} else {
				ans[res.ind] = {1, -1};
			}
			cnt_not_found = 0;
			continue;
		}

		it2 = all.lower_bound(point(-it->x, -it->y));
		if (it2 == all.end()) {
			it2 = all.begin();
		}
		if (it != it2 && (*it + *it2).len2() <= MAXL2) {
			auto res = *it + *it2;
			ans[it->ind] = {1, cnt};
			ans[it2->ind] = {1, cnt};
			ans.push_back({0, -1});
			auto mem = *it;
			assert(*it != *it2);
			all.erase(it2);
			it = all.begin();
			while (*it != mem) {
				++it;
			}
			all.erase(it);
			res.ind = cnt++;
			if (res.len2()) {
				all.insert(res);
			} else {
				ans[res.ind] = {1, -1};
			}
			cnt_not_found = 0;
			continue;
		}

		if (it2 != all.begin()) {
			--it2;
		} else {
			it2 = --all.end();
		}
		if (it2 != it && (*it + *it2).len2() <= MAXL2) {
			auto res = *it + *it2;
			ans[it->ind] = {1, cnt};
			ans[it2->ind] = {1, cnt};
			ans.push_back({0, -1});
			auto mem = *it;
			assert(*it != *it2);
			all.erase(it2);
			it = all.begin();
			while (*it != mem) {
				++it;
			}
			all.erase(it);
			res.ind = cnt++;
			if (res.len2()) {
				all.insert(res);
			} else {
				ans[res.ind] = {1, -1};
			}
			cnt_not_found = 0;
			continue;
		}

		++cnt_not_found;
	}

	vector<point> rest;
	for (auto p : all) {
		rest.push_back(p);
	}

	for (int i = 0; i < 1 << szof(rest); ++i) {
		point tmp;
		for (int j = 0; j < szof(rest); ++j) {
			if (i & (1 << j)) {
				tmp = tmp + rest[j];
			} else {
				tmp = tmp - rest[j];
			}
		}
		if (tmp.len2() <= MAXLANS2) {
			for (int j = 0; j < szof(rest); ++j) {
				if (i & (1 << j)) {
					ans[rest[j].ind].ff = 1;
				} else {
					ans[rest[j].ind].ff = -1;
				}
			}
			break;
		}
	}

	for (int i = szof(ans) - 1; i >= 0; --i) {
		if (ans[i].ss != -1) {
			ans[i].ff *= ans[ans[i].ss].ff;
		}
	}

	point sum;
	for (int i = 0; i < n; ++i) {
		cout << ans[i].ff << " ";
		if (ans[i].ff == 1) {
			sum = sum + inp[i];
		} else {
			sum = sum - inp[i];
		}
	}
	cout << "\n";
	assert(sum.len2() <= MAXLANS2);
}


int main() {
	//freopen("test", "r", stdin);
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