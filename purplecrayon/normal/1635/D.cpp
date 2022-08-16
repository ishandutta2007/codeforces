#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

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

int n, p;
ll a[MAXN];
num f[MAXN];

num get_cnt(int x) {
    int b = 31 - __builtin_clz(x) + 1; // number of used bits
    // cerr << x << ' ' << p-b << ' ' << f[p-b] << '\n';
    if (b > p) return 0;
    return f[p - b];
}
string to_bin(int x) {
    vector<int> v;
    while (x) v.push_back(x % 2), x /= 2;
    reverse(v.begin(), v.end());
    string s;
    for (int a : v) s += char('0' + a);
    return s;
}
void solve() {
    // either add a 1 or add two 0's
    // f(x) = f(x-1) + f(x-2)
    cin >> n >> p;
    for (int i = 0; i < n; i++) cin >> a[i];

    f[0] = 1;
    f[1] = 1;
    for (int i = 2; i <= p; i++) {
        f[i] = f[i-1] + f[i-2];
    }
    for (int i = 1; i <= p; i++) f[i] += f[i-1]; // at most i

    sort(a, a + n);

    num ans = 0;
    set<int> has;
    for (int i = 0; i < n; i++) {
        int x = a[i];
        vector<pair<int, int>> v;
        int make = 0;
        while (x && (!has.count(x) || make)) {
            if (sz(v) && x % 2 == v.back().first) {
                if (v.back().first == 0) {
                    if (v.back().second % 2) make--;
                    else make++;
                }
                v.back().second++;
            }
            else {
                if (x % 2 == 0) make++;
                v.emplace_back(x % 2, 1);
            }
            x /= 2;
            // if (i == 1)
                // cerr << "> " << x << ' ' << make << endl;
        }
        has.insert(a[i]);
        // cerr << i << ' ' << x << ' ' << to_bin(a[i]) << endl;
        if (x == 0) ans += get_cnt(a[i]);
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}