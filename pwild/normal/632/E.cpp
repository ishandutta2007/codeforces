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

const ll P = 2013265921;

ll modExp(ll a, ll n) {
	ll res = 1;
	while (n) {
		if (n & 1) res = res*a % P;
		a = a*a % P;
		n /= 2;
	}
	return res;
}

ll modInv(ll a) { return modExp(a,P-2); }


vl fft(vl v, ll N, int p) {
	v.resize(N);
	ll alpha = modExp(31,(P-1)/N);
	vl res = v;
	for (ll step = sz(v)/2; step; step /= 2) {
		ll n = sz(v)/step;
		ll wn = modExp(alpha,step), w = 1;
		if (p < 0) wn = modInv(wn);
		FOR(i,0,n/2) {
			FOR(j,0,step) {
				ll t = w * res[j + step*(2*i+1)] % P;
				v[j + step*i] = (res[j + step*2*i] + t) % P;
				v[j + step*(i+n/2)] = (P + res[j + step*2*i] - t) % P;
			}
			w = w*wn % P;
		}
		res = v;
	}
	ll Ni = modInv(N);
	if (p == -1) FOR(i,0,sz(res)) res[i] = res[i]*Ni % P;
	return res;
}

vl operator*(const vl &a, const vl &b) {
	ll N = 2*sz(a);
	vl ai = fft(a,N,1), bi = fft(b,N,1);
	vl ci(N);
	FOR(i,0,N) ci[i] = ai[i]*bi[i] % P;
	vl c = fft(ci,N,-1);
	FOR(i,0,N) c[i] = !!c[i];
	return c;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, k; cin >> n >> k;
	ll N = 1024;
	vl a(N);
	FOR(i,0,n) {
		ll x; cin >> x;
		a[x] = 1;
	}
	vl res(N);
	res[0] = 1;
	while (k) {
		N *= 2;
		if (k & 1) res = res*a; else res.resize(N);
		a = a*a;
		k /= 2;
	}
	cerr << N << endl;

	bool have = false;
	FOR(i,0,N) if (res[i]) {
		if (have) cout << " ";
		cout << i;
		have = true;
	}
	cout << endl;


}