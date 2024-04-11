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
mt19937 tw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(tw) % (y - x + 1) + x; }

struct node {
    int l, r;
    int val;
    node() {
        l = r = 0;
        val = 0;
    }
    node(int _l, int _r) {
        l = _l;
        r = _r;
        val = 0;
    }
    node(int _l, int _r, int _val) {
        l = _l;
        r = _r;
        val = _val;
    }
};  

int bpv;
vector<node> segtree;

int segsum(int v, int vl, int vr, int l, int r) {
    if (vr <= l || r <= vl) {
        return 0;
    }
    if (l <= vl && vr <= r) {
        return segtree[v].val;
    }
    int vm = (vl + vr) / 2;
    return segsum(segtree[v].l, vl, vm, l, r) + segsum(segtree[v].r, vm, vr, l, r);
}

int s_plus(int root, int pos, int val) {
    int ret = szof(segtree);
    int vl = 0, vr = bpv;
    while (vl + 1 < vr) {
        int vm = (vl + vr) / 2;
        if (vm > pos) {
            segtree.puba(segtree[root]);
            segtree.back().l = szof(segtree);
            segtree.back().val += val;
            root = segtree[root].l;
            vr = vm;
        } else {
            segtree.puba(segtree[root]);
            segtree.back().r = szof(segtree);
            segtree.back().val += val;
            root = segtree[root].r;
            vl = vm;
        }
    }
    segtree.puba(node(0, 0, segtree[root].val + val));
    return ret;
}

vector<int> roots = {1};

int get_sum(int x1, int y1, int x2, int y2) {
    return segsum(roots[x2], 0, bpv, y1, y2) - segsum(roots[x1], 0, bpv, y1, y2);
}

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);
    cerr << fixed << setprecision(15);
    cout << fixed << setprecision(15);
    
    int n, q;
    scanf("%d%d", &n, &q);

    bpv = 1;
    while (bpv < n) {
        bpv *= 2;
    }

    for (int i = 0; i < bpv; ++i) {
        segtree.puba(node(i * 2, i * 2 + 1));
    }
    for (int i = 0; i < bpv; ++i) {
        segtree.puba(node());
    }

    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        --x;
        roots.puba(s_plus(roots.back(), x, 1));
    }
    
    //cerr << get_sum(0, 0, 1, 1) << endl;

    for (int i = 0; i < q; ++i) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        --x1; --y1;
        ll cur = 0;
        vector<ll> am = {get_sum(0, 0, x1, y1),
                                get_sum(0, y1, x1, y2),
                                get_sum(0, y2, x1, n),
                                get_sum(x1, 0, x2, y1),
                                get_sum(x1, y1, x2, y2),
                                get_sum(x1, y2, x2, n),
                                get_sum(x2, 0, n, y1),
                                get_sum(x2, y1, n, y2),
                                get_sum(x2, y2, n, n)};
        /*
        for (int j = 0; j < 9; ++j) {
            cerr << am[j] << " ";
            if (j % 3 == 2) {
                cerr << endl;
            }
        }
        cerr << endl;
        */
        cur = am[4] * (am[4] - 1) + am[4] * (n - am[4]);
        cur += am[0] * (am[4] + am[5] + am[7] + am[8]);
        cur += am[1] * (am[3] + am[4] + am[5] + am[6] + am[7] + am[8]);
        cur += am[2] * (am[3] + am[4] + am[6] + am[7]);
        cur += am[5] * (am[0] + am[3] + am[6] + am[1] + am[4] + am[7]);
        cur += am[8] * (am[0] + am[1] + am[3] + am[4]);
        cur += am[7] * (am[0] + am[1] + am[2] + am[3] + am[4] + am[5]);
        cur += am[6] * (am[1] + am[2] + am[4] + am[5]);
        cur += am[3] * (am[1] + am[4] + am[7] + am[2] + am[5] + am[8]);
        assert(cur % 2 == 0);
        cur /= 2;
        cout << cur << "\n";
    }
    
    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}