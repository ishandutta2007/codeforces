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

struct point {
	double x, y;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	point a, b;
	cin >> a.x >> a.y >> b.x >> b.y;
	
	double v, tc;
	cin >> v >> tc;
	
	point w1, w2;
	cin >> w1.x >> w1.y >> w2.x >> w2.y;
	
	double tmin = 0, tmax = 1e18;
	FOR(k,0,1000) {
		double t = (tmin+tmax)/2;

		double t1 = min(tc,t);
		double t2 = max(t-tc,0.0);

		double cx = a.x + t1*w1.x + t2*w2.x;
		double cy = a.y + t1*w1.y + t2*w2.y;
		
		bool ok = hypot(cx-b.x, cy-b.y) < t*v;
		(ok ? tmax : tmin) = t;
	}
	cout << fixed << setprecision(20) << tmin << endl;
}