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
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define TR(X) ({ if(1) cerr << "TR: " << (#X) << " = " << (X) << endl; })

ll f(ll n, ll x) {
	if (x%2 == 0) {
		return x/2;
	} else if (n%2 == 0) {
		return n/2 + f(n/2, x/2);
	} else {
		return n/2 + f((n+1)/2, (x+1)/2);
	}
}

void simulate(ll n) {
	vl a(2*n);
	FOR(i,0,n) a[2*i] = i+1;

	while (true) {
		ll i = 2*n-1;
		while (a[i] == 0) i--;
		if (i == n-1) break;

		ll j = i-1;
		while (a[j] != 0) j--;

		a[j] = a[i];
		a[i] = 0;

	}
	FOR(k,0,n) assert(a[k]-1 == f(n,k));
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	FOR(n,1,20) simulate(n);
	
	ll n, q;
	cin >> n >> q;
	while (q--) {
		ll x; cin >> x;
		cout << 1+f(n,x-1) << "\n";
	}
}