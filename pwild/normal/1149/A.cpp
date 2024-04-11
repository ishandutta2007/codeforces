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
	
	ll n; cin >> n;
	ll one = 0, two = 0;
	FOR(i,0,n) {
		ll x; cin >> x;
		if (x == 1) one++; else two++;
	}
	
	ll M = 1e6;
	vb pr(M,true);
	FOR(i,2,M) if (pr[i]) {
		for (ll j = i+i; j < M; j += i) pr[j] = false;
	}
	pr[0] = pr[1] = false;

	ll k = min(n,5LL);
	ll res = -1;
	vl ans;
	FOR(mask,0,1 << k) {
		ll a = __builtin_popcount(mask), b = k-a;
		if (a > one || b > two) continue;
		
		auto take = [&](ll i) {
			if (i < k) return (mask & (1 << i)) ? 1 : 2;
			return (i-k < two-b) ? 2 : 1;
		};
		
		ll cur = 0, s = 0;
		FOR(i,0,n) {
			s += take(i);
			cur += pr[s];
		}

		if (cur > res) {
			res = cur;
			ans.clear();
			FOR(i,0,n) ans.pb(take(i));
		}
	}
	
	FOR(i,0,n) cout << ans[i] << " ";
	cout << endl;

}