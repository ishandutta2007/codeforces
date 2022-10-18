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
	vl c(n);
	FOR(i,0,n) cin >> c[i];
	ll res = 0, csum = 0, bsum = 0;
	FOR(i,0,n) csum += c[i];
	vb iscap(n);
	FOR(i,0,k) {
		ll b; cin >> b;
		b--;
		bsum += c[b];
		iscap[b] = true;
		res += c[b] * (csum - bsum);
	}
	FOR(i,0,n) if (!iscap[i] && !iscap[(i+1)%n]) res += c[i] * c[(i+1)%n];
	
	cout << res << endl;

}