#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e3+10, MOD = 1e9+7;

struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};
struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	static const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};

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


ll ceil_div(ll x, ll y) {
    return (x + y - 1) / y;
}


#warning remember mod

num sum(num s, num d, num n) {
    return n * (2 * s + (n - 1) * d) / 2;
}

int n, m, q;
vector<ar<int, 2>> adj[N];
int dp[N][N];

void solve() {
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++) {
        int a, b, w; cin >> a >> b >> w, --a, --b;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    memset(dp, -1, sizeof(dp));
    // dp[i][j] = longest path ending at j with exactly i steps
    
    dp[0][0] = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < n; j++) if (dp[i-1][j] != -1) {
            for (auto [k, x] : adj[j]) {
                dp[i][k] = max(dp[i][k], dp[i-1][j] + x);
            }
        }
    }
    
    LineContainer store;
    num ans = 0;
    for (int j = 0; j <= m; j++) {
        for (int i = 0; i < n; i++) if (dp[j][i] != -1) {
            int use = -1;
            for (auto& [_, x] : adj[i]) use = max(use, x);

            // use * (x - j) + dp[j][i]
            ar<ll, 2> line{use, (long long) -use * j + dp[j][i]};
            store.add(line[0], line[1]);
        }
        if (j) {
            ll cur = store.query(j);
            /*
            int cur = 0;
            for (auto& [m, b] : lines) {
                cur = max(cur, m * j + b);
            }
            */
            ans += cur;
        }
    }
    vector<ar<ll, 2>> lines;
    for (auto line : store) {
        while (sz(lines) && lines.back()[1] <= line.m) lines.pop_back();
        lines.push_back({line.k, line.m});
    }
    // sorted by slope
    assert(std::is_sorted(lines.begin(), lines.end()));
    // for (auto c : lines) cout << c[0] << ' ' << c[1] << endl;

    int M = sz(lines);
    vector<ll> isect{m + 1}; // [L, R)
    for (int i = 0; i < M - 1; i++) {
        // cerr << "(" << lines[i][0] << ", " << lines[i][1] << ")\t(" << lines[i+1][0] << ", " << lines[i+1][1] << ")\n";
        ll bound = ceil_div(lines[i][1] - lines[i+1][1], lines[i+1][0] - lines[i][0]);
        // cerr << "> " << bound << endl;
        isect.push_back(bound);
    }
    isect.push_back(q + 1);

    for (int i = 0; i < M; i++) {
        ll L = isect[i];
        ll R = isect[i+1];
        L = max(L, (long long) m + 1);
        R = min(R, (long long) q + 1);
        if (L < R) {
            ans += sum(lines[i][0] * L + lines[i][1], lines[i][0], R - L);
        }
        // for (int j = L; j < R; j++) ans += lines[i][0] * j + lines[i][1];
    }
    
    /*
    for (int i = m + 1; i <= q; i++) {
        int cur = 0;
        for (auto& [m, b] : lines) {
            cur = max(cur, m * i + b);
        }
        ans += cur;
    }
    */
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}


// a * x + b >= c * x + d
//
// (a - c) * x >= d - b            <- a - c is positive
// x >= (d - b) / (a - c)          <- d - b is negative
// x >= ceil((d - b) / (a - c))