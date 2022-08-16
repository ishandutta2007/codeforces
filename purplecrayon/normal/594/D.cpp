#include "bits/stdc++.h"
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

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


const int MAXV = 1e6+10;
int pf[MAXV];

void pre(){ //call pre at the beginning (in main)
    memset(pf, -1, sizeof(pf));
    for (int i = 2; i < MAXV; i++) if (pf[i] == -1) {
        for (int j = i; j < MAXV; j+=i) pf[j] = i;
    }
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

int n, a[MAXN], nxt[MAXV];
num ps[MAXN], ans[MAXN], t[4*MAXN];
vector<ar<int, 2>> ql[MAXN];

void upd(int v, int tl, int tr, int l, int r, num x) {
    if (r < tl || l > tr) return;
    if (l <= tl && tr <= r) { t[v] *= x; return; }
    int tm=(tl+tr)/2;
    upd(2*v, tl, tm, l, r, x), upd(2*v+1, tm+1, tr, l, r, x);
}
num qry(int v, int tl, int tr, int pos) {
    if (pos < tl || pos > tr) return 1;
    if (tl == tr) return t[v];
    int tm=(tl+tr)/2;
    return t[v]*qry(2*v, tl, tm, pos)*qry(2*v+1, tm+1, tr, pos);
}
void solve(){
    pre();

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ps[i] = num(a[i])*(i?ps[i-1]:num(1));
    }
    int q; cin >> q;
    for (int qt = 0; qt < q; qt++) {
        int l, r; cin >> l >> r, --l, --r;
        ql[l].push_back({r, qt});
        ans[qt] = ps[r]/(l?ps[l-1]:num(1));
    }
    fill(t, t+4*n, num(1));
    fill(nxt, nxt+MAXV, n);
    for (int i = n-1; i >= 0; i--) {
        auto pf = get_pf(a[i]);
        for (auto [p, k] : pf) {
            int nv = nxt[p];
            upd(1, 0, n-1, i, nv-1, num(p-1)/num(p));
            nxt[p] = i;
        }
        for (auto [r, qt] : ql[i]) {
            ans[qt] *= qry(1, 0, n-1, r);
        }
    }
    for (int i = 0; i < q; i++) cout << ans[i] << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}