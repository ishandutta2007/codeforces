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

// is a*b <= c*d ?
bool compare(ll a, ll b, ll c, ll d) {
	double ab = double(a)*b, cd = double(c)*d;
	if (abs(ab-cd)/max(1.0,abs(ab)) > 1e-9) return ab < cd;
	
	ll x = a*b, y = c*d;
	if (abs(x-y) < 1LL << 63) return x < y;
	return y < x;
}

// Stores set of lines a*x+b, supports max-queries at given x-values.
// Lines must be inserted by increasing slope a.
// Maxima must be queried by increasing x.
struct envelope {
	struct line {
		ll a, b;
		ll operator()(ll x) { return a*x + b; }
	};
	deque<line> v;

	bool bad(line s, line t, line u) {
		return compare(t.a-s.a, u.b-s.b, u.a-s.a, t.b-s.b);
	}

	void add_line(ll a, ll b) {
		v.push_front({a,b});
		while (sz(v) >= 3 && bad(v[0],v[1],v[2])) v.erase(begin(v)+1);
	}
	
	ll find_max(ll x) {
		if (v.empty()) return -oo;
		while (sz(v) >= 2 && v[sz(v)-2](x) >= v[sz(v)-1](x)) v.pop_back();
		return v[sz(v)-1](x);
	}
};

struct rect { ll x, y, a; };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;
	vector<rect> v(n);
	FOR(i,0,n) cin >> v[i].x >> v[i].y >> v[i].a;
	sort(all(v),[&](rect r, rect s) { return r.x < s.x; });
	
	ll res = 0;
	envelope E;
	for (rect r: v) {
		ll cur = r.x*r.y - r.a + max(0LL, E.find_max(-r.y));
		E.add_line(r.x,cur);
		res = max(res,cur);
	}
	cout << res << endl;
}