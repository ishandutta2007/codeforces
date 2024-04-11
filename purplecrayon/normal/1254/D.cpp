#include "bits/stdc++.h"
using namespace std;
 
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

#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1.5e5+10, MAXQ = 1.5e5+10, MOD = 998244353, B = 850;

template<class T> struct RMQ { //min range query (default)
	vector<vector<T>> st;
	vector<int> log;
	T combine(T a, T b) {return min(a, b);}
	void build(int n, vector<T>& a) {
		log = vector<int>(n + 1);
		for (int i = 2; i <= n; ++i) log[i] = log[i >> 1] + 1;
		int k = log[n];
		st = vector<vector<T>>(n, vector<T>(k + 1));
		for (int i = 0; i < n; ++i) st[i][0] = a[i];
		for (int j = 1; j <= k; ++j) for (int i = 0; i + (1 << j) - 1 < n; ++i)
			st[i][j] = combine(st[i][j - 1], st[i + (1 << (j - 1))][j-1]);
	}
	T qry(int l, int r) {
		int k = log[r - l + 1];
		return combine(st[l][k], st[r - (1 << k) + 1][k]);
	}
};
 
int n, st[MAXN], en[MAXN], depth[MAXN], et[MAXN], par[MAXN], tt=0;
vector<vector<int>> adj;
RMQ<pair<int, int>> rq;

void init_lc() {
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        v[i] = {depth[et[i]], -i};
    }
    rq.build(n, v);
}
int almost_anc(int root, int v) {
    if (st[root] <= st[v] && st[v] <= en[root]) {
        auto ans = rq.qry(st[root]+1, st[v]);
        return et[-ans.second];
    } else return par[root];
}

using num = modnum<MOD>;

int q, sub[MAXN];
num add[MAXN], cur[MAXN], prop[MAXN];
vector<pair<int, num>> buffer;


//(n-sz[anc])*d

void dfs_init(int c=0, int p=-1, int d=0) {
    sub[c] = 1; et[st[c] = tt++] = c; depth[c] = d, par[c] = p;
    for (auto nxt : adj[c]) if (nxt != p) {
        dfs_init(nxt, c, d+1);
        sub[c] += sub[nxt];
    }
    en[c] = tt-1;
}
void dfs1(int c=0, int p=-1) {
    cur[c] = add[c]*n;
    for (auto nxt : adj[c]) if (nxt != p) {
        prop[nxt] += add[c]*(n-sub[nxt]);
        dfs1(nxt, c);
    }
    if (c) {
        //p += add[c]*sub[c]
        prop[c] -= add[c]*sub[c];
        prop[0] += add[c]*sub[c];
    }
}
void dfs2(int c=0, int p=-1, num sm = 0) {
    sm += prop[c], cur[c] += sm;
    for (auto nxt : adj[c]) if (nxt != p) dfs2(nxt, c, sm);
}

void bld() {
    fill(prop, prop+n, num(0));

    for (int c = 0; c < n; c++) {
        cur[c] = add[c]*n;
        int p = par[c];
        for (auto nxt : adj[c]) if (nxt != p) {
            prop[nxt] += add[c]*(n-sub[nxt]);
        }
        if (c) {
            prop[c] -= add[c]*sub[c];
            prop[0] += add[c]*sub[c];
        }
    }
    for (int i = 0; i < n; i++) {
        int c = et[i];
        if (c) prop[c] += prop[par[c]];

        cur[c] += prop[c];
    }
}
void solve(){
    cin >> n >> q;
    adj.resize(n);
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b, --a, --b;
        adj[a].push_back(b), adj[b].push_back(a);
    }
    dfs_init(); init_lc();
    buffer.reserve(B);
    fill(add, add+n, 0);

    const num IN = num(1)/num(n);
    while (q--) {
        int ty; cin >> ty;
        if (ty == 1) {
            int c; ll v; cin >> c >> v, --c;
            add[c] += v;

            buffer.push_back({c, num(v)});
        } else {
            int c; cin >> c, --c;
            num ans = cur[c];

            for (auto v : buffer) {
                if (c == v.first) ans += v.second*n;
                else {
                    int anc = almost_anc(v.first, c);
                    int csub = sub[anc];
                    if (anc == par[v.first]) csub = n-sub[v.first];
                    //cerr << v.first << ' ' << c << ' ' << almost_anc(v.first, c) << ' ' << csub << '\n';
                    ans += v.second*num(n-csub);
                }
            }
            cout << (ans*IN) << '\n';
        }

        if (sz(buffer) >= B) {
            bld();
            buffer.clear();
        }
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}