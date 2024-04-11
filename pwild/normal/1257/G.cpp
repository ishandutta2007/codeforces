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

const ll MOD = 998244353, alpha = 3;

ll exp_mod(ll a, ll n) {
	ll res = 1;
	while (n) {
		if (n&1) res = res*a % MOD;
		a = a*a % MOD;
		n /= 2;
	}
	return res;
}

ll inv_mod(ll a) { return exp_mod(a,MOD-2); }

vl ntt(vl v, ll p) {
	vl res = v;
	for (ll step = sz(v)/2; step; step /= 2) {
		ll n = sz(v)/step;
		ll wn = exp_mod(alpha,(MOD-1)/n), w = 1;
		if (p < 0) wn = inv_mod(wn);
		FOR(i,0,n/2) {
			FOR(j,0,step) {
				ll t = w * res[j + step*(2*i+1)] % MOD;
				v[j + step*i] = (res[j + step*2*i] + t) % MOD;
				v[j + step*(i+n/2)] = (res[j + step*2*i] - t) % MOD;
			}
			w = w*wn % MOD;
		}
		res = v;
	}
	ll Ni = inv_mod(sz(v));
	if (p < 0) for (ll &x: res) x = x*Ni % MOD;
	return res;
}

const ll K = 20;
vl operator*(vl a, vl b) {
	ll szc = sz(a)+sz(b)-1;
	if (sz(a) < K || sz(b) < K) {
		vl c(szc);
		FOR(i,0,sz(a)) FOR(j,0,sz(b)) {
			c[i+j] = (c[i+j] + a[i]*b[j]) % MOD;
		}
		return c;
	}

	ll n = 1;
	while (n < sz(a)+sz(b)) n *= 2;
	a.resize(n), b.resize(n);
	a = ntt(a,1), b = ntt(b,1);
	vl c(n);
	FOR(i,0,n) c[i] = a[i]*b[i] % MOD;
	c = ntt(c,-1);
	c.resize(szc);
	return c;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;
	ll m = 3e6 + 10;
	vl cnt(m);
	FOR(i,0,n) {
		ll x; cin >> x;
		cnt[x]++;
	}
	
	auto comp = [&](const vl &a, const vl &b) { return sz(a) > sz(b); };
	priority_queue<vl,vvl,decltype(comp)> q(comp);
	
	FOR(i,0,m) if (cnt[i]) q.emplace(cnt[i]+1,1);
	
	while (sz(q) >= 2) {
		vl a = q.top(); q.pop();
		vl b = q.top(); q.pop();
		q.push(a*b);
	}
	ll res = q.top()[n/2];
	if (res < 0) res += MOD;
	cout << res << endl;
}