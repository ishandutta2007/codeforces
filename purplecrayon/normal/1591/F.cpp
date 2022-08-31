#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 5e5+10, MOD = 998244353;

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

//x = sum{dp}
//dp[i] *= -1
//dp[i] += x
//dp[i] > a[i] = 0

const ll NONE = -1e18+10;
struct T {
    ll lzy = NONE;
    num sum = 0;

    T *l, *r;
    ll tl, tr;

    T(ll _tl, ll _tr): tl(_tl), tr(_tr) {
        lzy = NONE;
        l = r = nullptr;
    }

    void extend() {
        if (l || r || tl == tr) return;
        ll tm = (tl+tr)/2;
        l = new T(tl, tm), r = new T(tm+1, tr);
    }
    num get_sum() {
        return lzy == NONE ? sum : num(lzy)*num(tr-tl+1);
    }
    void push() {
        if (lzy == NONE) return;
        sum = get_sum();
        if (l || r) {
            l->lzy = lzy, r->lzy = lzy;
        }
        lzy = NONE;
    }
    void set(ll ql, ll qr, ll x) {
        if (ql <= tl && tr <= qr) {
            lzy = x;
            return;
        }
        extend(); push();
        if (ql <= l->tr)
            l->set(ql, qr, x);
        if (qr >= r->tl) 
            r->set(ql, qr, x);

        sum = l->get_sum() + r->get_sum();
    }
} *t;

int n;
ll a[MAXN];

const int L = 0, R = 1e9+10;

void solve(){
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i], --a[i];

    t = new T(L, R);

    int mul = 1;
    num add = 0;

    auto get_sum = [&]() -> num {
        return (t->sum)*mul + add*num(R-L+1);
    };

    t->set(L, R, 0);
    for (int i = 0; i < n; i++) {
        if (!i) {
            t->set(0, a[i], 1);
        } else {
            num x = get_sum();
            mul *= -1, add *= num(-1);
            add += x;

            t->set(a[i]+1, R, (0-int(add))/mul);
        }
    }
    cout << get_sum() << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}