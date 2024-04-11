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

ll len(ll x) {
	ll ld = 64-__builtin_clzll(x);
	return (1LL << ld) - 1;
}

ll f(ll n, ll l, ll r) {
	ll k = len(n);
	l = max(l,0LL);
	r = min(r,k);
	if (l >= r) return 0;
	if (n == 1) return 1;
	
	k /= 2;
	ll res = 0;
	if (n & 1) res += l <= k && k < r;
	res += f(n/2, l, r);
	res += f(n/2, l-k-1, r-k-1);
	//cout << n << " " << l << " " << r << " " << res << endl;
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, l, r;
	cin >> n >> l >> r;
	l--;

	if (n == 0) {
		cout << 0 << endl;
		return 0;
	}
	
	cout << f(n, l, r) << endl;
}