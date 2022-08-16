#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e3+10, MOD = 998244353;
const ll INF = 1e9+10;

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


int n, m;
ll a[N];
vector<int> adj[N];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) adj[i].clear();
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> deg(n);
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y, --x, --y;
        adj[x].push_back(y);
        deg[y]++;
    }
    queue<int> q;
    vector<vector<pair<ll, num>>> dp(n, vector<pair<ll, num>>(n + 1));
    for (int i = 0; i < n; i++) if (deg[i] == 0) {
        q.push(i);
    }
    for (int i = 0; i < n; i++) {
        dp[i][0] = {a[i], num(a[i])};
    }
    int cnt = 0;
    while (sz(q)) {
        int c = q.front(); q.pop();
        cnt++;
        if (cnt == n) {
            for (int j = n; j >= 0; j--) if (dp[c][j].first != 0) {
                cout << dp[c][j].second + j << '\n';
                return;
            }
        }
        for (auto nxt : adj[c]) {
            for (int j = 0; j < n; j++) {
                dp[nxt][j + 1].first += dp[c][j].first;
                dp[nxt][j + 1].second += dp[c][j].second;
                dp[nxt][j + 1].first = min(dp[nxt][j + 1].first, INF);
            }
            pair<ll, int> mx{-1, -1};
            for (int j = 0; j <= n; j++) {
                if (mx.first >= j) {
                    dp[nxt][mx.second].first += dp[nxt][j].first;
                    dp[nxt][mx.second].second += dp[nxt][j].second;
                    dp[nxt][mx.second].first = min(dp[nxt][mx.second].first, INF);

                    dp[nxt][j].first = 0;
                    dp[nxt][j].second = 0;

                    mx = max(mx, {mx.second + dp[nxt][mx.second].first, mx.second});
                } else if (dp[nxt][j].first > 0) {
                    mx = max(mx, {j + dp[nxt][j].first, j});
                }
            }

            deg[nxt]--;
            if (deg[nxt] == 0) q.push(nxt);
        }
    }
    cout << 0 << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}