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

ll n, k, imax = 0;
vl a;

template<typename num>
num val(num m) {
	num res = 0;
	num binom = 1;
	FOR(i,0,imax+1) {
		if (a[n-1-i]) res += binom * a[n-1-i];
		binom = (binom * (m+i+1)) / (i+1);
	}
	return res;
}

bool test(ll m) {
	if (val(double(m)) > k + 100) return true;
	return val(m) >= k;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> k;
	a.resize(n);
	FOR(i,0,n) cin >> a[i];
	
	FOR(i,0,n) if (a[i] >= k) {
		cout << 0 << endl;
		return 0;
	}
	
	FOR(i,0,n) if (a[n-1-i]) imax = i;

	ll lo = -1, hi = 1;
	while (!test(hi)) hi *= 2;
	while (hi-lo > 1) {
		ll mid = (lo+hi)/2;
		if (test(mid)) hi = mid; else lo = mid;
	}
	cout << hi+1 << endl;
}