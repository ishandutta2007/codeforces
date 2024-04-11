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

const ll MOD = 1e9 + 7;

vector<pair<ll,string>> query;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s; cin >> s;
	ll q; cin >> q;
	q++;
	query.resize(q);
	query[0] = {0,s};
	FOR(i,1,q) {
		string t; cin >> t;
		query[i] = {t[0]-'0',t.substr(3)};
	}
	
	vector<pll> dp(10);
	FOR(j,0,10) dp[j] = {j,10};
	FORD(i,0,q) {
		ll val = 0, pow = 1;
		ll j = query[i].xx;
		string &t = query[i].yy;
		FOR(k,0,sz(t)) {
			ll cval, cpow;
			tie(cval,cpow) = dp[t[k]-'0'];
			val = (val * cpow + cval) % MOD;
			pow = pow * cpow % MOD;
		}
		dp[j] = {val,pow};
	}
	cout << dp[0].xx << endl;

}