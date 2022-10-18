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

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define all(c) (c).begin(), (c).end()
#define sz(c) int((c).size())
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define fst first
#define snd second

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int, int>;

#define FNAME "a"

#ifdef LOCAL
#define eprintf(args...) fprintf(stderr, args), fflush(stderr);
#else
#define eprintf(args...) ;
#endif

const int MAXN = 1e5 + 10;

struct edge {
    int a, b, w;
    int id;

    void read(int i) {
        id = i;
        cin >> a >> b >> w;
        --a;
        --b;
    }
    
    int to(int x) const {
        return a ^ b ^ x;
    }

    bool operator < (const edge& e) const {
        if  (w != e.w) {
            return w < e.w;
        }
        return id < e.id;
    }
};

int n, m;
vector<edge> g[MAXN];
vector<edge> gt[MAXN];
vector<edge> es;

bool read() {
    if  (!(cin >> n)) {
        return 0;
    }
    cin >> m;
    forn(i, n) {
        g[i].clear();
        gt[i].clear();
    }
    es.clear();
    forn(i, m) {
        edge e;
        e.read(i);
        g[e.a].pb(e);
        gt[e.b].pb(e);
        es.pb(e);
    }
    return 1;
}

struct segm_tree {
    vi t;
    int sz;

    segm_tree(int s = 0) {
        sz = 1;
        while (sz < s) {
            sz *= 2;
        }
        t.assign(sz * 2, 0);
    }

    int get_max(int l, int r) {
        l += sz;
        r += sz;
        int res = 0;
        while (l <= r) {
            res = max(res, t[l]);
            res = max(res, t[r]);
            l = (l + 1) >> 1;
            r = (r - 1) >> 1;
        }
        return res;
    }

    void upd(int pos, int val) {
        int v = sz + pos;
        while (v > 0) {
            t[v] = max(t[v], val);
            v >>= 1;
        }
    }
};

segm_tree T[MAXN];

void solve() {
    forn(v, n) {
        sort(all(gt[v]));
        T[v] = segm_tree(sz(gt[v]));
    }

    int ans = 0;
    for (auto e : es) {
        int old_id = e.id;
        e.id = -1;
        int pos = lower_bound(all(gt[e.a]), e) - gt[e.a].begin();
        e.id = old_id;

        int val = T[e.a].get_max(0, pos - 1);
        pos = lower_bound(all(gt[e.b]), e) - gt[e.b].begin();
        T[e.b].upd(pos, val + 1);

        ans = max(ans, val + 1); 
    }    

    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

#ifdef LOCAL
    freopen(FNAME ".in", "r", stdin);
    freopen(FNAME ".out", "w", stdout);
#endif

    while (read()) {
        solve();
    }

    return 0;
}