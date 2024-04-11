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

vl primes;

bool prime(ll n) {
	if (n < 2) return false;
	auto it = lower_bound(all(primes),n);
	if (it != end(primes) && *it == n) return true;
	for (ll p: primes) {
		if (n % p == 0) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll m = 200000;
	vb pr(m,true);
	for (ll i = 2; i < m; i++) if (pr[i]) {
		primes.pb(i);
		for (ll j = i*i; j < m; j += i) pr[j] = false;
	}

	ll n; cin >> n;
	
	if (prime(n)) {
		cout << 1 << endl;
		cout << n << endl;
		return 0;
	}
	
	ll nn = n - 6;
	while (!prime(nn)) nn -= 2;

	cout << 3 << endl;
	cout << nn << " ";
	n -= nn;
	
	for (ll p: primes) if (prime(n-p)) {
		cout << p << " " << n-p << endl;
		return 0;
	}
	
	assert(false);


}