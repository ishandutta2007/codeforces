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

// you iterate over the size of the range that contains the left endpoint, check if it's a valid range

int get(int n, vector<int> a) {
    int m = sz(a);
    vector<int> L(n, m), R(n, -1);
    vector<int> prv(n, -1), nxt(n, m);
    for (int i = 0; i < m; i++) {
        L[a[i]] = min(L[a[i]], i);
        R[a[i]] = max(R[a[i]], i);
    }
    for (int i = 0; i < n; i++) {
        for (int j = L[i]; j >= 0; j--) if (a[j] < i) {
            prv[i] = j;
            break;
        }
        for (int j = R[i]; j < m; j++) if (a[j] < i) {
            nxt[i] = j;
            break;
        }
    }

    vector<vector<int>> loc(n);
    for (int i = 0; i < m; i++) loc[a[i]].push_back(i);

    vector<vector<num>> dp(m, vector<num>(m));

    auto DP = [&](int l, int r) -> num {
        if (l > r || l < 0 || r >= m) return 1;
        return dp[l][r];
    };

    for (int r = 0; r < m; r++) {
        for (int l = r; l >= 0; l--) {
            bool bad = 0;

            int c = n;
            for (int k = l; k <= r; k++) {
                c = min(c, a[k]);
                if (L[a[k]] < l || R[a[k]] > r) {
                    bad = 1;
                    break;
                }
            }
            if (bad) continue;

            num one = 0, two = 0;
            for (int a = max(l, prv[c] + 1); a <= L[c]; a++) {
                one += DP(l, a-1) * DP(a, L[c]-1);
            }
            for (int b = R[c]; b <= min(r, nxt[c] - 1); b++) {
                two += DP(R[c]+1, b) * DP(b+1, r);
            }
            dp[l][r] = one * two;
            /*
            for (int a = max(l, prv[c] + 1); a <= L[c]; a++) {
                for (int b = R[c]; b <= min(r, nxt[c] - 1); b++) {
                    dp[l][r] += DP(l, a-1) * DP(a, L[c]-1) * DP(R[c]+1, b) * DP(b+1, r);
                    // dp[l][r] += dp[l][a-1] * dp[a][L[c]-1] * dp[R[c]+1][b] * dp[b+1][r];
                }
            }
            */
            for (int i = 1; i < sz(loc[c]); i++) {
                dp[l][r] *= DP(loc[c][i-1]+1, loc[c][i]-1);
                // dp[l][r] *= dp[loc[c][i-1]+1][loc[c][i]-1];
            }
        }
    }
    return int(dp[0][m-1]);
}
void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(m); for (auto& x : a) cin >> x, --x;
    vector<int> b;
    for (int x : a) {
        if (!sz(b) || b.back() != x) b.push_back(x);
    }
    if (sz(b) > 2 * n) {
        cout << 0 << '\n';
        return;
    }
    cout << get(n, b) << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}