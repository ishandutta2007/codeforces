#include <bits/stdc++.h>
using namespace std;

#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e5+10, MOD = 1e9+7;

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

int pf[N];
num fact[N], ifact[N];

void pre() {
    memset(pf, -1, sizeof(pf));
    for (int i = 2; i < N; i++) if (pf[i] == -1) {
        for (int j = i; j < N; j += i) pf[j] = i;
    }
}

int calc_mobius(int x) {
    int ans = 0;
    while (x > 1) {
        int p = pf[x];
        int cnt = 0;
        while (x % p == 0) {
            cnt++;
            x /= p;
        }
        if (cnt > 1) return 0;
        assert(cnt == 1);
        ans ^= 1;
    }
    return ans ? -1 : +1;
}

void solve() {
    // sum{lcm(c, gcd(a, b)) such that a + b + c = n
    // sum{lcm(n - a - b, gcd(a, b))

    // gcd(n - a - b, a, b) = gcd(n, a, b)
    // sum{n - a - b} * gcd(a, b) / gcd(n, a, b)  
    // dp[i] = sum{n - a - b} s.t. gcd(a, b) is a multiple of i
    // do inclusion exclusion with mobious function

    int n; cin >> n;
    vector<num> dp(n + 1);
    for (int g = 1; g <= n; g++) {
        vector<int> use;
        for (int a = g; a <= n; a += g) {
            use.push_back(a);
        }
        num cur = 0, cnt = 0;
        int b = sz(use)-1;
        for (int a = 0; a < sz(use); a++) {
            while (b >= 0 && use[a] + use[b] >= n) b--;
            cnt += b + 1;
            cur += num(use[a]) * (b + 1);
        }
        dp[g] = cnt * n - 2 * cur;
    }
    vector<int> f(n + 1);
    for (int i = 1; i <= n; i++) f[i] = calc_mobius(i);

    num ans = 0;
    for (int g = n; g >= 1; g--) {
        num cur = 0;
        for (int m = g; m <= n; m += g) {
            cur += dp[m] * f[m / g];
        }
        ans += g / std::gcd(n, g) * cur;
    }

    /*
    for (int a = 1; a <= n; a++) {
        for (int b = 1; a + b < n; b++) {
            int g = std::gcd(a, b);
            ans += g * (n - a - b) / std::gcd(n, g);
        }
    }
    */
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    pre();
    int T = 1;
    // cin >> T;
    while (T--) solve();
}