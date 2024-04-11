#include <bits/stdc++.h>
using namespace std;

typedef int ll;
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
	vl a(n);
	FOR(i,0,n) cin >> a[i];
	sort(all(a));
	a.erase(unique(all(a)),end(a));
	n = sz(a);
	
	ll m = 1e6 + 10;
	vl lb(m);
	FOR(i,0,n) lb[a[i]] = a[i];
	FOR(i,1,m) if (!lb[i]) lb[i] = lb[i-1];
	
	ll res = 0;
	FOR(i,0,n) {
		for (ll x = a[i]; x < m; x += a[i]) {
			ll y = min(x+a[i],m)-1;
			res = max(res,lb[y]-x);
		}
	}
	cout << res << endl;

}