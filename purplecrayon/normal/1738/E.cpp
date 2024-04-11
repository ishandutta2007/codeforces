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

num fact[N], ifact[N];

void pre() {
    fact[0] = ifact[0] = 1;
    for (int i = 1; i < N; i++) fact[i] = fact[i-1]*i;
    ifact[N-1] = inv(fact[N-1]);
    for (int i = N-2; i > 0; i--) ifact[i] = ifact[i+1]*num(i+1);
}
num nck(int n, int k) {
    return fact[n] * ifact[k] * ifact[n-k];
}

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& x : a) cin >> x;

    vector<num> po2(n + 1, 1);
    for (int i = 1; i <= n; i++) po2[i] = po2[i-1] * 2;

    ll L_sum = 0, R_sum = 0;
    num ans = 1;
    for (int l = 0, r = n-1; l < n; l++) {
        L_sum += a[l];
        while (R_sum < L_sum && r > l) {
            R_sum += a[r];
            r--;
        }
        if (L_sum == R_sum) {
            int z_l = 0, z_r = 0;
            while (l + z_l + 1 < n && a[l + z_l + 1] == 0) z_l++;
            while (r - z_r >= 0 && a[r - z_r] == 0) z_r++;
            // cerr << l << ' ' << z_l << ' ' << r << ' ' << z_r << endl;
            if (l + z_l == r) {
                // cerr << "one segment\n";
                // one big segment
                // x _ _ _ _ _ _ x

                int cur_sz = z_l + 1 + (r < n-1);
                ans *= po2[cur_sz - 1];
                break;
            } else {
                int one = z_l + 1, two = z_r + (r < n-1);
                // cerr << "one, two: " << one << ' ' << two << endl;
                num cur_ans = 0;
                for (int k = 0; k <= min(one, two); k++) {
                    cur_ans += nck(one, k) * nck(two, k);
                }
                ans *= cur_ans;

                l += z_l;
                r -= z_r;
            }
        }
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    pre();
    int T = 1;
    cin >> T;
    while (T--) solve();
}