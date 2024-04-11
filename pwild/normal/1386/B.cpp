#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pll;
typedef vector<bool> vb;
const ll oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;
#define sz(c) ll((c).size())
#define all(c) begin(c), end(c)
#define FOR(i,a,b) for (ll i = (a); i < (b); i++)
#define FORD(i,a,b) for (ll i = (b)-1; i >= (a); i--)
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define TR(X) ({ if(1) cerr << "TR: " << (#X) << " = " << (X) << endl; })

using i128 = __int128;

ostream &operator<<(ostream &out, i128 x) {
	ll N = 1e18;
	if (x < 0) out << "-", x = -x;
	if (x >= N) out << ll(x/N) << setw(18) << setfill('0') << ll(x%N);
	else out << ll(x);
	return out;
}

struct fraction {
	i128 a, b;

	fraction(i128 c, i128 d): a(c), b(d) {
		i128 g = __gcd(a,b);
		a /= g, b /= g;
		if (b < 0) a = -a, b = -b;
	}

	fraction operator+(const fraction &f) const { return fraction(a*f.b + b*f.a, b*f.b); }
	fraction operator-(const fraction &f) const { return fraction(a*f.b - b*f.a, b*f.b); }
	fraction operator*(const fraction &f) const { return fraction(a*f.a, b*f.b); }
	bool operator<(const fraction &f) const { return a*f.b < b*f.a; }
	bool operator<=(const fraction &f) const { return a*f.b <= b*f.a; }
	bool operator!=(const fraction &f) const { return a != f.a || b != f.b; }
};

ostream &operator<<(ostream &out, fraction f) { return out << f.a << "/" << f.b; }

struct point { i128 x, y; };

const point orig = {0,0};

pair<fraction, fraction> read_point() {
	ll a, b, c;
	cin >> a >> b >> c;
	return {fraction(a,a+b+c), fraction(b,a+b+c)};
}

point operator+(point a, point b) { return {a.x+b.x, a.y+b.y}; }
point operator-(point a, point b) { return {a.x-b.x, a.y-b.y}; }

i128 operator*(point a, point b) { return a.x*b.x + a.y*b.y; } // dot product
i128 operator%(point a, point b) { return a.x*b.y - a.y*b.x; } // cross product

bool operator<(point a, point b) { // lexicographical compare
	if (a.x != b.x) return a.x < b.x;
	return a.y < b.y;
}

ostream &operator<<(ostream &out, point a) { // for debugging
	return out << "(" << a.x << "," << a.y << ")";
}

ll ccw(point a, point b, point c) { // returns 1|0|-1 if c is left|straight|right of ab
	i128 res = (b-a)%(c-a);
	return res ? (res > 0 ? 1 : -1) : 0;
}

bool on_segment(point p, point a, point b) {
	return (a-p)*(b-p) <= 0 && ccw(a,b,p) == 0;
}

ll solve(multiset<point> &points) {
	if (points.count(orig)) return 1;

	for (point a: points) for (point b: points) {
		if (on_segment(orig, a, b)) return 2;
	}

	for (point a: points) for (point b: points) for (point c: points) {
		if (ccw(orig, a, b) > 0 && ccw(orig, b, c) > 0 && ccw(orig, c, a) > 0) return 3;
	}

	return 0;
}

struct ccw_cmp {
	bool operator()(const point &a, const point &b) const {
		if ((orig < a) != (orig < b)) return orig < b;
		return ccw(orig,a,b) > 0;
	}
};

bool removed[123456];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	auto [cx,cy] = read_point();
	
	set<point, ccw_cmp> hull;
	map<point,ll> point_count;
	vl ccw_count(3);
	ll orig_count = 0, opp_count = 0;
	
	auto add_angle = [&](point a, point b, ll add) {
		i128 c = a%b;
		ll k = c ? (c > 0 ? 1 : -1) : 0;
		ccw_count[k+1] += add;
	};

	auto add_point = [&](point p) {
		if (p.x == 0 && p.y == 0) {
			orig_count++;
		} else if (hull.empty()) {
			hull.insert(p);
			add_angle(p,p,1);
		} else {
			auto nit = hull.lower_bound(p);
			if (nit == end(hull)) nit = begin(hull);

			auto pit = prev(nit == begin(hull) ? end(hull) : nit);
			
			add_angle(*pit, *nit, -1);
			add_angle(*pit, p, 1);
			add_angle(p, *nit, 1);

			hull.insert(p);
			opp_count += hull.count(orig-p);
		}
	};
	
	auto remove_point = [&](point p) {
		if (p.x == 0 && p.y == 0) {
			orig_count--;
		} else if (sz(hull) == 1) {
			hull.clear(), add_angle(p,p,-1);
		} else {
			auto it = hull.find(p);
			assert(it != end(hull));

			auto pit = prev(it == begin(hull) ? end(hull) : it);
			auto nit = next(it);
			if (nit == end(hull)) nit = begin(hull);

			add_angle(*pit, *nit, 1);
			add_angle(*pit, p, -1);
			add_angle(p, *nit, -1);

			hull.erase(it);
			opp_count -= hull.count(orig-p);
		}
	};

	vector<point> points;

	ll n; cin >> n;
	while (n--) {
		char op; cin >> op;

		if (op == 'A') {
			auto [x,y] = read_point();
			x = x - cx, y = y - cy;

			point a = {x.a*y.b, y.a*x.b};
			i128 g = __gcd(a.x,a.y);
			if (g < 0) g = -g;
			if (g) a.x /= g, a.y /= g;
			
			points.pb(a);
			if (++point_count[a] == 1) add_point(a);
		} else if (op == 'R') {
			ll i; cin >> i;
			removed[i-1] = true;
			point a = points[i-1];
			if (point_count[a]-- == 1) remove_point(a);
		} else {
			assert(0);
		}
		
		ll res = 0;
		if (orig_count > 0) {
			res = 1;
		} else if (opp_count > 0) {
			res = 2;
		} else if (sz(hull) >= 3 && ccw_count[0] == 0) {
			res = 3;
		}
		cout << res << endl;	
	}
}