#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e3+10, MOD = 998244353;

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
	void init(int n) { 
        p.resize(n); iota(p.begin(), p.end(), 0);
        sz.assign(n, 1);
    }
	int find_set(int v) { 
        return v == p[v] ? v : p[v] = find_set(p[v]);
    }
	bool union_sets(int a, int b) {
        a = find_set(a), b = find_set(b);
        if (a == b) return false;
		if (sz[a] < sz[b]) swap(a, b);
		p[b] = a, sz[a] += sz[b], sz[b] = 0;
		return true;
	}
} d;

int n, m;
string g[N];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> g[i];
    if (n % 2 == 0 && m % 2 == 0) {
        num ans = 1;
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (g[i][j] == '?') ans *= 2;
        cout << ans << '\n';
    } else if (n % 2 == 1 && m % 2 == 1) {
        // row xor's must be the same and col xor's must be the same
        // make bipartite graph connecting rows and cols
        // each of the nodes start with a value
        // each edge means you can flip both of the nodes
        // count number of ways to choose a subset of edges to flip s.t. the values in all of the nodes at the end becomes a 0 (or a 1, but that case is equivalent)
        // consider each of the connected components separately
        // let's consider a tree, the number of ways is exactly 1 (assuming the xor's between the white and black nodes works out)
        // so the answer is 2^(m - n + 1), if the white and black nodes start with the same xor, and 0 otherwise

        num base = 1;
        vector<int> row_xor(n + m), col_xor(n + m);
        vector<int> row_cnt(n + m), col_cnt(n + m);
        d.init(n + m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) if (g[i][j] == '?') {
                if (!d.union_sets(i, j + n)) {
                    base *= 2;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) if (g[i][j] != '?') {
                row_xor[d.find_set(i)] ^= g[i][j] - '0', row_cnt[d.find_set(i)]++;
                col_xor[d.find_set(j + n)] ^= g[i][j] - '0', col_cnt[d.find_set(j + n)]++;
            }
        }


        bool z = 1, o = 1;
        for (int i = 0; i < n + m; i++) if (d.p[i] == i) {
            if (row_xor[i] != col_xor[i]) z = 0;
            if ((row_xor[i] ^ row_cnt[i]) % 2 != (col_xor[i] ^ col_cnt[i]) % 2) o = 0;
        }

        int cnt = int(z) + int(o);
        cout << base * cnt << '\n';
    } else if (n % 2 == 0 && m % 2 == 1) {
        // row xor's must be the same, col xor's can be whatever
        num z = 1, o = 1;
        for (int i = 0; i < n; i++) {
            num rz = 1, ro = 0;
            for (int j = 0; j < m; j++) {
                num nz = 0, no = 0;
                if (g[i][j] == '?') {
                    nz = rz + ro;
                    no = rz + ro;
                } else if (g[i][j] == '1') {
                    nz = ro, no = rz;
                } else if (g[i][j] == '0') {
                    nz = rz, no = ro;
                } else assert(false);
                rz = nz, ro = no;
            }
            z *= rz, o *= ro;
        }
        cout << z + o << '\n';
    } else if (n % 2 == 1 && m % 2 == 0) {
        // col xor's must be the same, row xor's can be whatever
        num z = 1, o = 1;
        for (int j = 0; j < m; j++) {
            num cz = 1, co = 0;
            for (int i = 0; i < n; i++) {
                num nz = 0, no = 0;
                if (g[i][j] == '?') {
                    nz = cz + co;
                    no = cz + co;
                } else if (g[i][j] == '1') {
                    nz = co, no = cz;
                } else if (g[i][j] == '0') {
                    nz = cz, no = co;
                } else assert(false);
                cz = nz, co = no;
            }
            z *= cz, o *= co;
        }
        cout << z + o << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}