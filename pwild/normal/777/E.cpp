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

void compress(vl &i2x, map<ll,ll> &x2i) {
	sort(all(i2x));
	i2x.erase(unique(all(i2x)),end(i2x));
	reverse(all(i2x));
	FOR(i,0,sz(i2x)) x2i[i2x[i]] = i;
}

struct BIT {
	ll n;
	vl bit;

	BIT(ll n): n(n) { bit.resize(n+2,0); }

	void add(int i, ll v) {
		for (++i; i <= n+1; i += i & -i) bit[i] = max(bit[i],v);
	}

	ll get_max(int i) {
		ll res = 0;
		for (; i; i -= i & -i) res = max(res,bit[i]);
		return res;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
/*	
	BIT bb(5);
	bb.add(0,1);
	bb.add(1,3);
	bb.add(2,2);
	bb.add(3,4);
	bb.add(4,2);
	DBGDO(bb.get_max(0));
	DBGDO(bb.get_max(1));
	DBGDO(bb.get_max(2));
	DBGDO(bb.get_max(3));
	DBGDO(bb.get_max(4));
*/

	ll n; cin >> n;
	
	vector<tuple<ll,ll,ll>> rings;
	FOR(i,0,n) {
		ll a, b, h; cin >> a >> b >> h;
		rings.eb(b,a,h);
	}
	
	sort(all(rings));

	vl a, b, h;
	for (ll i = 0; i < n; ) {
		ll ca, cb, ch;
		tie(cb,ca,ch) = rings[i];
		i++;
		while (i < n && get<0>(rings[i]) == cb) {
			ch += get<2>(rings[i]);
			i++;
		}
		a.pb(ca), b.pb(cb), h.pb(ch);
	}
	n = sz(a);
	
	vl i2x = a;
	for (ll x: b) i2x.pb(x);
	map<ll,ll> x2i;
	
	compress(i2x,x2i);
	
	vl dp(n);
	BIT bit(sz(i2x));

	FOR(i,0,n) {
		dp[i] = h[i] + bit.get_max(x2i[a[i]]);
		bit.add(x2i[b[i]], dp[i]);
	}

	ll res = 0;
	FOR(i,0,n) res = max(res,dp[i]);
	cout << res << endl;
}