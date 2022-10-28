#include "bits/stdc++.h"
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 3e5+10, MOD = 1e9+7;

template <int MOD_> struct modnum {
	static constexpr int MOD = MOD_;
	static_assert(MOD_ > 0, "MOD must be positive");
private:
	using ll = long long;

	int v;

	static int minv(int a, int m) {
		a %= m;
		assert(a);
		return a == 1 ? 1 : int(m - ll(minv(m, a)) * ll(m) / a);
	}
public:
	modnum() : v(0) {}
	modnum(ll v_) : v(int(v_ % MOD)) { if (v < 0) v += MOD; }
	explicit operator int() const { return v; }
	friend std::ostream& operator << (std::ostream& out, const modnum& n) { return out << int(n); }
	friend std::istream& operator >> (std::istream& in, modnum& n) { ll v_; in >> v_; n = modnum(v_); return in; }

	friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
	friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }

	modnum inv() const {
		modnum res;
		res.v = minv(v, MOD);
		return res;
	}
	friend modnum inv(const modnum& m) { return m.inv(); }
	modnum neg() const {
		modnum res;
		res.v = v ? MOD-v : 0;
		return res;
	}
	friend modnum neg(const modnum& m) { return m.neg(); }

	modnum operator- () const {
		return neg();
	}
	modnum operator+ () const {
		return modnum(*this);
	}

	modnum& operator ++ () {
		v ++;
		if (v == MOD) v = 0;
		return *this;
	}
	modnum& operator -- () {
		if (v == 0) v = MOD;
		v --;
		return *this;
	}
	modnum& operator += (const modnum& o) {
		v -= MOD-o.v;
		v = (v < 0) ? v + MOD : v;
		return *this;
	}
	modnum& operator -= (const modnum& o) {
		v -= o.v;
		v = (v < 0) ? v + MOD : v;
		return *this;
	}
	modnum& operator *= (const modnum& o) {
		v = int(ll(v) * ll(o.v) % MOD);
		return *this;
	}
	modnum& operator /= (const modnum& o) {
		return *this *= o.inv();
	}

	friend modnum operator ++ (modnum& a, int) { modnum r = a; ++a; return r; }
	friend modnum operator -- (modnum& a, int) { modnum r = a; --a; return r; }
	friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
	friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
	friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
	friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
};
using num = modnum<MOD>;
ll po(ll b, ll p, ll mod=MOD){
    ll r=1;
    for (; p; b=b*b%mod, p>>=1) if (p&1) r=r*b%mod;
    return r;
}
num po(num b, ll p){
    num r=1;
    for (; p; b=b*b, p>>=1) if (p&1) r=r*b;
    return r;
}

const int MAXV = 1e6+10;
int pf[MAXV], val[MAXV];
num fact[MAXV], ifact[MAXV];
vector<int> factors[MAXV];

void pre(){ //call pre at the beginning (in main)
    memset(pf, -1, sizeof(pf));
    for (int i = 2; i < MAXV; i++) if (pf[i] == -1) {
        for (int j = i; j < MAXV; j+=i) pf[j] = i;
    }
    for (int i = 1; i < MAXV; i++) {
        val[i] += i;
        for (int j = i; j < MAXV; j += i) {
            factors[j].push_back(i);
            if (i != j)
                val[j] -= val[i];
        }
    }
    
    fact[0] = ifact[0] = 1;
    for (int i = 1; i < MAXV; i++) fact[i] = fact[i-1]*i;
    ifact[MAXV-1] = inv(fact[MAXV-1]);
    for (int i = MAXV-2; i > 0; i--) ifact[i] = ifact[i+1]*num(i+1);
}
num nck(int n, int k){ //nck
    if (k > n) return num(0);
    return fact[n]*ifact[k]*ifact[n-k];
}
num nck(num n, num k){ //nck
    return nck(int(n), int(k));
}
vector<pair<int, int>> get_pf(int n){
    vector<pair<int, int>> r;
    int c=n;
    while (c > 1){
        int v = pf[c];
        r.emplace_back(v, 0);
		while (c%v == 0) r.back().second++, c /= v;
    }
    return r;
}
vector<pair<ll, int>> get_pf_big(ll n){
    vector<pair<ll, int>> r;
    for (ll i = 2; i*i <= n; i++) if (n%i == 0){
        r.emplace_back(i, 0);
        while (n%i == 0) r.back().second++, n /= i;
    }
    if (n>1) r.emplace_back(n, 1);
    return r;
}

int n, k, q, occ[MAXV];
num a[MAXV];

void solve(){
    pre();

    cin >> n >> k >> q;
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        occ[c]++;
    }

    num ans=0;
    for (int i = 1; i < MAXV; i++) {
        for (int j = 2*i; j < MAXV; j += i) {
            occ[i] += occ[j]; //add from multiples
        }
        a[i] = nck(occ[i], k);
        ans += val[i]*a[i];
    }
    while (q--) {
        int c; cin >> c;
        for (auto x : factors[c]) {
            ans -= val[x]*a[x];
            a[x] += nck(occ[x], k-1), occ[x]++;
            ans += val[x]*a[x];
        }
        cout << ans << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}