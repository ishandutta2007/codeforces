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

const ll MOD = 1e6 + 3;

ll modExp(ll a, ll n) {
	ll res = 1;
	while (n) {
		if (n & 1) res = res*a % MOD;
		a = a*a % MOD;
		n /= 2;
	}
	return res;
}

ll o2(ll n) {
	if (!n) return 0;
	return n/2 + o2(n/2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, k; cin >> n >> k;
	if (n <= 60 && ((1LL << n) < k)) {
		cout << "1 1" << endl;
		return 0;
	}
	
	ll half = (MOD+1)/2;
	
	ll A = 1;
	if (k >= MOD + 10) {
		A = 0;
	} else {
		ll x = modExp(2,n);
		FOR(i,1,k) A = A * (--x) % MOD;
	}
	A = A * modExp(half,o2(k-1)) % MOD;

	ll B = modExp(modExp(2,n),k-1);
	B = B * modExp(half,o2(k-1)) % MOD;
	
	A = (B - A + MOD) % MOD;

	cout << A << " " << B << endl;

}