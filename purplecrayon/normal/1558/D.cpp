#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 5e5+10, MOD = 998244353;
const ll INF = 1e18+10;

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

num nck(int n, int k) {
    return fact[n]*ifact[k]*ifact[n-k];
}

int rec(int n, int last, int bound, int cnt) {
    if (n == 0) return cnt <= 0;
    int ans = 0;
    for (int i = max((cnt > 0 ? last + 1 : last), 0); i <= bound; i++) {
        ans += rec(n-1, i, bound, cnt - (i > last && last != -1));
    }
    return ans;
}
num count(int n, int cnt) {
    // number of non decreasing arrays of length n such that there are cnt increases in the specified location
    // if cnt == 0: answer is (2 * n - 1 choose n)
    //
    // alternative combo arg:
    // consider difference array, sum must be <= n
    // n + 1 elements, sum must be n - 1, (2 * n - 1 choose n)
    // by fixing some things to be 1, you subtract 1 from a bunch of choices
    // sum -= cnt
    
    int N = n + 1;
    int sum = n - 1 - cnt;
    // cerr << sum + N - 1 << ' ' << N - 1 << endl;
    return nck(sum + N - 1, N - 1);
    // return rec(n, -1, n-1, cnt);
}

#include <bits/extc++.h>
using namespace __gnu_pbds;

template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

oset<int> o;

void pre() {
    fact[0] = ifact[0] = 1;
    for (int i = 1; i < N; i++) fact[i] = fact[i-1]*i;
    for (int i = 0; i < N; i++) o.insert(i);
    ifact[N-1] = inv(fact[N-1]);
    for (int i = N-2; i > 0; i--) ifact[i] = ifact[i+1]*num(i+1);
}

void solve() {
    int n, m; cin >> n >> m;
    vector<pair<int, int>> a(m);
    set<int> s;

    for (auto& c : a) {
        int x, y; cin >> x >> y, --x, --y;
        c = {x, y};
    }

    for (int i = m-1; i >= 0; i--) {
        int x = *o.find_by_order(a[i].second);
        int y = *o.find_by_order(a[i].second + 1);
        s.insert(y);
        o.erase(x);
    }
    int cnt = sz(s);

    cout << count(n, cnt) << '\n';

    for (int i = 0; i < m; i++) o.insert(a[i].second);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    pre();
    cin >> T;
    while (T--) solve();
}