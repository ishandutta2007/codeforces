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
	
	ll n, k; cin >> n >> k;
	
	if (k <= n || n == 4) {
		cout << -1 << endl;
		return 0;
	}
	ll a, b, c, d; cin >> a >> b >> c >> d;
	vl v;
	FOR(i,1,n+1) if (i != a && i != b && i != c && i != d) v.pb(i);
	
	cout << a << " " << c;
	for (ll i : v) cout << " " << i;
	cout << " " << d << " " << b << endl;
	cout << c << " " << a;
	for (ll i : v) cout << " " << i;
	cout << " " << b << " " << d << endl;




}