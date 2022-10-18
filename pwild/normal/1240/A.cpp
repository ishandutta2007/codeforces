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
	
	ll tc; cin >> tc;
	while (tc--) {
		ll n; cin >> n;
		vl p(n);
		FOR(i,0,n) cin >> p[i];
		sort(all(p),greater<ll>());

		ll x, a, y, b;
		cin >> x >> a >> y >> b;
		if (x < y) swap(x,y), swap(a,b);

		ll c = a/__gcd(a,b) * b;

		ll k; cin >> k;

		ll lo = 0, hi = n+1;
		while (hi-lo > 1) {
			ll m = (lo+hi)/2;

			ll cx = m/a, cy = m/b;
			ll cxy = m/c;
			cx -= cxy, cy -= cxy;

			vl add = {x+y,x,y,0};
			vl cnt = {cxy,cx,cy,oo};
			
			ll cur = 0, j = 0;
			FOR(i,0,m) {
				while (!cnt[j]) j++;
				cur += p[i]/100 * add[j];
				cnt[j]--;
			}
			
			if (cur >= k) hi = m; else lo = m;
		}
		
		ll res = hi;
		if (res > n) res = -1;
		cout << res << endl;
	}

}