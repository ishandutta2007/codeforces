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
	
	ll n, m; cin >> n >> m;
	vl a(n);
	FOR(i,0,n) cin >> a[i];
	a.erase(unique(all(a)),end(a));
	vl b(m);
	FOR(i,0,m) cin >> b[i];
	b.erase(unique(all(b)),end(b));
	
	ll res = 0;
	for (ll x: a) {
		ll j = lower_bound(all(b),x) - begin(b);
		ll cur = oo;
		FOR(dj,-1,2) {
			if (j+dj < 0 || j+dj >= m) continue;
			cur = min(cur,abs(x-b[j+dj]));
		}
		res = max(res,cur);
	}
	cout << res << endl;
}