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

const ll K = 12, MOD = 998244353;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	


	ll n; cin >> n;

	vl a(n), cnt(K);
	FOR(i,0,n) {
		cin >> a[i];
		ll len = 0, x = a[i];
		while (x) x /= 10, len++;
		cnt[len]++;
	}
	
	ll res = 0;
	FOR(i,0,n) {
		FOR(olen,1,K) if (cnt[olen]) {
			ll x = a[i], p = 1, cur = 0;
			FOR(i,0,oo) {
				if (x == 0) break;
				
				ll d = x%10;
				cur = (cur + d*p) % MOD;
				
				if (i < olen) p = p*100 % MOD;
				else p = p*10 % MOD;

				x /= 10;
			}
			res = (res + cur*cnt[olen]) % MOD;
		}
		FOR(olen,1,K) if (cnt[olen]) {
			ll x = a[i], p = 10, cur = 0;
			FOR(i,0,oo) {
				if (x == 0) break;
				
				ll d = x%10;
				cur = (cur + d*p) % MOD;
				
				if (i < olen-1) p = p*100 % MOD;
				else p = p*10 % MOD;

				x /= 10;
			}
			res = (res + cur*cnt[olen]) % MOD;
		}
	}
	cout << res << endl;
}