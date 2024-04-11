// ./f-swapping-problem.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;
using pii = pair<int, int>;

// template is 1-indexed
template <typename T> struct Ranks {
    vector<T> ranks;
    void init() {
        sort(ranks.begin(), ranks.end());
        ranks.resize(unique(ranks.begin(), ranks.end()) - ranks.begin());
    }
    template <typename It> void init(It st, It en) { ranks = vector<T>(st, en); init(); }
    void add(T v) { ranks.push_back(v); }
    int get(T v) { return lower_bound(ranks.begin(), ranks.end(), v) - ranks.begin() + 1; }
    int size() { return ranks.size(); }
};
// Template is 1-indexed
// RMQ + Set query
struct MinComp {
    using Data = ll;
    using Update = ll;
    const Data vdef = LLINF;
    Data merge(Data l, Data r) { return min(l, r); }
    void applyUpdate(Data &l, Update &r) { l = min(l, r); }
};
struct MaxComp {
    using Data = ll;
    using Update = ll;
    const Data vdef = -LLINF;
    Data merge(Data l, Data r) { return max(l, r); }
    void applyUpdate(Data &l, Update &r) { l = max(l, r); }
};
#define MID int mid = (l + r) / 2, lhs = i + 1, rhs = i + (mid - l + 1) * 2;
template <class Comp> struct SegmentTree {
    using Data = typename Comp::Data; using Update = typename Comp::Update; Comp C;
    int N;
    vector<Data> seg;
    void init(int n0) {
        N = n0;
        seg.assign(2 * N + 2, C.vdef);
    }
    Data _query(int ql, int qr, int i, int l, int r) {
        if (ql > r || qr < l) return C.vdef;
        if (l >= ql && r <= qr) return seg[i];
        MID;
        return C.merge(_query(ql, qr, lhs, l, mid), _query(ql, qr, rhs, mid + 1, r));
    }
    Data _update(int q, Update v, int i, int l, int r) {
        if (q > r || q < l) return seg[i];
        if (l == q && r == q) {
            C.applyUpdate(seg[i], v);
            return seg[i];
        }
        MID;
        return seg[i] = C.merge(_update(q, v, lhs, l, mid), _update(q, v, rhs, mid + 1, r));
    }
    Data query(int ql, int qr) { return _query(ql, qr, 1, 1, N); }
    void update(int q, Update v) { _update(q, v, 1, 1, N); }
};

// A < B
// C > D
// (We can only get a better answer when A->B and C->D) (opposite directions, we can swap and run again to check opposite case)
//
// Only two cases we have to worry about
//
// D
// B
// A
// C
//
// Add: 2A-2B
//
// C
// B
// D
// A
//
// Add: 2D-2B (by min = 2D)

const int MN = 2e5 + 1, MV = MN*2;
int N, 
    A[MN], B[MN];
Ranks<int> rs;

ll run() {
    ll res = 0;

    // case 1
    SegmentTree<MaxComp> case1; case1.init(rs.size());
    for (auto i = 0; i < N; i++) {
        if (A[i] >= B[i]) {
            case1.update(rs.get(B[i]), A[i]);
        }
    }
    for (auto i = 0; i < N; i++) {
        if (A[i] <= B[i]) {
            if (case1.query(1, rs.get(A[i])) >= B[i])
                res = min(res, 2LL*A[i] - 2*B[i]);
        }
    }

    // case 2
    vector<pii> psDown, psUp;
    for (auto i = 0; i < N; i++) {
        if (A[i] >= B[i]) {
            psDown.emplace_back(A[i], B[i]);
        }
    }
    for (auto i = 0; i < N; i++) {
        if (A[i] <= B[i]) {
            psUp.emplace_back(B[i], A[i]);
        }
    }
    sort(psDown.begin(), psDown.end(), greater<>());
    sort(psUp.begin(), psUp.end(), greater<>());

    SegmentTree<MinComp> case2; case2.init(rs.size());
    int ptr = 0, sz = psDown.size();
    for (auto [b, a] : psUp) {
        while (ptr < sz && psDown[ptr].first >= b) {
            auto [_, d] = psDown[ptr];
            case2.update(rs.get(d), 2*d);

            ptr++;
        }

        ll cur = case2.query(rs.get(a), rs.get(b));
        if (cur != LLINF) {
            res = min(res, cur - 2*b);
        }
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll init = 0;

    cin >> N;
    for (auto i = 0; i < N; i++) cin >> A[i];
    for (auto i = 0; i < N; i++) {
        cin >> B[i];
        init += abs(A[i] - B[i]);

        rs.add(A[i]);
        rs.add(B[i]);
    }
    rs.init();

    ll ans = run();
    for (auto i = 0; i < N; i++) swap(A[i], B[i]);
    ans = min(ans, run());

    cout << (init + ans) << '\n';

    return 0;
}