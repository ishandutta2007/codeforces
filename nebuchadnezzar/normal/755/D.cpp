#include "bits/stdc++.h"
#define puba push_back
#define ff first
#define ss second
#define bend(_x) begin(_x), end(_x)
#define szof(_x) ((int) (_x).size())
#define cmpby(_x) [](const auto& a, const auto& b) {return (a _x) < (b _x);}
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9 + 7;
const double PI = atan2(0, -1);

int bdv;
vector<ll> rsq;

int segtree_plus(int pos, int val) {
    pos += bdv;
    rsq[pos] += val;
    pos /= 2;
    while (pos) {
        rsq[pos] = rsq[pos * 2] + rsq[pos * 2 + 1];
        pos /= 2;
    }
    return 0;
}

ll segtree_get(int v, int vl, int vr, int l, int r) {
    if (vr <= l || r <= vl) {
        return 0;
    }
    if (l <= vl && vr <= r) {
        return rsq[v];
    }
    int vm = (vl + vr) / 2;
    return segtree_get(v * 2, vl, vm, l, r) + segtree_get(v * 2 + 1, vm, vr, l, r);
}

int n, k;

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    scanf("%d%d", &n, &k);

    if (k * 2 > n) {
        k = n - k;
    }

    int c = 0;

    bdv = 1;
    while (bdv < n) {
        bdv *= 2;
    }

    rsq.resize(bdv * 2);

    ll cur = 1;

    for (int i = 0; i < n; ++i) {
        int next = (c + k) % n;
        //cerr << c << " " << next << endl;
        if (next > c) {
            cur += segtree_get(1, 0, bdv, c + 1, next);
        } else {
            cur += segtree_get(1, 0, bdv, c + 1, n) + segtree_get(1, 0, bdv, 0, next);
        }
        ++cur;
        segtree_plus(c, 1);
        segtree_plus(next, 1);
        c = next;
        cout << cur << " ";
    }
    cout << "\n";



    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}