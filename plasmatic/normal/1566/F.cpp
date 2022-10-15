// ./f-points-movement.yml
#include <bits/stdc++.h>
using namespace std;

// Defines
#define fs first
#define sn second
#define pb push_back
#define eb emplace_back
#define mpr make_pair
#define mtp make_tuple
#define all(x) (x).begin(), (x).end()
// Basic type definitions
#if __cplusplus == 201703L // CPP17 only things
template <typename T> using opt_ref = optional<reference_wrapper<T>>; // for some templates
#endif
using ll = long long; using ull = unsigned long long; using ld = long double;
using pii = pair<int, int>; using pll = pair<long long, long long>;
#ifdef __GNUG__
// PBDS order statistic tree
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T, class comp = less<T>> using os_tree = tree<T, null_type, comp, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K, typename V, class comp = less<K>> using treemap = tree<K, V, comp, rb_tree_tag, tree_order_statistics_node_update>;
// HashSet
#include <ext/pb_ds/assoc_container.hpp>
template <typename T, class Hash> using hashset = gp_hash_table<T, null_type, Hash>;
template <typename K, typename V, class Hash> using hashmap = gp_hash_table<K, V, Hash>;
const ll RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash { ll operator()(ll x) const { return x ^ RANDOM; } };
#endif
// More utilities
int SZ(string &v) { return v.length(); }
template <typename C> int SZ(C &v) { return v.size(); }
template <typename C> void UNIQUE(vector<C> &v) { sort(v.begin(), v.end()); v.resize(unique(v.begin(), v.end()) - v.begin()); }
template <typename T, typename U> void maxa(T &a, U b) { a = max(a, b); }
template <typename T, typename U> void mina(T &a, U b) { a = min(a, b); }
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

ostream& operator<<(ostream& out, const pii o) {
    out << "(fs=" << o.fs << ", sn=" << o.sn << ")";
    return out;
}

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
// Default Comp: RMQ + Set query
// Functions merge and applyUpdate should be implemented left to right
struct Comp {
    using Data = ll;
    using Update = ll;
    const Data vdef = LLINF;
    Data merge(Data l, Data r) { return min(l, r); }
    void applyUpdate(Data &l, Update &r) { l = r; }
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

const int MN = 2e5 + 10;
int N, M;
ll P[MN], L[MN], R[MN];

void solve() {
    cin >> N >> M;

    set<int> vs;
    for (auto i = 1; i <= N; i++) {
        cin >> P[i];
        vs.insert(P[i]);
    }
    P[0] = -INF;
    P[N+1] = INF;
    sort(P+1, P+N+1);
    vs.insert(INF);

    vector<pii> _segs;
    for (auto i = 0; i < M; i++) {
        int l, r; cin >> l >> r;

        // useful segment
        if (*vs.lower_bound(l) > r) {
            _segs.eb(l, r);
        }
    }
    sort(all(_segs), [&] (const pii &a, const pii &b) {
        return a.fs == b.fs ? a.sn > b.sn : a.fs < b.fs;
    });

    // remove covered intervals
    vector<pii> segs;
    int _maxR = -INF;
    for (auto [l, r] : _segs) {
        while (!segs.empty() && segs.back().fs <= l && r <= segs.back().sn)
            segs.pop_back();
        segs.eb(l, r);
    }

    // cout << "segs=["; for (auto __x:segs)cout<<__x<<", "; cout<<"], "; cout << endl; // db I:segs

    for (auto i = 0; i <= N+1; i++)
        segs.eb(P[i], P[i]);
    sort(all(segs));

    // cout << "segs=["; for (auto __x:segs)cout<<__x<<", "; cout<<"], "; cout << endl; // db I:segs

    // get L,R
    for (auto i = 0; i <= N; i++) {
        int lidx = lower_bound(all(segs), pii(P[i], -INF)) - segs.begin(), ridx = lower_bound(all(segs), pii(P[i+1], -INF)) - segs.begin() - 1;

        L[i] = lidx;
        R[i] = ridx;
    }

    SegmentTree<Comp> stL, st2L;

    vector<vector<ll>> dp(N+1), pos(N+1);
    vector<Ranks<ll>> rs(N+1);
    for (auto i = 0; i <= N; i++) {
        for (auto j = L[i]; j <= R[i]; j++)
            rs[i].add(segs[j+1].sn);
        rs[i].init();

        dp[i].assign(R[i]-L[i]+1, LLINF);
        int sz = SZ(dp[i]);

        // calculate cur DP
        if (i > 0) {
            int szp = SZ(dp[i-1]);
            for (auto j = 0; j < sz; j++) {
                ll R = segs[j+L[i]].fs, startIdx = rs[i-1].get(2LL*P[i] - R);
                ll ansr = st2L.query(startIdx, szp) + R + P[i];
                ll ansl = stL.query(1, startIdx) + 2LL*R - P[i];

                // cout<<"j="<<(j)<<", "; cout<<"R="<<(R)<<", "; cout<<"startIdx="<<(startIdx)<<", "; cout<<"ansr="<<(ansr)<<", "; cout<<"ansl="<<(ansl)<<", "; cout << endl; // db j,R,startIdx,ansr,ansl
                dp[i][j] = min({ansl, ansr});
            }
        }
        else
            dp[i][0] = 0;

        // cout<<"i="<<(i)<<", "; cout<<"P[i]="<<(P[i])<<", "; cout << "rs[i].ranks=["; for (auto __x:rs[i].ranks)cout<<__x<<", "; cout<<"], "; cout << endl; // db i,P[i],I:rs[i].ranks
        // cout << "dp[i]=["; for (auto __x:dp[i])cout<<__x<<", "; cout<<"], "; cout << endl; // db I:dp[i]

        // upd segtree
        stL.init(sz);
        st2L.init(sz);
        for (auto j = 0; j < sz; j++) {
            int rpos = segs[L[i]+j+1].sn, IDX = rs[i].get(rpos);
            // cout<<"j="<<(j)<<", "; cout<<"IDX="<<(IDX)<<", "; cout<<"segs[j+1].sn="<<(segs[j+1].sn)<<", "; cout << endl; // db j,IDX,segs[j].sn
            stL.update(IDX, dp[i][j] - rpos);
            st2L.update(IDX, dp[i][j] - 2LL*rpos);
        }
    }

    // last point is: {
    //   on the left (gone)
    //   on the point
    // }

    ll ans = dp[N].back();
    cout << (ans) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        // Input
        
        solve();

        // Reset
    }
}