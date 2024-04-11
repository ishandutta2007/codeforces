#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())

using namespace std;
typedef long long LL;
typedef pair <int, int> pii;
const int MAXN = 2e5 + 5, bd = 18, bdv = 1 << bd;
const int INF = 1e9 + 9;

int n;
pii rmq[bdv * 2];
int plus_there[bdv * 2];
vector <int> inp;

int segtree_segplus(int v, int vl, int vr, int l, int r, int val);

int segtree_pushdown(int v, int vl, int vr) {
    if (plus_there[v] == 0) {
        return 0;
    }
    int vm = (vl + vr) / 2;
    segtree_segplus(v * 2, vl, vm, vl, vm, plus_there[v]);
    segtree_segplus(v * 2 + 1, vm + 1, vr, vm + 1, vr, plus_there[v]);
    plus_there[v] = 0;
    return 0;
}

int segtree_segplus(int v, int vl, int vr, int l, int r, int val) {
    if (vr < l || r < vl) {
        return 0;
    }
    if (l <= vl && vr <= r) {
        plus_there[v] += val;
        rmq[v].ff += val;
        return 0;
    }
    int vm = (vl + vr) / 2;
    segtree_pushdown(v, vl, vr);
    segtree_segplus(v * 2, vl, vm, l, r, val);
    segtree_segplus(v * 2 + 1, vm + 1, vr, l, r, val);
    rmq[v] = max(rmq[v * 2], rmq[v * 2 + 1]);
    return 0;
}

int segtree_set(int v, int vl, int vr, int pos, int num) {
    if (vr < pos || pos < vl) {
        return 0;
    }
    if (vl == pos && pos == vr) {
        rmq[v] = mapa(num, -pos);
        return 0;
    }
    int vm = (vl + vr) / 2;
    segtree_pushdown(v, vl, vr);

    segtree_set(v * 2, vl, vm, pos, num);
    segtree_set(v * 2 + 1, vm + 1, vr, pos, num);
    rmq[v] = max(rmq[v * 2], rmq[v * 2 + 1]);
    return 0;
}

int ans[MAXN];

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n;

    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        inp.puba(num);
    }

    for (int i = 0; i < n; ++i) {
        rmq[i + bdv] = mapa(inp[i] - (n - 1 - i), -i);
    }
    for (int i = n; i < bdv; ++i) {
        rmq[i + bdv] = mapa(-INF, -1);
    }

    for (int i = bdv - 1; i > 0; --i) {
        rmq[i] = max(rmq[i * 2], rmq[i * 2 + 1]);
    }

    for (int i = n - 1; i >= 0; --i) {
        pii p = rmq[1];
        if (p.ff < 0) {
            cout << ":(" << endl;
            return 0;
        }
        p.ss *= -1;
        ans[i] = p.ff;
        segtree_set(1, 0, bdv - 1, p.ss, -INF);
        segtree_segplus(1, 0, bdv - 1, 0, n - 1, 1);
        //segtree_segplus(1, 0, bdv - 1, i - 1, n - 1, -1);
    }

    for (int i = 0; i < n - 1; ++i) {
        if (ans[i] > ans[i + 1]) {
            cout << ":(" << endl;
            return 0;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}