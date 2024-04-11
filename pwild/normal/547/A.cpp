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
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define has(c,i) ((c).find(i) != end(c))
#define DBGDO(X) ({ if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; })

pair<ll,pll> eea(ll a, ll b) {
	if (!b) return {a,{1,0}};
	auto p = eea(b,a%b);
	ll s, t;
	tie(s,t) = p.yy;
	return {p.xx,{t,s-t*(a/b)}};
}

ll solve(ll a, ll b, ll m) {
	auto p = eea(a,m);
	if (b % p.xx) return -1;
	b /= p.xx, m /= p.xx;
	return ((b*p.yy.xx) % m + m) % m;
}

ll gcd(ll a, ll b) { return (b == 0) ? a : gcd(b, a%b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a,b)); }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll m; cin >> m;

	ll h[2], a[2], x[2], y[2], init[2], cyc[2];
	FOR(i,0,2) {
		cin >> h[i] >> a[i] >> x[i] >> y[i];
		
		init[i] = -1;
		FOR(k,0,m+1) {
			if (h[i] == a[i]) {
				init[i] = k; break;
			}
			h[i] = (x[i]*h[i] + y[i]) % m;
		}
		if (init[i] == -1) {
			cout << -1 << endl;
			return 0;
		}
		cyc[i] = -1;
		FOR(k,1,m+2) {
			h[i] = (x[i]*h[i] + y[i]) % m;
			if (h[i] == a[i]) {
				cyc[i] = k;
				break;
			}
		}
		if (cyc[i] == -1) cyc[i] = oo;
	}

	ll res = oo;

	FOR(i,0,2) if (cyc[i] < oo) FOR(k,0,m) {
		ll t = init[i] + k*cyc[i] - init[i^1];
		if (t < 0 || t % cyc[i^1]) continue;
		res = min(res,init[i]+k*cyc[i]);
	}
	if (res < oo) cout << res << endl;
	else cout << -1 << endl;

}