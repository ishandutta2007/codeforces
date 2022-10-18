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

const ll maxN = 3e6;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	vb pr(maxN,true);
	vl primes;
	pr[0] = pr[1] = false;
	for (ll i = 2; i < maxN; i++) if (pr[i]) {
		primes.pb(i);
		for (ll j = i*i; j < maxN; j += i) pr[j] = false;
	}

	ll n, k; cin >> n >> k;
	ll m = n/2;
	if (n == 1 && k > 0) {
		cout << -1 << endl;
		return 0;
	}
	if (m > k) {
		cout << -1 << endl;
		return 0;
	}
	ll r = k-m+1;
	
	vl res(n);
	res[0] = 2*r, res[1] = 3*r;

	FOR(i,2,n) res[i] = primes[i];

	FOR(i,0,n-1) cout << res[i] << " ";
	cout << res[n-1] << endl;

}