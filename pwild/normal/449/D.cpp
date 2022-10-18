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

const ll MOD = 1e9 + 7, N = 1 << 20;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;
	vl a(n);
	FOR(i,0,n) cin >> a[i];

	vl b(N);
	FOR(i,0,n) b[a[i]]++;
	reverse(all(b));
	
	FOR(k,0,20) FOR(i,0,N) if (i & (1 << k)) b[i] += b[i ^ (1 << k)];

	reverse(all(b));
	
	vl p2(N+1);
	p2[0] = 1;
	FOR(i,0,N) p2[i+1] = 2*p2[i] % MOD;
	
	ll res = 0;
	FOR(i,0,N) {
		ll sign = (__builtin_popcount(i) & 1) ? -1 : 1;
		res = (res + sign*p2[b[i]]) % MOD;
	}
	if (res < 0) res += MOD;
	cout << res << endl;
}