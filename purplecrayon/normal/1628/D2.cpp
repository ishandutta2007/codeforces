#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e6+10, MOD = 1e9+7;

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

num po2[MAXN], fact[MAXN], ifact[MAXN];
void pre() {
    po2[0] = fact[0] = ifact[0] = 1;
    for (int i = 1; i < MAXN; i++) po2[i] = po2[i-1]*2, fact[i] = fact[i-1]*i;
    ifact[MAXN-1] = inv(fact[MAXN-1]);
    for (int i = MAXN-2; i >= 0; i--) ifact[i] = ifact[i+1]*(i+1);
}
num nck(int n, int k) {
    if (n < 0 || k < 0 || k > n) return 0;
    return fact[n]*ifact[k]*ifact[n-k];
}
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    m = min(n, n - m); // allowed subtractions
    if (m == 0) {
        cout << num(k)*n << '\n';
        return;
    }
    num ans = 0;
    for (int i = 1; i <= n; i++) {
        num me = num(k) * i;
        ans += me / po2[n-i] * nck(n-i-1, m-1);
    }
    cout << ans << '\n';
}
int main(){
    pre();

    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}