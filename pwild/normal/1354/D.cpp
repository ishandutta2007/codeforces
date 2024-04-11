#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pll;
typedef vector<bool> vb;
const double eps = 1e-9;
#define sz(c) ll((c).size())
#define all(c) begin(c), end(c)
#define FOR(i,a,b) for (ll i = (a); i < (b); i++)
#define FORD(i,a,b) for (ll i = (b)-1; i >= (a); i--)
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define TR(X) ({ if(1) cerr << "TR: " << (#X) << " = " << (X) << endl; })

struct bit {
	ll n;
	vl a;

	bit(ll n): n(n), a(n+2) { }
	
	void add(ll i, ll v) {
		for (i++; i <= n+1; i += i & -i) a[i] += v;
	}
	
	ll get(ll i) {
		ll res = 0;
		for (; i; i -= i & -i) res += a[i];
		return res;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, q;
	cin >> n >> q;

	bit B(n+2);

	FOR(i,0,n) {
		ll a; cin >> a;
		B.add(a,1);
	}

	while (q--) {
		ll k; cin >> k;
		if (k >= 0) {
			B.add(k,1);
		} else {
			k = -k;
			ll lo = 0, hi = n+2;
			while (hi-lo > 1) {
				ll i = (lo+hi)/2;
				if (B.get(i) < k) lo = i; else hi = i;
			}
			B.add(lo,-1);
		}
	}

	FOR(i,1,n+2) {
		if (B.get(i)) {
			cout << i-1 << endl;
			return 0;
		}
	}
	cout << 0 << endl;
}