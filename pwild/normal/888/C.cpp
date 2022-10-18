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
	vl last(26,-1);
	vl dmax(26,0);

	ll n = sz(s);
	FOR(i,0,n) {
		ll j = s[i]-'a';
		dmax[j] = max(dmax[j], i-last[j]);
		last[j] = i;
	}
	FOR(j,0,26) dmax[j] = max(dmax[j], n-last[j]);
	
	FOR(j,0,26) cerr << dmax[j] << " ";
	cerr << endl;

	ll res = n;
	FOR(j,0,26) res = min(res,dmax[j]);
	cout << res << endl;
}