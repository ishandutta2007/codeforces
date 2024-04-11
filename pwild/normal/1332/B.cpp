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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	vl primes = {2,3,5,7,11,13,17,19,23,29,31};

	ll tc; cin >> tc;
	while (tc--) {
		ll n; cin >> n;
		vl a(n);
		FOR(i,0,n) cin >> a[i];
		FOR(i,0,n) for (ll p: primes) if (a[i]%p == 0) a[i] = p;
		
		ll m = 0;
		map<ll,ll> id;
		FOR(i,0,n) {
			if (!id.count(a[i])) id[a[i]] = ++m;
			a[i] = id[a[i]];
		}

		cout << m << endl;
		FOR(i,0,n) cout << a[i] << " \n"[i+1==n];
	}
}