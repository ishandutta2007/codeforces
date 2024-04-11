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
	
	string a = "+";
	char c;
	while (true) {
		cin >> c >> c;
		if (c == '=') break;
		a.pb(c);
	}
	ll n; cin >> n;
	ll k = sz(a), kpos = 0;
	FOR(i,0,k) kpos += a[i] == '+';
	ll kneg = k - kpos;
	ll rmin = kpos - n*kneg, rmax = n*kpos - kneg;
	if (rmin > n || rmax < n) {
		cout << "Impossible" << endl;
		return 0;
	}
	cout << "Possible" << endl;
	ll diff = n - rmin;
	vl x(k);
	FOR(i,0,k) {
		ll curdiff = min(n-1,diff);
		diff -= curdiff;
		if (a[i] == '+') x[i] = 1 + curdiff;
		else x[i] = n - curdiff;
	}
	
	FOR(i,0,k) {
		if (i) cout << a[i] << " ";
		cout << x[i] << " ";
	}
	cout << "= " << n << endl;

}