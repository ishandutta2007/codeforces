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
	int n[3];
	FOR(i,0,3) cin >> n[i];
	vvl a(3);
	FOR(k,0,3) {
		a[k].resize(n[k]);
		FOR(i,0,n[k]) cin >> a[k][i];
		sort(all(a[k]));
	}
	
	ll res = oo;
	FOR(k,0,3) {
		vl &v = a[(k+1)%3];
		vl &w = a[(k+2)%3];
		for (ll x: a[k]) {
			vl ys, zs;
			auto vit = lower_bound(all(v),x);
			auto wit = lower_bound(all(w),x);
			FOR(k,0,2) {
				if (vit != end(v)) ys.pb(*vit);
				if (vit == begin(v)) break;
				vit--;
			}
			FOR(k,0,2) {
				if (wit != end(w)) zs.pb(*wit);
				if (wit == begin(w)) break;
				wit--;
			}
			
			for (ll y: ys) for (ll z: zs) {
				ll cur = (x-y)*(x-y) + (y-z)*(y-z) + (z-x)*(z-x);
				res = min(res, cur);
			}
		}
	}
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll tc; cin >> tc;
	while (tc--) solve();
}