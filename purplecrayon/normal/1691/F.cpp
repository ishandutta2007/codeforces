#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;

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

const int V = 2e5+10;
num fact[V], ifact[V];

void pre() {
    fact[0] = ifact[0] = 1;
    for (int i = 1; i < V; i++) fact[i] = fact[i-1]*i;
    ifact[V-1] = inv(fact[V-1]);
    for (int i = V-2; i > 0; i--) ifact[i] = ifact[i+1]*num(i+1);
}
num nck(int n, int k) {
    if (n < 0 || k < 0 || k > n) return 0;
    return fact[n]*ifact[k]*ifact[n-k];
}
num nck(num n, num k) {
    return nck(int(n), int(k));
}

int n, k, sub[N], par[N];
vector<int> adj[N];

int dfs(int c, int p) {
    sub[c] = 1; par[c] = p;
    for (auto nxt : adj[c]) if (nxt != p) sub[c] += dfs(nxt, c);
    return sub[c];
}
int get_sub(int c, int p) {
    if (par[c] == p) return sub[c];
    return n - sub[p];
}
void solve() {
    pre();

    cin >> n >> k;
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b, --a, --b;
        adj[a].push_back(b), adj[b].push_back(a);
    }

    dfs(0, -1);

    vector<num> child(n);
    for (int nxt = 0; nxt < n; nxt++) {
        for (auto v : adj[nxt]) {
            child[nxt] += nck(get_sub(v, nxt), k);
        }
    }

    num ans = 0;
    for (int c = 0; c < n; c++) {
        for (auto nxt : adj[c]) {
            int cur = get_sub(nxt, c);
            ans += nck(cur, k) * (n - cur) * cur;
        }
        for (auto nxt : adj[c]) {
            int cur = get_sub(nxt, c);
            num mult = num(n - cur) * cur;
            num sum = child[nxt];
            /*
            for (auto v : adj[nxt]) {
                sum += nck(get_sub(v, nxt), k);
            }
            */
            sum -= nck(get_sub(c, nxt), k);
            ans -= sum * mult;
        }
    }
    for (int c = 0; c < n; c++) { // full tree case
        ans += nck(n, k) * n;
        for (int nxt : adj[c]) {
            ans -= nck(get_sub(nxt, c), k) * n;
        }
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}