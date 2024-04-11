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
		ll n, T, a, b;
		cin >> n >> T >> a >> b;
		vl hard(n), time(n);
		FOR(i,0,n) cin >> hard[i];
		FOR(i,0,n) cin >> time[i];

		vl is(n);
		iota(all(is),0);
		sort(all(is), [&](ll i, ll j) { return time[i] < time[j]; });
		
		ll cb = accumulate(all(hard),0LL), ca = n-cb;
		ll need = 0, res = 0;

		auto solve = [&](ll k, ll rem) {
			if (rem < 0) return 0LL;
			ll cur = k;
			ll ta = min(ca,rem/a);
			rem -= a*ta, cur += ta;
			ll tb = min(cb,rem/b);
			rem -= b*ta, cur += tb;
			return cur;
		};

		FOR(k,0,n) {
			ll i = is[k];
			if (k == 0 || time[is[k-1]] < time[is[k]]) {
				res = max(res, solve(k, time[i]-1-need));
			}
			
			if (hard[i]) {
				need += b, cb--;
			} else {
				need += a, ca--;
			}
		}

		res = max(res, solve(n, T-need));

		cout << res << endl;		
	}
}