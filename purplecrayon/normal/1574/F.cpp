#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 3e5+10, MOD = 998244353;

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

num get_ans(vector<int> a, int k) {
    sort(a.begin(), a.end());
    vector<pair<int, int>> v;
    for (auto c : a) {
        if (sz(v) && v.back().first == c) v.back().second++;
        else v.emplace_back(c, 1);
    }

    vector<num> dp(k+1);
    dp[0] = 1;
    for (int i = 1; i <= k; i++) {
        for (auto [x, c] : v) {
            if (i >= x) dp[i] += dp[i-x]*c;
        }
    }
    return dp[k];
}

int n, m, k, nxt[MAXN], prv[MAXN];
vector<int> a[MAXN];

int dfs(int c) {
    if (c == -1) return 0;
    return 1 + dfs(nxt[c]);
}

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
bool bad[MAXN];
void solve() {
    cin >> n >> m >> k;

    memset(nxt, -1, sizeof(nxt));
    memset(prv, -1, sizeof(nxt));

    d.init(k);
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        a[i].resize(c);
        for (auto& v : a[i]) cin >> v, --v;

        auto set = [&](int& x, int y) -> bool {
            if (x != -1 && x != y) return 0;
            x = y;
            return 1;
        };

        for (int j = 0; j < c; j++) {
            d.union_sets(a[i][j], a[i][0]);
            if (j < c-1) {
                if (!set(nxt[a[i][j]], a[i][j+1])) { 
                    bad[a[i][j]] = 1;
                }
            }
            if (j) {
                if (!set(prv[a[i][j]], a[i][j-1])) {
                    bad[a[i][j]] = 1;
                }
            }
        }

        map<int, int> occ;
        for (auto c : a[i]) {
            if (occ[c]++) {
                bad[c] = 1;
            }
        }
    }
    for (int i = 0; i < k; i++) if (bad[i]) bad[d.find_set(i)] = 1;

    vector<int> v;
    for (int i = 0; i < k; i++) if (!bad[d.find_set(i)]) {
        if (prv[i] == -1) {
            v.push_back(dfs(i));
        }
    }
    num ans = get_ans(v, m);
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}