#include <bits/stdc++.h>
using namespace std;

#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+10, MOD = 1e9+7;

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

const int MAXV = 2e6+10;
num fact[MAXV], ifact[MAXV];

void pre(){ //call pre at the beginning (in main)
    fact[0] = ifact[0] = 1;
    for (int i = 1; i < MAXV; i++) fact[i] = fact[i-1]*i;
    ifact[MAXV-1] = inv(fact[MAXV-1]);
    for (int i = MAXV-2; i > 0; i--) ifact[i] = ifact[i+1]*num(i+1);
}
num nck(int n, int k){ //nck
    if (k > n) return 0;
    return fact[n]*ifact[k]*ifact[n-k];
}
num nck(num n, num k){ //nck
    return nck(int(n), int(k));
}

const int MAXK = 1e2+10;

int n, m;
num a[MAXN][MAXK];
num ans[MAXN];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    pre();

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        ans[i] = x;
    }
    while (m--) {
        int l, r, k; cin >> l >> r >> k, --l, --r;
        a[l][k+1]++;
        for (int i = 1; i <= k; i++) a[r+1][i] -= nck(k+1-i+r-l, k-i+1);
        a[r+1][k+1]--;
    }
    for (int i = MAXK-1; i >= 1; i--) {
        for (int j = 1; j < n; j++) a[j][i] += a[j-1][i];
        for (int j = 0; j < n; j++) a[j][i-1] += a[j][i];
    }
    for (int i = 0; i < n; i++) ans[i] += a[i][0];
    for (int i = 0; i < n; i++) cout << ans[i] << ' '; cout << '\n';
}

//1 1 1 1 1 1
//1 2 3 4 5 6
//1 3 6 10 
//
//
//a[l]++, a[r]--;
//a[