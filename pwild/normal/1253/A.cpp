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
		
bool solve() {
	ll n; cin >> n;
	vl a(n), b(n);
	FOR(i,0,n) cin >> a[i];
	FOR(i,0,n) cin >> b[i];


	ll imin = n, imax = -1;
	FOR(i,0,n) if (a[i] != b[i]) {
		imin = min(imin,i);
		imax = max(imax,i);
	}
	
	if (imin > imax) return true;
	
	ll diff = b[imin]-a[imin];
	if (diff < 0) return false;
	
	FOR(i,imin,imax+1) if (b[i]-a[i] != diff) return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll tc; cin >> tc;
	while (tc--) {
		cout << (solve() ? "YES" : "NO") << endl;
	}

}