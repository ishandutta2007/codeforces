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

#define hash asdf

const ll N = 1e6 + 10, MOD[] = {ll(1e9) + 7, ll(1e9) + 9, ll(1e9) + 21}, A[] = {123,456,789};
ll powA[3][N];

struct hash {
	ll len = 0, val[3];

	hash() {
		memset(val,0,sizeof val);
	}

	hash(ll x) {
		len = 1;
		FOR(i,0,3) val[i] = (MOD[i] + x%MOD[i]) % MOD[i];
	}

	hash operator+(const hash &h) const {
		hash res;
		res.len = len + h.len;
		FOR(i,0,3) res.val[i] = (powA[i][h.len] * val[i] + h.val[i]) % MOD[i];
		return res;
	}

	hash operator*(const hash &h) const {
		hash res;
		FOR(i,0,3) res.val[i] = (val[i] + h.val[i]) % MOD[i];
		return res;
	}

	bool operator==(const hash &h) const {
		FOR(i,0,3) if (val[i] != h.val[i]) return false;
		return true;
	}

	bool operator<(const hash &h) const {
		FOR(i,0,3) if (val[i] != h.val[i]) return val[i] < h.val[i];
		return false;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	FOR(i,0,3) {
		powA[i][0] = 1;
		FOR(n,1,N) powA[i][n] = A[i]*powA[i][n-1] % MOD[i];
	}
	
	ll m = 30;
	ll n; cin >> n;
	vl a(n);
	FOR(i,0,n) cin >> a[i];
	
	vector<hash> c(m), d(m);
	FOR(k,0,m) FOR(i,1,n) {
		ll x = !!(a[i] & (1 << k)) - !!(a[0] & (1 << k));
		c[k] = c[k] + hash(x);
		d[k] = d[k] + hash(-x);
	}
	
	hash one;
	one.len = n-1;
	
	ll ma = m/2, mb = m-ma;
	vector<hash> L(1 << ma,one), R(1 << mb,one);

	FOR(i,0,ma) FOR(mask,0,1 << ma) {
		L[mask] = L[mask] * (mask & (1 << i) ? d[i] : c[i]);
	}
	FOR(i,0,mb) FOR(mask,0,1 << mb) {
		R[mask] = R[mask] * (mask & (1 << i) ? d[ma+i] : c[ma+i]);
	}
	
	map<hash,ll> M;
	FORD(mask,0,1 << mb) {
		hash h = R[mask];
		M[h] = mask;
	}
	
	FOR(mask,0,1 << ma) {
		hash h = L[mask];
		FOR(i,0,3) h.val[i] = (MOD[i] - h.val[i]) % MOD[i];
		if (M.count(h)) {
			ll res = mask | (M[h] << ma);
			cout << res << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}