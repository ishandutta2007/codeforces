#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

namespace vector_operators {
    template<typename T> vector<T>& operator*=(vector<T>& l, const T& r) { for (T& e : l) e *= r; return l; }
    template<typename T> vector<T> operator*(const T& l, vector<T> r) { return r *= l; }
    template<typename T> vector<T> conv(const vector<T>& l, const vector<T>& r) {
        if (l.empty() || r.empty()) return {};
        vector<T> p(sz(l) + sz(r) - 1);
        for (int i = 0; i < sz(l); i++) for (int j = 0; j < sz(r); j++) p[i+j] += l[i] * r[j];
        return p;
    }
    template<typename T> vector<T> operator*(const vector<T>& l, const vector<T>& r) { return conv(l, r); }
    template<typename T> vector<T>& operator-=(vector<T>& l, const vector<T>& r) { l.resize(max(sz(l), sz(r))); for (int i = 0; i < sz(r); i++) l[i] -= r[i]; return l; }
 
    template<typename T> vector<T> dot(const vector<T>& a, const vector<T>& b) { vector<T> p(min(sz(a), sz(b))); for (int i = 0; i < sz(p); i++) p[i] = a[i] * b[i]; return p; }
    template<typename T> vector<T>& operator<<=(vector<T>& v, int x) { v.insert(v.begin(), x, 0); return v; }
    template<typename T> vector<T> operator<<(vector<T> v, int x) { return v <<= x; }
 
    template<typename T> void rem_lead(vector<T>& v) { while (sz(v) && v.back() == 0) v.pop_back(); }
    template<typename T> vector<T> reversed(vector<T> v) { reverse(v.begin(), v.end()); rem_lead(v); return v; }
 
    template<typename T> pair<vector<T>, vector<T>> long_division(vector<T> a, vector<T> b) {
        rem_lead(a), rem_lead(b), assert(!b.empty());
        T B = T{1} / b.back(); for (T& e : b) e *= B;
        vector<T> q(max(sz(a) - sz(b) + 1, 0));
        for (; sz(a) >= sz(b); rem_lead(a)) {
            q[sz(a) - sz(b)] = a.back();
            a -= a.back() * (b << (sz(a) - sz(b)));
        }
        for (T& e : q) e *= B;
        return {q, a}; // quotient, remainder
    }
 
    template<typename T> vector<T>& operator/=(vector<T>& a, const vector<T>& b) { return a = long_division(a, b).first; }
    template<typename T> vector<T>& operator%=(vector<T>& a, const vector<T>& b) { return a = long_division(a, b).second; }
    template<typename T> vector<T> operator/(vector<T> a, const vector<T>& b) { return a /= b; }
    template<typename T> vector<T> operator%(vector<T> a, const vector<T>& b) { return a %= b; }
    template<typename T> vector<T> mod_pow(const vector<T>& v, ll e, const vector<T>& m) {
        if (!e) return {1};
        vector<T> res = mod_pow(v, e/2, m); res = res * res % m;
        return e&1 ? res * v % m : res;
    }
}
using namespace vector_operators;
template<typename T> struct LFSR {
    vector<T> seq;    // original sequence
    vector<T> fib;    // seq[i] = sum_j fib[j] * seq[i-1-j] (i >= sz(fib))
    vector<T> galois; // 0 = sum_j galois[j] * seq[i+j] (i <= sz(seq) - sz(galois))
 
    LFSR(vector<T> seq_) : seq(seq_) {
        vector<T> C = {1}, B = {1}; T b = 1;
        for (int i = 0, m = 1; i < sz(seq); i++, m++) {
            T d = 0; for (int j = 0; j < sz(C); j++) d += C[j] * seq[i - j];
            if (d == 0) continue;
            vector<T> B_ = C; C.resize(max(sz(C), m+sz(B)));
            T dbi = d/b; for (int j = 0; j < sz(B); j++) C[m+j] -= dbi * B[j];
            if (sz(B_) < m+sz(B)) { B = B_; b = d; m = 0; }
        }
        galois = vector_operators::reversed(C);
        fib = move(C); fib.erase(fib.begin()); fib *= T{-1};
    }
 
    T operator[](ll n) const {
        vector<T> r = dot(seq, mod_pow({0,1}, n, galois));
        return accumulate(r.begin(), r.end(), T{0});
    }
};
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



void solve(){
    ll n, m; cin >> n >> m;
    const int SIZE = 1000;
    vector<num> dp(SIZE);
    dp[0] = 1;
    for (int i = 1; i < SIZE; i++) {
        if (i >= m)
            dp[i] += dp[i-m];
        dp[i] += dp[i-1];
    }
    LFSR<num> massey(dp);
    cout << massey[n] << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}