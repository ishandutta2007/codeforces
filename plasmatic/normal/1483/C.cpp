// ./c-skyline-photo.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

// Thanks wesley thanks wesley thanks wesley
// RMQ + Increment query
struct Comp {
    using Data = ll;
    using Lazy = ll;
    const Data vdef = -LLINF;
    const Lazy ldef = 0;
    Data merge(Data l, Data r) const { return max(l, r); }
    Lazy mergeLazy(Lazy l, Lazy r) const { return l + r; }
    void applyLazy(Data &to, Lazy &v, int l, int r) { to += v; }
};
#define MID int mid = (l + r) / 2, lhs = i + 1, rhs = i + (mid - l + 1) * 2;
template <class Comp> struct LazySegmentTree {
    using Data = typename Comp::Data; using Lazy = typename Comp::Lazy; Comp C;
    int N;
    vector<Data> seg; vector<Lazy> lazy;
    void init(int n0) {
        N = n0;
        seg.assign(2 * N + 2, C.vdef);
        lazy.assign(2 * N + 2, C.ldef);
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
    Data _updateSingle(int q, Lazy v, int i, int l, int r) {
        push(i, l, r);
        if (q > r || q < l) return seg[i];
        if (l == q && r == q) return seg[i] = v;
        MID;
        return seg[i] = C.merge(_updateSingle(q, v, lhs, l, mid), _updateSingle(q, v, rhs, mid + 1, r));
    }
    Data query(int ql, int qr) { return _query(ql, qr, 1, 1, N); }
    void update(int ql, int qr, Lazy v) { _update(ql, qr, v, 1, 1, N); }
    void updateSingle(int q, Lazy v) { _updateSingle(q, v, 1, 1, N); }
};

const int MN = 3e5 + 1;
int N,
    H[MN];
ll dp[MN], B[MN];
LazySegmentTree<Comp> seg;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (auto i = 1; i <= N; i++) {
        cin >> H[i];
    }
    for (auto i = 1; i <= N; i++) {
        cin >> B[i];
    }

    fill(dp+1, dp+N+1, -LLINF);
    seg.init(N+1);

    H[0] = -INF;
    seg.updateSingle(1, 0);
    deque<int> q{0};
    for (auto i = 1; i <= N; i++) {
        // printf("i=%d H=%d B=%lld\n", i,H[i],B[i]);
        while (int(q.size())>1 && H[i] < H[q.back()]) {
            int b = q.back(); q.pop_back(); int b2 = q.back();
            // orig range (b2+1)..b, val = B[b]
            seg.update(b2+1, b, -B[b]);
            // printf("removing range b2=%d b=%d B=%lld\n", b2,b,B[b]);
        }
        int pre = q.back();
        q.push_back(i);
        // printf("pre=%d updateing range %d..%d with %lld\n", pre, pre+1,i,B[i]);

        seg.update(pre+1, i, B[i]);
        dp[i] = seg.query(1, N);
        seg.updateSingle(i+1, dp[i]);
    }

    cout << dp[N] << '\n';

    return 0;
}