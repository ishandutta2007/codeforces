#include <bits/stdc++.h>
using namespace std;

#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 998244353;

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
    // count the number of canonical forms, where canon form is the lexicographically smallest transformation
    // if you are adding some character c, and you have a set of possible characters that you could've added
    //      - if can't swap with c, now can add
    //      - else if < c, now bad
    //      - otherwise doesn't change
    //
    //  dp[prefix][mask]
    //
    // precompute mask transitions

    int n, m; cin >> n >> m;

    const int M = 10;
    bool can[M][M];
    memset(can, 0, sizeof(can));

    while (m--) {
        int a, b; cin >> a >> b;
        can[a][b] = can[b][a] = 1;
    }

    int trans[1 << M][M];
    memset(trans, -1, sizeof(trans));
    for (int i = 0; i < (1 << M); i++) {
        for (int j = 0; j < M; j++) if ((i >> j) & 1) {
            int new_mask = i;
            for (int k = 0; k < M; k++) {
                if (!can[j][k]) new_mask |= 1 << k;
                else if (k < j) new_mask &= ~(1 << k);
            }
            trans[i][j] = new_mask;
        }
    }

    num pre[1 << M], cur[1 << M];
    memset(pre, 0, sizeof(pre));
    memset(cur, 0, sizeof(cur));
    pre[(1 << M) - 1] = 1;
    for (int rep = 0; rep < n; rep++) {
        for (int i = 0; i < (1 << M); i++) {
            for (int j = 0; j < M; j++) if ((i >> j) & 1) {
                cur[trans[i][j]] += pre[i];
            }
        }
        memcpy(pre, cur, sizeof(cur));
        memset(cur, 0, sizeof(cur));
    }
    num ans = 0;
    for (int i = 0; i < (1 << M); i++) ans += pre[i];
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}