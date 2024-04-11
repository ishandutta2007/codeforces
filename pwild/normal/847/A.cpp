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
	vl l(n), r(n);
	FOR(i,0,n) cin >> l[i] >> r[i], l[i]--, r[i]--;

	vl c(n,-1);
	ll C = 0;
	FOR(i,0,n) if (c[i] == -1) {
		c[i] = C;
		for (ll j = l[i]; j != -1; j = l[j]) c[j] = C;
		for (ll j = r[i]; j != -1; j = r[j]) c[j] = C;
		C++;		
	}
	
	FOR(i,0,n) if (r[i] == -1) FOR(j,0,n) if (l[j] == -1)
		if (c[i] == c[j]+1) r[i] = j, l[j] = i;
	
	FOR(i,0,n) cout << l[i]+1 << " " << r[i]+1 << endl;

}