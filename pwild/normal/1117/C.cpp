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
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define has(c,i) ((c).find(i) != end(c))
#define TR(X) ({ if(1) cerr << "TR: " << (#X) << " = " << (X) << endl; })

struct point { ll x, y; };

point operator+(point a, point b) { return {a.x+b.x, a.y+b.y}; }
point operator*(ll k, point a) { return {k*a.x,k*a.y}; }

point mv[256];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	mv['U'] = {0,1};
	mv['D'] = {0,-1};
	mv['L'] = {-1,0};
	mv['R'] = {1,0};

	point s, t;
	cin >> s.x >> s.y >> t.x >> t.y;

	ll n; cin >> n;
	string a; cin >> a;

	vector<point> pref(n+1);
	pref[0] = {0,0};
	FOR(i,0,n) pref[i+1] = pref[i] + mv[ll(a[i])];
	
	point period = pref[n];
	
	ll Tmin = -1, Tmax = oo;
	while (Tmax - Tmin > 1) {
		ll T = (Tmin + Tmax) / 2;
		
		point center = s + (T/n)*period + pref[T%n];
		point diff = t + (-1)*center;
		
		if (abs(diff.x) + abs(diff.y) <= T) Tmax = T;
		else Tmin = T;
	}
	
	ll res = Tmax;
	if (res == oo) res = -1;
	cout << res << endl;
}