#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+10, MOD = 998244353;

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

num fact[MAXN], ifact[MAXN];

void pre() {
    fact[0] = ifact[0] = 1;
    for (int i = 1; i < MAXN; i++) fact[i] = fact[i-1]*i;
    ifact[MAXN-1] = inv(fact[MAXN-1]);
    for (int i = MAXN-2; i > 0; i--) ifact[i] = ifact[i+1]*num(i+1);
}
num nck(int n, int k) {
    if (n < 0 || k < 0 || k > n) return 0;
    return fact[n]*ifact[k]*ifact[n-k];
}
num po(num b, ll p) {
    num r=1;
    for (; p; b=b*b, p>>=1) if (p&1) r=r*b;
    return r;
}

int n;
ar<char, 2> a[MAXN];

char flip(char c) {
    if (c == '?') return c;
    return c ^ 'B' ^ 'W';
}
void solve() {
    cin >> n;
    bool has_b = 0, has_w = 0;
    bool all_same = 1;
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
        a[i][0] = flip(a[i][0]);
        for (char c : a[i]) {
            if (c == 'B') has_b = 1;
            if (c == 'W') has_w = 1;
        }
        if (a[i][0] != '?' && a[i][1] != '?' && a[i][0] != a[i][1])
            all_same = 0;
    }

    
    int open_left = 0, open_right = 0;
    int b_left = 0, b_right = 0;
    for (int i = 0; i < n; i++) {
        if (a[i][0] == 'B') b_left++;
        if (a[i][1] == 'B') b_right++;
        if (a[i][0] == '?') open_left++;
        if (a[i][1] == '?') open_right++;
    }
    num ans = 0;
    for (int b = 0; b <= n; b++) {
        num ways = nck(open_left, b - b_left) * nck(open_right, b - b_right);
        ans += ways;
    }
    // subtract out case where L == R for all dominoes
    if (all_same) {
        int cnt_free = 0;
        for (int i = 0; i < n; i++) if (a[i][0] == '?' && a[i][1] == '?')
            cnt_free++;

        ans -= po(2, cnt_free);
    }
    ans += int(!has_b) + int(!has_w); // add back case where everything is the same

    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    pre();
    int T=1;
    // cin >> T;
    while (T--) solve();
}