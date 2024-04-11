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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	double a, b, c, d; cin >> a >> b >> c >> d;

	double rmin = 0, rmax = 2e9;
	
	FOR(k,0,100) {
		double r = (rmin + rmax) / 2;
		
		double admin = min({(a-r)*(d-r),(a-r)*(d+r),(a+r)*(d-r),(a+r)*(d+r)});
		double admax = max({(a-r)*(d-r),(a-r)*(d+r),(a+r)*(d-r),(a+r)*(d+r)});
		double bcmin = min({(b-r)*(c-r),(b-r)*(c+r),(b+r)*(c-r),(b+r)*(c+r)});
		double bcmax = max({(b-r)*(c-r),(b-r)*(c+r),(b+r)*(c-r),(b+r)*(c+r)});
		
//		bcmin = -bcmin, bcmax = -bcmax;
//		swap(bcmin,bcmax);
		
		if (bcmax < admin || admax < bcmin) rmin = r;
		else rmax = r;
	}
	
	cout << fixed << setprecision(12) << rmin << endl;

}