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
	ll n; cin >> n;
	ll s12, s13, s23;
	cout << "? 1 2" << endl;
	cin >> s12;
	cout << "? 1 3" << endl;
	cin >> s13;
	cout << "? 2 3" << endl;
	cin >> s23;

	vl a(n);
	a[0] = (s12 + s13 - s23)/2;
	a[1] = s12 - a[0], a[2] = s13 - a[0];
	FOR(i,3,n) {
		cout << "? 1 " << i+1 << endl;
		cin >> a[i];
		a[i] -= a[0];
	}
	cout << "!";
	FOR(i,0,n) cout << " " << a[i];
	cout << endl;
}