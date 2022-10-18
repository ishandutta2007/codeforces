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
		ll n, k;
		cin >> n >> k;

		string a; cin >> a;

		vl cnt(k);
		FOR(i,0,n) cnt[i%k] += a[i]-'0';

		ll total = accumulate(all(cnt),0LL);

		ll res = oo;
		FOR(i,0,k) {
			ll cur = total - cnt[i];

			ll u = 0, v = 0, w = 0;
			for (ll j = i; j < n; j += k) {
				ll x = a[j]-'0';
				u += x, v += !x, w += x;
				v = min(u,v), w = min(v,w);
			}
			cur += w;

			res = min(res,cur);
		}
		cout << res << endl;
	}
}