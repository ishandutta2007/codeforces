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

const ll m = 3333;
ll pw[m];

ll gcd(ll a, ll b) { return (b == 0) ? a : gcd(b, a%b); }

ll go(ll n, ll l, ll r) {
	ll diff = r-l;

	if (n == 1) return diff+1;
	if (n == 2) return (diff+1)*diff;
	if (n > 30) return 0;
	
	ll pmax = 1;
	while (true) {
		pw[pmax] = 1;
		FOR(i,1,n) pw[pmax] = min(pw[pmax]*pmax, r+1);
		if (pw[pmax] > r) break;
		pmax++;
	}
	
	ll res = 0;
	FOR(p,1,pmax) FOR(q,p+1,pmax) if (gcd(p,q) == 1) {
		ll amin = (l+pw[p]-1)/pw[p], amax = r/pw[q];
		if (amin <= amax) res += amax-amin + 1;
	}
	res *= 2;
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, l, r;
	cin >> n >> l >> r;
	cout << go(n,l,r) << endl;
}