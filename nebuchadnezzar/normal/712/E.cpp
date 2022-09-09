#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) begin(_x), end(_x)
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
const int INF = 1e9 + 7;
const double PI = atan2(0, -1);

int n, q;
int bdv;

vector<pdd> segtree;

pdd myunion(pdd p1, pdd p2) {
    if (p1.ff < 0) {
        return p2;
    }
    if (p2.ff < 0) {
        return p1;
    }
    return {1 - ((1 - p1.ff) * (1 - p2.ff) / (1 - p1.ss * p2.ff)), p2.ss + (1 - p2.ss) * p1.ss * (1 - p2.ff) / (1 - p1.ss * p2.ff)};
}

int segtree_set(int pos, double val) {
    pos += bdv;
    segtree[pos] = {1 - val, val};
    pos /= 2;
    while (pos) {
        segtree[pos] = myunion(segtree[pos * 2], segtree[pos * 2 + 1]);
        pos /= 2;
    }
    return 0;
}

pdd segtree_get(int v, int vl, int vr, int l, int r) {
    if (vr <= l || r <= vl) {
        return {-1, -1};
    }
    if (l <= vl && vr <= r) {
        return segtree[v];
    }
    int vm = (vl + vr) / 2;
    return myunion(segtree_get(v * 2, vl, vm, l, r), segtree_get(v * 2 + 1, vm, vr, l, r));
}   

int main() {
    //freopen("inp", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    //pdd tmp1 = {1 - 1.0 / 3, 1.0 / 3};
    //pdd tmp2 = {1 - 1.0 / 2, 1.0 / 2};

    //auto tmp3 = myunion(tmp1, tmp2);

    //cerr << tmp3.ff << " " << tmp3.ss << endl;

    scanf("%d%d", &n, &q);

    bdv = 1;
    while (bdv < n) {
        bdv *= 2;
    }

    segtree.resize(bdv * 2);

    for (int i = 0; i < n; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        double tmp = a / (double) b;
        segtree[bdv + i] = {1 - tmp, tmp};
    }

    for (int i = bdv - 1; i >= 0; --i) {
        segtree[i] = myunion(segtree[i * 2], segtree[i * 2 + 1]);
    }

    for (int i = 0; i < q; ++i) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            int pos, a, b;
            scanf("%d%d%d", &pos, &a, &b);
            --pos;
            double tmp = a / (double) b;
            segtree_set(pos, tmp);
        } else {
            int l, r;
            scanf("%d%d", &l, &r);
            --l; --r;
            pdd tmp = segtree_get(1, 0, bdv, l, r + 1);
            printf("%.10f\n", 1 - tmp.ff);
        }
    }

    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}