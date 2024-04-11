#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+10, MOD = 777777777;

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

bool good[3][3];

struct T {
    num dp[3][3];
    void clear() {
        for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) dp[i][j] = 0;
    }
} t[4*MAXN];

T make_empty(int v) {
    T res; res.clear();
    for (int i = 0; i < 3; i++) {
        res.dp[i][i] = (v == -1 || v == i ? 1 : 0);
    }
    return res;
}

T comb(T l, T r) {
    T res; res.clear();
    for (int a = 0; a < 3; a++) for (int b = 0; b < 3; b++) for (int c = 0; c < 3; c++) if (good[b][c]) for (int d = 0; d < 3; d++) {
        res.dp[a][d] += l.dp[a][b]*r.dp[c][d];
    }
    return res;
}

void bld(int v, int tl, int tr) {
    if (tl == tr) t[v] = make_empty(-1);
    else {
        int tm=(tl+tr)/2;
        bld(2*v, tl, tm), bld(2*v+1, tm+1, tr);
        t[v] = comb(t[2*v], t[2*v+1]);
    }
}
void upd(int v, int tl, int tr, int pos, int val) {
    if (pos < tl || pos > tr) return;
    if (tl == tr) {
        t[v] = make_empty(val);
        return;
    }
    int tm=(tl+tr)/2;
    upd(2*v, tl, tm, pos, val), upd(2*v+1, tm+1, tr, pos, val);
    t[v] = comb(t[2*v], t[2*v+1]);
}
num qry() {
    num ans = 0;
    for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++)
        ans += t[1].dp[i][j];
    return ans;
}

int n, q;

void solve(){
    cin >> n >> q;
    for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) cin >> good[i][j];
    bld(1, 0, n-1);

    while (q--) {
        int pos, val; cin >> pos >> val, --pos, --val;
        upd(1, 0, n-1, pos, val);
        cout << qry() << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}