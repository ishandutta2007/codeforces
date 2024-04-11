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
	
	ll n; cin >> n;
	vb pr(n+1,true);
	pr[0] = pr[1] = false;
	FOR(i,2,n+1) if (pr[i]) for (ll j = i*i; j <= n; j += i) pr[j] = false;
	
	vl match(n+1,-1);
	FORD(i,2,n+1) if (pr[i]) {
		vl mults;
		for (ll j = i; j <= n; j += i) if (match[j] == -1) mults.pb(j);
		ll k = sz(mults);
		if (k == 1) continue;
		if (k % 2 == 0) {
			FOR(i,0,k/2) match[mults[2*i]] = mults[2*i+1];
			FOR(i,0,k/2) match[mults[2*i+1]] = mults[2*i];
		} else {
			FOR(i,1,k/2) match[mults[2*i+1]] = mults[2*i+2];
			FOR(i,1,k/2) match[mults[2*i+2]] = mults[2*i+1];
			match[mults[0]] = mults[2];
			match[mults[2]] = mults[0];
		}
	}

	ll res = 0;
	FOR(i,0,n+1) res += match[i] != -1;
	res /= 2;
	cout << res << endl;
	FOR(i,0,n+1) if (match[i] > i) cout << i << " " << match[i] << endl;
}