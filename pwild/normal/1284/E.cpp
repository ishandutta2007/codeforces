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
	return a.y + eps < b.y;
}

point perp(point a) { return {-a.y,a.x}; } // rotate 90 degrees counterclockwise

ll ccw(point a, point b, point c) { // returns 1|0|-1 if c is left|straight|right of ab
	ll res = (b-a)%(c-a);
	return res ? (res > 0 ? 1 : -1) : 0;
}

bool on_segment(point p, point a, point b) {
	return (a-p)*(b-p) < 0 && ccw(a,b,p) == 0;
}

bool top(point p) {
	return p.y > 0 || (p.y == 0 && p.x > 0);
}

const ll N = 2525;
ll bin[N][5];

ll solve(vector<point> a) {
	ll n = sz(a);
	point o = {0,0};
	sort(all(a),[&](point p, point q) {
		if (top(p) != top(q)) return top(p) > top(q);
		return ccw(o,p,q) > 0;
	});
	
	ll res = bin[n][4], j = 0;
	FOR(i,0,n) {
		j = max(j,i+1);
		while (ccw(o,a[i],a[j%n]) > 0) j++;
		res -= bin[j-i-1][3];
	}
	// cerr << res << endl;
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	bin[0][0] = 1;
	FOR(n,1,N) {
		bin[n][0] = 1;
		FOR(k,1,5) bin[n][k] = bin[n-1][k-1] + bin[n-1][k];
	}
	
	ll n; cin >> n;
	vector<point> a(n);
	FOR(i,0,n) cin >> a[i].x >> a[i].y;

	ll res = 0;
	FOR(i,0,n) {
		vector<point> b;
		FOR(j,0,n) if (j != i) b.pb(a[j]-a[i]);
		res += solve(b);	
	}
	cout << res << endl;
}