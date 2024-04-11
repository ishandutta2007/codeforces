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
#define DBGDO(X) ({ if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; })

ll n;
vl a; 
vector<double> b;

double f(double x) {
	FOR(i,0,n) b[i] = a[i] - x;
	
	double smin = 0, smax = 0, cmin = 0, cmax = 0;
	FOR(i,0,n) {
		cmin += b[i], cmax += b[i];
		cmin = min(cmin,0.0), cmax = max(cmax,0.0);
		smin = min(smin,cmin), smax = max(smax,cmax);
	}
	return max(abs(smin),abs(smax));
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	a = vl(n);
	b = vector<double>(n);
	FOR(i,0,n) cin >> a[i];
	
	double l = -1e5, r = 1e5;
	FOR(t,0,200) {
		double lm = l + (r-l)/3, rm = l + 2*(r-l)/3;
		if (f(lm) < f(rm)) r = rm; else l = lm;
	}

	cout << fixed << setprecision(12) << f(l) << endl;

}