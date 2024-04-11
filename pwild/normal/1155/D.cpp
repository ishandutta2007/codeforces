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
	
	ll n, x;
	cin >> n >> x;

	vl a(n);
	FOR(i,0,n) cin >> a[i];
	
	ll u = 0, v = 0, w = 0, res = 0;
	FOR(i,0,n) {
		ll nu = max(u+a[i],0LL);
		ll nv = max(v+x*a[i],0LL);
		ll nw = max(w+a[i],0LL);
		u = nu, v = nv, w = nw;
		v = max(u,v), w = max(v,w);
		res = max(res,w);
	}
	cout << res << endl;
}