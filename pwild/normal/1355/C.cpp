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

struct point { ll x, y; };

point operator+(point a,  point b) { return {a.x+b.x, a.y+b.y}; }
point operator-(point a,  point b) { return {a.x-b.x, a.y-b.y}; }
point operator*(ll t, point b) { return {t*b.x, t*b.y}; }

ll operator*(point a,  point b) { return a.x*b.x + a.y*b.y; } // dot product
ll operator%(point a,  point b) { return a.x*b.y - a.y*b.x; } // cross product

bool operator<(point a, point b) { // lexicographical compare
	if (a.x != b.x) return a.x < b.x;
	return a.y < b.y;
}

bool operator==(point a, point b) {
	return a.x == b.x && a.y == b.y;
}

ostream &operator<<(ostream &out, point a) { // for debugging
	return out << "(" << a.x << "," << a.y << ")";
}

double abs(point a) { return hypot(a.x,a.y); }
point perp(point a) { return {-a.y,a.x}; } // rotate 90 degrees counterclockwise

double angle(point a, point b) { // angle between two vectors (0 to pi)
	double d = a*b / abs(a) / abs(b);
	return acos(max(-1.0,min(1.0,d)));
}

ll ccw(point a, point b, point c) { // returns 1|0|-1 if c is left|straight|right of ab
	double res = (b-a)%(c-a);
	return res ? (res > 0 ? 1 : -1) : 0;
}

bool on_segment(point p, point a, point b) {
	return (a-p)*(b-p) <= 0 && ccw(a,b,p) == 0;
}

void convex_hull(vector<point> &p) {
	partial_sort(begin(p), begin(p)+1, end(p));
	sort(begin(p)+1, end(p), [&](point a, point b) {
		if (ll c = ccw(p[0],a,b)) return c == 1;
		return abs(a-p[0]) < abs(b-p[0]);
	});
	ll n = sz(p), k = 2;
	FOR(i,2,n) {
		p[k++] = p[i];
		while (k >= 3 && ccw(p[k-3],p[k-2],p[k-1]) <= 0) p[k-2] = p[k-1], k--;
	}
	p.resize(k);
}

ll pick(vector<point> p) {
	ll n = sz(p), a = 0, b = 0;
	FOR(i,0,n) {
		point u = p[i], v = p[(i+1)%n], w = v-u;
		a += u%v, b += abs(gcd(w.x,w.y));
	}
	return (abs(a)+b)/2 + 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
//	cout << pick({{2,1},{5,4},{5,6},{1,4}}) << endl;

	ll a, b, c, d;
	cin >> a >> b >> c >> d;

	ll res = 0;
	FOR(z,c,d+1) {
		// a <= x <= b
		// b <= y <= c
		// x+y >= z+1
		
		// max(b, z+1-x) <= y <= c
		// max(a, z+1-y) <= x <= b
		
		vector<point> poly;
		for (ll x: {a,b}) {
			ll ymin = max(b,z+1-x), ymax = c;
			if (ymin > ymax) continue;
			poly.pb({x,ymin}), poly.pb({x,ymax});
		}
		for (ll y: {b,c}) {
			ll xmin = max(a,z+1-y), xmax = b;
			if (xmin > xmax) continue;
			poly.pb({xmin,y}), poly.pb({xmax,y});
		}

		sort(all(poly));
		poly.erase(unique(all(poly)), end(poly));
		
		if (sz(poly) >= 2) {
			convex_hull(poly);
			res += pick(poly);
		} else {
			res += sz(poly);
		}
	}
	cout << res << endl;
}