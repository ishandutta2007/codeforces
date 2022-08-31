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

num fact[N], ifact[N];

void pre() {
    fact[0] = ifact[0] = 1;
    for (int i = 1; i < N; i++) fact[i] = fact[i-1]*i;
    ifact[N-1] = inv(fact[N-1]);
    for (int i = N-2; i > 0; i--) ifact[i] = ifact[i+1]*num(i+1);
}
void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& x : a) cin >> x, --x;

    vector<int> cnt(n);
    for (int x : a) cnt[x]++;

    vector<int> use; use.reserve(n);
    for (int i = 0; i < n; i++) if (cnt[i]) use.push_back(cnt[i]);

    int g = 0;
    for (int x : use) g = std::gcd(g, x);

    vector<num> memo_ans(n + 1), memo_cnt(n + 1);
    for (int k = 1; k <= n; k++) if (g % k == 0 && n % k == 0) {
        memo_cnt[k] = fact[n / k];
        for (int x : use) {
            x /= k;
            memo_cnt[k] *= ifact[x];
        }
        if (sz(use) == 1) {
            memo_ans[k] = memo_cnt[k];
            continue;
        }
        for (int x : use) {
            x /= k;
            if (k == n) {
                memo_ans[k]++;
            } else if (x > 1) {
                memo_ans[k] += memo_cnt[k] * fact[x] * ifact[n / k] * fact[n / k - 2] * ifact[x - 2];
            }
        }
        // memo_ans[k] = number of permutations in which first element is the same as last
        memo_ans[k] = memo_cnt[k] - memo_ans[k];
        memo_ans[k] *= num(n); // * (n / k) * k
    }

    num ans = 0;
    num tot_cnt = 0;
    for (int i = 1; i <= n; i++) {
        int period = std::gcd(n, i);
        if (g % (n / period)) continue;
        // if not divisible, then you can't have a period of that size
        ans += memo_ans[n / period];
        tot_cnt += memo_cnt[n / period];
    }
    ans /= tot_cnt;
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    pre();
    int T = 1;
    cin >> T;
    while (T--) solve();
}