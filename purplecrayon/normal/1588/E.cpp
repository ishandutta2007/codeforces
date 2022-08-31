#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
#warning fix later
// typedef long long ll;
const int MAXN = 3e3+10, MOD = 1e9+7;

template<typename T> T K(T a) { return a * a; }
#define K(a) K(1LL * (a))
typedef double ll; // can be changed to 'long double'
typedef double ld;
const ld PI = 2 * acos(0);
const ld eps = 1e-9;
#pragma GCC diagnostic ignored "-Wnarrowing"
struct P {
	ll x, y;
    string ts(){ return "(" + to_string(x) + ", " + to_string(y) + ")"; }
    void read(){ cin >> x >> y; }
	P operator -(const P& he) const {
		return P{x - he.x, y - he.y};
	}
	P operator +(const P& he) const {
		return P{x + he.x, y + he.y};
	}
	ll operator *(const P& he) const {
		return x * he.y - y * he.x;
	}
	P operator *(ld mul) const {
		return P{x * mul, y * mul};
	}
	P operator /(ld mul) const {
		return P{x / mul, y / mul};
	}
	ld len() const {
		return sqrt(x * x + y * y);
	}
	ll dot(P b) { return x * b.x + y * b.y; }
	ld len() { return sqrt(K(x) + K(y)); }
	P scaleTo(ld to) { return *this * (to / len()); }
	ld dist(P & b) { return (*this - b).len(); }
	P rotate90() { return P{-y, x}; }
	ld angle() { return atan2(y, x); }
    ld pos_angle() { ld ans = angle(); if (ans < -eps) ans += 2 * PI; return ans; }
	P rotate(ld ang) {
		ld c = cos(ang), s = sin(ang);
		return P{x * c - y * s, x * s + y * c};
	}
	// '<' and 'below()' needed for Convex Hull
	bool operator < (P he) { return make_pair(x, y) < make_pair(he.x, he.y); }
	bool below(P a, P b) { return (b - a) * (*this - a) <= 0/*eps*/; } //INFO 1
	// Internal/External Similitude Center
	P apol_in(P b, ld ratio) { // ratio = dist()/he.dist()
		return (*this + b * ratio) / (1 + ratio);
	}
	P apol_out(P b, ld ratio) {
		return (*this - b * ratio) / (1 - ratio);
	}
};
struct L2 {
	P one, two;
	// P p[2]; P & operator [](int i) { return p[i]; }
	// const P & operator [](int i) const { return p[i]; }
	P dir() { return two - one; }
	P normal() { return dir().rotate90(); }
	ld dist(P he) {
		return abs((he - one) * (he - two)) / one.dist(two);
	}
	ld segDist(P he) { // epsilon not needed, but it would work too
		if((he - two) * normal() < 0 && normal() * (he - one) < 0)
			return dist(he);
		return min(one.dist(he), two.dist(he));
	}
	P inter(L2 he) {
		P A = dir(), B = he.dir();
		ll den = A * B;
		assert(abs(den) > eps); // parallel, maybe equal
		return (A * (he.one * he.two) - B * (one * two)) * (1.0 / den);
		// A = (x1*y2-y1*x2)*(x3-x4)-(x1-x2)*(x3*y4-y3*x4)
		// A'= (x1*y2-y1*x2)*(y3-y4)-(y1-y2)*(x3*y4-y3*x4)
		// B = (x1-x2)*(y3-y4)-(y1-y2)*(x3-x4)
		// return P{A / B, A' / B};
	}
	P project(P he) {
		P unit_normal = normal().scaleTo(1);
		return he + unit_normal * unit_normal.dot(one - he);
	}
	P reflect(P he) { return project(he) * 2 - he; }
// for CH: sort by slope; below() : change to L3 or compare 'x' of intersections
};
L2 toL2(ll a, ll b, ll c) {
	P first;
	if(abs(b) > eps) first = P{0, (ld) -c / b};
	else if(abs(a) > eps) first = P{(ld) -c / a, 0};
	else assert(false);
	return L2{first, first + P{b, -a}};
}
ll det(ll t[3][3]) { // for CH of lines Ax+By+C=0
	ll s = 0;
	for(int i = 0; i < 3; ++i)
		for(int j = i + 1, mul = 1; j != i + 3; ++j, mul -= 2)
			s += t[0][i] * t[1][j%3] * t[2][3-i-j%3] * mul;
	return s;
}
struct L3 {
	// a * x + b * y + c = 0, assert(b > 0 || (b == 0 && a > 0))
	ll a, b, c;
	L3 fix() { // <done>TODO, test it</done>
		assert(abs(b) > eps || abs(a) > eps);
		ll g = (b > eps || (abs(b) < eps && a > eps)) ? 1 : -1;
		// __gcd(x,0) is undef-beh, http://codeforces.com/blog/entry/13410
		// if(is_integral<ll>::value) g *= abs(__gcd(c, __gcd(a?b:a, a?a:b)));
		// if(is_floating_point<ll>::value) g *= sqrt(K(a) + K(b));
		return L3{a / g, b / g, c / g};
	}
	ld dist(P he) {
		return abs(a * he.x + b * he.y + c) / sqrt(K(a) + K(b));
	}
	P dir() { return P{b, -a}; }
	P normal() { return P{a, b}; } // equivalently: dir().rotate90()
	P project(P he) {
		ld den = K(a) + K(b); // non-integer because we need division
		return P{(b * (b * he.x - a * he.y) - a * c) / den,
				 (a * (a * he.y - b * he.x) - b * c) / den };
	}
	P reflect(P he) { return project(he) * 2 - he; }
	P inter(L3 he) {
		#define Q(i, j) (i * he.j - j * he.i)
		ll den = Q(a, b);
		assert(abs(den) > 1e-14); // parallel, maybe equal
		return P{Q(b, c), Q(c, a)} * (1.0 / den);
		#undef Q
	}
	bool operator < (L3 he) {
		// produces the order for finding an upper envelope
		// assert(b > 0 && he.b > 0);
		// a / b < he.a / he.b, ties: -c/b < ...
		if(abs(a * he.b - b * he.a) < eps) return b * he.c < c * he.b;
							// <done>test it</done>
		return a * he.b < b * he.a;
	}
	bool below(L3 A, L3 C) {
		ll t[3][3] = { {A.a,A.b,A.c}, {a,b,c}, {C.a,C.b,C.c} };
		return det(t) <= 0/*eps*/; // WARN1
	}
};
L3 toL3(P one, P two) {
	ll a = two.y - one.y;
	ll b = one.x - two.x;
	return L3{a, b, -(a * one.x + b * one.y)}.fix();
}
struct Circle {
	P o;
	ld r;
	vector<P> tangency(P he) {
		ld d = o.dist(he);
		if(abs(d - r) < eps) return vector<P>{he};
		if(d < r) return vector<P>{};
		ld alpha = asin(r / d);
		P vec = (o - he) * sqrt(1 - K(r / d)); // *sqrt(d^2-r^2)/d
		// faster: compute 'sin' and 'cos' once
		return vector<P>{he + vec.rotate(alpha), he + vec.rotate(-alpha)};
	}
	vector<P> inter(L3 he) {
		P prim = he.project(o);
		ld d = prim.dist(o);
		if(d >= r + eps) return vector<P>{};
		if(abs(d - r) <= eps) return vector<P>{prim};
		P vec = he.dir().scaleTo(sqrt(K(r) - K(d)));
		return vector<P>{prim + vec, prim - vec};
	}	
	vector<P> inter(Circle he) {
		return inter(L3{2*(o.x-he.o.x), 2*(o.y-he.o.y),
				K(r)-K(he.r)-K(o.x)-K(o.y)+K(he.o.x)+K(he.o.y)});
	}
	vector<L2> tangency(Circle he) {
		vector<L2> ret;
		ld ratio = r / he.r;
		auto considerPoint = [&] (P p) {
			vector<P> one = tangency(p), two = he.tangency(p);
			for(int i = 0; i < (int) min(one.size(), two.size()); ++i)
				ret.push_back(L2{one[i], two[i]});
		};
		if(abs(r - he.r) < 1e-9) { // beka z nawiasow XD
			P dir = (he.o - o).rotate90().scaleTo(r);
			for(int tmp : {1, -1})
				ret.push_back(L2{o + dir * tmp, he.o + dir * tmp});
		}
		else considerPoint(o.apol_out(he.o, ratio));
		// the following will produce 2/1/0 pairs
		// for distant/touching/intersecting circles
		considerPoint(o.apol_in(he.o, ratio));
		return ret;
	}
};

ar<ld, 2> isect_range(ar<ld, 2> one, ar<ld, 2> two) {
    ar<ld, 2> ans = {max(one[0], two[0]), min(one[1], two[1])};
    if (ans[0] > ans[1]) return {-1, -1};
    return ans;
}
ar<ld, 2> isect(ar<ld, 2> one, ar<ld, 2> two) {
    if (one == ar<ld, 2>{-1, -1} || two == ar<ld, 2>{-1, -1}) return {-1, -1};
    if (one[0] <= one[1] && two[0] <= two[1]) return isect_range(one, two);

    auto get_ranges = [&](ar<ld, 2> c) {
        vector<ar<ld, 2>> v;
        if (c[0] <= c[1]) v.push_back(c), v.push_back({c[0] + 2 * PI, c[1] + 2 * PI});
        else v.push_back({c[0], c[1] + 2 * PI});
        return v;
    };

    // only one intersection
    vector<ar<ld, 2>> range_one = get_ranges(one), range_two = get_ranges(two);
    for (auto& x : range_one) for (auto& y : range_two) {
        ar<ld, 2> ans = isect_range(x, y);
        if (ans != ar<ld, 2>{-1, -1}) {
            if (ans[0] >= 2*PI) ans[0] -= 2*PI;
            if (ans[1] >= 2*PI) ans[1] -= 2*PI;
            return ans;
        }
    }
    return {-1, -1};
}

int n, R;
P pts[MAXN];
bool good[MAXN][MAXN];

void solve() {
    cin >> n >> R;
    for (int i = 0; i < n; i++) pts[i].read();


    for (int i = 0; i < n; i++) {
        ar<ld, 2> range{-2, -2};
        for (int j = 0; j < n; j++) {
            Circle c{pts[j], R};
            vector<P> tangent = c.tangency(pts[i]);
            if (sz(tangent) < 2) continue;

            ld one = (tangent[0] - pts[i]).pos_angle(), two = (tangent[1] - pts[i]).pos_angle();
            if (one > two) swap(one, two);
            if (two - one > PI) {
                swap(one, two);
            }
            // the segment on a circle from one..two
            if (range == ar<ld, 2>{-2, -2}) range = {one, two};
            else range = isect(range, {one, two});
        }
        if (range == ar<ld, 2>{-1, -1}) continue;
        if (range == ar<ld, 2>{-2, -2}) {
            for (int j = 0; j < n; j++) good[i][j] = 1;
            continue;
        }
        for (int j = 0; j < n; j++) if (i != j) {
            ld cur = (pts[j] - pts[i]).pos_angle();
            if (isect(range, {cur, cur}) != ar<ld, 2>{-1, -1}) {
                good[i][j] = 1;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            ans += good[i][j] && good[j][i];

    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}