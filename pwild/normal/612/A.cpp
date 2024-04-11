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
	
	ll n, p, q; cin >> n >> p >> q;
	string s; cin >> s;

	for (ll i = 0; p*i <= n; i++) if ((n-p*i) % q == 0) {
		ll j = (n-p*i)/q;
		
		cout << i+j << endl;
		FOR(k,0,i) {
			cout << s.substr(0,p) << endl;
			s = s.substr(p);
		}
		FOR(k,0,j) {
			cout << s.substr(0,q) << endl;
			s = s.substr(q);
		}
		
		return 0;
	}
	cout << -1 << endl;

}