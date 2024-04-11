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
	
	vl s = {0,1,2,0,2,1,0};
	vl a(3);
	FOR(i,0,3) cin >> a[i];
	
	ll k = min({a[0]/3,a[1]/2,a[2]/2});
	a[0] -= 3*k;
	a[1] -= 2*k;
	a[2] -= 2*k;
	
	ll res = 0;
	FOR(i,0,7) {
		vl b = a;
		ll cur = 0;
		while (b[ s[(i+cur)%7] ]--) cur++;
		assert(cur < 7);
		res = max(res,cur);
	}
	res += k*7;
	cout << res << endl;
}