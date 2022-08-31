#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 4e2+10, MOD = 1e9+7;

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


// count the number of permutations of size n such that the number of cycles is >= n - k
// since you need at least n - k cycles, at most 2*k aren't singleton
// proof by contradiction:
//     2*k+1 that aren't singletons, n - k - 1 cycles for the rest, at most k cycles, n - k - 1 + k < n nodes
// proof by analysis:
//     original process affects two nodes at once, can affect at most 2*k in total
//
// calculate f(non-singletons (n), num-cycles (k)): the number of permutations of size n with k different cycles with size at least 2

int f_slow(int n, int k) {
    if (n == 0) return 1;
    vector<int> P(n); iota(P.begin(), P.end(), 0);
    int ans = 0;
    do {
        vector<bool> vis(n);
        int cnt = 0;
        bool bad = 0;
        for (int i = 0; i < n; i++) if (!vis[i]) {
            int c = i;
            int me = 0;
            cnt++;
            while (!vis[c]) {
                me++;
                vis[c] = 1;
                c = P[c];
            }
            if (me == 1) {
                bad = 1;
                break;
            }
        }
        if (cnt != k) bad = 1;
        if (!bad) ans++;
    } while (next_permutation(P.begin(), P.end()));
    return ans;
}
num nck_big(int n, int k) {
    num ans = 1;
    for (int i = 0; i < k; i++) {
        ans *= n - i;
        ans /= i + 1;
    }
    return ans;
}

int n, k;
num ans[MAXN], fact[MAXN], ifact[MAXN], dp[MAXN][MAXN];

num nck(int n, int k) {
    return fact[n] * ifact[k] * ifact[n - k];
}
num f(int n, int k) {
    return dp[n][k];
}
void solve() {
    cin >> n >> k;

    fact[0] = ifact[0] = 1;
    for (int i = 1; i <= 2 * k; i++) fact[i] = fact[i-1] * i, ifact[i] = fact[i].inv();

    dp[0][0] = 1;
    for (int a = 1; a <= 2 * k; a++) {
        for (int b = 1; b <= a; b++) {
            for (int x = 2; x <= a; x++) {
                // fact[a - 1] * ifact[a - x + 1]
                num cur_ways = fact[a - 1] * ifact[a - x] * dp[a - x][b - 1];
                // num cur_ways = nck(a - 1, x - 1) * dp[a - x][b - 1] * fact[x - 1];
                dp[a][b] += cur_ways;
            }
        }
    }

    for (int a = 0; a <= min(n, 2 * k); a++) {
        num choose = nck_big(n, a);
        for (int b = 0; b <= min(n, a); b++) {
            // f(a, b) -> a non-singletons and b cycles within them, b + (n - a) cycles
            ll cnt_cyc = b + (n - a);
            num cur = f(a, b) * choose;
            ll x = n - cnt_cyc;
            if (x <= k)
                ans[x] += cur;
            /*
            for (ll x = n - cnt_cyc; x <= k; x += 2) if (cnt_cyc >= n - x)
                ans[x] += cur;
            */
        }
    }
    for (int i = 1; i <= k; i++) {
        if (i >= 2) ans[i] += ans[i - 2];
        cout << ans[i] << ' ';
    }
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}