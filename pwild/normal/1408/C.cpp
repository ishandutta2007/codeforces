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

double distance(double t, const vl &a) {
	double res = 0;
	FOR(i,0,sz(a)) {
		double v = i+1;
		if (t*v < a[i]) {
			res += t*v;
			return res;
		}
		res += a[i];
		t -= a[i]/v;
	}
	return res;
}

double solve() {
	ll n, len;
	cin >> n >> len;
	vl a(n+1);
	FOR(i,0,n) cin >> a[i];
	a[n] = len;
	FORD(i,0,n) a[i+1] -= a[i];
	
	vl b = a;
	reverse(all(b));
	
	double tmin = 0, tmax = 2e9;
	FOR(k,0,70) {
		double t = (tmin+tmax)/2;
		if (distance(t,a) + distance(t,b) >= len) tmax = t;
		else tmin = t;
	}
	return tmin;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll tc; cin >> tc;
	while (tc--) {
		cout << fixed << setprecision(20) << solve() << endl;
	}
}