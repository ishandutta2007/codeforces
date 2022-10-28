#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1.5e3+10, MOD = 998244353;

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

struct poly {
    vector<num> p;

    poly(){}
    poly(int n): p(n) {}
    poly(int n, num v): p(n, v) {}
    poly(vector<num>& a): p(a) {}

    friend poly operator * (const poly& a, const poly& b) {
        int n = sz(a.p), m = sz(b.p);
        poly ans(n+m-1);
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
            ans[i+j] += a[i]*b[j];
        return ans;
    }
    const num& operator [] (int i) const { return p[i]; }
    num& operator [] (int i) { return p[i]; }
    size_t size() { return p.size(); }
};

int n, par[MAXN], sz[MAXN];
int comp_ed[MAXN];
ar<int, 2> ed[MAXN*MAXN];
poly dp[MAXN];

int find_set(int v) {
    return v == par[v] ? v : par[v] = find_set(par[v]); 
}
void solve(){
    cin >> n;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        int x; cin >> x, --x;
        if (i < j) {
            ed[x] = {i, j};
        }
    }
    for (int i = 0; i < n; i++) {
        dp[i] = poly(2);
        dp[i][1] = 1;
        par[i] = i, sz[i] = 1;
    }
    const int M = n*(n-1)/2;
    for (int i = 0; i < M; i++) {
        auto [a, b] = ed[i];
        a = find_set(a), b = find_set(b);
        if (a != b) {
            if (sz[a] < sz[b]) swap(a, b);
            par[b] = a, sz[a] += sz[b];
            comp_ed[a] += comp_ed[b];
            comp_ed[a]++;

            dp[a] = dp[a]*dp[b];
            dp[b] = poly();
        } else {
            comp_ed[a]++;
        }

        if (comp_ed[a] == sz[a]*(sz[a]-1)/2) dp[a][1]++;
    }
    int root = find_set(0);
    for (int k = 1; k <= n; k++) {
        cout << dp[root][k] << ' ';
    }
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}