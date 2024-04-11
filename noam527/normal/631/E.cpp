#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#include <stack>
#include <queue>
#include <random>
#include <fstream>
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

// maximum cht = type(1), minimum cht = type(-1)
struct cht {
	typedef long long ll;
	struct line {
		ll m, b, i, q;
		double nxt = 9e18;
		line(ll mm, ll bb, ll ii, ll qq = 0) : m(mm), b(bb), i(ii), q(qq) {};
		bool operator < (const line &x) const {
			if (!q && !x.q) return m < x.m;
			if (q) return m < x.nxt;
			return nxt < x.m;
		}
	};
	double cut(const line &x, const line &y) {
		return double(x.b - y.b) / (y.m - x.m);
	}
	int sign, nxtind = 0;
	cht(int type) {
		sign = type;
	}
	typedef set<line> s;
	s h;
	void upd(s::iterator &it) {
		if (next(it) != h.end()) {
			double n = cut(*it, *next(it));
			line l = *it;
			h.erase(it);
			l.nxt = n;
			it = h.insert(l).first;
		}
	}
	bool ok(s::iterator it) {
		if (it == h.begin() || next(it) == h.end() || cut(*prev(it), *it) < cut(*it, *next(it))) return true;
		return h.erase(it), false;
	}
	void insert(ll slope, ll constant) {
		line add(sign * slope, sign * constant, nxtind++);
		s::iterator it = h.insert(add).first;
		if (!ok(it)) return;
		while (it != h.begin() && !ok(prev(it)));
		while (next(it) != h.end() && !ok(next(it)));
		upd(it);
		if (it != h.begin()) upd(--it);
	}
	ll query(ll x) {
		line l = *h.lower_bound(line(x, 0, 0, 1));
		return sign * (x * l.m + l.b);
	}
	// returns the index of the best slope (indexed by the amount of lines tried to insert prior to it)
	ll iquery(ll x) {
		return h.lower_bound(line(x, 0, 0, 1))->i;
	}
};

ll check(const vector<ll> &a, int mult) {
	int n = a.size() - 1;
	ll rtn = 0;
	vector<ll> s(n + 1);
	s[0] = 0;
	s[1] = a[1];
	for (int i = 2; i <= n; i++) s[i] = s[i - 1] + a[i];
	cht hull(1);
	hull.insert(mult, -mult * s[0]);
	for (int i = 2, at, at2; i <= n; i++) {
		at = hull.iquery(a[i]) + 1;
//		cout << "index " << i << " with at=" << at << " which gives " << mult * (s[i - 1] - i * a[i] + at * a[i] - s[at - 1]) << endl;
		rtn = max(rtn, mult * (s[i - 1] - i * a[i] + at * a[i] - s[at - 1]));
		hull.insert(mult * i, -mult * s[i - 1]);
	}
	return rtn;
}

int n;
vector<ll> a;
ll ans, val = 0;

int main() {
	fast;
	cin >> n;
	a.resize(n + 1, 0);
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) val += (i * a[i]);
	ans = val;
	ans = max(ans, val + check(a, 1));
	a.push_back(0);
	reverse(a.begin(), a.end());
	a.pop_back();
	ans = max(ans, val + check(a, -1));
	cout << ans << endl;
}