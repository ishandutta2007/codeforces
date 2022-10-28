#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e3+10, MOD = 998244353;

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

string s, t;
num dp[N][N][2][2][2];

void solve() {
    cin >> s >> t;
    int n = sz(s), m = sz(t);

    num ans = 0;
    dp[n][m][0][0][0] = dp[n][m][1][0][0] = 1;
    for (int i = n; i >= 0; i--) {
        for (int j = m; j >= 0; j--) {
            if (i == n && j == m) continue;
            for (int k = 0; k < 3; k++) {
                for (int a : {0, 1}) for (int b : {0, 1}) {
                    if (k == 0 && i == 0) dp[i][j][k][a][b] = 0;
                    else if (k == 1 && j == 0) dp[i][j][k][a][b] = 0;
                    else {
                        char prv = '?';
                        if (k < 2) prv = (k == 0 ? s[i-1] : t[j-1]);

                        num cur = !a && !b;
                        if (i < n && s[i] != prv && a) {
                            cur += dp[i+1][j][0][0][b] + dp[i+1][j][0][1][b];
                        }
                        if (j < m && t[j] != prv && b) {
                            cur += dp[i][j+1][1][a][0] + dp[i][j+1][1][a][1];
                        }

                        if (k < 2) dp[i][j][k][a][b] = cur;
                        else if (a == 1 && b == 1 && i < n && j < m) {
                            ans += cur;
                        }
                    }
                }
            }
        }
    }
    cout << ans  << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}