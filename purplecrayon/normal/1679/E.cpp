#include <bits/stdc++.h>
using namespace std;

#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e6+10, MOD = 998244353;

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
    string s; cin >> s;


    vector<vector<int>> cnt(n, vector<int>(n));
    vector<vector<int>> mask(n, vector<int>(n));

    for (int l = n-1; l >= 0; l--) {
        for (int r = l; r < n; r++) {
            if (l == r) {
                cnt[l][r] = s[l] == '?';
                continue;
            }
            if (cnt[l+1][r-1] == -1) {
                cnt[l][r] = -1;
                mask[l][r] = -1;
                continue;
            }
            if (s[l] != '?' && s[r] != '?') {
                if (s[l] == s[r]) cnt[l][r] = cnt[l+1][r-1], mask[l][r] = mask[l+1][r-1];
                else cnt[l][r] = mask[l][r] = -1;
                continue;
            }
            if (s[l] == '?' && s[r] == '?') {
                cnt[l][r] = cnt[l+1][r-1] + 1;
                mask[l][r] = mask[l+1][r-1];
                continue;
            }
            char c = s[l] ^ s[r] ^ '?';
            cnt[l][r] = cnt[l+1][r-1];
            mask[l][r] = mask[l+1][r-1] | (1 << (c - 'a'));
        }
    }

    const int M = 17;
    vector<vector<num>> dp(M + 1, vector<num>(1 << M));
    vector<vector<num>> po(M + 1, vector<num>(n + 1, 1));

    for (int b = 1; b <= M; b++) {
        for (int i = 1; i <= n; i++)
            po[b][i] = po[b][i-1] * b;
    }

    int tot_q = 0;
    for (char c : s) if (c == '?') tot_q++;

    for (int l = 0; l < n; l++) {
        int c_q = 0;
        for (int r = l; r < n; r++) {
            c_q += s[r] == '?';

            if (cnt[l][r] != -1) {
                for (int base = 1; base <= M; base++) {
                    dp[base][mask[l][r]] += po[base][cnt[l][r]] * po[base][tot_q - c_q];
                }
            }
        }
    }

    for (int base = 1; base <= M; base++) {
        for (int i = 0; i < M; i++) {
            for (int m = 0; m < (1 << M); m++) {
                if ((m >> i) & 1)
                    dp[base][m] += dp[base][m ^ (1 << i)];
            }
        }
    }

    int q; cin >> q;
    while (q--) {
        string t; cin >> t;
        int m = 0;
        for (char c : t) m |= 1 << (c - 'a');
        cout << dp[sz(t)][m] << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}