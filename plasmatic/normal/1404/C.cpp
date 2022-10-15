// ./c-fixed-point-removal.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

// Thanks wesley thanks wesley thanks wesley
// RMQ + Increment query
struct Comp {
    using Data = pair<int, int>; // val, idx
    using Lazy = int;
    const Data vdef = {-INF, -1};
    const Lazy ldef = 0;
    Data merge(Data l, Data r) const { return max(l, r); }
    Lazy mergeLazy(Lazy l, Lazy r) const { return l + r; }
    void applyLazy(Data &to, Lazy &v, int l, int r) { to.first += v; }
};
#define MID int mid = (l + r) / 2, lhs = i + 1, rhs = i + (mid - l + 1) * 2;
template <class Comp> struct LazySegmentTree {
    using Data = typename Comp::Data; using Lazy = typename Comp::Lazy; Comp C;
    int N;
    vector<Data> seg; vector<Lazy> lazy;
    Data _build(int i, int l, int r) {
        if (l == r) return seg[i] = {C.vdef.first, l};
        MID;
        return seg[i] = C.merge(_build(lhs, l, mid), _build(rhs, mid+1, r));
    }
    void init(int n0) {
        N = n0;
        seg.assign(2 * N + 2, C.vdef);
        lazy.assign(2 * N + 2, C.ldef);
        _build(1, 1, N);
    }
    void push(int i, int l, int r) {
        if (lazy[i] != C.ldef) {
            MID;
            C.applyLazy(seg[i], lazy[i], l, r);
            if (l != r) {
                lazy[lhs] = C.mergeLazy(lazy[lhs], lazy[i]);
                lazy[rhs] = C.mergeLazy(lazy[rhs], lazy[i]);
            }
            lazy[i] = C.ldef;
        }
    }
    Data _query(int ql, int qr, int i, int l, int r) {
        if (ql > r || qr < l) return C.vdef;
        push(i, l, r);
        if (l >= ql && r <= qr) return seg[i];
        MID;
        return C.merge(_query(ql, qr, lhs, l, mid), _query(ql, qr, rhs, mid + 1, r));
    }
    Data _update(int ql, int qr, Lazy v, int i, int l, int r) {
        push(i, l, r);
        if (ql > r || qr < l) return seg[i];
        if (l >= ql && r <= qr) {
            lazy[i] = v;
            push(i, l, r);
            return seg[i];
        }
        MID;
        return seg[i] = C.merge(_update(ql, qr, v, lhs, l, mid), _update(ql, qr, v, rhs, mid + 1, r));
    }
    Data query(int ql, int qr) { return _query(ql, qr, 1, 1, N); }
    void update(int ql, int qr, Lazy v) { _update(ql, qr, v, 1, 1, N); }
};
// Template is 1-indexed (by default).  Can be made 0-indexed by modifying Comp
// Default: Point increment and prefix sum query
struct BitComp {
    using Data = int;
    const Data vdef = 0;
    void applyUpdate(Data &to, Data &v) { to += v; }
    int transformInd(int idx, int N) { return idx; }
};
template <typename Comp> struct BIT {
    using Data = typename Comp::Data; Comp C;
    int N; vector<Data> bit;
    void init(int n0) {
        N = n0;
        bit.assign(N + 1, C.vdef);
    }
    void update(int x, Data v) {
        x = C.transformInd(x, N);
        for (; x <= N; x += x & -x)
            C.applyUpdate(bit[x], v);
    }
    Data query(int x) {
        x = C.transformInd(x, N);
        Data res = C.vdef;
        for (; x; x -= x & -x)
            C.applyUpdate(res, bit[x]);
        return res;
    }
};

const int MN = 3e5 + 1;
int N, Q,
    A[MN], ans[MN];
vector<pair<int, int>> qs[MN];
LazySegmentTree<Comp> seg;
BIT<BitComp> bit;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> Q;
    for (auto i = 1; i <= N; i++) {
        cin >> A[i];
        A[i] -= i;
    }

    for (auto i = 0; i < Q; i++) {
        int x, y; cin >> x >> y;
        int l = x+1, r = N-y;
        qs[l].emplace_back(r, i);
    }

    seg.init(N);
    bit.init(N);
    for (auto l = N; l >= 1; l--) {
        if (A[l] <= 0) {
            seg.update(l, l, A[l] + INF);
        }

        while (seg.query(1, N).first >= 0) {
            auto [_, idx] = seg.query(1, N);
            bit.update(idx, 1);
            seg.update(idx, idx, -INF);
            seg.update(idx+1, N, 1);
        }

        for (auto [r, i] : qs[l])
            ans[i] = bit.query(r);
    }

    for (auto i = 0; i < Q; i++) cout << ans[i] << '\n';

    return 0;
}