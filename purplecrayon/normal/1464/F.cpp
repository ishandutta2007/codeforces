#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

vector<vector<int>> adj;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
typedef pair<int, int> pii;
typedef vector<int> vi;
template<class T>
struct RMQ {
	vector<vector<T>> jmp;
    RMQ(){}
	RMQ(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
			jmp.emplace_back(sz(V) - pw * 2 + 1);
			rep(j,0,sz(jmp[k]))
				jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(int a, int b) {
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};
struct LCA {
	int T = 0;
	vi time, path, ret, dep;
	RMQ<int> rmq;

    LCA(){}
	LCA(vector<vi>& C) : time(sz(C)), dep(sz(C)), rmq((dfs(C,0,-1, 0), ret)) {}
	void dfs(vector<vi>& C, int v, int par, int d) {
		time[v] = T++; dep[v] = d;
		for (int y : C[v]) if (y != par) {
			path.push_back(v), ret.push_back(time[v]);
			dfs(C, y, v, d+1);
		}
	}
	int lca(int a, int b) {
		if (a == b) return a;
		tie(a, b) = minmax(time[a], time[b]);
		return path[rmq.query(a, b)];
	}
    int dist(int a, int b){ return dep[a]+dep[b]-2*dep[lca(a, b)]; }
} lc;

int dist(int a, int b){ return lc.dist(a, b); }
int lca(int a, int b){ return lc.lca(a, b); }

struct P {
    int a, b;

    bool contains(int x) {
        return ::dist(a, x)+::dist(b, x) == ::dist(a, b);
    }
    bool is_empty() {
        return min(a, b) == -1;
    }
    bool contains(P x) {
        return contains(x.a) && contains(x.b);
    }
    friend bool operator == (const P& u, const P& v) {
        return make_pair(u.a, u.b) == make_pair(v.a, v.b) || make_pair(u.b, u.a) == make_pair(v.a, v.b);
    }
    int dist(){ return is_empty() ? -1 : ::dist(a, b); }
};
P isect(P a, P b) {
    ar<int, 4> nodes{a.a, a.b, b.a, b.b};
    vector<int> cand;
    for (int _a : nodes) for (int _b : nodes) cand.push_back(lca(_a, _b));
    sort(cand.begin(), cand.end());
    cand.erase(unique(cand.begin(), cand.end()), cand.end());


    P ans{-1, -1};
    for (int i = 0; i < sz(cand); i++) {
        for (int j = i; j < sz(cand); j++) {
            P cur{cand[i], cand[j]};
            if (a.contains(cur) && b.contains(cur) && cur.dist() > ans.dist())
                ans = cur;
        }
    }
    return ans;
}

int cand[12], ca[12], cb[12], ptr=0;
int dist(P a, P b) {
    ar<int, 4> nodes{a.a, a.b, b.a, b.b}; ptr=0;
    for (int _a : nodes) for (int _b : nodes) cand[ptr++] = lca(_a, _b);
    sort(cand, cand+ptr);
    ptr = unique(cand, cand+ptr)-cand;

    int ca_len = std::copy_if(cand, cand+ptr, ca, [&](int x){ return a.contains(x); }) - ca;
    int cb_len = std::copy_if(cand, cand+ptr, cb, [&](int x){ return b.contains(x); }) - cb;

    int ans = MOD;
    for (int i = 0; i < ca_len; i++) {
        for (int j = 0; j < cb_len; j++) {
            ans = min(ans, dist(ca[i], cb[j]));
        }
    }
    return ans;
}
struct D {
    P a, b;
    int diam(){ return dist(a, b); }
    bool is_empty(){ return a.is_empty() || b.is_empty(); }
    bool is_path(){ return a==b; }
};
const D EMPTY = {{-1, -1}, {-1, -1}};

D merge(D a, D b) {
    if (a.is_empty()) return b;
    if (b.is_empty()) return a;
    if (a.is_path() && b.is_path()) {
        P both = isect(a.a, b.a);
        if (!both.is_empty()) return {both, both};
    }

    D ans{a.a, a.b}; int ans_diam = ans.diam();
    ar<P, 4> ends{a.a, a.b, b.a, b.b};
    for (int i = 0; i < 4; i++) for (int j = i+1; j < 4; j++) {
        D cur{ends[i], ends[j]}; int cur_diam = cur.diam();
        if (ans_diam < cur_diam) ans = cur, ans_diam = cur_diam;
    }
    return ans;
}

int n, q, cq=0, qs[MAXN];
bool ans[MAXN];
map<ar<int, 2>, vector<ar<int, 2>>> mp;

vector<D> t[4*MAXN];
void ae(int v, int tl, int tr, int l, int r, D x) {
    if (r < tl || l > tr) return;
    if (l <= tl && tr <= r) {
        t[v].push_back(x);
        return;
    }
    int tm=(tl+tr)/2;
    ae(2*v, tl, tm, l, r, x), ae(2*v+1, tm+1, tr, l, r, x);
}
void ae(int l, int r, D x){ 
    ae(1, 0, cq-1, l, r, x);
}
void dc(int v, int tl, int tr, D x) {
    for (auto d : t[v]) {
        x = merge(x, d);
    }
    if (tl == tr) {
        ans[tl] = (x.diam() <= 2*qs[tl]);
    } else {
        int tm=(tl+tr)/2;
        dc(2*v, tl, tm, x), dc(2*v+1, tm+1, tr, x);
    }
}
void solve(){
    cin >> n >> q;
    adj.resize(n);
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b, --a, --b;
        adj[a].push_back(b), adj[b].push_back(a);
    }
    lc = LCA(adj);
    for (int i = 0; i < q; i++) {
        int t; cin >> t;
        if (t == 1) {
            int a, b; cin >> a >> b, --a, --b;
            if (a > b) swap(a, b);
            mp[{a, b}].push_back({cq, -1});
        }
        if (t == 2) {
            int a, b; cin >> a >> b, --a, --b;
            if (a > b) swap(a, b);
            if (mp[{a, b}].back()[0] == cq) mp[{a, b}].pop_back();
            else mp[{a, b}].push_back({cq-1, +1});
        }
        if (t == 3) {
            int d; cin >> d;
            qs[cq++] = d;
        }
    }
    for (auto& c : mp) {
        auto& [p, v] = c;
        sort(v.begin(), v.end());
        D cur{{p[0], p[1]}, {p[0], p[1]}};

        int ps = 0;

        int pos = -1;
        for (auto [t, delta] : v) {
            delta *= -1;

            if (ps == 0 && delta == 1) pos = t;
            if (ps == 1 && delta == -1) {
                ae(pos, t, cur);
            }
            ps += delta;
            assert(ps >= 0);
        }
        if (ps) {
            ae(pos, cq-1, cur);
        }
    }
    dc(1, 0, cq-1, EMPTY);
    for (int i = 0; i < cq; i++) {
        cout << (ans[i]?"Yes\n":"No\n");
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}