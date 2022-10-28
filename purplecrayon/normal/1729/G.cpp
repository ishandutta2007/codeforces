#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e3+10, MOD = 1e9+7;

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
    if (n < 0 || k < 0 || n < k) return 0;
    return fact[n] * ifact[k] * ifact[n-k];
}

num merge(int a, int b) {
    return nck(a + b, a);
}
void solve() {
    string s, t; cin >> s >> t;
    int n = sz(s), m = sz(t);
    vector<bool> match(n);
    for (int i = 0; i + m <= n; i++) {
        if (s.substr(i, m) == t) {
            match[i] = 1;
        }
    }
    vector<vector<int>> dp(n + 1, vector<int>(n));
    vector<vector<num>> cnt(n + 1, vector<num>(n, 1));
    for (int l = n-1; l >= 0; l--) {
        for (int r = l; r < n; r++) {
            dp[l][r] = MOD;
            bool has = 0;
            for (int k = l; k + m <= r + 1; k++) if (match[k]) {
                has = 1;
                int L = (k ? dp[l][k-1] : 0), R = dp[k+m][r];
                int new_dp = 1 + L + R;
                num new_cnt = (k ? cnt[l][k-1] : 1) * cnt[k+m][r] * merge(L, R);
                if (dp[l][r] == new_dp) {
                    cnt[l][r] += new_cnt;
                } else if (new_dp < dp[l][r]) {
                    dp[l][r] = new_dp;
                    cnt[l][r] = new_cnt;
                }
            } 
            if (!has) dp[l][r] = 0, cnt[l][r] = 1;
        }
    }
    int ans_dp = dp[0][n-1];
    num ans_cnt = cnt[0][n-1] / fact[ans_dp];
    cout << ans_dp << ' ' << ans_cnt << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    pre();
    int T = 1;
    cin >> T;
    while (T--) solve();
}