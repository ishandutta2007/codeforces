#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e2+10, MOD = 998244353;
 
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

struct DSU {
	vector<int> p, sz;
	void init(int n){ p.resize(n); sz.assign(n, 1); iota(p.begin(), p.end(), 0); }
	int find_set(int v){ return v==p[v]?v:p[v]=find_set(p[v]); }
	bool union_sets(int a, int b){
		if ((a=find_set(a))==(b=find_set(b))) return false;
		if (sz[a] < sz[b]) swap(a, b);
		p[b]=a, sz[a]+=sz[b], sz[b]=0;
		return true;
	}
} d;

num fact[N], ifact[N];

void pre() {
    fact[0] = ifact[0] = 1;
    for (int i = 1; i < N; i++) fact[i] = fact[i-1]*i;
    ifact[N-1] = inv(fact[N-1]);
    for (int i = N-2; i > 0; i--) ifact[i] = ifact[i+1]*num(i+1);
}
num nck(int n, int k) {
    if (n < 0 || k > n || k < 0) return 0;
    return fact[n]*ifact[k]*ifact[n-k];
}

void solve() {
    int n; cin >> n;

    auto dist = [&](ar<int, 2> one, ar<int, 2> two) {
        return abs(one[0] - two[0]) + abs(one[1] - two[1]);
    };
    vector<ar<int, 2>> a(n); for (auto& [x, y] : a) cin >> x >> y;

    vector<vector<int>> me(n);
    for (int i = 0; i < n; i++) {
        vector<ar<int, 2>> v;
        for (int j = 0; j < n; j++) if (i != j) {
            v.push_back({dist(a[i], a[j]), j});
        }
        sort(v.begin(), v.end());
        int j = 0;
        while (j < sz(v) && v[j][0] == v[0][0]) j++; 
        me[i].push_back(i);
        for (int k = 0; k < j; k++) me[i].push_back(v[k][1]);
        sort(me[i].begin(), me[i].end());
    }

    vector<bool> done(n);
    vector<int> use;
    for (int i = 0; i < n; i++) if (!done[i]) {
        vector<ar<int, 2>> v;
        for (int j = 0; j < n; j++) if (i != j) {
            v.push_back({dist(a[i], a[j]), j});
        }
        sort(v.begin(), v.end());
        int j = 0;
        while (j < sz(v) && v[j][0] == v[0][0]) j++; 
        bool bad = 0;
        for (int k = 0; k < j && !bad; k++) {
            if (done[v[k][1]]) bad = 1;
            if (me[v[k][1]] != me[i]) bad = 1;
            for (int l = 0; l < k && !bad; l++) {
                if (dist(a[i], a[v[k][1]]) != dist(a[v[k][1]], a[v[l][1]])) {
                    bad = 1;
                }
            }
        }

        done[i] = 1;
        if (!bad) {
            for (int k = 0; k < j; k++) {
                done[v[k][1]] = 1;
            }
            use.push_back(j + 1);
        } else {
            use.push_back(1);
        }
    }

    vector<num> pre(n + 1), cur(n + 1);
    pre[0] = 1;
    for (int x : use) {
        for (int i = 0; i < n; i++) {
            cur[i + 1] += pre[i];
        }
        if (x > 1) {
            for (int i = 0; i <= n - x; i++) if (pre[i] != 0) {
                cur[i + x] += pre[i];
            }
        }
        pre = cur;
        std::fill(cur.begin(), cur.end(), num(0));
    }

    num ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += nck(n, i) * fact[i] * pre[i];
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    pre();
    int T = 1;
    // cin >> T;
    while (T--) solve();
}