#include <bits/stdc++.h>
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

template<class T>
struct FT {
    vector<T> bit;
    FT(int n) : bit(n) {}
    FT(){}
    void upd(int i, T x) {
        for (; i < sz(bit); i |= i+1) bit[i] += x;
    }
    T qry(int r) {
        T ans = T();
        for (++r; r > 0; r &= r-1) ans += bit[r-1];
        return ans;
    }
    T qry(int l, int r) {
        return qry(r)-qry(l-1);
    }
};

int n, b[2*MAXN], me[2*MAXN], p[MAXN], sorted_l[MAXN];
ar<int, 2> a[MAXN];
num inside[MAXN];
bool need[MAXN];

bool can(int l, int r, int i) {
    return l < a[i][0] && a[i][1] < r;
}
int me_range;
int l_pointer;
num rec(int l, int r) {
    for (; me_range >= 0; me_range--) if (can(l, r, me_range) && need[me_range]) {
        break;
    }
    if (me_range == -1) {
        return 0;
    }

    auto [me_l, me_r] = a[me_range];
    num ans = inside[me_range];
    
    for (; l_pointer < n; l_pointer++) {
        int c = sorted_l[l_pointer];
        auto [he_l, he_r] = a[c];
        if (he_l >= me_l) break;
        if (he_r <= me_r && can(l, r, c)) ans += inside[c];
    }
    /*
    for (int i = 0; i < n; i++) if (can(l, r, i)) {
        auto [he_l, he_r] = a[i];
        if (he_r > me_r) {
            // ignore
        } else if (he_l < me_l) {
            ans += inside[i];
        }
    }
    */
    ans += rec(me_l, me_r);
    return ans;
}
void solve() {
    cin >> n;
    memset(need, 0, sizeof(need));
    iota(p, p+n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1], --a[i][0], --a[i][1];
    }
    sort(p, p+n, [&](auto x, auto y){ return a[x][1] < a[y][1]; });
    sort(a, a+n, [&](auto x, auto y){ return x[1] < y[1]; });
    for (int i = 0; i < n; i++) {
        b[a[i][0]] = a[i][1], me[a[i][0]] = i;
        b[a[i][1]] = a[i][0], me[a[i][1]] = i;
    }
    iota(sorted_l, sorted_l+n, 0);
    sort(sorted_l, sorted_l+n, [&](auto x, auto y){ return a[x] < a[y]; });

    int m; cin >> m;
    set<int> s;
    while (m--) {
        int c; cin >> c, --c;
        s.insert(c);
    }
    for (int i = 0; i < n; i++) if (s.count(p[i])) need[i] = 1;

    FT<num> bit(2*n);

    for (int i = 0; i < 2*n; i++) {
        if (b[i] < i) { // right endpoint
            inside[me[i]] = 1 + bit.qry(b[i]+1, 2*n-1);
            bit.upd(b[i], inside[me[i]]);
        }
    }

    me_range = n-1;
    cout << rec(-1, 2*n) << '\n';
    // ans += left endpoint < me_l
    // ignore right endpoint >= me_r
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}