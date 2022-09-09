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
const int MAXN = 35005, MAXK = 55;

int n, k;
vector<int> rmq[MAXK];
vector<int> addit[MAXN];
int bpv;

int segtree_segplus(int pos, int v, int vl, int vr, int l, int r, int num) {
    if (vr <= l || r <= vl) {
        return 0;
    }
    if (l <= vl && vr <= r) {
        rmq[pos][v] += num;
        addit[pos][v] += num;
        return 0;
    }

    rmq[pos][v * 2] += addit[pos][v];
    rmq[pos][v * 2 + 1] += addit[pos][v];
    addit[pos][v * 2] += addit[pos][v];
    addit[pos][v * 2 + 1] += addit[pos][v];
    addit[pos][v] = 0;

    int vm = (vl + vr) / 2;
    segtree_segplus(pos, v * 2, vl, vm, l, r, num);
    segtree_segplus(pos, v * 2 + 1, vm, vr, l, r, num);

    rmq[pos][v] = max(rmq[pos][v * 2], rmq[pos][v * 2 + 1]);
    return 0;
}

int segtree_max(int pos, int v, int vl, int vr, int l, int r) {
    if (vr <= l || r <= vl) {
        return -1;
    }
    if (l <= vl && vr <= r) {
        return rmq[pos][v];
    }

    rmq[pos][v * 2] += addit[pos][v];
    rmq[pos][v * 2 + 1] += addit[pos][v];
    addit[pos][v * 2] += addit[pos][v];
    addit[pos][v * 2 + 1] += addit[pos][v];
    addit[pos][v] = 0;

    int vm = (vl + vr) / 2;
    return max(segtree_max(pos, v * 2, vl, vm, l, r), segtree_max(pos, v * 2 + 1, vm, vr, l, r));
}

int segtree_set(int id, int pos, int val) {
    int v = 1, vl = 0, vr = bpv;
    while (vl + 1 < vr) {
        rmq[id][v * 2] += addit[id][v];
        rmq[id][v * 2 + 1] += addit[id][v];
        addit[id][v * 2] += addit[id][v];
        addit[id][v * 2 + 1] += addit[id][v];
        addit[id][v] = 0;

        int vm = (vl + vr) / 2;
        if (vm > pos) {
            vr = vm;
            v = v * 2;
        } else {
            vl = vm;
            v = v * 2 + 1;
        }
    }
    if (rmq[id][v] < val) {
        rmq[id][v] = val;
        v /= 2;
        while (v) {
            rmq[id][v] = max(rmq[id][v * 2], rmq[id][v * 2 + 1]);
            v /= 2;
        }
    }
    return 0;
}

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);
    cerr << fixed << setprecision(15);
    cout << fixed << setprecision(15);
    
    scanf("%d%d", &n, &k);

    vector<int> arr;
    for (int i = 0; i < n; ++i) {
        int num;
        scanf("%d", &num);
        --num;
        arr.puba(num);
    }

    bpv = 1;
    while (bpv < n) {
        bpv *= 2;
    }

    for (int i = 0; i < k; ++i) {
        rmq[i].resize(bpv * 2, -INF);
        addit[i].resize(bpv * 2);
    }

    segtree_set(0, 0, 1);

    vector<int> last(n, -1);

    last[arr[0]] = 0;
    for (int i = 1; i < n; ++i) {
        //cerr << last[arr[i]] << endl;
        for (int j = 0; j < k; ++j) {
            if (j < k - 1) {
                segtree_set(j + 1, i, segtree_max(j, 1, 0, bpv, 0, i) + 1);
            }
            segtree_segplus(j, 1, 0, bpv, last[arr[i]] + 1, i, 1);
        }
        last[arr[i]] = i;
        /*
        for (int j = 0; j <= i; ++j) {
            cerr << segtree_max(0, 1, 0, bpv, j, j + 1) << " ";
        }
        cerr << endl;*/
    }
    
    cout << segtree_max(k - 1, 1, 0, bpv, 0, n) << "\n";
    
    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}