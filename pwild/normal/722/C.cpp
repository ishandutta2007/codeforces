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
	vl a(n);
	FOR(i,0,n) cin >> a[i];
	vl s(n+1);
	FOR(i,0,n) s[i+1] = s[i] + a[i];

	vl p(n);
	FOR(i,0,n) cin >> p[i], p[i]--;
	
	set<ll> dest = {-1,n};
	multiset<ll> sums;
	sums.insert(s[n]);

	FOR(i,0,n) {
		ll lo = *(--dest.lower_bound(p[i]));
		ll hi = *(dest.upper_bound(p[i]));
		sums.erase(sums.find(s[hi]-s[lo+1]));
		sums.insert(s[hi]-s[p[i]+1]);
		sums.insert(s[p[i]]-s[lo+1]);
		dest.insert(p[i]);
		cout << *sums.rbegin() << "\n";
	}



}