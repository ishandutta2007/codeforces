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


int n, k;
ll a[N]; num ans = 0;
vector<ar<int, 2>> adj[N];

bool blocked[N];
int par[N], sub[N];
int dfs_sub(int u, int p) {
    sub[u] = 1;
    for (auto [v, _] : adj[u]) if (v != p && !blocked[v]) sub[u] += dfs_sub(v,u);
    return sub[u];
}
int dfs_centroid(int u, int p, int sz) {
    for (auto [v, _] : adj[u])  if (v != p && !blocked[v] && sub[v] > sz/2) return dfs_centroid(v,  u, sz);
    return u;
}

vector<pair<num, int>> cur_info;
void dfs_info(int c, int p, int last, int cnt, num sum) {
    sum += a[c];
    cur_info.push_back({sum, cnt});
    for (auto [nxt, col] : adj[c]) if (nxt != p && !blocked[nxt]) {
        dfs_info(nxt, c, col, cnt + (col != last), sum);
    }
}
num solve_pair(const auto& one, const auto& two, num extra_sum, int extra_cnt, int max_sz) {
    vector<num> sum(max_sz + 1);
    vector<int> cnt(max_sz + 1);
    for (const auto& [s_one, c_one] : one) {
        sum[c_one] += s_one;
        cnt[c_one]++;
    }
    for (int i = 1; i <= max_sz; i++) sum[i] += sum[i-1], cnt[i] += cnt[i-1];

    num cur = 0;
    for (const auto& [s_two, c_two] : two) if (c_two <= k - extra_cnt) {
        int use = min(max_sz, k - extra_cnt - c_two);
        cur += sum[use];
        cur += (extra_sum + s_two) * cnt[use];
    }
    return cur;
}
void solve_cent(int c) {
    int sz = sub[c];
    vector<pair<num, int>> cent_info[2];
    num same = 0;
    for (auto [nxt, col] : adj[c]) if (!blocked[nxt]) {
        cur_info.clear();
        dfs_info(nxt, c, col, 0, 0);
        same -= solve_pair(cur_info, cur_info, a[c], 0, sub[nxt]); 
        for (auto x : cur_info) cent_info[col].push_back(x);
    }
    ans += solve_pair(cent_info[0], cent_info[1], num(a[c]), 1, sz);
    same += solve_pair(cent_info[0], cent_info[0], num(a[c]), 0, sz);
    same += solve_pair(cent_info[1], cent_info[1], num(a[c]), 0, sz);
    ans += same / 2;

    vector<pair<num, int>> only_cent;
    only_cent.push_back({0, 0});

    ans += solve_pair(only_cent, cent_info[0], num(a[c]), 0, sz);
    ans += solve_pair(only_cent, cent_info[1], num(a[c]), 0, sz);
}

void build(int u, int p) {
    int sz = dfs_sub(u, p);
    int cent = dfs_centroid(u, p, sz);
    solve_cent(cent);
    par[cent] = p; blocked[cent] = 1;
    for (auto [nxt, _] : adj[cent]) if (!blocked[nxt]) build(nxt, cent);
}

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i], ans += a[i];
    for (int i = 0; i < n-1; i++) {
        int a, b, c; cin >> a >> b >> c, --a, --b;
        adj[a].push_back({b, c}), adj[b].push_back({a, c});
    }
    build(0, -1);
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}