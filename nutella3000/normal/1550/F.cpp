#include <bits/stdc++.h>
using namespace std;
     
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define size(a) (int) a.size()
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
#define all(a) begin(a), end(a)
#define mp make_pair
#define pb emplace_back
#define ld long double
mt19937 rnd;

const int inf = 2e9 + 3, mod = 1e9 + 7;
const int max_n = 1 << 21;

struct node {
    int mn, id, l, r, lazy1, lazy2;
    node() : mn(inf), l(inf), r(-inf), lazy1(-inf), lazy2(inf) {}
    node(int mn, int l, int r) : mn(mn), l(l), r(r) {}
} t[2 * max_n];

void upd(int v, pii req, int le) {
    auto& [mn, id, l, r, lazy1, lazy2] = t[v];
    if (req.fi == 1) {
        mn = l = inf;
        r = -inf;
        return;
    }
    if (le) {
        if (mn > l - req.se) {
            mn = l - req.se;
            id = l;
        }
        chkmax(lazy1, req.se);
    }else {
        if (mn > req.se - r) {
            mn = req.se - r;
            id = r;
        }
        chkmin(lazy2, req.se);
    }
}

void push(int v) {
    int &l1 = t[v].lazy1, &l2 = t[v].lazy2;
    upd(v * 2, mp(2, l1), true);
    upd(v * 2 + 1, mp(2, l1)    , true);
    upd(v * 2, mp(2, l2), false);
    upd(v * 2 + 1, mp(2, l2), false);
    l1 = 0, l2 = 0;
}

node unite(node v1, node v2) {
    node v;
    v.mn = min(v1.mn, v2.mn);
    v.id = (v1.mn <= v2.mn ? v1.id : v2.id);
    v.l = min(v1.l, v2.l);
    v.r = max(v1.r, v2.r);
    return v;
}

void segset(pii req, int v = 1, int tl = -max_n / 2, int tr = max_n / 2) {
    if (req.fi == 1 && (tl > req.se || tr <= req.se)) return;
    if ((req.fi == 1 && tr == tl + 1) || (req.fi == 2 && (tl >= req.se || tr <= req.se))) {
        upd(v, req, req.se <= tl);
        return;
    }
    push(v);
    int mid = (tl + tr) / 2;
    segset(req, v * 2, tl, mid);
    segset(req, v * 2 + 1, mid, tr);
    t[v] = unite(t[v * 2], t[v * 2 + 1]);
}

pii segget() {
    return mp(t[1].mn, t[1].id);
}

void build(vector<int> a) {
    for (int i : a) {
        int v = i + max_n * 3 / 2;
        t[v].id = t[v].l = t[v].r = i;
    }
    for (int i = max_n - 1; i >= 1; --i)
        t[i] = unite(t[i * 2], t[i * 2 + 1]);
}

void run() {
    int n, q, s, d;
    cin >> n >> q >> s >> d;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    s = a[s - 1];
    build(a);

    vector<int> cost(max_n);
    int max_cost = 0, lst = s;

    for (int i = 0; i < n - 1; ++i) {
        segset(mp(1, lst));
        segset(mp(2, lst + d));
        segset(mp(2, lst - d));
        pii v = segget();
        //cout << "segget " << v.fi << " " << v.se << endl;
        chkmax(max_cost, v.fi);
        cost[v.se] = max_cost;
        lst = v.se;   
    }

    /*for (int i = 0; i < n; ++i)
        cout << cost[a[i]] << " ";
    cout << endl;*/
    while (q--) {
        int to, k;
        cin >> to >> k;
        cout << (cost[a[to - 1]] <= k ? "Yes" : "No") << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(20);

#ifdef ahahaha
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    //cin >> t;
    while (t--) {
        run();
    }
}