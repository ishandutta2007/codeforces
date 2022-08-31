#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e5+10, MOD = 998244353;

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

struct S {
    int cnt = 0;
    ll sum = 0;
    ll sq = 0;

    void add(ll x) {
        cnt++;
        sum += x;
        sq += x * x;
    }
    ll qry(ll x) {
        // sum{(x - y)^2} for all y in S
        // sum{x^2 - 2*x*y + y^2}
        return x * x * cnt - 2 * x * sum + sq;
    }
};

void solve() {
    int n, m; cin >> n >> m;
    vector<ar<int, 2>> a(n * m);
    for (int i = 0; i < n * m; i++) cin >> a[i][0], a[i][1] = i;
    sort(a.begin(), a.end());

    int R, C; cin >> R >> C, --R, --C;

    num ev = 0;
    S row, col;
    for (int i = 0; i < n*m; i++) {
        int j = i;
        while (j < n*m && a[j][0] == a[i][0]) j++;
        j--;
        
        num to_add = 0;
        for (int k = i; k <= j; k++) {
            num cur = 0;
            if (i) cur = (ev + row.qry(a[k][1] / m) + col.qry(a[k][1] % m)) / i;
            to_add += cur;
            if (a[k][1] == R * m + C) {
                cout << cur << '\n';
                return;
            }
        }
        ev += to_add;


        for (int k = i; k <= j; k++) {
            row.add(a[k][1] / m);
            col.add(a[k][1] % m);
        }

        i = j;
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}