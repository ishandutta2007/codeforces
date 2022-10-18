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

void solve() {
	ll n, k;
	cin >> n >> k;
	vl a(n);
	FOR(i,0,n) cin >> a[i];

	ll m = 2*k+10;
	vl one(m), zero(m);
	FOR(i,0,n/2) {
		ll x = a[i], y = a[n-1-i];

		zero[x+y]++;

		ll lo = min(x,y)+1, hi = max(x,y)+k;
		one[lo]++;
		one[hi+1]--;
	}
	FOR(x,0,m-1) one[x+1] += one[x];
	
	ll res = oo;
	FOR(x,0,m) {
		one[x] -= zero[x];
		ll two = n/2 - one[x] - zero[x];
		res = min(res, one[x] + 2*two);
	}
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll tc; cin >> tc;
	while (tc--) solve();
}