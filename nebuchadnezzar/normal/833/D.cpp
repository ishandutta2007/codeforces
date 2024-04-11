#include "bits/stdc++.h"
#define puba push_back
#define ff first
#define ss second
#define bend(_x) begin(_x), end(_x)
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9 + 7;
const ll INFL = 1e18 + 123;
const double PI = atan2(0, -1);
const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;

bool used[MAXN];
int n;
vector<pair<int, pair<int, int>>> graph[MAXN];
int sz[MAXN];
int largest[MAXN];

vector<int> cur_list;
void calc_sz(int v, int p) {
    cur_list.puba(v);
    //cerr << v << endl;
    sz[v] = 1;
    largest[v] = 0;
    for (auto to : graph[v]) {
        if (!used[to.ff] && p != to.ff) {
            calc_sz(to.ff, v);
            sz[v] +=  sz[to.ff];
            largest[v] = max(largest[v], sz[to.ff]);
        }
    }
}

ll ans = 1;
vector<pair<pii, ll>> points, cur_points;

void dfs(int v, int p, int n0, int n1, ll prod) {
    cur_points.puba({{n0, n1}, prod});
    for (auto to : graph[v]) {
        if (!used[to.ff] && p != to.ff) {
            dfs(to.ff, v, n0 + (to.ss.ss == 0), n1 + (to.ss.ss == 1), (prod * to.ss.ff) % MOD);
        }
    }
}

ll mpow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) {
            ret = (ret * a) % MOD;
        }
        a = a * a % MOD;
        b >>= 1; 
    }
    return ret;
}

ll inv(ll num) {
    return mpow(num, MOD - 2);
}

struct node {
    int l, r;
    ll num;
    int amount;
    node() {
        l = r = -1;
        num = 1;
        amount = 0;
    }
    node(int _l, int _r, ll _num) {
        l = _l;
        r = _r;
        num = _num;
        amount = 0;
    }
    node(int _l, int _r, ll _num, int _amount) {
        l = _l;
        r = _r;
        num = _num;
        amount = _amount;
    }
};

vector<node> segtree;
int bpv;

int segtree_mul(int id, int pos, ll val) {
    int v = id;
    int vl = 0, vr = bpv;
    int ret = szof(segtree);
    while (vr - vl > 1) {
        int vm = (vl + vr) / 2;
        if (vm > pos) {
            segtree.puba(node(szof(segtree) + 1, segtree[v].r, segtree[v].num * val % MOD, segtree[v].amount + 1));
            v = segtree[v].l;
            vr = vm;
        } else {
            segtree.puba(node(segtree[v].l, szof(segtree) + 1, segtree[v].num * val % MOD, segtree[v].amount + 1));
            v = segtree[v].r;
            vl = vm;
        }
    }
    segtree.puba(node(-1, -1, segtree[v].num * val % MOD, segtree[v].amount + 1));
    return ret;
}

pair<ll, int> comb(pair<ll, int> p1, pair<ll, int> p2) {
    return {p1.ff * p2.ff % MOD, p1.ss + p2.ss};
}

pair<ll, int> segtree_get(int v, int vl, int vr, int l, int r) {
    //cerr << v << " " << vl << " " << vr << " " << l << " " << r << endl;
    if (vr <= l || r <= vl) {
        return {1, 0};
    }
    if (l <= vl && vr <= r) {
        //cerr << segtree[v].num << endl;
        return {segtree[v].num, segtree[v].amount};
    }
    int vm = (vl + vr) / 2;
    return comb(segtree_get(segtree[v].l, vl, vm, l, r), segtree_get(segtree[v].r, vm, vr, l, r));
}

ll calc(vector<pair<pii, ll>>& v) {
    //cerr << "start calc" << endl;
    vector<pair<pii, ll>> arr;
    vector<int> arry;
    for (auto p : v) {
        //cerr << p.ff.ff << " " << p.ff.ss << " " << p.ss << endl;
        int x1 = -(p.ff.ff - 2 * p.ff.ss);
        int y1 = -(p.ff.ss - 2 * p.ff.ff);
        //cerr << x1 << " " << y1 << endl;
        arry.puba(y1);

        arr.puba({{x1, y1}, p.ss});
    }


    sort(bend(arry));
    arry.resize(unique(bend(arry)) - arry.begin());
    sort(bend(arr));

    ll ret = 1;
    vector<int> roots(szof(arr) + 1);
    roots[szof(arr)] = 1;

    bpv = 1;
    while (bpv < szof(arry)) {
        bpv *= 2;
    }

    segtree.clear();
    segtree.puba(node());
    for (int i = 1; i < bpv; ++i) {
        segtree.puba(node(i * 2, i * 2 + 1, 1));
    }
    for (int i = 0; i < bpv; ++i) {
        segtree.puba(node(-1, -1, 1));
    }

    for (int i = szof(arr) - 1; i >= 0; --i) {
        int fromx = -arr[i].ff.ff;
        int l = i, r = szof(arr);
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (arr[mid].ff.ff >= fromx) {
                r = mid;
            } else {
                l = mid;
            }
        }
        //cerr << i << " " << r << endl;
        //cerr << roots[r] << endl;

        auto tmp = segtree_get(roots[r], 0, bpv, lower_bound(bend(arry), -arr[i].ff.ss) - arry.begin(), bpv);
        ret = ret * tmp.ff % MOD * mpow(arr[i].ss, tmp.ss) % MOD;
        //cerr << ret << endl;

        roots[i] = segtree_mul(roots[i + 1], lower_bound(bend(arry), arr[i].ff.ss) - arry.begin(), arr[i].ss);
    }
    return ret;
}

void rec(int v) {
    cur_list.clear();
    calc_sz(v, v);

    int best = INF;
    for (int u : cur_list) {
        largest[u] = max(largest[u], szof(cur_list) - sz[u]);
        if (best > largest[u]) {
            best = largest[u];
            v = u;
        }
    }

    //cerr << best << " " << v << endl;

    used[v] = true;
    points.clear();
    points.puba({{0, 0}, 1});
    for (auto to : graph[v]) {
        if (!used[to.ff]) {
            cur_points.clear();
            dfs(to.ff, to.ff, to.ss.ss == 0, to.ss.ss == 1, to.ss.ff);
            ans = ans * inv(calc(cur_points)) % MOD;
            for (auto p : cur_points) {
                points.puba(p);
            }
        }
    }
    ans = ans * calc(points) % MOD;
    for (auto to : graph[v]) {
        if (!used[to.ff]) {
            rec(to.ff);
        }
    }
}

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);
    cerr << fixed << setprecision(15);
    cout << fixed << setprecision(15);
    
    assert(123 * inv(123) % MOD == 1);

    /*
    vector<pair<pii, ll>> arr = {{{1, 2}, 123}, {{0, 0}, 321}};
    cerr << calc(arr) << endl;
    return 0;
    */
    scanf("%d", &n);
    
    for (int i = 0; i < n - 1; ++i) {
        int u, v, x, c;
        scanf("%d%d%d%d", &u, &v, &x, &c);
        --u; --v;
        graph[u].puba({v, {x, c}});
        graph[v].puba({u, {x, c}});
    }

    rec(0);
    
    cout << ans << "\n";
    
    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}