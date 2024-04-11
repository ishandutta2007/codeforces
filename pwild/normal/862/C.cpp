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
	
	ll n, x; cin >> n >> x;
	
	if (x == 0 && n == 2) {
		cout << "NO" << endl;
		return 0;
	}
	
	cout << "YES" << endl;

	if (x == 0 && n % 4 == 2) {
		cout << "1 2 3 ";
		n -= 3;
	}

	ll A = 1 << 17, B = 1 << 18, C = 1 << 19;

	if (n > 4) {
		ll k = 2 * ((n-1)/4);
		FOR(i,0,k) cout << A+i << " " << A+(A-1-i) << " ";
		n -= 2*k;
	}

	if (n == 1) {
		cout << x << endl;
	} else if (n == 2) {
		cout << B << " " << B+x << endl;
	} else if (n == 3) {
		cout << B+C << " " << C << " " << B+x << endl;
	} else if (n == 4) {
		cout << B+C << " " << C << " " << B << " " << x << endl;
	} else assert(0);


}