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

void solve() {
    int n; cin >> n;
    string s, t; cin >> s >> t;
    for (int i = 0; i < n; i += 2) if (s[i] != '?') s[i] ^= '0' ^ '1';
    for (int i = 0; i < n; i += 2) if (t[i] != '?') t[i] ^= '0' ^ '1';

    vector<vector<num>> pre(n), suf(n);
    for (int rep : {0, 1}) {
        vector<num> one(2*n+1, 0), two(2*n+1, 0);
        one[n] = 1;
        for (int i = 0; i < n; i++) {
            char a = (rep ? s[n-1-i] : s[i]);
            char b = (rep ? t[n-1-i] : t[i]);
            for (int x : {0, 1}) if (a - '0' == x || a == '?') {
                for (int y : {0, 1}) if (b - '0' == y || b == '?') {
                    int delta = x - y;
                    for (int k = 0; k < 2*n+1; k++) if (one[k] != 0) {
                        two[k + delta] += one[k];
                    }
                }
            }

            if (rep) suf[n-1-i] = two;
            else pre[i] = two;

            for (int j = 0; j < 2*n+1; j++) one[j] = two[j], two[j] = 0;
        }
    }
    num ans = 0;
    for (int i = 0; i < n - 1; i++) {
        // ans += abs(1's <= i in S, 1's <= i in T) over all strings
        // number of ways for some prefix of S to have exactly x more 1's than a prefix of T
        for (int x = -n; x <= n; x++) {
            int y = -x;
            ans += pre[i][x+n] * suf[i+1][y+n] * abs(x);
        }
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}