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

#define has(x,k) (x & (1LL << k))

void solve(ll x) {
	ll M = 40;
	mt19937_64 gen(12345);
	uniform_int_distribution<ll> dis(1,(1LL << M) - 1);
	ll n = 1000;
	vl b(n);
	FOR(i,0,M) b[i] = 1LL << i;
	FOR(i,M,n) b[i] = dis(gen);
	
	vector<tuple<ll,char,ll>> res;
	res.eb(x,'^',x);
	FOR(i,0,M-1) res.eb(b[i]*x,'+',b[i]*x);
	FOR(i,M,n) {
		ll u = 0;
		FOR(k,0,M) if (has(b[i],k)) res.eb(u,'+',b[k]*x), u += b[k]*x;
	}

	vl a(n+1);
	FOR(i,0,n) a[i] = b[i]*x;
	a[n] = 1;
	
	ll w = *max_element(all(a));
	ll K = 0;
	while (w >= (1LL << K)) K++;

	vl pivots;
	FOR(k,0,K) {
		FOR(i,0,n) if (has(a[i],k)) {
			pivots.pb(i);
			FOR(kk,k+1,K) if (has(a[i],kk)) {
				FOR(j,0,n+1) if (has(a[j],k)) a[j] ^= 1LL << kk;
			}
			break;
		}
		if (a[n] < (1LL << (k+1))) break;
		assert(sz(pivots) == k+1);
	}
	
	vl sol;
	FORD(k,0,sz(pivots)) {
		if (has(a[n],k)) sol.pb(b[pivots[k]]), a[n] ^= a[pivots[k]];
	}

	ll u = sol[0]*x;
	FOR(i,1,sz(sol)) {
		res.eb(u,'^',sol[i]*x);
		u ^= sol[i]*x;
	}
	assert(u == 1);
	
	cout << sz(res) << endl;
	for (auto [x,op,y]: res) cout << x << " " << op << " " << y << endl;
}

void test() {
	ll x = 3, y = 999999;
	while (x < y) {
		solve(x);
		solve(y);
		x += 2, y -= 2;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll z; cin >> z;
	solve(z);
}