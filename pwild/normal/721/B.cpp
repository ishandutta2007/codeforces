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

ll f(ll i, ll k) {
	return i+1 + (i/k)*5; 
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, k; cin >> n >> k;
	vector<vector<string>> s(110);
	FOR(i,0,n) {
		string t; cin >> t;
		s[sz(t)].pb(t);
	}
	
	string pw; cin >> pw;
	
	ll i1 = 0;
	FOR(i,0,sz(pw)) i1 += sz(s[i]);
	ll i2 = i1 + sz(s[sz(pw)]) - 1;
	
	cout << f(i1,k) << " " << f(i2,k) << endl;
}