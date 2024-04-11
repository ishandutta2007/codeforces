#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <memory.h>
#include <algorithm>
#include <cassert>
#include <numeric>
#include <functional>
#include <queue>

using namespace std;

#define prev prev_______________________
#define next next_______________________
#define hash hash_______________________
#define y1 y1___________________________

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define all(c) (c).begin(), (c).end()
#define sz(c) int((c).size())
#define mp(x, y) make_pair(x, y)
#define pb push_back
#define fst first
#define snd second
#define image(c) sort(all(c)), c.resize(unique(all(c)) - c.begin())

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

#ifdef LOCAL
#define eprintf(args...) fprintf(stderr, args), fflush(stderr);
#else
#define eprintf(args...) ;
#define cerr if (0) cerr
#endif

int n;
vvi g;

vector<pii> ps;
vector<pii> qs;

bool read() {
    if  (!(cin >> n)) {
        return 0;
    }
    g.clear();
    g.resize(n);
    for (int i = 1; i < n; ++i) {
        int p;
        cin >> p;
        --p;
        g[p].pb(i);
    }

    int m;
    cin >> m;
    ps.resize(m);
    forn(i, m) {
        cin >> ps[i].fst >> ps[i].snd;
        --ps[i].fst;
        --ps[i].snd;
    }

    int q;
    cin >> q;
    qs.resize(q);
    forn(i, q) {
        cin >> qs[i].fst >> qs[i].snd;
        --qs[i].fst;
        --qs[i].snd;
    }
    return 1;
}

const int MAXN = 2e5 + 10;
const int MAXL = 19;

int par[MAXL][MAXN];
int tin[MAXN];
int tout[MAXN];
int timer;
int depth[MAXN];

void dfs0(int v, int p) {
    par[0][v] = p;
    for (int i = 1; i < MAXL; ++i) {
        par[i][v] = par[i - 1][par[i - 1][v]];
    }
    tin[v] = timer++;
    for (int to : g[v]) {
        depth[to] = depth[v] + 1;
        dfs0(to, v);
    }
    tout[v] = timer;
}

bool upper(int a, int b) {
    return tin[a] <= tin[b] && tout[b] <= tout[a];
}

int lca(int a, int b) {
    if  (upper(a, b)) {
        return a;
    }
    if  (upper(b, a)) {
        return b;
    }
    ford(l, MAXL) {
        if  (!upper(par[l][b], a)) {
            b = par[l][b];
        }
    }
    return par[0][b];
}

vi who_ps[MAXN];
int node_up[MAXN];

void dfs1(int v) {
    node_up[v] = -1;

    auto upd = [&](int u) {
        int& ans = node_up[v];
        if  (ans == -1 || depth[u] < depth[ans]) {
            ans = u;
        }
    };

    upd(v);

    for (int to : g[v]) {
        dfs1(to);
        upd(node_up[to]);
    }

    for (int id : who_ps[v]) {
        int c = lca(ps[id].fst, ps[id].snd);
        upd(c);
    }
}

int par_up[MAXL][MAXN];

void dfs2(int v) {
    par_up[0][v] = node_up[v];
    for (int i = 1; i < MAXL; ++i) {
        par_up[i][v] = par_up[i - 1][par_up[i - 1][v]];
    }
    
    for (int to : g[v]) {
        dfs2(to);
    }
}

pii up_until(int a, int c) {
    int cnt = 0;
    ford(l, MAXL) {
        if  (!upper(par_up[l][a], c)) {
            a = par_up[l][a];
            cnt += 1 << l;
        }
    }
    if  (!upper(node_up[a], c)) {
        return mp(-1, -1);
    }
    return mp(a, cnt);
}

vi who_ps_c[MAXN];
vi who_qs_c[MAXN];

template<class T>
int lb(const vector<T>& v, const T& x) {
    return lower_bound(all(v), x) - v.begin();
}

template<class T>
int ub(const vector<T>& v, const T& x) {
    return upper_bound(all(v), x) - v.begin();
}

namespace Solver2d {

struct fenw {
    vi t;

    fenw(int s = 0) {
        t.assign(s, 0);
    }

    int get(int l, int r) {
        if  (l > r) {
            return 0;
        }
        return get(r) - get(l - 1);
    }

    int get(int r) {
        int ans = 0;
        for (int i = r; i >= 0; i &= i + 1, --i) {
            ans += t[i];
        }
        return ans;
    }

    void upd(int pos, int inc) {
        for (int i = pos; i < sz(t); i |= i + 1) {
            t[i] += inc;
        }
    }
};

struct rect {
    int x1, x2;
    int y1, y2;
    int id;
};

struct pnt {
    int x, y;
};

map<int, bool> solve(vector<rect> rs, vector<pnt> ps) {
    eprintf("rs:\n");
    for (auto r : rs) {
        eprintf("x[%d, %d] y[%d, %d] id=%d\n", r.x1, r.x2, r.y1, r.y2, r.id + 1);
    }
    eprintf("ps:\n");
    for (auto p : ps) {
        eprintf("x=%d, y=%d\n", p.x, p.y);
    }
    eprintf("\n");

    vi ys;
    vi xs;
    for (auto p : ps) {
        xs.pb(p.x);
        ys.pb(p.y);
    }
    for (auto r : rs) {
        xs.pb(r.x1 - 1);
        xs.pb(r.x2);
    }
    image(xs);
    image(ys);

    vvi who_start(sz(xs));
    vvi who_end(sz(xs));
    vvi who_p(sz(xs));

    forn(i, sz(rs)) {
        int x = lb(xs, rs[i].x1 - 1);
        who_start[x].pb(i);

        x = lb(xs, rs[i].x2);
        who_end[x].pb(i);
    } 
    forn(i, sz(ps)) {
        int x = lb(xs, ps[i].x);
        who_p[x].pb(i);
    }

    map<int, int> sum;
    fenw T(sz(ys));
    forn(x, sz(xs)) {
        for (int i : who_p[x]) {
            int y = lb(ys, ps[i].y);
            T.upd(y, +1);
        }
        for (int i : who_start[x]) {
            int y1 = lb(ys, rs[i].y1);
            int y2 = ub(ys, rs[i].y2);
            int pref = T.get(y1, y2 - 1);
            sum[rs[i].id] -= pref;
        }
        for (int i : who_end[x]) {
            int y1 = lb(ys, rs[i].y1);
            int y2 = ub(ys, rs[i].y2);
            int pref = T.get(y1, y2 - 1);
            sum[rs[i].id] += pref;
        }
    }

    map<int, bool> res;
    for (const auto& r : rs) {
        res[r.id] = sum[r.id] > 0;
    }
    return res;
}

};

void solve() {
    timer = 0;
    depth[0] = 0;
    dfs0(0, 0);

    forn(i, n) {
        who_ps[i].clear();
    }
    forn(i, sz(ps)) {
        who_ps[ps[i].fst].pb(i);
        who_ps[ps[i].snd].pb(i);
    }

    dfs1(0);

    dfs2(0);

    forn(i, n) {
        who_qs_c[i].clear();
        who_ps_c[i].clear();
    }
    forn(i, sz(qs)) {
        int c = lca(qs[i].fst, qs[i].snd);
        who_qs_c[c].pb(i);
    }
    forn(i, sz(ps)) {
        int c = lca(ps[i].fst, ps[i].snd);
        who_ps_c[c].pb(i);
    }

    vi ans(sz(qs));
    vii nq(sz(qs), mp(-1, -1));
    forn(v, n) {
        auto qs_v = who_qs_c[v];
        auto ps_v = who_ps_c[v];

        eprintf("IN v=%d\n", v + 1);

        for (int i : qs_v) {
            pii f = up_until(qs[i].fst, v);
            pii s = up_until(qs[i].snd, v);
            if  (f.fst == -1 || s.fst == -1) {
                nq[i] = mp(-1, -1);
                ans[i] = -1;
                continue;
            }

            eprintf("i=%d, nq=(%d, %d)\n", i + 1, f.fst + 1, s.fst + 1);
            nq[i] = mp(f.fst, s.fst);
            ans[i] = f.snd + s.snd;
        }   

        using namespace Solver2d;
        vector<rect> rs;
        vector<pnt> pnts;
        for (int i : qs_v) {
            if  (ans[i] == -1) {
                continue;
            }
            int a = nq[i].fst;
            int b = nq[i].snd;
            rs.pb(rect{tin[a], tout[a] - 1, tin[b], tout[b] - 1, i});
        } 

        for (int i : ps_v) {
            int a = ps[i].fst;
            int b = ps[i].snd;
            pnts.pb(pnt{tin[a], tin[b]});
            pnts.pb(pnt{tin[b], tin[a]});
        }

        auto have_one = solve(rs, pnts);
        for (int i : qs_v) {
            if  (ans[i] == -1) {
                continue;
            }
            assert(have_one.count(i));
            if  (qs[i].fst == v || qs[i].snd == v || have_one[i]) {
                ++ans[i];
            } else {
                ans[i] += 2;
            }
        }
    }

    forn(i, sz(qs)) {
        cout << ans[i] << "\n";
    }
    cout << "\n";
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout.tie(0);

#ifdef LOCAL
    #define FNAME "a"
    freopen(FNAME ".in", "r", stdin);
    freopen(FNAME ".out", "w", stdout);
#endif

    while (read()) {
        solve();

        break;
    }

    return 0;
}