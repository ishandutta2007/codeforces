// ./d-flip-the-cards.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;
using pii = pair<int, int>;
#define fs first
#define sn second

// Lazy(a, b) => if a!=-1: set to a, +=b

// Example comparator: Range min + Range increment
// In the functions mergeLazy and applyLazy, objects are merged from `v` to `to`.  In the function merge, data is merged from left to right
struct Comp {
    using Data = int;
    using Lazy = pii;
    const Data vdef = INF;
    const Lazy ldef = {-1, 0};
    Data merge(Data l, Data r) const { return min(l, r); }
    Lazy mergeLazy(Lazy to, Lazy v) const { return v.fs == -1 ? pii{to.fs, to.sn+v.sn} : v; }
    void applyLazy(Data &to, Lazy &v, int l, int r) { if (v.fs != -1) to = v.fs; to += v.sn; }
};
#define MID int mid = (l + r) / 2, lhs = i + 1, rhs = i + (mid - l + 1) * 2;
template <class Comp> struct LazySegmentTree {
    using Data = typename Comp::Data; using Lazy = typename Comp::Lazy; Comp C;
    int N;
    vector<Data> seg; vector<Lazy> lazy;
    void init(int n0) {
        N = n0;
        seg.assign(2 * N + 4, C.vdef);
        lazy.assign(2 * N + 4, C.ldef);
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
    Data _setPoint(int q, Data v, int i, int l, int r) {
        push(i, l, r);
        if (q > r || q < l) return seg[i];
        if (l >= q && r <= q) return seg[i] = v;
        MID;
        return seg[i] = C.merge(_setPoint(q, v, lhs, l, mid), _setPoint(q, v, rhs, mid + 1, r));
    }
    Data query(int ql, int qr) { return _query(ql, qr, 1, 1, N); }
    void update(int ql, int qr, Lazy v) { _update(ql, qr, v, 1, 1, N); }
    void setPoint(int q, Data v) { _setPoint(q, v, 1, 1, N); }
};

const int MN = 2e5 + 1;
int N,
    A[MN], flip[MN];

LazySegmentTree<Comp> seg0, seg1;

void lower(LazySegmentTree<Comp> &seg, int idx, int newv) {
    if (newv < seg.query(idx, idx))
        seg.setPoint(idx, newv);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (auto i = 1; i <= N; i++) {
        int a, b; cin >> a >> b;
        if ((a <= N) == (b <= N)) {
            cout << (-1) << '\n';
            return 0;
        }

        if (b <= N) {
            swap(a, b); // swap
            flip[a] = 1;
        }
        // assert(a <= N && b > N);
        A[a] = b-N;
    }

    // cout<<"A=["; for(int __i=0; __i<((N+1)); __i++)cout<<(A)[__i]<<", "; cout<<"], ";cout << endl; // db A:(N+1):A
    // cout<<"flip=["; for(int __i=0; __i<(N+1); __i++)cout<<(flip)[__i]<<", "; cout<<"], ";cout << endl; // db A:N+1:flip

    seg0.init(N+1);
    seg1.init(N+1);

    seg0.setPoint(N+1, 0);
    seg1.setPoint(N+1, 1);

    A[0] = N+1;

    for (auto i = 1; i <= N; i++) {
        // switch 0->1
        int dpv1 = seg0.query(A[i]+1, N+1) + !flip[i];
        // switch 1->0
        int dpv0 = seg1.query(A[i]+1, N+1) + flip[i];

        // range update non-switching
        if (A[i] < A[i-1]) {
            if (!flip[i])
                seg1.update(1, N+1, {-1, 1});
            else
                seg0.update(1, N+1, {-1, 1});
        }
        else {
            seg0.update(1, N+1, {INF, 0});
            seg1.update(1, N+1, {INF, 0});
        }

        lower(seg0, A[i-1], dpv0);
        lower(seg1, A[i-1], dpv1);
    }

    int ans = min({seg0.query(1, N+1), seg1.query(1, N+1), (int)INF});
    cout << (ans == INF ? -1 : ans) << '\n';

    return 0;
}