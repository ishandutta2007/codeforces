// ./c-travelling-salesman-problem.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;
using pii = pair<int, int>;

// Template is 1-indexed
// RMQ + Set query
struct Comp {
    using Data = ll;
    using Update = ll;
    const Data vdef = LLINF;
    Data merge(Data l, Data r) { return min(l, r); }
    void applyUpdate(Data &l, Update &r) { l = min(l, r); }
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

const int MN = 1e5 + 1;
int N;
    // A[MN], C[MN];
tuple<int, int, int> vs[MN];
ll dp1[MN], dp2[MN];
Ranks<int> rs;
SegmentTree<Comp> sdown, snocost;

ll run(int l, int r, ll dp[MN]) {
    fill(dp, dp+MN, LLINF);
    dp[l] = 0;
    sdown.init(rs.size());
    snocost.init(rs.size());
    for (auto i = l; i <= r; i++) {
        auto [a, _, c] = vs[i];
        if (i > l) {
            dp[i] = min(sdown.query(1, rs.get(a)) + a, snocost.query(rs.get(a), rs.size()));
        }
        // printf("i=%d a=%d c=%d IDX=%d dp=%lld\n", i,a,c,_,dp[i]);

        sdown.update(rs.get(a+c), dp[i]-a-c);
        snocost.update(rs.get(a+c), dp[i]);
    }
    return dp[r];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (auto i = 0; i < N; i++) {
        // cin >> A[i] >> C[i];
        int a, c; cin >> a >> c;
        vs[i] = {a, i, c};
        rs.add(a);
        rs.add(a+c);
    }
    rs.init();
    sort(vs, vs+N);

    int st = -1;
    for (auto i = 0; i < N; i++)
        if (get<1>(vs[i]) == 0)
            st = i;

    run(0, N-1, dp1);
    // printf("run2\n");
    // run(0, st, dp2);

    // printf("res1=%lld res2=%lld\n", dp1[N-1],dp2[st]);
    // ll ans = min(dp1[N-1] + dp2[st], (ll)max(0, get<0>(vs[N-1]) - get<0>(vs[0]) - get<2>(vs[0])));
    ll ans = dp1[N-1];
    for (auto i = 0; i < N; i++) ans += get<2>(vs[i]);
    cout << ans << '\n';

    return 0;
}