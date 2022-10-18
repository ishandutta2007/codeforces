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
	
	string s; cin >> s;
	ll n = sz(s), p = n;
	FOR(i,0,n) if (s[i] == '.') p = i;
	
	if (p < n) s = s.substr(0,p) + s.substr(p+1), n = sz(s);
	
	ll q = 0;
	while (q < n && s[q] == '0') q++;

	if (q == n) {
		cout << 0 << endl;
		return 0;
	}
	
	ll e = p-q-1;
	s = s.substr(q), n = sz(s);
	
	ll r = n;
	while (r > 0 && s[r-1] == '0') r--;
	s = s.substr(0,r), n = r;
	
	if (n == 1) cout << s;
	else cout << s[0] << "." << s.substr(1);

	if (e) cout << "E" << e;
	cout << endl;

}